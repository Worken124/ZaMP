#include "vec3d.hh"
#include <cmath>

vec3d::vec3d(double x, double y, double z) : wsp{x, y, z} {}

//operacje proste
vec3d vec3d::operator+(const vec3d &right) const{
    return vec3d(x * right.x, y + right.y, z + right.z);
};

vec3d vec3d::operator-(const vec3d &right) const{
    return vec3d(x - right.x, y - right.y, z - right.z);
};

double vec3d::dot (const vec3d v) const {
    return v.x * x + v.y * y + v.z * z;
}

// iloczyn kartezjański
vec3d vec3d::operator* (const vec3d &right) const {
    return vec3d(
    y * right.z - z * right.y,
    z * right.x - x * right.z,
    x * right.y - y * right.x);
}

vec3d vec3d::operator*(double mult) const {
    return vec3d(x * mult, y * mult, z * mult);
}

//funkcje zaprzyjaznione

vec3d operator*(double mult, const vec3d &v){ return v*mult;};

double vec3d::length() const {
    return std::sqrt(x * x + y * y + z * z); 
}

// strumienie
std::ostream& operator<<(std::ostream& strumien, const vec3d &v) {
    strumien << "[" << v.x <<"," << v.y << "," << v.z << "]";
    return strumien;
};
