#pragma once

#include <string>

#include <models/i_dto.h>

class ExampleData : public IDto {
   public:
    ExampleData(int integerData) : _integerData(integerData){};

    std::string GetStringifyData() override {
        return std::to_string(_integerData);
    }

   private:
    int _integerData;
};