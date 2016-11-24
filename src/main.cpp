#include <iostream>
#include "jvm_args/JvmArgs.h"
#include "jvm/Jvm.h"
#include "utils/mem_zip/unzipper.h"
#include "class_path/dir_entry.h"

INITIALIZE_EASYLOGGINGPP

using zipper::Unzipper;
using zipper::ZipEntry;


int main(int argc, char *argv[]) {

    Jvm jvm;

    // get command args
    auto args = jvm.initial(argc, argv);

    std::string dir = "/Library/Java/JavaVirtualMachines/jdk1.8.0_51.jdk/Contents/Home/jre/lib/rt.jar";

//    DirEntry dirEntry(dir);
//
//    std::cout << getenv("JAVA_HOME");
//
//    dirEntry.readClass("");
//
//    for (int i = 0; i < dirEntry.getSize(); ++i) {
//        std::cout << dirEntry.getByteChars()[i];
//    }

    Unzipper unzipper(dir);
    std::vector<ZipEntry> entries = unzipper.entries();

    for (int i = 0; i < entries.size(); i++) {
        std::cout << entries[i].name << std::endl;
    }

    std::vector<unsigned char> unzipped_entry;

    unzipper.extractEntryToMemory("java/io/EOFException.class", unzipped_entry);

    for (int i = 0; i < unzipped_entry.size(); ++i) {
        std::cout << unzipped_entry[i];
    }


    unzipper.close();

    return 0;
}

