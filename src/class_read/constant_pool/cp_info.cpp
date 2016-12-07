
#include "cp_info.h"

cp_item *read_cp_item_from_bytes(bytes_reader &reader, BC_U1 u32) {

    if (!reader.get_ready_to_read_constant_pool()) {
        throw std::logic_error("reader must be ready to read cp");
    }


}
