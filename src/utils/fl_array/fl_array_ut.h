//
// Created by zhangyutong926 on 12/2/16.
//

#ifndef JUSTVM_FL_ARRAY_U_H
#define JUSTVM_FL_ARRAY_U_H


#include <cstdint>

#define FL_ARRAY_UT_P(NAME, TYPE, CONTENT) \
    TYPE NAME__LINE__[] = CONTENT; \
    fl_array_ut NAME() \

// WARNING: All value will be store as a pointer so you may want to keep your eye on it and make sure it is validated.
template<typename T>
class fl_array_ut {
public:
    fl_array_ut(uint32_t length = 0);
    fl_array_ut(T *source, );

private:
    uint32_t length;
    T **content;
};

//TODO


#endif //JUSTVM_FL_ARRAY_U_H
