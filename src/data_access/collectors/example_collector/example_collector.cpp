#include "../i_collector.h"
#include "example_collector.h"

#include <models/i_dto.h>
#include <models/result.h>
#include "example_data.h"

ExampleCollector::ExampleCollector(int collectionSecondsInterval)
    : ICollector(collectionSecondsInterval){};

Result<std::unique_ptr<IDto>> ExampleCollector::Collect() {
    if (!IsTimeToCollect()) {
        return Result<std::unique_ptr<IDto>>(false);
    }

    _lastCollectionTime = std::chrono::system_clock::now();

    return Result<std::unique_ptr<IDto>>(std::make_unique<ExampleData>(100));
};
