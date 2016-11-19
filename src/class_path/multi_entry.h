//
// Created by 刘丰恺 on 2016/11/16.
//

#ifndef JUSTVM_MULTI_ENTRY_H
#define JUSTVM_MULTI_ENTRY_H

#include "entry.h"
#include <vector>
#include <string>


class MultiEntry : public Entry {
protected:
    std::vector<Entry> multiEntry;

    std::string listEntry;

public:

    MultiEntry(std::string path) {

    };

    virtual ~MultiEntry() {};

    virtual void readClass(std::string className) override;

    virtual std::string &toString() override;
};


#endif //JUSTVM_MULTI_ENTRY_H
