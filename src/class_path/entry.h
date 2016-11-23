//
// Created by 刘丰恺 on 2016/11/14.
//

#ifndef JUSTVM_ENTRY_H
#define JUSTVM_ENTRY_H

#include "../utils/util.h"
#include "../utils/pystring/pystring.h"
#include <string>

class Entry {
public:

    Entry() {};

    virtual ~Entry() = default;

    /**
     * read class file
     */
    virtual void readClass(std::string className) = 0;

    virtual std::string &toString() = 0;

    size_t getSize() const {
        return fileSize;
    };

    Point<byte> getByteChars() const {
        return byteChars;
    };

protected:
    size_t fileSize;

    Point<byte> byteChars = new byte;
};


#endif //JUSTVM_ENTRY_H
