//
// Created by 刘丰恺 on 2016/12/1.
//

#include "../utils/mem_zip/unzipper.h"
#include "class_reader.h"
#include "class_file.h"
#include <iostream>
#include <cinttypes>

using std::cout;
using std::endl;

using zipper::Unzipper;
using zipper::ZipEntry;

int main() {

    std::string dir = "/Library/Java/JavaVirtualMachines/jdk1.8.0_51.jdk/Contents/Home/jre/lib/rt.jar";

    Unzipper unzipper(dir);
    std::vector<ZipEntry> entries = unzipper.entries();

    std::vector<byte> unzipped_entry;

    unzipper.extractEntryToMemory("java/lang/String$1.class", unzipped_entry);

//    for (int i = 0; i < unzipped_entry.size(); ++i) {
//        printf("%x ", unzipped_entry[i]);
//    }

    ClassReader reader(std::cref(unzipped_entry));

//    printf("%x" " \n", reader.readType<uint32>());
//    printf("%" PRIu16 " \n", reader.readType<uint16>());
//    printf("%" PRIu16 "\n", reader.readType<uint16>());
//    printf("%" PRIu16 "\n", reader.readType<uint16>());
    ClassFile classFile;
    classFile.setMagic(reader.readType<uint32>());
    classFile.setMinorVersion(reader.readType<uint16>());
    classFile.setMajorVersion(reader.readType<uint16>());
    classFile.setConstantPoolCount(reader.readType<uint16>());

    return 0;
}