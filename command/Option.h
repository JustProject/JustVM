//
// Created by 刘丰恺 on 2016/11/12.
//

#ifndef JUSTVM_OPTION_H
#define JUSTVM_OPTION_H

#include <string>
#include "behaviour.h"
#include "params.h"

namespace cmd {

    template<typename FunctionParamsType>
    class Option : public Params, public Behaviour<FunctionParamsType> {
    public:
        Option(const std::string &name,
               const std::string &optionInfo,
               const std::function<void(FunctionParamsType)> &function)
                : Behaviour<FunctionParamsType>(function), Params(optionInfo), name(name) { }


        virtual ~Option() { }

        virtual void handler() override {
            this->call();
            this->used = true;
        }

        /**
         * Check argument for option
         */
        virtual bool check(const std::string &args) override {
            if (this->contains(args)) {
                std::size_t pos = this->valuePosition(args);

                // lost value
                if (pos != name.size()) {
                    throw NeedOptionValue("Option " + name + " requires value !!!");
                }

                std::stringstream ss;
                ss << std::fixed << args.substr(pos + 1);
                ss >> value;

                if (ss.fail()) {
                    throw GetValueFail("Option: " + name + " get value failed !!!");
                }

                return true;
            }

            return false;
        }

        virtual unsigned int valuePosition(const std::string &string) override {
            std::size_t pos = value.find("=");

            if ((this->contains(value))
                && (pos == std::string::npos)) {
                throw OptionNotSpecified("Option: " + name + " with no value after equal sign !!!");
            }

            return (unsigned int) pos;
        }


    protected:
        typedef std::string OptionName;
        /**
         * Current option value
         */
        FunctionParamsType value;

        /*
        * Current option name
        */
        const OptionName name;

        bool contains(const std::string &argv) {
            return argv.find(name) == 0;
        }
    };

    /**
     * Option need value
     */
    class NeedOptionValue : public std::invalid_argument {

    public:
        explicit NeedOptionValue(const std::string &__s)
                : invalid_argument(__s) { }
    };

    /**
     * Can not get option value successful
     */
    class GetValueFail : public std::invalid_argument {

    public:
        explicit GetValueFail(const std::string &__s) : invalid_argument(__s) { }
    };

    class OptionNotSpecified : public std::invalid_argument { ;
    public:
        explicit OptionNotSpecified(const std::string &__s) :
                invalid_argument(__s) { }
    };

    template<>
    class Option<void> : public Params, public Behaviour<void> {
    public:
        typedef std::string OptionName;
    protected:
        /**
         * Current Option name
         */
        const OptionName name;
    public:
        Option(const std::string &name,
               const std::string &optionInfo,
               const std::function<void()> &function)
                : Params(optionInfo),
                  Behaviour(function),
                  name(name) { }


        virtual ~Option() { }

        virtual void handler() override {
            this->call();
            this->used = true;
        }

        virtual bool check(const std::string &args) override {
            return args == name;
        }

        virtual unsigned int valuePosition(const std::string &) override {
            throw new std::invalid_argument(this->getOptionInfo() + " fuck value !!!");
        }

    };
}

#endif //JUSTVM_OPTION_H
