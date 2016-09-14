#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <redis3m/redis3m.hpp>
#include <vector>
#include <boost/algorithm/string.hpp>

#include "adserver_common/positioninfo.h"

using namespace redis3m;
using namespace std;

redis3m::simple_pool::ptr_t redisconn_pool;
std::string redisip = "192.168.7.46";
int redisport = 26811;

redis3m::simple_pool::ptr_t redisconn_pool_to;
std::string redisipto = "127.0.0.1";
int redisportto = 26811;

int max_retry = 10;
int interval = 5;

int maxtry = 3;

//for psids
std::vector<std::string> keys;

int getPosition(const std::string &positionid, std::string& str);
int setPosition(const string& str);
int getKeys(std::vector<std::string> &keys);

int main(int argc, char** argv) {
    cout << "---------------------------USAGE-------------------------------" << endl;
    cout << "`positioninfo get` to dump position info into position_dump.txt" << endl;
    cout << "`positioninfo set ip port` to set position info to redis" << endl;
    cout << "----------------------------END--------------------------------" << endl;
    cout << endl;


    if (argc != 2 && argc != 4) {
        cout << "input error" << endl;
        return 0;
    }
    string button = argv[1];
    if (argc == 2 && "get" != button) {
        cout << "input error to get info" << endl;
        return -1;
    } else if (argc == 4 && "set" != button) {
        cout << "input error to set info" << endl;
        return -2;
    }

    if (argc == 4) {
        string ip = argv[2];
        if (ip == "192.168.7.46" || ip == "192.168.7.47" || ip == "192.168.7.48") {
            cout << "the ip is online, and could not insert to." << endl;
            return -3;
        } else {
            redisipto = argv[2];
            redisportto = atoi(argv[3]);
        }
    }

    int ret = 0;

    if (button == "get") {
        ofstream myfile;
        myfile.open("position_dump.txt");

        //配置连接池
        redisconn_pool = redis3m::simple_pool::create(redisip, redisport);
        redisconn_pool->set_failover_option(max_retry, interval);

        getKeys(keys);
        for (size_t i = 0; i < keys.size(); i++) {
            std::string tmp_id = keys[i];
            std::string str_store;
            ret = getPosition(tmp_id, str_store);
            if (ret) {
                continue;
            }
            myfile << str_store;
        }

        myfile.close();
    }

    if (button == "set") {
        redisconn_pool_to = redis3m::simple_pool::create(redisipto, redisportto);
        redisconn_pool_to->set_failover_option(max_retry, interval);
        ifstream putfile;
        std::string temp;
        putfile.open("position_dump.txt");
        do {
            temp.clear();
            std::getline(putfile, temp);
            if (temp == "")
                break;
            setPosition(temp);
        } while (1);
    }

    cout << "Operation finish." << endl;
    return 0;
}

//获取单个广告位信息
int getPosition(const std::string &positionid, std::string& str) {
    std::string strinsert;
    std::vector<redis3m::reply> replys;
    redis3m::connection::ptr_t c;

    c = redisconn_pool->get();
    if (c == NULL)
        return -1;
    command cmd("HMGET");
    cmd << positionid << "m_width" << "m_height" << "m_word_chain_length_min"
            << "m_word_chain_length_max" << "m_creative_type" << "m_creative_size"
            << "m_is_internal" << "m_carousel_num" << "m_billing_mode" << "m_pos_device"
            << "m_ad_label" << "m_law_label" << "m_adposori_type";

    int i = 0;
    for (; i < maxtry; i++) {
        try {
            reply rs = c->run(cmd);
            replys = rs.elements();
            break;
        } catch (const slave_read_only& err) {
            continue;
        } catch (transport_failure& transerr) {
            continue;
        }
    }

    if (i == maxtry) {
        cout << "get positioninfo failed, try maxtry times, and the positionid is: " << positionid
                << endl;
        redisconn_pool->put(c);
        return -2;
    }

    int size = replys.size();
    if (size < 13) {
        redisconn_pool->put(c);
        return -3;
    }

    std::string strvalue;

    //将返回的信息链接成为可以作为数据插入的字符串
    strinsert += positionid;

    strinsert += " m_width ";
    strvalue = replys[0].str();
    strinsert += strvalue;
    //解析Redis返回各个域的信息

    strinsert += " m_height ";
    strvalue = replys[1].str();
    strinsert += strvalue;

    strinsert += " m_word_chain_length_min ";
    strvalue = replys[2].str();
    strinsert += strvalue;

    strinsert += " m_word_chain_length_max ";
    strvalue = replys[3].str();
    strinsert += strvalue;

    strinsert += " m_creative_type ";
    strvalue = replys[4].str();
    strinsert += strvalue;

    strinsert += " m_creative_size ";
    strvalue = replys[5].str();
    strinsert += strvalue;

    strinsert += " m_is_internal ";
    strvalue = replys[6].str();
    strinsert += strvalue;

    strinsert += " m_carousel_num ";
    strvalue = replys[7].str();
    strinsert += strvalue;

    strinsert += " m_billing_mode ";
    strvalue = replys[8].str();
    strinsert += strvalue;

    strinsert += " m_pos_device ";
    strvalue = replys[9].str();
    strinsert += strvalue;

    strinsert += " m_ad_label ";
    strvalue = replys[10].str();
    strinsert += strvalue;

    strinsert += " m_law_label ";
    strvalue = replys[11].str();
    strinsert += strvalue;

    strinsert += " m_adposori_type ";
    strvalue = replys[12].str();
    strinsert += strvalue;

    strinsert += "\n";
    redisconn_pool->put(c);

    str = strinsert;

    return 0;
}

int getKeys(std::vector<std::string> &keys) {
    std::vector<redis3m::reply> replys;
    redis3m::connection::ptr_t conn;
    int i = 0, size = 0;

    for (i = 1; i <= maxtry; i++) {
        conn = redisconn_pool->get();
        if ( NULL == conn) {
            continue;
        }

        try {
            reply rs = conn->run(redis3m::command("keys")("*"));
            replys = rs.elements();
        } catch (const slave_read_only &sro) {
            redisconn_pool->put(conn);
            continue;
        } catch (const transport_failure &tf) {
            redisconn_pool->put(conn);
            continue;
        }

        redisconn_pool->put(conn);
        break;
    }

    std::string v;
    size = replys.size();
    for (i = 0; i < size; i++) {
        v = replys[i].str();
        if (v != "") {
            keys.push_back(v);
        }
    }

    return 0;
}

int setPosition(const string& str) {
    std::vector<redis3m::reply> replys;
    redis3m::connection::ptr_t conn;
    command cmd("HMSET");
    std::vector<std::string> arguments;
    arguments.clear();
    boost::split(arguments, str, boost::is_any_of(" "));
    for (size_t i = 0; i < arguments.size(); i++) {
        cmd << arguments[i];
    }

    int j = 0;
    for (j = 1; j <= maxtry; j++) {
        conn = redisconn_pool_to->get();
        if ( NULL == conn) {
            continue;
        }

        try {
            reply rs = conn->run(cmd);
            replys = rs.elements();
        } catch (const slave_read_only &sro) {
            redisconn_pool_to->put(conn);
            continue;
        } catch (const transport_failure &tf) {
            redisconn_pool_to->put(conn);
            continue;
        }

        redisconn_pool_to->put(conn);
        break;
    }

    if (j > maxtry) {
        cout << "in setPosition hmset to redis fail." << endl;
        return -1;
    }

    return 0;
}
