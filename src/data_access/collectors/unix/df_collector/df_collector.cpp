#include "df_collector.h"

#include <data_access/collectors/base_collector.h>
#include <models/base_dto.h>
#include <models/result.h>

#include <iostream>
#include <sstream>
#include <string>

#include "df_data.h"

DfCollector::DfCollector(uint32_t collectionSecondsInterval, const std::string& collectorName)
    : BaseCollector(collectionSecondsInterval, collectorName){};

DfCollector::DfCollector(uint32_t collectionSecondsInterval, const std::string& collectorName, const std::vector<std::string>&& discNames)
    : BaseCollector(collectionSecondsInterval, collectorName),
      _discNames(std::move(discNames)){};

Result<std::unique_ptr<BaseDto>> DfCollector::Collect() {
    auto outputResult = _systemExecutor.Execute(_command);
    if (!outputResult.IsSuccess()) {
        return Result<std::unique_ptr<BaseDto>>(outputResult.Status(),
                                             outputResult.ErrorMessage());
    }

    if (_discNames.empty()) {
        return Result<std::unique_ptr<BaseDto>>(
            std::make_unique<DfData>(outputResult.ReleaseValue()));
    }

    return Result<std::unique_ptr<BaseDto>>(std::make_unique<DfData>(
        GetFilteredString(outputResult.ReleaseValue())));
};

std::string DfCollector::GetFilteredString(const std::string& rawString) {
    std::string filteredString = rawString.substr(0, rawString.find('\n'));

    std::stringstream rawStringStream(rawString);
    std::string line;

    while (std::getline(rawStringStream, line)) {
        for (const std::string& discName : _discNames) {
            if (line.starts_with(discName)) {
                filteredString += "\n" + line;
            }
        }
    }

    return filteredString;
}
