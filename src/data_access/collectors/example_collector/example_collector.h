#pragma once
#include <data_access/collectors/collector.h>

class ExampleCollector : public ICollector {
   public:
    ExampleCollector(int collectionSecondsInterval, std::string collectorName);

    Result<std::unique_ptr<IDto>> Collect() override;
};