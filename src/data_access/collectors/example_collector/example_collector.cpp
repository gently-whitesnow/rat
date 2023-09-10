#include "example_collector.h"

#include <data_access/collectors/base_collector.h>
#include <models/base_dto.h>
#include <models/result.h>
#include <models/result_status.h>

#include <string>

#include "example_data.h"

ExampleCollector::ExampleCollector(uint32_t collectionSecondsInterval, const std::string& collectorName)
    : BaseCollector(collectionSecondsInterval, collectorName){};

Result<std::unique_ptr<BaseDto>> ExampleCollector::Collect() {
    return Result<std::unique_ptr<BaseDto>>(
        std::make_unique<ExampleData>("Example data"));
};
