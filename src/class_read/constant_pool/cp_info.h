//
// Created by 刘丰恺 on 2016/12/2.
//

#ifndef JUSTVM_CONSTANTINFO_H
#define JUSTVM_CONSTANTINFO_H

#include "../class_reader.h"
#include "util.h"
#include "dynamic_enum.h"
#include "dynamic_class.h"

/** \brief Constant Pool Tag
 *
 * This enum possess the tag of cp_info.
 * WARNING: This class is immutable.
 *
 * FYI, JVM Specs "4.4 The Constant Pool"
 */
ENUM_CLASS(cp_tag, BC_U1,
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
);


///////////////////////////////////////////////////////////////////////////
// constant base
///////////////////////////////////////////////////////////////////////////

class CONSTANT_Base {
public:
    BC_U1 tag : BC_U1_SIZE;

    CONSTANT_Base() {}

    inline virtual void read_constant_info(bytes_reader &reader) = 0;
};

///////////////////////////////////////////////////////////////////////////
// constant meta infp
///////////////////////////////////////////////////////////////////////////

re_class(CONSTANT_Meta_info, CONSTANT_Base) {
public:
    BC_U1 info[7];

    inline void read_constant_info(bytes_reader &reader) override;
};

inline void CONSTANT_Meta_info::read_constant_info(bytes_reader &reader) {

}

///////////////////////////////////////////////////////////////////////////
// constant class info
///////////////////////////////////////////////////////////////////////////

re_class(CONSTANT_Class_info, CONSTANT_Base) {
public:
    BC_U2 name_index : BC_U2_SIZE;

    inline void read_constant_info(bytes_reader &reader) override;
};

inline void CONSTANT_Class_info::read_constant_info(bytes_reader &reader) {
    printf("class info");
}

///////////////////////////////////////////////////////////////////////////
// constant class file ref info
///////////////////////////////////////////////////////////////////////////

re_class(CONSTANT_Fieldref_info, CONSTANT_Base) {
public:
    BC_U2 class_index : BC_U2_SIZE;
    BC_U2 name_and_type_index : BC_U2_SIZE;

    inline void read_constant_info(bytes_reader &reader) override;
};

inline void CONSTANT_Fieldref_info::read_constant_info(bytes_reader &reader) {

}

///////////////////////////////////////////////////////////////////////////
// constant method ref info
///////////////////////////////////////////////////////////////////////////

re_class(CONSTANT_Methodref_info, CONSTANT_Base) {
public:
    BC_U2 class_index : BC_U2_SIZE;
    BC_U2 name_and_type_index : BC_U2_SIZE;

    inline void read_constant_info(bytes_reader &reader) override;
};

inline void CONSTANT_Methodref_info::read_constant_info(bytes_reader &reader) {

}

///////////////////////////////////////////////////////////////////////////
// constant interface method-ref info
///////////////////////////////////////////////////////////////////////////

re_class(CONSTANT_InterfaceMethodref_info, CONSTANT_Base) {
public:
    BC_U2 class_index : BC_U2_SIZE;
    BC_U2 name_and_type_index : BC_U2_SIZE;

    inline void read_constant_info(bytes_reader &reader) override;
};

inline void CONSTANT_InterfaceMethodref_info::read_constant_info(bytes_reader &reader) {

}

///////////////////////////////////////////////////////////////////////////
// constant string info
///////////////////////////////////////////////////////////////////////////

re_class(CONSTANT_String_info, CONSTANT_Base) {
public:
    BC_U2 string_index : BC_U2_SIZE;

    inline void read_constant_info(bytes_reader &reader) override;
};

inline void CONSTANT_String_info::read_constant_info(bytes_reader &reader) {

}

///////////////////////////////////////////////////////////////////////////
// constant integer info
///////////////////////////////////////////////////////////////////////////

re_class(CONSTANT_Integer_info, CONSTANT_Base) {
public:
    BC_U4 bytes : BC_U4_SIZE;

    inline void read_constant_info(bytes_reader &reader) override;
};

inline void CONSTANT_Integer_info::read_constant_info(bytes_reader &reader) {

}

///////////////////////////////////////////////////////////////////////////
// constant float info
///////////////////////////////////////////////////////////////////////////

re_class(CONSTANT_Float_info, CONSTANT_Base) {
public:
    BC_U4 bytes : BC_U4_SIZE;

    inline void read_constant_info(bytes_reader &reader) override;
};

inline void CONSTANT_Float_info::read_constant_info(bytes_reader &reader) {

}

///////////////////////////////////////////////////////////////////////////
// constant long info
///////////////////////////////////////////////////////////////////////////

re_class(CONSTANT_Long_info, CONSTANT_Base) {
public:
    BC_U4 high_bytes : BC_U4_SIZE;
    BC_U4 low_bytes : BC_U4_SIZE;

    inline void read_constant_info(bytes_reader &reader) override;
};

inline void CONSTANT_Long_info::read_constant_info(bytes_reader &reader) {

}

///////////////////////////////////////////////////////////////////////////
// constant double info
///////////////////////////////////////////////////////////////////////////

re_class(CONSTANT_Double_info, CONSTANT_Base) {
public:
    BC_U4 high_bytes : BC_U4_SIZE;
    BC_U4 low_bytes : BC_U4_SIZE;

    inline void read_constant_info(bytes_reader &reader) override;
};

inline void CONSTANT_Double_info::read_constant_info(bytes_reader &reader) {

}

///////////////////////////////////////////////////////////////////////////
// constant name and type
///////////////////////////////////////////////////////////////////////////

re_class(CONSTANT_NameAndType_info, CONSTANT_Base) {
public:
    BC_U2 name_index : BC_U2_SIZE;
    BC_U2 descriptor_index : BC_U2_SIZE;

    inline void read_constant_info(bytes_reader &reader) override;
};

inline void CONSTANT_NameAndType_info::read_constant_info(bytes_reader &reader) {

}

/** \brief Utf8 string constant item.
 *         THIS IS A SPECIAL CASE AND REQUIRE SPECIAL TREATMENT.
 *
 * There's one tiny change between the implement and the specs: bytes is a pointer that pointed to the content,
 * because of the length-immutability of re_class(and union.
 *
 * FYI, JVM Specs "4.4.7 The CONSTANT_Utf8_info Structure"
 */
re_class(CONSTANT_Utf8_info, CONSTANT_Base) {
    BC_U2 length : BC_U2_SIZE;
    BC_U1 *bytes; // FIXME Maybe you'd like to change the type of the pointer

    inline void read_constant_info(bytes_reader &reader) override;
};

inline void CONSTANT_Utf8_info::read_constant_info(bytes_reader &reader) {

}

///////////////////////////////////////////////////////////////////////////
// constant method handle info
///////////////////////////////////////////////////////////////////////////

re_class(CONSTANT_MethodHandle_info, CONSTANT_Base) {
public:
    BC_U1 reference_kind : BC_U1_SIZE;
    BC_U2 reference_index : BC_U2_SIZE;

    inline void read_constant_info(bytes_reader &reader) override;
};

inline void CONSTANT_MethodHandle_info::read_constant_info(bytes_reader &reader) {

}

///////////////////////////////////////////////////////////////////////////
// constant method type info
///////////////////////////////////////////////////////////////////////////

re_class(CONSTANT_MethodType_info, CONSTANT_Base) {
public:
    BC_U1 tag : BC_U1_SIZE;
    BC_U2 descriptor_index : BC_U2_SIZE;

    inline void read_constant_info(bytes_reader &reader) override;
};

inline void CONSTANT_MethodType_info::read_constant_info(bytes_reader &reader) {

}

re_class(CONSTANT_InvokeDynamic_info, CONSTANT_Base) {
public:
    BC_U2 boostrap_method_attr_index : BC_U2_SIZE;
    BC_U2 name_and_type_index : BC_U2_SIZE;

    inline void read_constant_info(bytes_reader &reader) override;
};

inline void CONSTANT_InvokeDynamic_info::read_constant_info(bytes_reader &reader) {

}

/** \brief This possess a single item in the constant pool.
 *
 * By default, you write data into meta_info.info, except Utf8 info.
 */
union cp_item {
    CONSTANT_Meta_info meta_info;
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

    cp_item() {};
};

/**
 * Use this method to get constant-pool item from bytes
 * you should use it after get the count of constant-pool
 * @param reader bytes_reader
 * @param u16 flag
 * @return cp-item
 */
cp_item *read_cp_item_from_bytes(bytes_reader &reader, BC_U1 u32);

void read_cp_meta_info(CONSTANT_Meta_info &, bytes_reader &reader);

void read_cp_class_info(CONSTANT_Class_info &, bytes_reader &reader);

void read_cp_field_ref_info(CONSTANT_Fieldref_info &, bytes_reader &reader);

void read_cp_method_ref_info(CONSTANT_Methodref_info &, bytes_reader &reader);

void read_cp_interface_method_ref_info(CONSTANT_InterfaceMethodref_info &, bytes_reader &reader);

void read_cp_string_info(CONSTANT_String_info &, bytes_reader &reader);

void read_cp_integer_info(CONSTANT_Integer_info &, bytes_reader &reader);

void read_cp_float_info(CONSTANT_Float_info &, bytes_reader &reader);

void read_cp_long_info(CONSTANT_Long_info &, bytes_reader &reader);

void read_cp_double_info(CONSTANT_Double_info &, bytes_reader &reader);

void read_cp_name_type_info(CONSTANT_NameAndType_info &, bytes_reader &reader);

void read_cp_utf8_info(CONSTANT_Utf8_info &, bytes_reader &reader);

void read_cp_method_handle_info(CONSTANT_MethodHandle_info &, bytes_reader &reader);

void read_cp_method_type_info(CONSTANT_MethodType_info &, bytes_reader &reader);

void read_cp_invoke_dynamic_info(CONSTANT_InvokeDynamic_info &, bytes_reader &reader);


#endif //JUSTVM_CONSTANTINFO_H
