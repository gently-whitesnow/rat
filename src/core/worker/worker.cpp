#include <iostream>
#include <vector>

#include <data_access/collectors/i_collector.h>
#include <data_access/senders/i_sender.h>

#include "worker.h"

Worker::Worker(std::vector<std::unique_ptr<ICollector>>&& collectors,
               std::vector<std::unique_ptr<ISender>>&& senders)
    : _collectors(std::move(collectors)), _senders(std::move(senders)) {
    _models = std::vector<std::unique_ptr<IDto>>(collectors.size());
};

void Worker::Run() {
    while (true) {
        for (const auto& collectorPtr : _collectors) {
            auto dtoResult = collectorPtr->Collect();
            if(dtoResult.IsSuccess()) _models.push_back(dtoResult.ReleaseValue());
        }

        if (_models.size() == 0) continue;

        for (const auto& senderPtr : _senders) {
            senderPtr->Send(_models);
        }
        _models.clear();
    }
};
