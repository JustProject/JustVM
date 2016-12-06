//
// Created by 刘丰恺 on 2016/11/20.
//

#ifndef JUSTVM_CLASS_READER_H
#define JUSTVM_CLASS_READER_H

#include <vector>
#include "../utils/util.h"
#include <cassert>
#include <boost/type_traits/is_same.hpp>

class ClassReader {
public:

    ClassReader(const std::vector<byte> &data);

    ~ClassReader() {};

    template<typename returnType>
    returnType readType();

protected:
    const std::vector<byte> &data;

    size_t currentPoint = 0;

private:
    uint8 readUint8();
};

template<typename returnType>
returnType ClassReader::readType() {

    static_assert(boost::is_same<returnType, uint16>::value ||
                  boost::is_same<returnType, uint8>::value ||
                  boost::is_same<returnType, uint32>::value ||
                  boost::is_same<returnType, uint64>::value,
                  "you should use uint 8/16/32/64 !!!");

    if (boost::is_same<returnType, uint8>::value) {
        return readUint8();
    } else if (boost::is_same<returnType, uint16>::value) {
        byte u1 = readUint8();
        byte u2 = readUint8();

        uint16 u16 = u1 << 8 | u2;
        return u16;
    } else if (boost::is_same<returnType, uint32>::value) {

        byte u1 = readUint8();
        byte u2 = readUint8();
        byte u3 = readUint8();
        byte u4 = readUint8();
        uint32 u32 = u1 << 24 | u2 << 16 | u3 << 8 | u4;
        return u32;
    } else if (boost::is_same<returnType, uint64>::value) {
        byte u1 = readUint8();
        byte u2 = readUint8();
        byte u3 = readUint8();
        byte u4 = readUint8();

        byte u5 = readUint8();
        byte u6 = readUint8();
        byte u7 = readUint8();
        byte u8 = readUint8();

        uint32 ul = u1 << 24 | u2 << 16 | u3 << 8 | u4;
        uint32 ur = u5 << 24 | u6 << 16 | u7 << 8 | u8;

        uint64 u64 = (unsigned long) ul << 32 | ur;

        return u64;
    }
    return 0;
}

uint8 ClassReader::readUint8() {
    byte u1 = data[currentPoint++];
    return u1;
}

ClassReader::ClassReader(const std::vector<byte> &data) : data(data) {}

#endif //JUSTVM_CLASS_READER_H
