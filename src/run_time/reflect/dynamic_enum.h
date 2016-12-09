//
// Created by 刘丰恺 on 2016/12/7.
//

#ifndef JUSTVM_DYNAMIC_ENUM_H
#define JUSTVM_DYNAMIC_ENUM_H

#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <cstdlib>
#include "pystring/pystring.h"
#include <vector>

#ifdef REFLECT_NS
namespace REFLECT_NS {
#endif

struct EnumReflectionDefaultTag {
};

struct EnumItem {
    std::string tag_name;
    int number;
};

/**
 * @tparam T enum-type
 * @tparam Type enum-item-type
 * @tparam Tag tag
 */
template<typename T, typename Type, typename Tag = EnumReflectionDefaultTag>
class EnumReflectionHelper {
    static T rand_result;
public:
    std::string to_string(T) const {
        return "";
    }

//    T fromString(std::string) const {
//        return rand_result;
//    }

    T from_value(Type) const {
        return 0;
    }

    std::string from_value_to_string(Type) const {
        return "";
    }
};

#ifdef REFLECT_NS
}
#endif

#define __ENUM_TO_STRING(TypeName, Type, ...)                         \
    template<typename Tag>                                      \
    class EnumReflectionHelper<TypeName,Type, Tag>              \
    {                                                           \
        std::map<Type, EnumItem> re_string_table;             \
    public:                                                     \
        EnumReflectionHelper()                                  \
        {                                                       \
            std::stringstream si(#__VA_ARGS__);                 \
            std::string token;                                  \
            token = si.str();\
            std::vector<std::string> temp;\
            std::vector<std::string> temp_kv;\
            pystring::split(pystring::replace(token," ",""),temp_kv, ",",-1);\
            int count = 0;\
            for(auto item : temp_kv){\
                temp.clear();\
                pystring::split(item, temp, "=",-1);\
                EnumItem enumItem;\
                enumItem.number = count;\
                enumItem.tag_name = temp[0];\
                re_string_table[atoi(temp[1].c_str())] = enumItem;\
                count++;\
            }\
        }     \
        std::string to_string(TypeName type) const               \
        {   \
            return re_string_table.at(static_cast<Type>(type)).tag_name;\
        }     \
        TypeName from_value(Type type){\
            return static_cast<TypeName>(                       \
                re_string_table[type].number);\
        }\
        std::string from_value_to_string(Type type) const {\
            return re_string_table.at(type).tag_name;\
        }\
        static EnumReflectionHelper* getHelper()                \
        {                                                       \
            static EnumReflectionHelper helper;                 \
            return &helper;                                     \
        }                                                       \
    };

#define __ENUM_DEFINE(TypeName, Type, ...)        \
    enum class TypeName : Type { __VA_ARGS__ };    \

#define ENUM_CLASS(TypeName, Type, ...)       \
    __ENUM_DEFINE(TypeName,Type, __VA_ARGS__)\
    __ENUM_TO_STRING(TypeName,Type,__VA_ARGS__)\

#ifdef REFLECT_NS
#define ENUM_REFLECT(TypeName)              \
    (::REFLECT_NS::EnumReflectionHelper<TypeName, Type>::getHelper())
#else
#define ENUM_REFLECT(TypeName, Type)              \
    (EnumReflectionHelper<TypeName, Type>::getHelper())
#endif

#define UNION_REFLECT(TypeName, Type, Tag)\
    (EnumReflectionHelper<TypeName, Type, Tag>::getHelper())

#endif //JUSTVM_DYNAMIC_ENUM_H
