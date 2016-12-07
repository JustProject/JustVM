//
// Created by zhangyutong926 on 12/2/16.
//

#ifndef JUSTVM_FL_ARRAY_U_H
#define JUSTVM_FL_ARRAY_U_H


#include <cstdint>
#include <memory>

namespace just {
    namespace util {
        namespace fl_array {
#define FL_ARRAY_UT_P(NAME, TYPE, LENGTH, CONTENT...) \
    TYPE NAME##__FILE__##__DATE__##__TIME___temp[LENGTH] = CONTENT; \
    fl_array_ut<TYPE> NAME(LENGTH, &(NAME##__FILE__##__DATE__##__TIME___temp[0]));

            typedef uint32_t fl_array_size_t;

            template<typename T>
            class fl_array_ut {
            public:
                fl_array_ut(fl_array_size_t = 0);

                fl_array_ut(fl_array_size_t, T *);

                ~fl_array_ut();

                bool contains(const T &);

                T *begin();

                T *end();

                inline fl_array_size_t count() const {
                    return length;
                }

                T &operator[](fl_array_size_t);

                // TODO operator=

            private:
                fl_array_size_t length;
                std::shared_ptr<T> *value;
            };

            template<typename T>
            fl_array_ut<T>::fl_array_ut(fl_array_size_t length) {
                T temp[length] = {((T) 0)};
                new(this)fl_array_ut(length, &temp[0]);
            }

            template<typename T>
            fl_array_ut<T>::fl_array_ut(fl_array_size_t length, T *source): length(length) {
                value = new std::shared_ptr<T>[length];
                for (int i = 0; i < length; i++) {
                    value[i] = std::make_shared<T>(source[i]);
                }
            }

            template<typename T>
            fl_array_ut<T>::~fl_array_ut() {
                delete[] value;
            }

            template<typename T>
            T &fl_array_ut<T>::operator[](fl_array_size_t target) {
                return *value[target];
            }

            template<typename T>
            bool fl_array_ut<T>::contains(const T &item) {
                for (int i = 0; i < length; i++) {
                    if (value[i] == &item) {
                        return true;
                    }
                }
                return false;
            }

            template<typename T>
            T *fl_array_ut<T>::begin() {
                return value[0].get();
            }

            template<typename T>
            T *fl_array_ut<T>::end() {
                return value[length - 1].get();
            }

            template<typename T>
            bool operator==(const fl_array_ut<T> &lhs, const fl_array_ut<T> &rhs) {
                if (lhs.count() != rhs.count()) {
                    return false;
                }
                for (int i = 0; i < lhs.count(); i++) {
                    if (lhs[i] != rhs[i]) {
                        return false;
                    }
                }
                return true;
            }
        }
    }
}

#endif //JUSTVM_FL_ARRAY_U_H
