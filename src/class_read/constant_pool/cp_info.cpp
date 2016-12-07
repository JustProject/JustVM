#include "cp_info.h"

cp_item *read_cp_item_from_bytes(bytes_reader &reader, BC_U2 u32) {
    static_assert(reader.get_ready_to_read_constant_pool(),
                  "bytes_reader should be ready to read constant item");

}
