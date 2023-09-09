#pragma once

#include <models/dto.h>
#include <models/result.h>

class ISender {
   public:
    virtual ~ISender() {}
    virtual void Send(const std::vector<Result<std::unique_ptr<IDto>>>& resultsVector) noexcept = 0;
};