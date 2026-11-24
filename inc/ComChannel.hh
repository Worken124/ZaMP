#ifndef ComChannel_HH
#define ComChannel_HH

#include <mutex>

class ComChannel {
public:
    ComChannel();
    ~ComChannel();

    [[nodiscard]] std::unique_lock<std::mutex> lock() const;

private:
    mutable std::mutex _guard;
};

#endif
