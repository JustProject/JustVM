#include <iostream>
#include "logger/log.h"
#include "command.h"

INITIALIZE_EASYLOGGINGPP

class FuckDemo {
public:
    void help() {
        LOG(INFO) << "fuck helper -- ";
    };
};

int main(int argc, char *argv[]) {

    FuckDemo demo;

    printf("%s", getenv("JAVA_HOME"));

    std::shared_ptr<cmd::Option<void>> help =
            std::make_shared<cmd::Option<void>>("h", "Help",
                                                std::bind(&FuckDemo::help, &demo));
    cmd::Command command(argc, argv, {help});

    return 0;
}

