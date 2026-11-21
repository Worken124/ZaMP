#ifndef GeomObject_HH
#define GeomObject_HH

#include "vec3d.hh"
#include <mutex>
#include <string>

class GeomObject {
    private:
        std::string _name;
        std::mutex _guard;

        vec3d _pos_m;
        vec3d _rot_deg;

    public:
        std::string getName() const {return _name;};
        void setName(std::string new_name) {_name = new_name;};
        vec3d getPos_m() const {return _pos_m;};
        vec3d *usePos_m() {return &_pos_m;};
        //virtual ~GeomObject() = default;
};

#endif
