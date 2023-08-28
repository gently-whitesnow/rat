#pragma once
#include <string>

class IDto {
   public:
    virtual ~IDto() {}
    virtual std::string GetStringifyData() = 0;
};