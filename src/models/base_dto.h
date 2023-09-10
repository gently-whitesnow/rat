#pragma once
#include <string>

class BaseDto {
   public:
    BaseDto(std::string data) : _data(data) {}
    virtual ~BaseDto() {}

    const std::string& GetStringifyData() const { return _data; }

   private:
    std::string _data;
};