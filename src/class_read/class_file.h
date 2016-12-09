//
// Created by 刘丰恺 on 2016/12/2.
// Yoto at Fri., Dec. 2nd, 2016, 23:21
//

#ifndef JUSTVM_CLASS_FILE_H
#define JUSTVM_CLASS_FILE_H


#include "access_flag/af.h"
#include "../utils/util.h"
#include "constant_pool/cp_info.h"


class class_file {
protected:
    uint32 magic;
    uint16 minorVersion;
    uint16 majorVersion;
    uint16 constantPoolCount;
    std::vector<cp_item> constantPool;
    af_item accessFlags;
    uint16 thisClass;
    uint16 superClass;

    std::vector<uint16> interfaces;

    // fields & methods
public:

    void insert_item_to_cp(cp_item *item);

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

    inline af_item getAccessFlags() const {
        return accessFlags;
    }

    inline void setAccessFlags(const af_item accessFlags) {
        this->accessFlags = accessFlags;
    }

    inline uint16 getThisClass() const {
        return thisClass;
    }

    inline void setThisClass(const uint16 thisClass) {
        this->thisClass = thisClass;
    }

    inline uint16 getSuperClass() const {
        return superClass;
    }

    inline void setSuperClass(const uint16 superClass) {
        this->superClass = superClass;
    }

    inline const std::vector<uint16> &getInterfaces() const {
        return interfaces;
    }

    inline void setInterfaces(const std::vector<uint16> &interfaces) {
        this->interfaces = interfaces;
    }

    const std::vector<cp_item> &getConstantPool() const {
        return constantPool;
    }

    void setConstantPool(const std::vector<cp_item> &constantPool) {
        this->constantPool = constantPool;
    }
};


#endif //JUSTVM_CLASS_FILE_H
