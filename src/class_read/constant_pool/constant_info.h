//
// Created by 刘丰恺 on 2016/12/2.
//

#ifndef JUSTVM_CONSTANTINFO_H
#define JUSTVM_CONSTANTINFO_H

#include "util.h"

class ConstantInfo {
public:
    /**
     * uint8 tag for constant-item in pool
     */
    const static uint8
            CONSTANT_UTF_8 = 1,
            CONSTANT_INTEGER = 3,
            CONSTANT_FLOAT = 4,
            CONSTANT_LONG = 5,
            CONSTANT_DOUBLE = 6,
            CONSTANT_CLASS = 7,
            CONSTANT_FIELD_REF = 9,
            CONSTANT_METHOD_REF = 10,
            CONSTANT_INTERFACE_METHOD_REF = 11,
            CONSTANT_NAME_AND_TYPE = 12,
            CONSTANT_METHOD_HANDLER = 15,
            CONSTANT_METHOD_TYPE = 16,
            CONSTANT_INVOKE_DYNAMIC = 18,
            CONSTANT_STRING = 8;


protected:
    uint8 tag;

    std::vector<uint8> info;
public:

    uint8 getTag() const;

    void setTag(uint8 tag);

    const std::vector<uint8> &getInfo() const;

    void setInfo(const std::vector<uint8> &info);
};


#endif //JUSTVM_CONSTANTINFO_H
