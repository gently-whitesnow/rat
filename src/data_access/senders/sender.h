#pragma once

#include <models/dto.h>

#include <memory>
#include <vector>

class ISender {
   public:
    virtual ~ISender(){}
    virtual void Send(
        const std::vector<std::unique_ptr<IDto>>& dtoVectors) noexcept = 0;
};