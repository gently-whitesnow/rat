#pragma once
#include <models/dto.h>
#include <data_access/senders/sender.h>

class ExampleSender : public ISender {
   public:
    ExampleSender();

    void Send(const std::vector<std::unique_ptr<IDto>>& dtoVectors) noexcept override;
};