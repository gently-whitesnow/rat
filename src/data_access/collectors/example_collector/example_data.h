#pragma once

#include <models/base_dto.h>

#include <string>

class ExampleData : public BaseDto {
   public:
    ExampleData(const std::string& exampleData) : BaseDto(exampleData){};
};