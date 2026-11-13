#ifndef Scene_HH
#define Scene_HH


#include <map>
#include <memory>

#include "GeomObject.hh"



class Scene : public std::map<std::string, std::shared_ptr<GeomObject>> {
public:
    bool addGeomObject(std::shared_ptr<GeomObject> newObject);
    std::shared_ptr<GeomObject> findGeomObject(const std::string &objectName);
};


#endif