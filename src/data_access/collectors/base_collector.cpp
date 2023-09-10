#include <data_access/collectors/base_collector.h>
#include <models/base_dto.h>

#include <string>

BaseCollector::BaseCollector(uint32_t collectionSecondsInterval, const std::string& collectorName)
    : _collectionSecondsInterval(collectionSecondsInterval), _collectorName(collectorName) {
    // for collecting data on initializing
    _lastCollectionTime = std::chrono::system_clock::now() - std::chrono::seconds(_collectionSecondsInterval);
};

bool BaseCollector::IsTimeToCollect() {
    auto currentTime = std::chrono::system_clock::now();
    auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - _lastCollectionTime).count();

    if (elapsedSeconds >= _collectionSecondsInterval) {
        return true;
    }
    return false;
}

Result<std::unique_ptr<BaseDto>> BaseCollector::TryCollect() {
    if (!IsTimeToCollect()) {
        return Result<std::unique_ptr<BaseDto>>(ResultStatus::NotReady);
    }

    _lastCollectionTime = std::chrono::system_clock::now();

    auto collectionResult = Collect();

    if (!collectionResult.IsSuccess()) {
        return Result<std::unique_ptr<BaseDto>>(collectionResult.Status(), _collectorName + ":\n" + collectionResult.ErrorMessage());
    }

    return Result<std::unique_ptr<BaseDto>>(std::make_unique<BaseDto>(
        _collectorName + ":\n" + collectionResult.ReleaseValue()->GetStringifyData()));
};