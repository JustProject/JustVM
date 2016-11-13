//
// Created by 刘丰恺 on 2016/11/12.
//

#ifndef JUSTVM_PARAMS_H
#define JUSTVM_PARAMS_H

#include <string>
#include <sstream>
#include "optioninfo.h"

namespace cmd {

    /**
     * Params for each argument
     */
    class Params : public OptionInfo {

    protected:
        bool used = false;

    public:
        /**
         * Default Constructor for Params
         */
        Params(const std::string &optionInfo)
                : OptionInfo(optionInfo) { }


        virtual ~Params() { }

        /**
         * method to parse arguments
         */
        virtual void handler() = 0;

        /**
         * method to check validity
         */
        virtual bool check(const std::string &args) = 0;

        /**
         * command must use this params?
         */
        virtual bool isNeeded() {
            return false;
        };

        /**
         * parsed it?
         */
        virtual bool isParsed() {
            return used;
        };

        /**
         * need more params?
         */
        virtual bool needParams() {
            return false;
        }

        /**
         * position where value starts in passed string
         */
        virtual unsigned int valuePosition(const std::string &) = 0;
    };

}

#endif //JUSTVM_PARAMS_H
