//
// Created by 刘丰恺 on 2016/12/2.
//

#include "class_file.h"

uint32 ClassFile::getMagic() const {
    return magic;
}

void ClassFile::setMagic(uint32 magic) {
    ClassFile::magic = magic;
}

uint16 ClassFile::getMinorVersion() const {
    return minorVersion;
}

void ClassFile::setMinorVersion(uint16 minorVersion) {
    ClassFile::minorVersion = minorVersion;
}

uint16 ClassFile::getMajorVersion() const {
    return majorVersion;
}

void ClassFile::setMajorVersion(uint16 majorVersion) {
    ClassFile::majorVersion = majorVersion;
}

uint16 ClassFile::getConstantPoolCount() const {
    return constantPoolCount;
}

void ClassFile::setConstantPoolCount(uint16 constantPoolCount) {
    ClassFile::constantPoolCount = constantPoolCount;
}

uint16 ClassFile::getAccessFlags() const {
    return accessFlags;
}

void ClassFile::setAccessFlags(uint16 accessFlags) {
    ClassFile::accessFlags = accessFlags;
}

uint16 ClassFile::getThisClass() const {
    return thisClass;
}

void ClassFile::setThisClass(uint16 thisClass) {
    ClassFile::thisClass = thisClass;
}

uint16 ClassFile::getSuperClass() const {
    return superClass;
}

void ClassFile::setSuperClass(uint16 superClass) {
    ClassFile::superClass = superClass;
}

const std::vector<uint16> &ClassFile::getInterfaces() const {
    return interfaces;
}

void ClassFile::setInterfaces(const std::vector<uint16> &interfaces) {
    ClassFile::interfaces = interfaces;
}
