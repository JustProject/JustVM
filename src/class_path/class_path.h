//
// Created by 刘丰恺 on 2016/11/16.
//

#ifndef JUSTVM_CLASS_PATH_H
#define JUSTVM_CLASS_PATH_H

#include "../utils/pystring.h"
#include "../utils/util.h"

namespace ept {

    class ClassPath {

    public:
        void setJreHome(std::string &jre);

        void setClassPath(std::string &cp);
    };

}

#endif //JUSTVM_CLASS_PATH_H
