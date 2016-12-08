
#include "cp_info.h"

using std::cout;
using std::endl;


cp_item *read_cp_item_from_bytes(bytes_reader &reader, BC_U1 u16) {

    if (!reader.get_ready_to_read_constant_pool()) {
        throw std::logic_error("reader must be ready to read cp!");
    }

    auto name = ENUM_REFLECT(cp_tag, BC_U1)->
            from_value_to_string(u16);

    if (name == "") {
        throw std::logic_error("enum value must be in cp_tag!");
    } else {
        name += "_info";
    }

    auto item_struct = Reflect(CONSTANT_Base)[name]->create();

    item_struct->read_constant_info(reader);

    return (cp_item *) item_struct;
}

void read_cp_meta_info(CONSTANT_Meta_info &, bytes_reader &reader) {

}

void read_cp_class_info(CONSTANT_Class_info &, bytes_reader &reader) {

}

void read_cp_field_ref_info(CONSTANT_Fieldref_info &, bytes_reader &reader) {

}

void read_cp_method_ref_info(CONSTANT_Methodref_info &, bytes_reader &reader) {

}

void read_cp_interface_method_ref_info(CONSTANT_InterfaceMethodref_info &, bytes_reader &reader) {

}

void read_cp_string_info(CONSTANT_String_info &, bytes_reader &reader) {

}

void read_cp_integer_info(CONSTANT_Integer_info &, bytes_reader &reader) {

}

void read_cp_float_info(CONSTANT_Float_info &, bytes_reader &reader) {

}

void read_cp_long_info(CONSTANT_Long_info &, bytes_reader &reader) {

}

void read_cp_double_info(CONSTANT_Double_info &, bytes_reader &reader) {

}

void read_cp_name_type_info(CONSTANT_NameAndType_info &, bytes_reader &reader) {

}

void read_cp_utf8_info(CONSTANT_Utf8_info &, bytes_reader &reader) {

}

void read_cp_method_handle_info(CONSTANT_MethodHandle_info &, bytes_reader &reader) {

}

void read_cp_method_type_info(CONSTANT_MethodType_info &, bytes_reader &reader) {

}

void read_cp_invoke_dynamic_info(CONSTANT_InvokeDynamic_info &, bytes_reader &reader) {

}
