#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <redis3m/redis3m.hpp>

#include "creativeinfo.pb.h"

#define RET_SUCCESS 0
#define RET_ERROR -1
#define NUM_PER_CREATIVE 11

using namespace std;
using namespace boost;
using namespace redis3m;

redis3m::simple_pool::ptr_t redisconn_pool;
std::string redisip = "127.0.0.1";
int redisport = 3680;

int max_retry = 10;
int interval = 5;

int maxtry = 3;

int get_creativeinfo();
int set_creativeinfo();

int main(int argc, char** argv) {
    cout << "---------------------------USAGE-------------------------------" << endl;
    cout << "`creativeinfo get` to dump creative info into creative_dump.txt" << endl;
    cout << "`creativeinfo set ip port` to set creative info to redis" << endl;
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
        }
        redisip = argv[2];
        redisport = atoi(argv[3]);
    }

    int ret = 0;

    if (button == "get") {
        ret = get_creativeinfo();
        if (ret) {
            cerr << "get creative info from redis error." << endl;
            return RET_ERROR;
        }
    }

    if (button == "set") {
        ret = set_creativeinfo();
        if (ret) {
            cerr << "set creative info to redis error." << endl;
            return RET_ERROR;
        }
    }

    cout << "operation finish." << endl;

    return RET_SUCCESS;
}

int get_creativeinfo() {
    redisip = "192.168.7.46";
    redisport = 3680;

    ifstream myfile;
    myfile.open("../groupinfo/mysql_dump.txt");
    if (!myfile.good()) {
        cerr << "cannot open file: ../groupinfo/group_dump.txt" << endl;
        return RET_ERROR;
    }

    string str;
    vector<string> m_vec;
    vector<string> m_vec2;
    set<string> creativeid_set;
    int creative_num = 0;

    redisconn_pool = redis3m::simple_pool::create(redisip, redisport);
    redisconn_pool->set_failover_option(max_retry, interval);

    do {
        getline(myfile, str);
        if (str == "") {
            break;
        }

        m_vec.clear();
        split(m_vec, str, is_any_of(","));
        if (m_vec.size() != 5) {
            continue;
        }

        m_vec2.clear();
        split(m_vec2, m_vec[2], is_any_of("\001"));
        creative_num = atoi(m_vec2[2].c_str());
        for (int i = 0; i < creative_num; i++) {
            creativeid_set.insert(m_vec2[3 + NUM_PER_CREATIVE * i]);
        }
    } while (1);

    myfile.close();

    redis3m::connection::ptr_t conn;
    string creative_data;
    ofstream outfile;
    outfile.open("creative_dump.txt");
    ad::CreativeInfo creative_info;
    ad::Creative* creative;

    for (set<string>::iterator iter = creativeid_set.begin(); iter != creativeid_set.end();
            iter++) {
        for (int i = 0; i < maxtry; ++i) {
            conn = redisconn_pool->get();
            if (NULL == conn) {
                continue;
            }

            try {
                creative_data = conn->run(redis3m::command("GET")(*iter)).str();
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
        if (creative_data != "") {
            creative = creative_info.add_creative();
            creative->set_id(*iter);
            creative->set_info(creative_data);
        }
    }
    creative_info.SerializeToOstream(&outfile);
    outfile.close();

    return 0;
}

int set_creativeinfo() {
    ifstream myfile;
    string str;
    vector<string> m_vec;
    myfile.open("creative_dump.txt");
    ad::CreativeInfo creative_info;
    creative_info.ParseFromIstream(&myfile);

    redisconn_pool = redis3m::simple_pool::create(redisip, redisport);
    redisconn_pool->set_failover_option(max_retry, interval);
    redis3m::connection::ptr_t conn;

    for (int i = 0; i < creative_info.creative_size(); ++i) {
        const ad::Creative& m_creative = creative_info.creative(i);
        m_vec.clear();
        m_vec.push_back(m_creative.id());
        m_vec.push_back(m_creative.info());
        command cmd("SET");
        cmd << m_vec[0] << m_vec[1];

        for (int i = 0; i < maxtry; ++i) {
            conn = redisconn_pool->get();
            if (NULL == conn) {
                continue;
            }
            try {
                reply rs = conn->run(cmd);
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
    }
    myfile.close();

    return 0;
}
