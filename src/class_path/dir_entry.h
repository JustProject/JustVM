//
// Created by 刘丰恺 on 2016/11/16.
//

#ifndef JUSTVM_DIR_ENTRY_H
#define JUSTVM_DIR_ENTRY_H

#include "entry.h"
#include "../utils/util.h"
#include <string>


class DirEntry : public Entry {

protected:
    std::string absPath;

public:
    DirEntry(std::string &path) : absPath(path) {}

    virtual ~DirEntry() {};

    virtual void readClass(std::string className) override;

    virtual std::string &toString() override;
};


#endif //JUSTVM_DIR_ENTRY_H
