#ifndef Cube_HH
#define Cube_HH

#include "GeomObject.hh"

class Cube : public GeomObject {
private:
    vec3d _RGB;
    vec3d _scale;
    vec3d _shift;

public:
    Cube();
    ~Cube() override;

    void setRGB(const vec3d &rgb) { _RGB = rgb; }
    void setScale(const vec3d &s) { _scale = s; }
    void setShift(const vec3d &sh) { _shift = sh; }

    vec3d getRGB()   const { return _RGB; }
    vec3d getScale() const { return _scale; }
    vec3d getShift() const { return _shift; }
};

#endif
