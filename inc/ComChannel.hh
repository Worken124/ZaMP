#ifndef ComChannel_HH
#define ComChannel_HH

#include <mutex>
#include <thread>

class ComChannel {
public:
    ComChannel();
    ~ComChannel();
private:
    std::mutex _guard;
};

#endif
