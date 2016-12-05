//
// Created by zhangyutong926 on 12/2/16.
//

#include <iostream>
#include "fl_array/fl_array_ut.hpp"

using namespace just::util::fl_array;

int main(int argc, char **argv) {
    FL_ARRAY_UT_P(arr, int, 5, {1, 2, 3, 4, 5});
    std::cout << arr[0] << " ";
    fl_array_ut<int> b(10);
    b[0] = 1;
    std::cout << b[0] << " ";
//    fl_array_ut<int> c = make_fl_array(10, 1);
//    std::cout << c[0];
}
