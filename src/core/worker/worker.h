#pragma once

#include <iostream>

#include <data_access/collectors/i_collector.h>
#include <data_access/senders/i_sender.h>
#include <models/i_dto.h>

class Worker {
   public:
    Worker(std::vector<std::unique_ptr<ICollector>>&& collectors,
           std::vector<std::unique_ptr<ISender>>&& senders);

    void Run();

   private:
    std::vector<std::unique_ptr<ICollector>> _collectors;
    std::vector<std::unique_ptr<ISender>> _senders;
    std::vector<std::unique_ptr<IDto>> _models;
};