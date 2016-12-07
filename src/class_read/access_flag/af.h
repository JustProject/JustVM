//
// Created by zhangyutong926 on 12/5/16.
//

#ifndef JUSTVM_AF_H
#define JUSTVM_AF_H


#include <util.h>
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
     * ACC_SYNTHETIDC FALSE
     * ACC_ANNOTATION FALSE
     * ACC_ENUM FALSE
     */
    af_item() :
            acc_public(true),
            acc_final(false),
            acc_super(true), // FIXME Are we talking about Java 8 and above?
            acc_interface(false),
            acc_abstract(false),
            acc_synthetic(false),
            acc_annotation(false),
            acc_enum(false) {}

    af_item(just::util::fl_array::fl_array_ut<af_tag> &) throw(std::invalid_argument);

    af_item(BC_U2);

    BC_U2 getModifier();

    inline bool is_public() const {
        return acc_public;
    }

    inline bool is_final() const {
        return acc_final;
    }

    inline bool is_super() const {
        return acc_super;
    }

    inline bool is_interface() const {
        return acc_interface;
    }

    inline bool is_abstract() const {
        return acc_abstract;
    }

    inline bool is_synthetic() const {
        return acc_synthetic;
    }

    inline bool is_annotation() const {
        return acc_annotation;
    }

    inline bool is_enum() const {
        return acc_enum;
    }

private:
    bool acc_public;
    bool acc_final;
    bool acc_super;
    bool acc_interface;
    bool acc_abstract;
    bool acc_synthetic;
    bool acc_annotation;
    bool acc_enum;
    just::util::fl_array::fl_array_ut<af_tag> flag_list;
};


#endif //JUSTVM_AF_H
