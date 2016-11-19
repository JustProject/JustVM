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

    DirEntry dirEntry(dir);

    dirEntry.readClass("");

    for (int i = 0; i < dirEntry.getSize(); ++i) {
        std::cout << dirEntry.getByteChars()[i];
    }

    return 0;
}

