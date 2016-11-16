//
// Created by 刘丰恺 on 2016/11/14.
//

#ifndef JUSTVM_ENTRY_H
#define JUSTVM_ENTRY_H

#include "util.h"
#include "../utils/pystring.h"
#include <string>
#include <fstream>
#include <vector>
#include <cassert>


namespace ept {

    class Entry {
    public:

        Entry() { };

        ~Entry() { };

        /**
         * read class file
         */
        virtual std::vector<byte> readClass(std::string className) = 0;

        virtual std::string &toString() = 0;


/**
 * Get file size
 */
        static size_t getFileSize(FILE *file) {
            fseek(file, 0, SEEK_END);
            size_t read_len = ftell(file);
            fseek(file, 0, SEEK_SET);
            return read_len;
        }

        static size_t getFileSize(const char *filePath) {
            FILE *file = fopen(filePath, "rb");
            if (file == nullptr) {
                return 0;
            }
            size_t size = getFileSize(file);
            fclose(file);
            return size;
        }

/**
 * read unsigned char (byte) from a file
 */
        std::vector<byte> readFromFile(const char *filePath) {
            FILE *file = fopen(filePath, "rb");
            std::vector<byte> result;
            if (file == nullptr) {
                return result;
            }

            size_t fileSize = getFileSize(file);
            if (fileSize != 0) {
                result.resize(fileSize);
                size_t n = fread(&result[0], 1, fileSize, file);
                assert(n <= fileSize);
                if (n != fileSize) {
                    result.resize(n);
                }
            }

            // 在读取过程当中，有可能文件大小有变化，再尝试读取
            const size_t read_len = 1024;
            char buf[read_len];
            for (; ;) {
                size_t n = fread(buf, 1, read_len, file);
                result.insert(result.end(), buf, buf + n);
                if (n < read_len) {
                    break;
                }
            }
            fclose(file);
            return result;
        }
    };

}

#endif //JUSTVM_ENTRY_H
