#pragma once
#include <data_access/senders/sender.h>
#include <models/base_dto.h>
#include <models/result.h>

class ExampleSender : public ISender {
   public:
    ExampleSender();

    void Send(const std::vector<Result<std::unique_ptr<BaseDto>>>& resultsVector) noexcept override;
};