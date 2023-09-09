#pragma once
#include <string>

class IDto {
   public:
    IDto(std::string data) : _data(data) {}
    virtual ~IDto() {}

    const std::string& GetStringifyData() const { return _data; }

   private:
    std::string _data;
};