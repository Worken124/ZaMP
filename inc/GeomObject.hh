#ifndef GeomObject_HH
#define GeomObject_HH

#include "vec3d.hh"
#include <mutex>
#include <string>

class GeomObject {
    private:
        std::string _name;

        vec3d _pos_m;
        vec3d _rot_deg;

    protected:
        mutable std::mutex _guard;

    public:
        GeomObject() : _pos_m(0,0,0), _rot_deg(0,0,0) {}
        virtual ~GeomObject() = default;

        GeomObject(const GeomObject &) = delete;
        GeomObject &operator=(const GeomObject &) = delete;


        
        std::string getName() const {return _name;}
        void setName(const std::string &new_name) {_name = new_name;}

        vec3d getPos_m() const {return _pos_m;}
        vec3d *usePos_m() {return &_pos_m;}

        vec3d getRot_deg() const {return _rot_deg;}
        vec3d *useRot_deg() {return &_rot_deg;}

        [[nodiscard]] std::unique_lock<std::mutex> lock() const { return std::unique_lock<std::mutex>(_guard); }
};

#endif
