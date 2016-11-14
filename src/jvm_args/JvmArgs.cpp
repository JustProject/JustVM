//
// Created by 刘丰恺 on 2016/11/14.
//

#include "JvmArgs.h"

void JvmArgs::help() {
    LOG(INFO) << "fuck helper -- ";
}

void JvmArgs::version() {
    LOG(INFO) << "fuck version -- ";
}

void JvmArgs::addClassPath(std::string cp) {
    LOG(INFO) << "fuck class path -- " << cp;
    this->classPaths.push_back(cp);
}

void JvmArgs::addArgs(std::string arg) {
    LOG(INFO) << "fuck args -- " << arg;
    this->args.push_back(arg);
}

void JvmArgs::setClass(std::string classFile) {
    LOG(INFO) << "fuck class -- " << classFile;
    this->classFile = classFile;
}

void JvmArgs::setJrePath(std::string jrePath) {
    LOG(INFO) << "fuck class -- " << jrePath;
    this->jreFilePath = jrePath;
}



