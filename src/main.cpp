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

    void getJrePath(std::string cp) {
        LOG(INFO) << "fuck jre -- " << cp;
    }

    void getClass(std::string classFile) {
        LOG(INFO) << "fuck class -- " << classFile;
    }

    void getArgs(std::string args) {
//        for (auto arg : args) {
//            LOG(INFO) << "fuck args -- " << arg;
//        }
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
    // class path
    auto classPath =
            std::make_shared<cmd::MultiValue>(";", multiPath);

    auto xJreOption =
            std::make_shared<cmd::Option<std::string>>("XjreOption", "JRE PATH",
                                                       std::bind(&FuckDemo::getJrePath, &demo,
                                                                 std::placeholders::_1)
            );

    // class file
    auto classFile =
            std::make_shared<cmd::Option<std::string>>("-class", "Class",
                                                       std::bind(&FuckDemo::getClass, &demo,
                                                                 std::placeholders::_1));

    auto args =
            std::make_shared<cmd::Option<std::string>>("-args", "Args",
                                                       std::bind(&FuckDemo::getArgs, &demo,
                                                                 std::placeholders::_1));

    cmd::Command command(argc, argv, {help, version, xJreOption, classPath, classFile, args});

    return 0;
}

