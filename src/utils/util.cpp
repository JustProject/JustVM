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

void decode_mutf_8(Point<byte> byte_point, int len) {
    Point<uint16> uint16_point = new uint16[len];
    uint16 c, char2, char3;
    int count = 0, uint16_count = 0;
    for (; count < len;) {
        c = uint16(byte_point[count]);
        if (c > 127) {
            break;
        }
        count++;
        uint16_point[uint16_count] = c;
        uint16_count++;
    }

    for (; count < len;) {
        c = uint16(byte_point[count]);
        switch (c >> 4) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                /* 0xxxxxxx*/
                count++;
                uint16_point[uint16_count] = c;
                uint16_count++;
                break;
            case 12:
            case 13:
                /* 110x xxxx   10xx xxxx*/
                count += 2;
                if (count > len) {
                    throw std::logic_error("malformed input: partial character at end");
                }
                char2 = uint16(byte_point[count - 1]);
                if (char2 & 0xC0 != 0x80) {
                    throw std::logic_error("malformed input around byte" + (char) count);
                }
                uint16_point[uint16_count] = c & 0x1F << 6 | char2 & 0x3F;
                uint16_count++;
                break;
            case 14:
                /* 1110 xxxx  10xx xxxx  10xx xxxx*/
                count += 3;
                if (count > len) {
                    throw std::logic_error("malformed input: partial character at end");
                }
                char2 = uint16(bytearr[count - 2]);
                char3 = uint16(bytearr[count - 1]);
                if (char2 & 0xC0 != 0x80 || char3 & 0xC0 != 0x80) {
                    throw std::logic_error("malformed input around byte" + (char) (count - 1));
                }
                uint16_point[uint16_count] = c & 0x0F << 12 | char2 & 0x3F << 6 | char3 & 0x3F << 0;
                uint16_count++;
                break;
            default:
                /* 10xx xxxx,  1111 xxxx */
                throw std::logic_error("malformed input around byte" + (char) (count));
        }
    }
}

