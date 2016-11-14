//
// Created by 刘丰恺 on 2016/11/14.
//

#include "Jvm.h"

/**
 * initial command options
 * @param argc size of options
 * @param *argv[] args
 * @return ptr of JvmArgs
 */
std::shared_ptr<JvmArgs> Jvm::initialCommand(int argc, char *argv[]) {
    JvmArgs jvmArgs;

    // print help message
    auto help =
            std::make_shared<cmd::Option<void>>
                    ("-h", "Help",
                     std::bind(&JvmArgs::help, &jvmArgs));
    // vm version
    auto version =
            std::make_shared<cmd::Option<void>>
                    ("-v", "Version",
                     std::bind(&JvmArgs::version, &jvmArgs));
    // multi parts of class path
    auto multiPath =
            std::make_shared<cmd::Option<std::string>>
                    ("-cp", "ClassPath",
                     std::bind(&JvmArgs::addClassPath, &jvmArgs,
                               std::placeholders::_1));
    // class path
    auto classPath =
            std::make_shared<cmd::MultiValue>(";", multiPath);

    auto xJreOption =
            std::make_shared<cmd::Option<std::string>>
                    ("XjreOption", "JRE PATH",
                     std::bind(&JvmArgs::setJrePath, &jvmArgs,
                               std::placeholders::_1)
                    );

    // class file
    auto classFile =
            std::make_shared<cmd::Option<std::string>>
                    ("-class", "Class",
                     std::bind(&JvmArgs::setClass, &jvmArgs,
                               std::placeholders::_1));

    auto arg =
            std::make_shared<cmd::Option<std::string>>
                    ("-args", "Args",
                     std::bind(&JvmArgs::addArgs, &jvmArgs,
                               std::placeholders::_1));
    auto args =
            std::make_shared<cmd::MultiValue>(";", arg);


    cmd::Command command(argc, argv, {help, version, xJreOption, classPath, classFile, args});

    commandArgs = std::make_shared<JvmArgs>(jvmArgs);

    return commandArgs;
}

void Jvm::startJustVm() {
    if (commandArgs != nullptr) {
        startJustVm(commandArgs);
    }
}

void Jvm::startJustVm(std::shared_ptr<JvmArgs> args) {

}





