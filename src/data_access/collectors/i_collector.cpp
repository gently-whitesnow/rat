#include "i_collector.h"

ICollector::ICollector(int collectionSecondsInterval) : _collectionSecondsInterval(collectionSecondsInterval) {
    _lastCollectionTime = std::chrono::system_clock::now() - std::chrono::seconds(_collectionSecondsInterval);
 };

bool ICollector::IsTimeToCollect(){
    auto currentTime = std::chrono::system_clock::now();
    auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - _lastCollectionTime).count();

    if (elapsedSeconds >= _collectionSecondsInterval) {
        return true;
    }
    return false;
}