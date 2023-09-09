#include "collector.h"

#include <models/dto.h>

#include <string>

ICollector::ICollector(int collectionSecondsInterval, std::string collectorName)
    : _collectionSecondsInterval(collectionSecondsInterval), _collectorName(collectorName) {
    _lastCollectionTime = std::chrono::system_clock::now() -
                          std::chrono::seconds(_collectionSecondsInterval);
};

bool ICollector::IsTimeToCollect() {
    auto currentTime = std::chrono::system_clock::now();
    auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(
                              currentTime - _lastCollectionTime)
                              .count();

    if (elapsedSeconds >= _collectionSecondsInterval) {
        return true;
    }
    return false;
}

Result<std::unique_ptr<IDto>> ICollector::TryCollect() {
    if (!IsTimeToCollect()) {
        return Result<std::unique_ptr<IDto>>(ResultStatus::NotReady);
    }

    _lastCollectionTime = std::chrono::system_clock::now();

    auto collectionResult = Collect();

    if (!collectionResult.IsSuccess()) {
        return Result<std::unique_ptr<IDto>>(
            collectionResult.Status(),
            _collectorName + ":\n" + collectionResult.ErrorMessage());
    }

    return Result<std::unique_ptr<IDto>>(std::make_unique<IDto>(
        _collectorName + ":\n" +
        collectionResult.ReleaseValue()->GetStringifyData()));
};