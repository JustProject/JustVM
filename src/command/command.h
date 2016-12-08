//
// Created by 刘丰恺 on 2016/11/14.
//

#include "params_list.h"

#ifndef JUSTVM_COMMAND_H
#define JUSTVM_COMMAND_H

namespace just {
    namespace cmd {

        class Command : public ParamsList {

        public:
            Command(int argc, char *argv[],
                    const std::initializer_list<std::shared_ptr<Params>> &initParamsList,
                    const std::string &optionInfo = "Command")
                    : ParamsList(initParamsList, optionInfo) {
                for (unsigned int i = 1; i < argc; i++) {
                    this->check(argv[i]);
                }
                handler();
            }
        };

    }
}

#endif //JUSTVM_COMMAND_H
