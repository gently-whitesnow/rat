#pragma once

#include <models/result.h>

#include <string>

class SystemExecutor {
   public:
    SystemExecutor();
    ~SystemExecutor();
    const Result<std::string> Execute(const std::string& command) noexcept;
};