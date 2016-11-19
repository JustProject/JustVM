//
// Created by 刘丰恺 on 2016/11/19.
//

#ifndef JUSTVM_CLASS_READER_H
#define JUSTVM_CLASS_READER_H

#include "../utils/util.h"
#include <vector>

class ClassReader {
protected:

    uint32 magic;
    uint16 minorVersion;
    uint16 majorVersion;
    // constant pool
    uint16 accessFlags;
    uint16 thisClass;
    uint16 superClass;

    std::vector<uint16> interfaces;

    // fields & methods

private:


public:


};

#endif //JUSTVM_CLASS_READER_H
