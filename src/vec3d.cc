#include "vec3d.hh"
#include <cmath>

vec3d::vec3d(double x, double y, double z) : wsp{x, y, z} {}

//operacje proste
vec3d vec3d::operator+(const vec3d &right) const{
    return vec3d(x + right.x, y + right.y, z + right.z);
};

vec3d &vec3d::operator+=(const vec3d &right) {
    x += right.x;
    y += right.y;
    z += right.z;
    return *this;
}

vec3d vec3d::operator-(const vec3d &right) const{
    return vec3d(x - right.x, y - right.y, z - right.z);
};

vec3d &vec3d::operator-=(const vec3d &right) {
    x -= right.x;
    y -= right.y;
    z -= right.z;
    return *this;
}

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
// operacje brzydkie, na kwaternionach lepiej

vec3d vec3d::rotRPY(const vec3d &rot_deg) const {
    constexpr double deg2rad = 3.14159265358979323846 / 180.0;

    const double cx = std::cos(rot_deg.x * deg2rad), sx = std::sin(rot_deg.x * deg2rad);
    const double cy = std::cos(rot_deg.y * deg2rad), sy = std::sin(rot_deg.y * deg2rad);
    const double cz = std::cos(rot_deg.z * deg2rad), sz = std::sin(rot_deg.z * deg2rad);

    const vec3d r0(cz * cy,  cz * sy * sx - sz * cx,  cz * sy * cx + sz * sx);
    const vec3d r1(sz * cy,  sz * sy * sx + cz * cx,  sz * sy * cx - cz * sx);
    const vec3d r2(   -sy,                 cy * sx,                 cy * cx);

    return vec3d(r0.dot(*this), r1.dot(*this), r2.dot(*this));
}

// funkcje zaprzyjaznione

vec3d operator*(double mult, const vec3d &v){ return v*mult;};

double vec3d::length() const {
    return std::sqrt(x * x + y * y + z * z); 
}

// strumienie

std::istream& operator>>(std::istream& strumien, vec3d &v) {
    strumien >> v.x >> v.y >> v.z;
    return strumien;
}

std::ostream& operator<<(std::ostream& strumien, const vec3d &v) {
    strumien << v.x << v.y << v.z;
    return strumien;
};

void vec3d::print() {
    std::cout << "[" << x <<"," << y << "," << z << "]";
    return;
};
