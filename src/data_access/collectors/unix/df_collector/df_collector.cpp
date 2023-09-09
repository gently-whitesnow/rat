#include "df_collector.h"

#include <data_access/collectors/collector.h>
#include <models/dto.h>
#include <models/result.h>

#include <iostream>
#include <sstream>
#include <string>

#include "df_data.h"

DfCollector::DfCollector(int collectionSecondsInterval,
                         std::string collectorName)
    : ICollector(collectionSecondsInterval, collectorName){};

DfCollector::DfCollector(int collectionSecondsInterval,
                         std::string collectorName,
                         std::vector<std::string> discNames)
    : ICollector(collectionSecondsInterval, collectorName),
      _discNames(std::move(discNames)){};

Result<std::unique_ptr<IDto>> DfCollector::Collect() {
    auto outputResult = _systemExecutor.Execute(_command);
    if (!outputResult.IsSuccess()) {
        return Result<std::unique_ptr<IDto>>(outputResult.Status(),
                                             outputResult.ErrorMessage());
    }

    if (_discNames.empty()) {
        return Result<std::unique_ptr<IDto>>(
            std::make_unique<DfData>(outputResult.ReleaseValue()));
    }

    auto ans = GetFilteredString(outputResult.ReleaseValue());
    return Result<std::unique_ptr<IDto>>(std::make_unique<DfData>(ans));
};

std::string DfCollector::GetFilteredString(const std::string& rawString) {
    std::string filteredString = "";

    std::stringstream rawStringStream(rawString);

    std::string subStreamString = "";

    bool isFirstLine = true;
    while (std::getline(rawStringStream, subStreamString, '\n')) {
        for (const std::string& discName : _discNames) {
            if (isFirstLine) {
                filteredString += subStreamString;
                isFirstLine = false;
            }
            if (subStreamString.starts_with(discName)) {
                filteredString += "\n" + subStreamString;
            }
        }
    }

    return filteredString;
}
