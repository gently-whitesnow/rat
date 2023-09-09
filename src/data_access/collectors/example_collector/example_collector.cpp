#include "example_collector.h"

#include <models/dto.h>
#include <models/result.h>
#include <models/result_status.h>

#include <string>

#include "../collector.h"
#include "example_data.h"

ExampleCollector::ExampleCollector(int collectionSecondsInterval, std::string collectorName)
    : ICollector(collectionSecondsInterval, collectorName){};

Result<std::unique_ptr<IDto>> ExampleCollector::Collect() {
    return Result<std::unique_ptr<IDto>>(
        std::make_unique<ExampleData>("Example data"));
};
