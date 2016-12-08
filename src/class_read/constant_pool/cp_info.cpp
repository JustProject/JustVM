
#include "cp_info.h"

using std::cout;
using std::endl;


cp_item *read_cp_item_from_bytes(bytes_reader &reader, BC_U1 u16) {

    if (!reader.get_ready_to_read_constant_pool()) {
        throw std::logic_error("reader must be ready to read cp!");
    }

    auto name = ENUM_REFLECT(cp_tag, BC_U1)->
            from_value_to_string(u16);

    if (name == nullptr) {
        throw std::logic_error("enum value must be in cp_tag!");
    } else {
        name += "_info";
    }

    auto item_struct = Reflect(CONSTANT_Base)[name]->create();

    item_struct->read_constant_info(reader);

    return (cp_item *) item_struct;
}