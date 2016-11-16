//
// Created by 刘丰恺 on 2016/11/16.
//

#include "class_path.h"
#include "util.h"

namespace ept {

    void ClassPath::setClassPath(string &cp) {
        if (cp == "") {
            string newCp(".");

        }
        // set user class path
    }

    void ClassPath::setJreHome(string &jre) {
        vector<string> jreVec;
        jreVec.push_back(jre);
        jreVec.push_back(LIB_DIR);
        jreVec.push_back(ALL_DIR);

        string jreLib = pystring::join(SEPARATOR, jreVec);
        // add jre/lib/* ...


        auto insert_2 = jreVec.begin() + 2;
        jreVec.insert(insert_2, EXT_DIR);
        // add jre/lib/ext/*
        string jreExt = pystring::join(SEPARATOR, jreVec);
    }
}