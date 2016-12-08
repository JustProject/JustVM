//
// Created by 刘丰恺 on 2016/12/7.
//
#include "cp_info.h"
#include <iostream>

using std::cout;
using std::endl;

/**
 * test enum reflect
 * @return
 */
int main0() {
    ENUM_REFLECT(cp_tag, BC_U1)->from_value(11);

    cout << ENUM_REFLECT(cp_tag, BC_U1)->to_string(cp_tag::CONSTANT_InvokeDynamic) << endl;

    auto reflect = ENUM_REFLECT(cp_tag, BC_U1);

    std::string name = reflect->from_value_to_string(11);

    auto tag_struct = reflect->from_value(11);

    cp_item *item = (cp_item *) (&tag_struct);

    return 0;
}

/**
 * test class reflect
 * @return
 */
int main1() {
    Reflect(CONSTANT_Base)[ENUM_REFLECT(cp_tag, BC_U1)->
            from_value_to_string(11)]->create();

}