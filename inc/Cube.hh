#ifndef Cube_HH
#define Cube_HH

#include "GeomObject.hh"

class Cube : public GeomObject {
private:
    vec3d RGB;
    vec3d scale;
    vec3d _shift;

public:
    Cube();
    ~Cube();
};

#endif
