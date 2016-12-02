//
// Created by 刘丰恺 on 2016/12/2.
//

#include "constant_info.h"

uint8 ConstantInfo::getTag() const {
    return tag;
}

void ConstantInfo::setTag(uint8 tag) {
    ConstantInfo::tag = tag;
}

const std::vector<uint8> &ConstantInfo::getInfo() const {
    return info;
}

void ConstantInfo::setInfo(const std::vector<uint8> &info) {
    ConstantInfo::info = info;
}
