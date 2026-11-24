#include "ComChannel.hh"

std::unique_lock<std::mutex> ComChannel::lock() const
{
    return std::unique_lock<std::mutex>(_guard);
}

ComChannel::ComChannel() {}

ComChannel::~ComChannel() {}
