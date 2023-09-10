#include "worker.h"

#include <data_access/collectors/base_collector.h>
#include <data_access/senders/sender.h>

#include <iostream>
#include <vector>

Worker::Worker(std::vector<std::unique_ptr<BaseCollector>>&& collectors, std::vector<std::unique_ptr<ISender>>&& senders)
    : _collectors(std::move(collectors)), _senders(std::move(senders)) {
    _models.reserve(collectors.size());
};

void Worker::Run() {
    while (true) {
        for (const auto& collectorPtr : _collectors) {
            auto dtoResult = collectorPtr->TryCollect();
            if (dtoResult.IsReady()) _models.emplace_back(std::move(dtoResult));
        }

        if (_models.size() == 0) continue;

        for (const auto& senderPtr : _senders) {
            senderPtr->Send(_models);
        }
        _models.clear();
    }
};
