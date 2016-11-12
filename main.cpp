#include <iostream>
#include "logger/easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main() {

    printf("%s", getenv("JAVA_HOME"));
    return 0;
}