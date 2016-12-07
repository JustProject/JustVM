//
// Created by 刘丰恺 on 2016/12/7.
//

#ifndef JUSTVM_DYNAMIC_ENUM_H
#define JUSTVM_DYNAMIC_ENUM_H

#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include "pystring/pystring.h"
#include <vector>

#ifdef REFLECT_NS
namespace REFLECT_NS {
#endif

struct EnumReflectionDefaultTag {
};

template<typename T, typename Type, typename Tag = EnumReflectionDefaultTag>
class EnumReflectionHelper {
    static T rand_result;
public:
    std::string toString(T) const {
        return "";
    }

    T fromString(std::string) const {
        return rand_result;
    }

    T fromValue(Type) const {
        return 0;
    }
};

#ifdef REFLECT_NS
}
#endif

#define __ENUM_TO_STRING(TypeName, Type, ...)                         \
    template<typename Tag>                                      \
    class EnumReflectionHelper<TypeName,Type, Tag>              \
    {                                                           \
        Type toType(const std::string & str){\
            Type item;\
            std::stringstream ss;\
            ss << str;\
            ss >> item;\
            return item;\
        }\
        std::map<Type, std::string> re_string_table;             \
        std::map<Type, int> type_number_table;\
    public:                                                     \
        EnumReflectionHelper()                                  \
        {                                                       \
            std::stringstream si(#__VA_ARGS__);                 \
            std::string token;                                  \
            token = si.str();\
            std::vector<std::string> temp;\
            std::vector<std::string> temp_kv;\
            pystring::split(pystring::strip(token),temp_kv, ",",-1);\
            int count = 0;\
            for(auto item : temp_kv){\
                temp.clear();\
                pystring::split(item,temp,"=",-1);\
                count++;\
                re_string_table[toType(temp[1])] = #TypeName"::"+temp[0];\
                type_number_table[toType(temp[1])] = count;\
            }\
        }     \
        std::string toString(TypeName type) const               \
        { return re_string_table[static_cast<int>(type)]; }     \
        TypeName fromValue(Type type){\
            std::cout << re_string_table[type] << std::endl;\
            return static_cast<TypeName>(                       \
                type_number_table[type]);\
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
    (::REFLECT_NS::EnumReflectionHelper<TypeName>::getHelper())
#else
#define ENUM_REFLECT(TypeName, Type)              \
    (EnumReflectionHelper<TypeName, Type>::getHelper())
#endif


#endif //JUSTVM_DYNAMIC_ENUM_H
