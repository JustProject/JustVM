//
// Created by 刘丰恺 on 2016/11/19.
//

#include "dir_entry.h"

void DirEntry::readClass(std::string className) {
    // size
    this->fileSize = getFileSize((absPath + className).c_str());
    // read
    this->byteChars = readByteFromFile(this->byteChars, (absPath + className).c_str());
}

std::string &DirEntry::toString() {
    return absPath;
}

