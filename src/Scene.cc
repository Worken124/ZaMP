#include "Scene.hh"

bool Scene::addGeomObject(std::shared_ptr<GeomObject> newObject) {
    
    printf("\nDodawanie objektu o nazwie: %s\n", newObject->getName().c_str());
    
    (*this)[newObject->getName()] = newObject;

    // Nie konieczne, ale może przydatne
    if (this->find(newObject->getName()) == this->end()) {
        std::cerr << "Dodanie objektu do zbioru nie powiodło się!" << std::endl;
        return false;
    }

    return true;
}

std::shared_ptr<GeomObject> Scene::findGeomObject(const std::string &objectName) {
    iterator it = this->find(objectName);
    return (it != this->end()) ? it->second : nullptr;
}