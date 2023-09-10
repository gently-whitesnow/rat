#pragma once

#include <data_access/collectors/base_collector.h>
#include <data_access/senders/sender.h>
#include <models/base_dto.h>

#include <iostream>
#include <vector>

class Worker {
   public:
    Worker(std::vector<std::unique_ptr<BaseCollector>>&& collectors, std::vector<std::unique_ptr<ISender>>&& senders);

    void Run();

   private:
    std::vector<std::unique_ptr<BaseCollector>> _collectors;
    std::vector<std::unique_ptr<ISender>> _senders;
    std::vector<Result<std::unique_ptr<BaseDto>>> _models;
};