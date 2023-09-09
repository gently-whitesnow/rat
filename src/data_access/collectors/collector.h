#pragma once

#include <models/dto.h>
#include <models/result.h>

class ICollector {
   public:
    ICollector(int collectionSecondsInterval, std::string collectorName);
    Result<std::unique_ptr<IDto>> TryCollect();

    virtual ~ICollector() {}

   private:
    bool IsTimeToCollect();
    std::chrono::time_point<std::chrono::system_clock> _lastCollectionTime;
    virtual Result<std::unique_ptr<IDto>> Collect() = 0;

   private:
    int _collectionSecondsInterval = 3600;
    std::string _collectorName;
};