#ifndef AbstractGeomObject_HH
#define AbstractGeomObject_HH

#include "vec3d.hh"

class AbstractGeomObject {
private:
    vec3d pos_m;
    std::string name;

public:
    std::string getName() const {return name;};
    void setName(std::string new_name) {name = new_name;};
    std::string getPos_m() const {return name;};
    vec3d *usePos_m() {return &pos_m;};
};

#endif
