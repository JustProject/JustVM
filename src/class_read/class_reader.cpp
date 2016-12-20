//
// Created by 刘丰恺 on 2016/12/20.
//

#include "class_reader.h"


uint8 bytes_reader::read_Uint8() {
    byte u1 = data[currentPoint++];
    return u1;
}

void bytes_reader::set_ready_to_read_constant_pool(bool flag) {
    this->ready_to_read_constant_pool_item = flag;
}

const bool bytes_reader::get_ready_to_read_constant_pool() {
    return ready_to_read_constant_pool_item;
}

bytes_reader::bytes_reader(const std::vector<byte> &data) : data(data) {}

void bytes_reader::read_bytes_by_len(Point<byte> byte_point, int len) {
    for (int i = 0; i < len; ++i) {
        byte_point[i] = data[currentPoint + i];
    }

    currentPoint += len;
}