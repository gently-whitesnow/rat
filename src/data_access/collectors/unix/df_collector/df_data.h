#pragma once

#include <models/base_dto.h>

#include <string>

class DfData : public BaseDto {
   public:
    DfData(const std::string& dfData) : BaseDto(dfData){};
};