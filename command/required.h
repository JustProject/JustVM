//
// Created by 刘丰恺 on 2016/11/13.
//

#ifndef JUSTVM_REQUIRED_H
#define JUSTVM_REQUIRED_H

#include <params.h>
#include "params.h"

namespace cmd {

    /**
     * Required Params
     */
    class Required : public Params {

    protected:
        std::shared_ptr<Params> params;
    public:
        Required(const std::shared_ptr<Params> &params)
                : Params(params.get()->getOptionInfo()),
                  params(params) { };


        virtual ~Required() { }

        virtual void handler() override {
            params.get()->handler();
        }

        virtual bool check(const std::string &args) override {
            return params.get()->check(args);
        }

        virtual bool isNeeded() override {
            return true;
        }

        virtual bool isParsed() override {
            return params.get()->isParsed();
        }

        virtual unsigned int valuePosition(const std::string &string) override {
            return params.get()->valuePosition(string);
        }

    };

}

#endif //JUSTVM_REQUIRED_H
