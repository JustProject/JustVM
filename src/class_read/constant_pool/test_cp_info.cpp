//
// Created by 刘丰恺 on 2016/12/7.
//
#include "cp_info.h"
#include <iostream>
using std::cout;
using std::endl;


int main() {
    ENUM_REFLECT(cp_tag, BC_U1)->fromValue(11);
    cout << ENUM_REFLECT(cp_tag, BC_U1)->toString(cp_tag::CONSTANT_InvokeDynamic) << endl;
    return 0;
}