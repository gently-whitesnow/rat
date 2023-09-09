#pragma once

#include <models/dto.h>

#include <string>

class ExampleData : public IDto {
   public:
    ExampleData(const std::string& exampleData) : IDto(exampleData){};
};