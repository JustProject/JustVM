//
// Created by 刘丰恺 on 2016/12/2.
//

#ifndef JUSTVM_CLASS_FILE_H
#define JUSTVM_CLASS_FILE_H


#include "../utils/util.h"

class ClassFile {
protected:
    uint32 magic;
    uint16 minorVersion;
    uint16 majorVersion;
    uint16 constantPoolCount;
    // constant pool
    uint16 accessFlags;
    uint16 thisClass;
    uint16 superClass;

    std::vector<uint16> interfaces;

    // fields & methods
public:
    uint32 getMagic() const;

    void setMagic(uint32 magic);

    uint16 getMinorVersion() const;

    void setMinorVersion(uint16 minorVersion);

    uint16 getMajorVersion() const;

    void setMajorVersion(uint16 majorVersion);

    uint16 getConstantPoolCount() const;

    void setConstantPoolCount(uint16 constantPoolCount);

    uint16 getAccessFlags() const;

    void setAccessFlags(uint16 accessFlags);

    uint16 getThisClass() const;

    void setThisClass(uint16 thisClass);

    uint16 getSuperClass() const;

    void setSuperClass(uint16 superClass);

    const std::vector<uint16> &getInterfaces() const;

    void setInterfaces(const std::vector<uint16> &interfaces);
};


#endif //JUSTVM_CLASS_FILE_H
