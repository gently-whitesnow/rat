#pragma once
#include <data_access/collectors/base_collector.h>

class ExampleCollector : public BaseCollector {
   public:
    ExampleCollector(uint32_t collectionSecondsInterval, const std::string& collectorName);

    Result<std::unique_ptr<BaseDto>> Collect() override;
};