//
// Created by 刘丰恺 on 2016/11/20.
//

#ifndef JUSTVM_CLASS_READER_H
#define JUSTVM_CLASS_READER_H

#include <vector>
#include "../utils/util.h"
#include <cassert>
#include <boost/type_traits/is_same.hpp>

class bytes_reader {
public:

    bytes_reader(const std::vector<byte> &data);

    ~bytes_reader() {};

    template<typename returnType>
    returnType read_bytes_with_type();

    const bool get_ready_to_read_constant_pool();

    void read_bytes_by_len(Point<byte> byte_point, int len);

protected:
    const std::vector<byte> &data;

    bool ready_to_read_constant_pool_item = false;

    size_t currentPoint = 0;

private:
    uint8 read_Uint8();

    void set_ready_to_read_constant_pool(bool flag);
};

template<typename returnType>
returnType bytes_reader::read_bytes_with_type() {

    static_assert(boost::is_same<returnType, uint16>::value ||
                  boost::is_same<returnType, uint8>::value ||
                  boost::is_same<returnType, uint32>::value ||
                  boost::is_same<returnType, uint64>::value,
                  "you should use uint 8/16/32/64 !!!");

    if (boost::is_same<returnType, uint8>::value) {
        return read_Uint8();
    } else if (boost::is_same<returnType, uint16>::value) {
        byte u1 = read_Uint8();
        byte u2 = read_Uint8();

        uint16 u16 = u1 << 8 | u2;

        // after read (1 * uint32 + 3 * uint16)
        // ready to read constant pool
        if (currentPoint == 10) {
            this->set_ready_to_read_constant_pool(true);
        }

        return u16;
    } else if (boost::is_same<returnType, uint32>::value) {

        byte u1 = read_Uint8();
        byte u2 = read_Uint8();
        byte u3 = read_Uint8();
        byte u4 = read_Uint8();
        uint32 u32 = u1 << 24 | u2 << 16 | u3 << 8 | u4;
        return u32;
    } else if (boost::is_same<returnType, uint64>::value) {
        byte u1 = read_Uint8();
        byte u2 = read_Uint8();
        byte u3 = read_Uint8();
        byte u4 = read_Uint8();

        byte u5 = read_Uint8();
        byte u6 = read_Uint8();
        byte u7 = read_Uint8();
        byte u8 = read_Uint8();

        uint32 ul = u1 << 24 | u2 << 16 | u3 << 8 | u4;
        uint32 ur = u5 << 24 | u6 << 16 | u7 << 8 | u8;

        uint64 u64 = (unsigned long) ul << 32 | ur;

        return u64;
    }
    return 0;
}

//template<>
//uint8 bytes_reader::read_bytes_with_type<uint8>() {
//    return read_Uint8();
//}
//
//template<>
//uint16 bytes_reader::read_bytes_with_type<uint16>() {
//    byte u1 = read_Uint8();
//    byte u2 = read_Uint8();
//
//    uint16 u16 = u1 << 8 | u2;
//
//    // after read (1 * uint32 + 3 * uint16)
//    // ready to read constant pool
//    if (currentPoint == 10) {
//        this->set_ready_to_read_constant_pool(true);
//    }
//
//    return u16;
//}
//
//template<>
//uint32 bytes_reader::read_bytes_with_type<uint32>() {
//    byte u1 = read_Uint8();
//    byte u2 = read_Uint8();
//    byte u3 = read_Uint8();
//    byte u4 = read_Uint8();
//    uint32 u32 = u1 << 24 | u2 << 16 | u3 << 8 | u4;
//    return u32;
//}



#endif //JUSTVM_CLASS_READER_H
