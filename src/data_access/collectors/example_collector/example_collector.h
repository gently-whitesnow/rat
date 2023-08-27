#pragma once
#include <data_access/collectors/i_collector.h>

class ExampleCollector : public ICollector {
   public:
    ExampleCollector(int collectionSecondsInterval);

    Result<std::unique_ptr<IDto>> Collect() override;
};