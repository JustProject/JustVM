//
// Created by 刘丰恺 on 2016/11/16.
//

#ifndef JUSTVM_DIR_ENTRY_H
#define JUSTVM_DIR_ENTRY_H

#include "entry.h"
#include <string>

namespace ept {
    class DirEntry : public Entry {

    protected:
        std::string absPath;

    public:
        DirEntry(std::string &path) : absPath(path) { }

        ~DirEntry() {

        };

        std::vector<byte> readClass(std::string className) override {
            auto result = readFromFile((absPath + className).c_str());
            return result;
        }

        std::shared_ptr<byte> readByteClass(std::string className) {
            return readByteFromFile((absPath + className).c_str());
        }

        std::string &toString() override {
            return absPath;
        }
    };
}


#endif //JUSTVM_DIR_ENTRY_H
