#ifndef Scene_HH
#define Scene_HH


#include <map>
#include <memory>

#include "AbstractGeomObject.hh"



class Scene : public std::map<std::string, std::shared_ptr<AbstractGeomObject>> {
public:
    bool addGeomObject(std::shared_ptr<AbstractGeomObject> newObject);
    std::shared_ptr<AbstractGeomObject> findGeomObject(const std::string &objectName);
};


#endif