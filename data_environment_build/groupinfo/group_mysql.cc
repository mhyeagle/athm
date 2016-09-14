#include <iostream>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <mysql/mysql.h>

#define RET_SUCCESS 0
#define RET_ERROR -1

using namespace std;

int get_data(string date);
int set_data(string date, string hostip, string hostport, string user, string passwd);
string get_date();

int main(int argc, char** argv) {
    cout << "---------------------------USAGE-------------------------------" << endl;
    cout << "`groupinfo get` to dump group info into mysql_dump.txt" << endl;
    cout << "`groupinfo set hostip hostport user password` to set group info to mysql" << endl;
    cout << "----------------------------END--------------------------------" << endl;
    cout << endl;

    if (argc != 2 && argc != 6) {
        cout << "input error" << endl;
        return RET_SUCCESS;
    }

    string button = argv[1];
    if (argc == 2 && "get" != button) {
        cout << "input error to get info" << endl;
        return RET_ERROR;
    } else if (argc == 6 && "set" != button) {
        cout << "input error to set info" << endl;
        return RET_ERROR;
    }

    string host_ip;
    string host_port;
    string user;
    string passwd;
    if (argc == 6) {
        host_ip = argv[2];
        host_port = argv[3];
        user = argv[4];
        passwd = argv[5];
    }

    int ret = 0;
    string date = get_date();

    if (button == "get") {
        ret = get_data(date);
        if (ret) {
            cerr << "get group data from mysql error." << endl;
            return RET_ERROR;
        }
    }

    if (button == "set") {
        ret = set_data(date, host_ip, host_port, user, passwd);
        if (ret) {
            cerr << "set group data to mysql error, hostip:" << host_ip << " hostport:" << host_port
                    << " username:" << user << " password:" << passwd << endl;
            return RET_ERROR;
        }
    }

    cout << "operation finish." << endl;

    return 0;
}

void finish_with_error(MYSQL *con) {
    cerr << mysql_error(con) << endl;
    mysql_close(con);
}

string get_date() {
    stringstream ss;
    time_t now_seconds;
    now_seconds = time(NULL);
    struct tm * local_tm;
    local_tm = localtime(&now_seconds);
    int year = local_tm->tm_year + 1900;
    int month = local_tm->tm_mon + 1;
    int day = local_tm->tm_mday;
    ss << year;
    if (month < 10) {
        ss << "0";
    }
    ss << month << day;

    return ss.str();
}

int get_data(string date) {

    ofstream myfile;
    myfile.open("mysql_dump.txt");

    MYSQL *con = mysql_init(NULL);

    if (NULL == con) {
        cout << "mysql_init() failed!" << endl;
        return RET_ERROR;
    }

    if (mysql_real_connect(con, "adengine-mm-3306.bj.autohome.com.cn", "adengine", "D74isyhdBnhP",
            "adengine", 0, NULL, 0) == NULL) {
        finish_with_error(con);
        return RET_ERROR;
    }

    string query_str = "SELECT * FROM group_" + date;
    if (mysql_query(con, query_str.c_str())) {
        finish_with_error(con);
        return RET_ERROR;
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (NULL == result) {
        finish_with_error(con);
        return RET_ERROR;
    }

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        myfile << row[0] << ',';
        myfile << "'" << row[1] << "'" << ',';
        myfile << "'" << row[2] << "'" << ',';
        myfile << row[3] << ',';
        myfile << row[4] << "\n";
    }

    myfile.close();
    mysql_free_result(result);
    mysql_close(con);

    return 0;
}

int set_data(string date, string hostip, string hostport, string user, string passwd) {
    int ret = 0;

    ifstream myfile;
    myfile.open("mysql_dump.txt");
    string data_line;
    string command;
    string group_date = "group_" + date;
    string before_com = "INSERT INTO " + group_date + " VALUES(";
    string end_com = ")";

    MYSQL *con = mysql_init(NULL);

    if (NULL == con) {
        cout << "mysql_init() failed!" << endl;
        return RET_ERROR;
    }

    if (mysql_real_connect(con, hostip.c_str(), user.c_str(), passwd.c_str(), NULL, 0, NULL,
            0) == NULL) {
        finish_with_error(con);
        return RET_ERROR;
    }

    if (mysql_select_db(con, "adengine")) {
        ret = mysql_query(con, "create database adengine;");
        if (ret) {
            finish_with_error(con);
            return RET_ERROR;
        }
    }

    string drop_table_str = "drop table group_" + date;
    mysql_query(con, drop_table_str.c_str());

    string create_table_str =
            "create table " + group_date
                    + "(\
    doc_num bigint(20) not null, \
    invert_index mediumblob not null, \
    positive_index mediumblob not null, \
    counter_status int(11) not null, \
    business_status int(11) not null, \
    primary key (doc_num) );";
    if (mysql_query(con, create_table_str.c_str())) {
        finish_with_error(con);
        return RET_ERROR;
    }

    while (1) {
        data_line.clear();
        getline(myfile, data_line);
        if (data_line == "") {
            break;
        }
        command = before_com + data_line + end_com;
        if (mysql_query(con, command.c_str())) {
            finish_with_error(con);
            return RET_ERROR;
        }
    }

    myfile.close();
    mysql_close(con);

    return 0;
}
