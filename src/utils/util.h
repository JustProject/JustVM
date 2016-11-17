#pragma once

#ifndef JUSTVM_UTIL_H
#define JUSTVM_UTIL_H

#define byte unsigned char
#define SEPARATOR "/"
#define LIB_DIR "lib"
#define EXT_DIR "ext"
#define ALL_DIR "*"

#include <string>
#include <fstream>
#include <vector>
#include <cassert>
#include <memory>

size_t getFileSize(FILE *file);

size_t getFileSize(const char *filePath);

std::vector<byte> readFromFile(const char *filePath);

std::shared_ptr<byte> readByteFromFile(const char *filePath);

#endif //JUSTVM_UTIL_H
