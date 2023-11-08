#pragma once

#include <string>

#include <models/result.h>

class IConfigReader {
public:
    virtual Result<std::string> Read() const noexcept = 0;
};