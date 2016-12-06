//
// Created by 刘丰恺 on 2016/12/2.
//

#ifndef JUSTVM_CONSTANTINFO_H
#define JUSTVM_CONSTANTINFO_H

#include "util.h"
#include "../class_reader.h"


/** \brief Constant Pool Tag
 *
 * This enum possess the tag of cp_info.
 * WARNING: This class is immutable.
 *
 * FYI, JVM Specs "4.4 The Constant Pool"
 */
enum cp_tag : BC_U1 {
    CONSTANT_Class = 7,
    CONSTANT_Fieldref = 9,
    CONSTANT_Methodref = 10,
    CONSTANT_InterfaceMethodref = 11,
    CONSTANT_String = 8,
    CONSTANT_Integer = 3,
    CONSTANT_Float = 4,
    CONSTANT_Long = 5,
    CONSTANT_Double = 6,
    CONSTANT_NameAndType = 12,
    CONSTANT_Utf8 = 1,
    CONSTANT_MethodHandle = 15,
    CONSTANT_MethodType = 16,
    CONSTANT_InvokeDynamic = 18
};

struct CONSTANT_Meta {
    BC_U1 tag : BC_U1_SIZE;
    BC_U1 info[7];
};

struct CONSTANT_Class_info {
    BC_U1 tag : BC_U1_SIZE;
    BC_U2 name_index : BC_U2_SIZE;
};

struct CONSTANT_Fieldref_info {
    BC_U1 tag : BC_U1_SIZE;
    BC_U2 class_index : BC_U2_SIZE;
    BC_U2 name_and_type_index : BC_U2_SIZE;
};

struct CONSTANT_Methodref_info {
    BC_U1 tag : BC_U1_SIZE;
    BC_U2 class_index : BC_U2_SIZE;
    BC_U2 name_and_type_index : BC_U2_SIZE;
};

struct CONSTANT_InterfaceMethodref_info {
    BC_U1 tag : BC_U1_SIZE;
    BC_U2 class_index : BC_U2_SIZE;
    BC_U2 name_and_type_index : BC_U2_SIZE;
};

struct CONSTANT_String_info {
    BC_U1 tag : BC_U1_SIZE;
    BC_U2 string_index : BC_U2_SIZE;
};

struct CONSTANT_Integer_info {
    BC_U1 tag : BC_U1_SIZE;
    BC_U4 bytes : BC_U4_SIZE;
};

struct CONSTANT_Float_info {
    BC_U1 tag : BC_U1_SIZE;
    BC_U4 bytes : BC_U4_SIZE;
};

struct CONSTANT_Long_info {
    BC_U1 tag : BC_U1_SIZE;
    BC_U4 high_bytes : BC_U4_SIZE;
    BC_U4 low_bytes : BC_U4_SIZE;
};

struct CONSTANT_Double_info {
    BC_U1 tag : BC_U1_SIZE;
    BC_U4 high_bytes : BC_U4_SIZE;
    BC_U4 low_bytes : BC_U4_SIZE;
};

struct CONSTANT_NameAndType_info {
    BC_U1 tag : BC_U1_SIZE;
    BC_U2 name_index : BC_U2_SIZE;
    BC_U2 descriptor_index : BC_U2_SIZE;
};

/** \brief Utf8 string constant item.
 *         THIS IS A SPECIAL CASE AND REQUIRE SPECIAL TREATMENT.
 *
 * There's one tiny change between the implement and the specs: bytes is a pointer that pointed to the content,
 * because of the length-immutability of struct and union.
 *
 * FYI, JVM Specs "4.4.7 The CONSTANT_Utf8_info Structure"
 */
struct CONSTANT_Utf8_info {
    BC_U1 tag : BC_U1_SIZE;
    BC_U2 length : BC_U2_SIZE;
    BC_U1 *bytes; // FIXME Maybe you'd like to change the type of the pointer
};

struct CONSTANT_MethodHandle_info {
    BC_U1 tag : BC_U1_SIZE;
    BC_U1 reference_kind : BC_U1_SIZE;
    BC_U2 reference_index : BC_U2_SIZE;
};

struct CONSTANT_MethodType_info {
    BC_U1 tag : BC_U1_SIZE;
    BC_U2 descriptor_index : BC_U2_SIZE;
};

struct CONSTANT_InvokeDynamic_info {
    BC_U1 tag : BC_U1_SIZE;
    BC_U2 boostrap_method_attr_index : BC_U2_SIZE;
    BC_U2 name_and_type_index : BC_U2_SIZE;
};

/** \brief This possess a single item in the constant pool.
 *
 * By default, you write data into meta_info.info, except Utf8 info.
 */
union cp_item {
    CONSTANT_Meta meta_info;
    CONSTANT_Class_info class_info;
    CONSTANT_Fieldref_info fieldref_info;
    CONSTANT_Methodref_info methodref_info;
    CONSTANT_InterfaceMethodref_info interfaceMethodref_info;
    CONSTANT_String_info string_info;
    CONSTANT_Integer_info integer_info;
    CONSTANT_Float_info float_info;
    CONSTANT_Long_info long_info;
    CONSTANT_Double_info double_info;
    CONSTANT_NameAndType_info nameAndType_info;
    CONSTANT_Utf8_info utf8_info;
    CONSTANT_MethodHandle_info methodHandle_info;
    CONSTANT_MethodType_info methodType_info;
    CONSTANT_InvokeDynamic_info invokeDynamic_info;
};

cp_item *read_cp_item_from_bytes(bytes_reader, BC_U2);


#endif //JUSTVM_CONSTANTINFO_H
