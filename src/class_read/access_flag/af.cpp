//
// Created by zhangyutong926 on 12/5/16.
//

#include <map>
#include <stdexcept>
#include "af.h"

#define INVALID_EXPT_CONSTRUCT_ACSTATUS \
{ \
    throw new std::invalid_argument("Invalid flags for ACStatus construction."); \
    return false; /*FIXME This should be useless*/ \
};

using namespace just::util::fl_array;

bool af_item::check_af_valid() {
    // Access Flag validating BEGIN
    // JVM Specs "4.1 The ClassFile Structure"
    if (flag_ext_map[af_tag::ACC_INTERFACE] && (
            !flag_ext_map[af_tag::ACC_ABSTRACT] ||
            flag_ext_map[af_tag::ACC_FINAL] ||
            flag_ext_map[af_tag::ACC_SUPER] ||
            flag_ext_map[af_tag::ACC_ENUM]))
        INVALID_EXPT_CONSTRUCT_ACSTATUS
    if (!flag_ext_map[af_tag::ACC_INTERFACE] &&
        flag_ext_map[af_tag::ACC_ANNOTATION])
        INVALID_EXPT_CONSTRUCT_ACSTATUS
    if (flag_ext_map[af_tag::ACC_FINAL] &&
        flag_ext_map[af_tag::ACC_ABSTRACT])
        INVALID_EXPT_CONSTRUCT_ACSTATUS
    if (flag_ext_map[af_tag::ACC_ANNOTATION] &&
        !flag_ext_map[af_tag::ACC_INTERFACE])
        INVALID_EXPT_CONSTRUCT_ACSTATUS
    std::map::size_type etype_mod_cnt = flag_ext_map.count(af_tag::ACC_ENUM) +
                        flag_ext_map.count(af_tag::ACC_ANNOTATION) +
                        flag_ext_map.count(af_tag::ACC_INTERFACE);
    if (etype_mod_cnt > 1)
        INVALID_EXPT_CONSTRUCT_ACSTATUS
    // Access Flag validating END
    return true;
}

af_item::af_item(): flag_ext_map({
                                         {ACC_PUBLIC, true},
                                         {ACC_FINAL, false},
                                         {ACC_SUPER, true},
                                         {ACC_SUPER, true},
                                         {ACC_INTERFACE, false},
                                         {ACC_ABSTRACT, false},
                                         {ACC_SYNTHETIC, false},
                                         {ACC_ANNOTATION, false},
                                         {ACC_ENUM, false}
                                 }), modifier(0x0021) {}

void af_item::calc_modifier() {
    modifier = 0;
    // std::pair<af_tag, bool> & origin
    for (auto item : flag_ext_map) {
        if (item.second) {
            modifier += item.first;
        }
    }
}

// FIXME Data-specified implementation
af_item::af_item(fl_array_ut<af_tag> &flags) {
    // The following code is for the purpose of runtime acceleration
    for (af_tag &item : flags) {
        flag_ext_map[item] = true;
    }

    check_af_valid();
    calc_modifier();
}

/** \brief Get specific digit from a bytes
 *
 * @tparam T Target bytes type
 * @tparam _base Number base, such as 10, 010, 0x10, etc.
 * @tparam _digit For 0x1234, 0 -> 4; 1 -> 3; 2 -> 2; 4 -> 1
 * @param src The number you want to parse
 * @return the digit you want
 */
// XXX C++ Template MetaProgramming Warning!
template<typename T, int _base, int _digit>
static inline BYTE get_hexdigit_from_bytes(const T src) {
    for (int i = 0; i < _digit; i++) {
        src /= _base;
    }
    return src % _base;
}

#define DEF_DIG_ARG_U2HEX(MOD, DIG) \
    BYTE digit_##DIG = get_hexdigit_from_bytes<BC_U2, 0x10, DIG>(MOD);
#define UNSUPPORTED_AF(DIG) \
    throw new std::invalid_argument("Af error at digit " #DIG);

af_item::af_item(BC_U2 modifier): modifier(modifier) {
    // TODO Construct from a modifier
    DEF_DIG_ARG_U2HEX(modifier, 0);
    DEF_DIG_ARG_U2HEX(modifier, 1);
    DEF_DIG_ARG_U2HEX(modifier, 2);
    DEF_DIG_ARG_U2HEX(modifier, 3);

    // FIXME Bad practice
    switch (digit_0) {
        case 0x0:
            break;
        case 0x1:
            flag_ext_map[af_tag::ACC_PUBLIC] = true;
            break;
        default: UNSUPPORTED_AF(0x0)
    }
    switch (digit_1) {
        case 0x1:
            flag_ext_map[af_tag::ACC_FINAL] = true;
            break;
        case 0x2:
            flag_ext_map[af_tag::ACC_SUPER] = true;
            break;
        case 0x3:
            flag_ext_map[af_tag::ACC_FINAL] = true;
            flag_ext_map[af_tag::ACC_SUPER] = true;
            break;
        default: UNSUPPORTED_AF(0x1)
    }
    switch (digit_2) {
        case 0x0:
            break;
        case 0x2:
            flag_ext_map[af_tag::ACC_INTERFACE] = true;
            break;
        case 0x4:
            flag_ext_map[af_tag::ACC_ABSTRACT] = true;
            break;
        case 0x6:
            flag_ext_map[af_tag::ACC_INTERFACE] = true;
            flag_ext_map[af_tag::ACC_ABSTRACT] = true;
            break;
        default: UNSUPPORTED_AF(0x2)
    }
    switch (digit_3) {
        case 0x0:
            break;
        case 0x1:
            flag_ext_map[af_tag::ACC_SYNTHETIC] = true;
            break;
        case 0x2:
            flag_ext_map[af_tag::ACC_ANNOTATION] = true;
            break;
        case 0x3:
            flag_ext_map[af_tag::ACC_SYNTHETIC] = true;
            flag_ext_map[af_tag::ACC_ANNOTATION] = true;
            break;
        case 0x4:
            flag_ext_map[af_tag::ACC_ENUM] = true;
            break;
        case 0x6:
            flag_ext_map[af_tag::ACC_ANNOTATION] = true;
            flag_ext_map[af_tag::ACC_ENUM] = true;
            break;
        case 0x7:
            flag_ext_map[af_tag::ACC_SYNTHETIC] = true;
            flag_ext_map[af_tag::ACC_ANNOTATION] = true;
            flag_ext_map[af_tag::ACC_ENUM] = true;
            break;
        default: UNSUPPORTED_AF(0x3)
    }

    check_af_valid();
}

af_item::af_item(std::map<af_tag, bool> flag_map): flag_ext_map(flag_map) {
    check_af_valid();
    calc_modifier();
}

BC_U2 af_item::getModifier() {
    if (modifier == EXPT_MODIFIER) {
        calc_modifier();
    }
    return modifier;
}
