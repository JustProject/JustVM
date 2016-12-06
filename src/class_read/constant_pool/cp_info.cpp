//
// Created by 刘丰恺 on 2016/12/2.
//

#include "cp_info.h"

/**
 * Length and memory-layout groups:
 *
 * 1 2    3
 * CONSTANT_Class_info
 * CONSTANT_String_info
 * CONSTANT_MethodType_info (~)
 *
 * 1 2 2    5
 * CONSTANT_Fieldref_info
 * CONSTANT_Methodref_info
 * CONSTANT_InterfaceMethodref_info
 * CONSTANT_NameAndType_info (~)
 * CONSTANT_InvokeDynamic_info (~)
 * CONSTANT_InvokeDynamic_info (~)
 *
 * 1 4    5
 * CONSTANT_Integer_info
 * CONSTANT_Float_info
 *
 * 1 4 4    9
 * CONSTANT_Long_info
 * CONSTANT_Double_info
 *
 *
 * CONSTANT_Utf8_info
 *
 * 1 1 2    4
 * CONSTANT_MethodHandle_info
 */

cp_item *read_cp_item_from_bytes(bytes_reader src, BC_U2 cp_cnt) {
    cp_item *res = new cp_item[cp_cnt];
    for (int i = 0; i < cp_cnt; i++) {
        cp_tag tag_t = (cp_tag) src.readType<BC_U1>();
        if (tag_t != cp_tag::CONSTANT_Utf8) {
            switch (tag_t) {
                case CONSTANT_Class:
                    // TODO
                    break;
                case CONSTANT_Fieldref:
                    // TODO
                    break;
                case CONSTANT_Methodref:
                    // TODO
                    break;
                case CONSTANT_InterfaceMethodref:
                    // TODO
                    break;
                case CONSTANT_String:
                    // TODO
                    break;
                case CONSTANT_Integer:
                    // TODO
                    break;
                case CONSTANT_Float:
                    // TODO
                    break;
                case CONSTANT_Long:
                    // TODO
                    break;
                case CONSTANT_Double:
                    // TODO
                    break;
                case CONSTANT_NameAndType:
                    // TODO
                    break;
                case CONSTANT_MethodHandle:
                    // TODO
                    break;
                case CONSTANT_MethodType:
                    // TODO
                    break;
                case CONSTANT_InvokeDynamic:
                    // TODO
                    break;
                default:
                    throw(std::invalid_argument("read_cp_item_from_bytes malfunctioning")); // FIXME More serious error_msg required
            }
        } else {
            // TODO Special case for utf8 string
        }
    }
}
