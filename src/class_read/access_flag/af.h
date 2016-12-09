//
// Created by zhangyutong926 on 12/5/16.
//

#ifndef JUSTVM_AF_H
#define JUSTVM_AF_H


#include <util.h>
#include <map>
#include <fl_array/fl_array_ut.hpp>


enum af_tag : BC_U2 {
    ACC_PUBLIC = 0x0001,
    ACC_FINAL = 0x0010,
    ACC_SUPER = 0x0020,
    ACC_INTERFACE = 0x0200,
    ACC_ABSTRACT = 0x0400,
    ACC_SYNTHETIC = 0x1000,
    ACC_ANNOTATION = 0x2000,
    ACC_ENUM = 0x4000
};

// FIXME This is a FSM, Finite State Machine, so if you have a better way to implement, you're welcome to try.
/** \brief This class possess the Access Flag status of a java class.
 *
 * Each of the bool value possess a single flag that a java class can have.
 * You may already noticed that some of the access flag is interconnected and some of them is interexclused.
 * You may also noticed the ACStatus is immutable, which mean once you initiated the class, the modifiers cannot be changed anymore.
 *
 * FYI, JVM Specs "Table 4.1-A Class access and property modifiers"
 */
class af_item {
public:
    /** \brief The default constructor will construct the access flag of a HelloWorld-liked public class.
     *
     * In detaled, HelloWorld-liked public class means:
     * ACC_PUBLIC TRUE
     * ACC_FINAL FALSE
     * ACC_SUPER TRUE (In Java 8 and above versions)
     * ACC_INTERFACE FALSE
     * ACC_ABSTRACT FALSE
     * ACC_SYNTHETIC FALSE
     * ACC_ANNOTATION FALSE
     * ACC_ENUM FALSE
     */
    af_item();

    af_item(just::util::fl_array::fl_array_ut<af_tag> &) throw(std::invalid_argument);

    af_item(BC_U2) throw(std::invalid_argument);

    af_item(std::map<af_tag, bool>) throw(std::invalid_argument);

    /** \brief To check whether the access flag set the instance possessed is valid or not.
     *
     * @return true or invalid_argument
     */
    bool check_af_valid() throw(std::invalid_argument);

    BC_U2 getModifier();

    // XXX C++ Template MetaProgramming Warning!
    template<af_tag _t>
    inline bool is_flag_ext() {
        return flag_ext_map[_t];
    }

private:
    std::map<af_tag, bool> flag_ext_map;
#define EXPT_MODIFIER 0xFFFF
    BC_U2 modifier = EXPT_MODIFIER;

    void calc_modifier();
};


#endif //JUSTVM_AF_H
