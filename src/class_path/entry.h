//
// Created by 刘丰恺 on 2016/11/14.
//

#ifndef JUSTVM_ENTRY_H
#define JUSTVM_ENTRY_H

#include "../utils/util.h"
#include "../utils/pystring.h"
#include <string>
#include <fstream>
#include <vector>
#include <cassert>


namespace ept {

    class Entry {
    public:

        Entry() { };

        ~Entry() { };

        /**
         * read class file
         */
        virtual std::vector<byte> readClass(std::string className) = 0;

        virtual std::string &toString() = 0;



    };

}

#endif //JUSTVM_ENTRY_H
