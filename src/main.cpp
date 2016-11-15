#include <iostream>
#include <vector>
#include "logger/log.h"
#include "jvm_args/JvmArgs.h"
#include "jvm/Jvm.h"


INITIALIZE_EASYLOGGINGPP


int main(int argc, char *argv[]) {

    Jvm jvm;

    // get command args
    auto args = jvm.initial(argc, argv);



    return 0;
}

