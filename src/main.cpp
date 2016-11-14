#include <iostream>
#include <multi_value.h>
#include "logger/log.h"
#include "command.h"

INITIALIZE_EASYLOGGINGPP

class FuckDemo {
public:
    void help() {
        LOG(INFO) << "fuck helper -- ";
    };

    void version() {
        LOG(INFO) << "fuck version -- ";
    }

    void classPath(std::string cp) {
        LOG(INFO) << "fuck cp -- " << cp;
    }
};

int main(int argc, char *argv[]) {

    FuckDemo demo;

    printf("%s \n", getenv("JAVA_HOME"));

    // print help message
    auto help =
            std::make_shared<cmd::Option<void>>("-h", "Help",
                                                std::bind(&FuckDemo::help, &demo));
    // vm version
    auto version =
            std::make_shared<cmd::Option<void>>("-v", "Version",
                                                std::bind(&FuckDemo::version, &demo));
    // multi parts of class path
    auto multiPath =
            std::make_shared<cmd::Option<std::string>>("-cp", "ClassPath",
                                                       std::bind(&FuckDemo::classPath, &demo,
                                                                 std::placeholders::_1));
    auto classPath =
            std::make_shared<cmd::MultiValue>(";", multiPath);


    cmd::Command command(argc, argv, {help, version, classPath});

    return 0;
}

