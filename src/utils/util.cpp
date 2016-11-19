//
// Created by 刘丰恺 on 2016/11/16.
//
#include "util.h"

using std::shared_ptr;
using std::vector;

/**
 * Get file size
 */
size_t getFileSize(FILE *file) {
    fseek(file, 0, SEEK_END);
    size_t read_len = (size_t) ftell(file);
    fseek(file, 0, SEEK_SET);
    return read_len;
}

size_t getFileSize(const char *filePath) {
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
vector<byte> readFromFile(const char *filePath) {
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
    for (;;) {
        size_t n = fread(buf, 1, read_len, file);
        result.insert(result.end(), buf, buf + n);
        if (n < read_len) {
            break;
        }
    }
    fclose(file);
    return result;
}

Point<byte> readByteFromFile(Point<byte> byteChars, const char *filePath) {
    return readByteFromFile(byteChars, (const int) getFileSize(filePath), filePath);
}

Point<byte> readByteFromFile(Point<byte> byteChars,
                             const size_t size, const char *filePath) {
    FILE *file = fopen(filePath, "rb");
    if (file == nullptr) {
        return byteChars;
    }

    if (size != 0) {
        byteChars = new byte[size];
        size_t n = fread(byteChars, 1, size, file);
        assert(n <= size);
    }

    return byteChars;
}

