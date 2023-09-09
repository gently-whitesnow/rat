#include "system_executor.h"

#include <models/result.h>
#include <models/result_status.h>

#include <cstdio>
#include <cstring>
#include <iostream>

SystemExecutor::SystemExecutor() {}

SystemExecutor::~SystemExecutor() {}

const Result<std::string> SystemExecutor::Execute(
    const std::string& command) noexcept {
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        return Result<std::string>(
            ResultStatus::InternalError,
            "Couldn't open the command pipe: " + command);
    }

    char buffer[128];
    std::string output = "";

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        output += buffer;
    }

    pclose(pipe);

    if (output.empty()) {
        return Result<std::string>(ResultStatus::InternalError,
                                   "Empty command output of:" + command);
    }

    return Result<std::string>(std::move(output));
}