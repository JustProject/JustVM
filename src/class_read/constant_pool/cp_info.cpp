
#include "cp_info.h"

using std::cout;
using std::endl;

/**
 * reader cp item from bytes
 * @param reader bytes_reader
 * @param u16 item_tag
 * @return cp pointer
 */
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

    cp_item *item = (cp_item *) item_struct;

    return item;
}

void read_cp_meta_info(CONSTANT_Meta_info &info, bytes_reader &reader) {
    // TODO : MAYBE WE DON'T NEED IT ANYMORE.=-=
}


/**
 * read class info
 * @param info class info &
 * @param reader bytes_readers
 */
void read_cp_class_info(CONSTANT_Class_info &info, bytes_reader &reader) {
    info.tag = static_cast<BC_U1>(cp_tag::CONSTANT_Class);
    info.name_index = reader.read_bytes_with_type<uint16>();
}

/**
 * read field info
 * @param info &
 * @param reader bytes_readers
 */
void read_cp_field_ref_info(CONSTANT_Fieldref_info &info, bytes_reader &reader) {
    info.tag = static_cast<BC_U1>(cp_tag::CONSTANT_Fieldref);
    info.class_index = reader.read_bytes_with_type<uint16>();
    info.name_and_type_index = reader.read_bytes_with_type<uint16>();
}

/**
 * read method ref info
 * @param info &
 * @param reader bytes_readers
 */
void read_cp_method_ref_info(CONSTANT_Methodref_info &info, bytes_reader &reader) {
    info.tag = static_cast<BC_U1>(cp_tag::CONSTANT_Methodref);
    info.class_index = reader.read_bytes_with_type<uint16>();
    info.name_and_type_index = reader.read_bytes_with_type<uint16>();
}

/**
 * read interface method ref info
 * @param info  &
 * @param reader bytes_readers
 */
void read_cp_interface_method_ref_info(CONSTANT_InterfaceMethodref_info &info, bytes_reader &reader) {
    info.tag = static_cast<BC_U1>(cp_tag::CONSTANT_InterfaceMethodref);
    info.class_index = reader.read_bytes_with_type<uint16>();
    info.name_and_type_index = reader.read_bytes_with_type<uint16>();
}

/**
 * read string info
 * @param info  &
 * @param reader bytes_readers
 */
void read_cp_string_info(CONSTANT_String_info &info, bytes_reader &reader) {
    info.tag = static_cast<BC_U1>(cp_tag::CONSTANT_String);
    info.string_index = reader.read_bytes_with_type<uint16>();
}

/**
 * read integer info
 * @param info  &
 * @param reader bytes_readers
 */
void read_cp_integer_info(CONSTANT_Integer_info &info, bytes_reader &reader) {
    info.tag = static_cast<BC_U1>(cp_tag::CONSTANT_Integer);
    info.bytes = reader.read_bytes_with_type<uint32>();
}

/**
 * read float info
 * @param info  &
 * @param reader bytes_readers
 */
void read_cp_float_info(CONSTANT_Float_info &info, bytes_reader &reader) {
    info.tag = static_cast<BC_U1>(cp_tag::CONSTANT_Float);
    info.bytes = reader.read_bytes_with_type<uint32>();
}

/**
 * read long info
 * @param info  &
 * @param reader bytes_readers
 */
void read_cp_long_info(CONSTANT_Long_info &info, bytes_reader &reader) {
    info.tag = static_cast<BC_U1>(cp_tag::CONSTANT_Long);
    info.high_bytes = reader.read_bytes_with_type<uint32>();
    info.low_bytes = reader.read_bytes_with_type<uint32>();
}

/**
 * read double info
 * @param info  &
 * @param reader bytes_readers
 */
void read_cp_double_info(CONSTANT_Double_info &info, bytes_reader &reader) {
    info.tag = static_cast<BC_U1>(cp_tag::CONSTANT_Double);
    info.high_bytes = reader.read_bytes_with_type<uint32>();
    info.low_bytes = reader.read_bytes_with_type<uint32>();
}

/**
 * read name & type info
 * @param info  &
 * @param reader bytes_readers
 */
void read_cp_name_type_info(CONSTANT_NameAndType_info &info, bytes_reader &reader) {
    info.tag = static_cast<BC_U1>(cp_tag::CONSTANT_NameAndType);
    info.name_index = reader.read_bytes_with_type<uint16>();
    info.descriptor_index = reader.read_bytes_with_type<uint16>();
}

/**
 * read mutf-8 info
 * @param info  & // TODO MAYBE CONVERT MUTF-8 TO UTF8 LATER
 * @param reader bytes_readers
 */
void read_cp_utf8_info(CONSTANT_Utf8_info &info, bytes_reader &reader) {
    info.tag = static_cast<BC_U1>(cp_tag::CONSTANT_Utf8);
    info.length = static_cast<BC_U4>(reader.read_bytes_with_type<uint16>());
    info.bytes = new byte[info.length];

    reader.read_bytes_by_len(info.bytes, info.length);
}

/**
 * read method handle info
 * @param info  &
 * @param reader bytes_readers
 */
void read_cp_method_handle_info(CONSTANT_MethodHandle_info &info, bytes_reader &reader) {
    info.tag = static_cast<BC_U1>(cp_tag::CONSTANT_MethodHandle);
    info.reference_kind = reader.read_bytes_with_type<uint8>();
    info.reference_index = reader.read_bytes_with_type<uint16>();
}

/**
 * read method & type info
 * @param info  &
 * @param reader bytes_readers
 */
void read_cp_method_type_info(CONSTANT_MethodType_info &info, bytes_reader &reader) {
    info.tag = static_cast<BC_U1>(cp_tag::CONSTANT_MethodType);
    info.descriptor_index = reader.read_bytes_with_type<uint16>();
}

/**
 * read invoke dynamic info
 * @param info  &
 * @param reader bytes_readers
 */
void read_cp_invoke_dynamic_info(CONSTANT_InvokeDynamic_info &info, bytes_reader &reader) {
    info.tag = static_cast<BC_U1>(cp_tag::CONSTANT_InvokeDynamic);
    info.name_and_type_index = reader.read_bytes_with_type<uint16>();
    info.boostrap_method_attr_index = reader.read_bytes_with_type<uint16>();
}
