//
// Created by 刘丰恺 on 2016/11/16.
//

#ifndef JUSTVM_MULTI_ENTRY_H
#define JUSTVM_MULTI_ENTRY_H

#include "entry.h"
#include <vector>
#include <string>

namespace ept {
    class MultiEntry : public Entry {
    protected:
        std::vector<Entry> multiEntry;

        std::string listEntry;

    public:

        MultiEntry(std::string path) {

        };

        ~MultiEntry() {

        }

        std::vector<byte> readClass(std::string className) override {
//            for (auto entry : multiEntry) {
//                auto result = entry.readClass(className);
//
//                if (result != nullptr && result.size() != 0) {
//                    return result;
//                }
//            }
//
            return nullptr;
        }

        std::string &toString() override {
            if (listEntry == nullptr) {
                std::vector list;

                for (int i = 0; i < multiEntry.size(); ++i) {
                    list.push_back(multiEntry[i]);
                }

                listEntry = pystring::join(" | ", list);
            }

            return listEntry;
        };
    };
}

#endif //JUSTVM_MULTI_ENTRY_H
