//
// Created by 刘丰恺 on 2016/11/16.
//

#ifndef JUSTVM_DIR_ENTRY_H
#define JUSTVM_DIR_ENTRY_H

#include "entry.h"
#include <string>

using std::ifstream;

namespace ept {
    class DirEntry : public Entry {

    protected:
        std::string absPath;

    public:
        DirEntry(std::string &path) : absPath(path) { }

        ~DirEntry() {
            delete absPath;
        };

        std::vector<byte> readClass(std::string className) override {

            auto result = readFromFile((absPath + className).c_str());

            return result;
        }

        std::string &toString() override {
            return absPath;
        }
    };
}


#endif //JUSTVM_DIR_ENTRY_H
