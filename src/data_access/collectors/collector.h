#pragma once

#include <models/dto.h>
#include <models/result.h>

#include <memory>
#include <chrono>

class ICollector {
   public:
    ICollector(int collectionSecondsInterval);
    virtual Result<std::unique_ptr<IDto>> Collect() = 0;

    virtual ~ICollector(){}

   protected:
    bool IsTimeToCollect();
    std::chrono::time_point<std::chrono::system_clock> _lastCollectionTime;

   private:
    int _collectionSecondsInterval = 3600;
};