#pragma once

#include <models/base_dto.h>
#include <models/result.h>

class BaseCollector {
   public:
    BaseCollector(uint32_t collectionSecondsInterval, const std::string& collectorName);
    Result<std::unique_ptr<BaseDto>> TryCollect();

    virtual ~BaseCollector() {}

   private:
    bool IsTimeToCollect();
    std::chrono::time_point<std::chrono::system_clock> _lastCollectionTime;
    virtual Result<std::unique_ptr<BaseDto>> Collect() = 0;

   private:
    int _collectionSecondsInterval = 3600;
    std::string _collectorName;
};