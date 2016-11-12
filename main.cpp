#include <iostream>
#include "command/option.h"
#include "logger/log.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char *argv[]) {

    printf("%s", getenv("JAVA_HOME"));

    return 0;
}