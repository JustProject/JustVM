//
// Created by 刘丰恺 on 2016/11/12.
//

#ifndef JUSTVM_ARGUMENT_H
#define JUSTVM_ARGUMENT_H

#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include "params.h"
#include "behaviour.h"

namespace just {
    namespace cmd {

        template<typename FunctionParamsType>
        class Argument : public Params, public Behaviour<FunctionParamsType> {
        protected:
            FunctionParamsType value;
        public:

            typedef class Argument Type;

            /**
             * @params : option info
             *
             * @params : behaviour function
             */
            Argument(const std::string &optionInfo,
                     const std::function<void(FunctionParamsType)> &function)
                    : Params(optionInfo), Behaviour(function) {};

            virtual ~Argument() {}

            /**
             * handler message
             */
            virtual void handler() override {
                this->call(value);
                this->used = true;
            }

            virtual bool check(const std::string &args) override {
                std::stringstream ss;

                ss << std::fixed << args;
                ss >> value;

                return !ss.fail();
            }

            virtual unsigned int valuePosition(const std::string &string) override {
                return 0;
            }
        };
    }
}

#endif //JUSTVM_ARGUMENT_H
