#pragma once

#include <models/dto.h>

#include <string>

class DfData : public IDto {
   public:
    DfData(const std::string& dfData) : IDto(dfData){};
};