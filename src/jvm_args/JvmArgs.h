//
// Created by 刘丰恺 on 2016/11/14.
//

#ifndef JUSTVM_JVMARGS_H
#define JUSTVM_JVMARGS_H

#include <string>
#include <vector>
#include "log.h"

class JvmArgs {
protected:

    /**
     * args
     * -args=[ARG_1];[ARG_2];[ARG_3]
     */
    std::vector<std::string> args;

    /**
     * class_paths
     * -cp=[CLASS_PATH_1];[CLASS_PATH_2];[CLASS_PATH_3]
     */
    std::vector<std::string> classPaths;

    std::string classFile;

    std::string jreFilePath;

public:

    JvmArgs() { }

    virtual ~JvmArgs() { }

    void help();

    void version();

    void addClassPath(std::string cp);

    void setJrePath(std::string jrePath);

    void setClass(std::string classFile);

    void addArgs(std::string arg);

    const std::string &getClassFile() const {
        return classFile;
    }

    void setClassFile(const std::string &classFile) {
        JvmArgs::classFile = classFile;
    }

    const std::vector<std::string> &getArgs() const {
        return args;
    }

    void setArgs(const std::vector<std::string> &args) {
        JvmArgs::args = args;
    }

    const std::vector<std::string> &getClassPaths() const {
        return classPaths;
    }

    void setClassPaths(const std::vector<std::string> &classPaths) {
        JvmArgs::classPaths = classPaths;
    }

    const std::string &getJreFilePath() const {
        return jreFilePath;
    }

    void setJreFilePath(const std::string &jreFilePath) {
        JvmArgs::jreFilePath = jreFilePath;
    }
};


#endif //JUSTVM_JVMARGS_H
