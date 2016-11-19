//
// Created by 刘丰恺 on 2016/11/19.
//

#include "multi_entry.h"

using std::vector;
using std::string;

void MultiEntry::readClass(std::string className) {
//    for (auto entry : multiEntry) {
//        entry.readClass(className);
//
//        if (entry.getByteChars() != nullptr && entry.getFileSize() != 0) {
//            this->byteChars = entry.getByteChars();
//        }
//    }
//
//    for (int i = 0; i < multiEntry.size(); ++i) {
//        auto entry = dynamic_cast<>multiEntry[i];
//    }

}

std::string &MultiEntry::toString() {
    if (listEntry.empty()) {
        vector<string> list;

        for (int i = 0; i < multiEntry.size(); ++i) {
            list.push_back(multiEntry[i].toString());
        }

        listEntry = pystring::join(" | ", list);
    }

    return listEntry;
}
