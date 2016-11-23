#include <iostream>
#include "jvm_args/JvmArgs.h"
#include "jvm/Jvm.h"
#include "class_path/dir_entry.h"

INITIALIZE_EASYLOGGINGPP
//
//using zipper::Unzipper;
//using zipper::ZipEntry;


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

//    CZipFile zipTest;
//
//    zipTest.SetFileName(dir);
//
//    zipTest.OpenFile();
//
//    for (int i = 0; i < zipTest.GetFilesNumber(); i++) {
//        printf("%s\n", zipTest.GetFileAttributes(i)->file_name);
//    }

//    Unzipper unzipper("zipfile.zip");
//    std::vector<ZipEntry> entries = unzipper.entries();
//
//    for (int i = 0; i < entries.size(); ++i) {
//        std::cout << entries[i].name << std::endl;
//    }


//    unzipper.close();


    return 0;
}

