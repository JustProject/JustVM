//
// Created by zhangyutong926 on 12/5/16.
//

#include <map>
#include <stdexcept>
#include "af.h"

#define INVALID_EXPT_CONSTRUCT_ACSTATUS throw new std::invalid_argument("Invalid flags for ACStatus construction.");

using namespace just::util::fl_array;

af_item::af_item(fl_array_ut<af_tag> &flags) {
    // FIXME Data-specified implementation
    // The following code is for the purpose of runtime acceleration
    std::map<BC_U2, bool> flag_ext;
    for (af_tag &item : flags) {
        flag_ext[item] = true;
    }

    // JVM Specs "4.1 The ClassFile Structure"
    if (flag_ext.count(af_tag::ACC_INTERFACE) && (
            !flag_ext.count(af_tag::ACC_ABSTRACT) ||
            flag_ext.count(af_tag::ACC_FINAL) ||
            flag_ext.count(af_tag::ACC_SUPER) ||
            flag_ext.count(af_tag::ACC_ENUM))) {INVALID_EXPT_CONSTRUCT_ACSTATUS;}

    // TODO Rest tag Yoto
}

af_item::af_item(BC_U2 modifier) {
    // TODO Construct from a modifier
}

BC_U2 af_item::getModifier() {
    // TODO Calculate the modifier
    return 0;
}

/** \brief Get specific digit from a bytes
 *
 * @tparam T Target bytes type
 * @tparam _base Number base, such as 10, 010, 0x10, etc.
 * @tparam _digit For 0x1234, 0 -> 4; 1 -> 3; 2 -> 2; 4 -> 1
 * @param src The number you want to parse
 * @return the digit you want
 */
template<typename T, int _base, int _digit>
static inline BYTE get_hexdigit_from_bytes(const T src) {
    for (int i = 0; i < _digit; i++) {
        src /= _base;
    }
    return src % _base;
}
