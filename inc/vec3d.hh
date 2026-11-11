#ifndef VEC3D_HH
#define VEC3D_HH

#include <iostream>

class vec3d
{
public:
    union {
        struct { double x, y, z; };
        double wsp[3];
    };
    vec3d(double x, double y, double z);
    //~vec3d();

    //zapis/odczyt
    double& operator[] (int i) {return wsp[i];};

    //operacje proste
    vec3d operator+(const vec3d &right) const;
    vec3d operator-(const vec3d &right) const;


    //operacje zlozone
    vec3d operator*(const vec3d &right) const;
    vec3d operator*(double mult) const;
    double dot(const vec3d v) const;
    double length() const;
    friend vec3d operator*(double mult, const vec3d &v);
    friend std::ostream& operator<<(std::ostream& strumien, const vec3d &v);
};

#endif