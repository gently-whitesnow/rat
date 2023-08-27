#pragma once
#include <models/i_dto.h>
#include <data_access/senders/i_sender.h>

class ExampleSender : public ISender {
   public:
    ExampleSender();

    void Send(const std::vector<std::unique_ptr<IDto>>& dtoVectors) noexcept override;
};