#pragma once

#include <models/dto.h>

class ISender {
   public:
    virtual ~ISender(){}
    virtual void Send(
        const std::vector<std::unique_ptr<IDto>>& dtoVectors) noexcept = 0;
};