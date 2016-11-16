#include <iostream>
#include "jvm_args/JvmArgs.h"
#include "jvm/Jvm.h"
#include "class_path/dir_entry.h"

INITIALIZE_EASYLOGGINGPP


int main(int argc, char *argv[]) {

    Jvm jvm;

    // get command args
    auto args = jvm.initial(argc, argv);

    std::string dir = "/Users/liufengkai/Desktop/a.md";

    ept::DirEntry dirEntry(dir);

    auto fuck = dirEntry.readClass("");

    for (auto fu : fuck) {
        std::cout << fu;
    }

//    LOG(INFO) << fuck[1][1];

    return 0;
}

