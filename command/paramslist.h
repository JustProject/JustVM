//
// Created by 刘丰恺 on 2016/11/13.
//

#ifndef JUSTVM_PARAMSLIST_H
#define JUSTVM_PARAMSLIST_H

#include <string>
#include <vector>
#include "params.h"


namespace cmd {
    class ParamsList : public Params {
    protected:
        std::vector<std::shared_ptr<Params>> paramsList;

        std::vector<std::string> values;


    public:
        ParamsList(std::initializer_list<std::shared_ptr<Params>> initParamsList,
                   std::string optionInfo = "optionInfo") :
                Params(optionInfo), paramsList(initParamsList) { };

    };
}

#endif //JUSTVM_PARAMSLIST_H
