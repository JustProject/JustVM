//
// Created by 刘丰恺 on 2016/11/14.
//


#ifndef JUSTVM_MULTI_VALUE_H
#define JUSTVM_MULTI_VALUE_H

#include <vector>
#include "params.h"

namespace cmd {

    class MultiValue : public Params {
    protected:

        std::vector<std::string> values;

        std::shared_ptr<Params> params;

        /**
         * symbol to splite values
         */
        std::string separator;
    public:
        MultiValue(std::string separator, std::shared_ptr<Params> parameter)
                : Params(parameter->getOptionInfo()), params(parameter),
                  separator(separator) {
        }


        virtual ~MultiValue() { }

        virtual void handler() override {
            for (auto value : values) {
                params->check(value);
                params->handler();
            }
        }

        virtual bool check(const std::string &value) override {
            size_t start = 0;
            size_t pos = 0;
            bool _check = true;
            std::string prefix = "";

            start = params.get()->valuePosition(value);

            if (start > value.size()) {
                return false;
            }

            if (start > 0) {
                prefix = value.substr(0, ++start);
            }

            do {
                pos = value.find(separator, start);
                values.push_back(prefix + value.substr(start, pos - start));
                _check &= params.get()->check(values.back());
                start = pos + 1;

                if (!_check) {
                    values.clear();
                    break;
                }
            } while ((pos != std::string::npos) && (start < value.size()));
            return _check;
        }

        virtual bool isNeeded() override {
            return params.get()->isNeeded();
        }

        virtual bool isParsed() override {
            return params.get()->isParsed();
        }

        virtual unsigned int valuePosition(const std::string &string) override {
            return params.get()->valuePosition(string);
        }
    };

}

#endif //JUSTVM_MULTI_VALUE_H
