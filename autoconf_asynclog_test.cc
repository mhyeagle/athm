#include <iostream>
#include <string>
#include <map>

#include <autoconf/autoconf_sdk.h>
#include <ahasynclog/log.h>

using namespace std;

const string PREFIX = "/autoconf/adver/zaibei/groupserver";

int main() {
    CAutoConf test_conf(PREFIX);
    std::map<std::string, std::string> kv;
    int ret = test_conf.get_map(kv);
    std::map<std::string, std::string>::iterator iter;
    for(iter = kv.begin(); iter != kv.end(); ++iter) {
        cout << iter->first << " : " << iter->second << endl;
        cout << endl;
    }

    iter = kv.find("log_conf");
    std::string log_str = iter->second;

    CAsyncLogHandler::init_content(log_str);
    CAsyncLogger *logger = CAsyncLogHandler::get_logger("CPDGROUPSERVER");
    logger->Error("test_debug");
    CAsyncLogHandler::shutdown();

    return 0;
}
