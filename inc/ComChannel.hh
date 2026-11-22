#ifndef ComChannel_HH
#define ComChannel_HH

#include <mutex>
#include <thread>

class ComChannel {
public:
    ComChannel();
    ~ComChannel();
private:
    mutable std::mutex _guard;
};

#endif
