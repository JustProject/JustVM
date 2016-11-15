//
// Created by 刘丰恺 on 2016/11/14.
//

#ifndef JUSTVM_JVM_H
#define JUSTVM_JVM_H

#include "../jvm_args/JvmArgs.h"
#include "command.h"
#include "multi_value.h"
#include "option.h"

class Jvm {

protected:
    std::shared_ptr<JvmArgs> commandArgs;

public:
    /**
     * initial command options
     * @param argc size of options
     * @param *argv[] args
     * @return ptr of JvmArgs
     */
    std::shared_ptr<JvmArgs> initial(int argc, char **argv);

    void startJustVm();

    void startJustVm(std::shared_ptr<JvmArgs> args);

};


#endif //JUSTVM_JVM_H
