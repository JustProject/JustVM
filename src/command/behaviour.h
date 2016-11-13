//
// Created by 刘丰恺 on 2016/11/12.
//

#ifndef JUSTVM_BEHAVIOUR_H
#define JUSTVM_BEHAVIOUR_H

#include <functional>
#include <string>

namespace cmd {

    template<typename FunctionParamsType>
    class Behaviour {
    protected:
        /**
         * The function solve the argument
         */
        std::function<void(FunctionParamsType)> function;

        /**
         * Run the function
         */
        void call(FunctionParamsType value) {
            this->function(value);
        }

    public:
        /**
         * Default Function
         */
        Behaviour(const std::function<void(FunctionParamsType)> &function) :
                function(function) { }


        virtual ~Behaviour() { }

    };

    /**
     * Void Input Behaviour
     */
    template<>
    class Behaviour<void> {
    protected:

        std::function<void()> function;

        void call() {
            this->function();
        }

    public:
        Behaviour(const std::function<void()> &function)
                : function(function) { }


        virtual ~Behaviour() { }
    };
}

#endif //JUSTVM_BEHAVIOUR_H
