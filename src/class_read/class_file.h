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
    inline uint32 getMagic() const {
        return magic;
    }

    inline void setMagic(const uint32 magic) {
        this->magic = magic;
    }

    inline uint16 getMinorVersion() const {
        return minorVersion;
    }

    inline void setMinorVersion(const uint16 minorVersion) {
        this->minorVersion = minorVersion;
    }

    inline uint16 getMajorVersion() const {
        return majorVersion;
    }

    inline void setMajorVersion(const uint16 majorVersion) {
        this->majorVersion = majorVersion;
    }

    inline uint16 getConstantPoolCount() const {
        return constantPoolCount;
    }

    inline void setConstantPoolCount(const uint16 constantPoolCount) {
        this->constantPoolCount = constantPoolCount;
    }

    inline uint16 getAccessFlags() const;

    inline void setAccessFlags(const uint16 accessFlags);

    inline uint16 getThisClass() const;

    inline void setThisClass(const uint16 thisClass);

    inline uint16 getSuperClass() const;

    inline void setSuperClass(const uint16 superClass);

    inline const std::vector<uint16> &getInterfaces() const;

    inline void setInterfaces(const std::vector<uint16> &interfaces);
};


#endif //JUSTVM_CLASS_FILE_H
