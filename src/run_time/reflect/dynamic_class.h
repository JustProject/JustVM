//
// Created by 刘丰恺 on 2016/12/5.
//

#ifndef JUSTVM_DYNAMIC_CLASS_H
#define JUSTVM_DYNAMIC_CLASS_H

#include <iostream>
#include <map>
#include <string>
#include <type_traits>

namespace REFLECT {

/*! Reflect Tag to devide reflections into various groups */
    struct DEFAULT_REFLECT_TAG {
    };

/*!
 Base of factory, used it to store pointer in map
 */
    template<class T, typename REFLECT_TAG = DEFAULT_REFLECT_TAG>
    class BaseFactory {
    public:
        /*!
         Create a object of base class
         @return pointer to new object
         */
        virtual T *create() const = 0;
    };

/*!
 Devired factory
 */
    template<class Base, class T, typename REFLECT_TAG = DEFAULT_REFLECT_TAG>
    class Factory : public BaseFactory<Base> {
    public:
        /*!
         @see BaseFactory::create()
         */
        virtual T *create() const {
            return new T();
        }
    };

/*!
 Global factory map. Use function with static variable to keep __the_map global unique
 @return __the_map
 */
    template<class Base, typename REFLECT_TAG = DEFAULT_REFLECT_TAG>
    std::map<std::string, BaseFactory<Base, REFLECT_TAG> *> &
    __global_factory_map() {
        static std::map<std::string, BaseFactory<Base, REFLECT_TAG> *> __the_map;
        return __the_map;
    }

/*!
 Class to regist factory to global factory map when constructing
 */
    template<
            class Base,
            class T,
            typename class_name_wp,
            typename REFLECT_TAG = DEFAULT_REFLECT_TAG>
    class __REFLECT_REGIST_CLASS {
    public:
        __REFLECT_REGIST_CLASS() {
            __global_factory_map<Base, REFLECT_TAG>().insert(
                    std::make_pair<std::string, Factory<Base, T, REFLECT_TAG> *>(
                            std::string(class_name_wp::get()), new Factory<Base, T, REFLECT_TAG>()
                    ));
        }

        void *get() {
            return nullptr;
        };
    };

/*!
 Class to make sure registing class is constructed once and only once
 */
    template<
            class Base,
            class T,
            typename class_name_wp,
            typename REFLECT_TAG = DEFAULT_REFLECT_TAG>
    class __REFLECT_REGIST_CLASS_CALLER {
        static __REFLECT_REGIST_CLASS<
                Base,
                T,
                class_name_wp,
                REFLECT_TAG> __registor;

    public:
        __REFLECT_REGIST_CLASS_CALLER() {
            __registor.get();
        }
    };

/* Define the static member of __REFLECT_REGIST_CLASS_CALLER */
    template<
            class Base,
            class T,
            typename class_name_wp,
            typename REFLECT_TAG>
    __REFLECT_REGIST_CLASS<
            Base,
            T,
            class_name_wp,
            REFLECT_TAG>
            __REFLECT_REGIST_CLASS_CALLER<
                    Base,
                    T,
                    class_name_wp,
                    REFLECT_TAG>::__registor;

/* Use a struct to store and pass string literial */
#define __STRING_WRAPPER(s)     \
  struct __string_wrapper_##s { \
    static char const *         \
    get()                       \
    {                           \
      return #s;                \
    }                           \
  };

/*! Macro to call when RE_class has only two arguments */
#define RE_class_2(classname, Base)             \
__STRING_WRAPPER(classname)                     \
static REFLECT::__REFLECT_REGIST_CLASS_CALLER<  \
  Base,                                         \
  class classname,                              \
  __string_wrapper_##classname>                 \
  _registor_caller_##classname;                 \
class classname : public Base

/*! Macro to call when RE_class has three arguments */
#define RE_class_3(classname, Base, tag)        \
__STRING_WRAPPER(classname)                     \
static REFLECT::__REFLECT_REGIST_CLASS_CALLER<  \
  Base,                                         \
  class classname,                              \
  __string_wrapper_##classname, tag>            \
  _registor_caller_##classname;                 \
class classname : public Base

/*! Small thick to overload macro RE_class */
#define __RE_CLASS_GET_MACRO(_1, _2, _3, NAME, ...) NAME

/*! RE_class(Class, BaseClass [, tag]) */
#define re_class(...) __RE_CLASS_GET_MACRO(__VA_ARGS__, RE_class_3, RE_class_2)(__VA_ARGS__)

/*! Macro to call when Reflect has only one argument */
#define Reflect_1(T) (REFLECT::__global_factory_map<T>())

/*! Macro to call when Reflect has two arguments */
#define Reflect_2(T, tag) (REFLECT::__global_factory_map<T, tag>())

#define __REFLECT_GET_MACRO(_1, _2, NAME, ...) NAME

/*! Reflect(BaseClass [, tag]) */
#define Reflect(...) __REFLECT_GET_MACRO(__VA_ARGS__, Reflect_2, Reflect_1)(__VA_ARGS__)

}

#endif //JUSTVM_DYNAMIC_CLASS_H
