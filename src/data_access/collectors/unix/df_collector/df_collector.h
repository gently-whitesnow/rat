#pragma once
#include <data_access/collectors/base_collector.h>
#include <data_access/collectors/unix/system_executor.h>

#include <string>
#include <vector>

class DfCollector : public BaseCollector {
   public:
    DfCollector(uint32_t collectionSecondsInterval, const std::string& collectorName,
                const std::vector<std::string>&& discNames);

    DfCollector(uint32_t collectionSecondsInterval, const std::string& collectorName);

    Result<std::unique_ptr<BaseDto>> Collect() override;

   private:
    std::string GetFilteredString(const std::string& rawString);
    SystemExecutor _systemExecutor;
    std::string _command = "df -h";
    std::vector<std::string> _discNames;
};