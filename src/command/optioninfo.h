//
// Created by 刘丰恺 on 2016/11/12.
//

#ifndef JUSTVM_OPTIONINFO_H
#define JUSTVM_OPTIONINFO_H

#include <string>

namespace cmd {

    /**
     * The option Info for each command line.
     */
    class OptionInfo {

    private:
        const std::string optionInfo;

    public:
        OptionInfo(const std::string &optionInfo)
                : optionInfo(optionInfo) { }


        virtual ~OptionInfo() { }

        /**
         * Return the option message for the command
         */
        const std::string &getOptionInfo() const {
            return optionInfo;
        }
    };

}


#endif //JUSTVM_OPTIONINFO_H
