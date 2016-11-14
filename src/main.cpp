#include <iostream>
#include <vector>
#include <multi_value.h>
#include "logger/log.h"
#include "command.h"
#include "jvm_args/JvmArgs.h"

INITIALIZE_EASYLOGGINGPP

std::shared_ptr<JvmArgs> initialCommand(int argc, char *argv[]) {
    JvmArgs demo;

    printf("%s \n", getenv("JAVA_HOME"));

    // print help message
    auto help =
            std::make_shared<cmd::Option<void>>("-h", "Help",
                                                std::bind(&JvmArgs::help, &demo));
    // vm version
    auto version =
            std::make_shared<cmd::Option<void>>("-v", "Version",
                                                std::bind(&JvmArgs::version, &demo));
    // multi parts of class path
    auto multiPath =
            std::make_shared<cmd::Option<std::string>>("-cp", "ClassPath",
                                                       std::bind(&JvmArgs::addClassPath, &demo,
                                                                 std::placeholders::_1));
    // class path
    auto classPath =
            std::make_shared<cmd::MultiValue>(";", multiPath);

    auto xJreOption =
            std::make_shared<cmd::Option<std::string>>("XjreOption", "JRE PATH",
                                                       std::bind(&JvmArgs::setJrePath, &demo,
                                                                 std::placeholders::_1)
            );

    // class file
    auto classFile =
            std::make_shared<cmd::Option<std::string>>("-class", "Class",
                                                       std::bind(&JvmArgs::setClass, &demo,
                                                                 std::placeholders::_1));

    auto arg =
            std::make_shared<cmd::Option<std::string>>("-args", "Args",
                                                       std::bind(&JvmArgs::addArgs, &demo,
                                                                 std::placeholders::_1));
    auto args =
            std::make_shared<cmd::MultiValue>(";", arg);


    cmd::Command command(argc, argv, {help, version, xJreOption, classPath, classFile, args});

    return std::make_shared<JvmArgs>(demo);
}

int main(int argc, char *argv[]) {

    auto args = initialCommand(argc, argv);



    return 0;
}

