#pragma once

#include <models/base_dto.h>
#include <models/result.h>

class ISender {
   public:
    virtual ~ISender() {}
    virtual void Send(const std::vector<Result<std::unique_ptr<BaseDto>>>& resultsVector) noexcept = 0;
};