//
// Created by 刘丰恺 on 2016/11/13.
//

#ifndef JUSTVM_PARAMSLIST_H
#define JUSTVM_PARAMSLIST_H

#include <string>
#include <vector>
#include "params.h"
#include "option.h"


namespace cmd {
    class ParamsList : public Params {
    protected:
        std::vector<std::shared_ptr<Params>> paramsList;

        std::vector<std::string> values;

        std::vector<bool> checked;

    public:
        ParamsList(std::initializer_list<std::shared_ptr<Params>> initParamsList,
                   std::string optionInfo = "optionInfo") :
                Params(optionInfo), paramsList(initParamsList) {
            for (int i = 0; i < paramsList.size(); ++i) {
                checked.push_back(false);
                values.push_back("");
            }
        };


        virtual ~ParamsList() { }

        virtual void handler() override {
            for (unsigned int i = 0; i < paramsList.size(); i++) {
                auto param = paramsList[i];
                if (checked[i] || param.get()->needParams()) {
                    param->handler();
                }
            }
            for (auto param : paramsList) {
                if (param->isNeeded() && !param->isParsed()) {
                    throw NeedOptionValue(param->getOptionInfo() + " is required");
                }
            }
        }

        virtual bool check(const std::string &args) override {
            bool check = false;

            for (unsigned int i = 0; i < paramsList.size(); i++) {
                auto param = paramsList[i].get();
                if (!checked[i]) {
                    check = param->check(args);
                    if (check) {
                        checked[i] = check;
                        values[i] = args;
                        break;
                    }
                }
            }

            bool all_checked = (checked.size() == paramsList.size());

            for (int j = 0; j < checked.size(); ++j) {
                all_checked &= checked[j];
            }

            return all_checked;
        }

        virtual bool needParams() override {
            return true;
        }

        virtual unsigned int valuePosition(const std::string &) {
            throw std::logic_error("List does not have value part");
        }
    };
}

#endif //JUSTVM_PARAMSLIST_H
