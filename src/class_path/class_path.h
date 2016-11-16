//
// Created by 刘丰恺 on 2016/11/16.
//

#ifndef JUSTVM_CLASS_PATH_H
#define JUSTVM_CLASS_PATH_H

#include "../utils/pystring.h"

using std::string;
using std::vector;

namespace ept {

    class ClassPath {

    public:
        void setJreHome(string &jre);

        void setClassPath(string &cp);
    };

}

#endif //JUSTVM_CLASS_PATH_H
