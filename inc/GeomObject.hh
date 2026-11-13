#ifndef GeomObject_HH
#define GeomObject_HH

#include "vec3d.hh"
#include <mutex>

class GeomObject {
private:
    vec3d _pos_m;
    std::string _name;
    std::mutex _guard;

public:
    std::string getName() const {return _name;};
    void setName(std::string new_name) {_name = new_name;};
    std::string getPos_m() const {return _name;};
    vec3d *usePos_m() {return &_pos_m;};
};

#endif
