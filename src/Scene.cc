#include "Scene.hh"

Scene::Scene() {}

Scene::~Scene() {}

bool Scene::addGeomObject(std::shared_ptr<AbstractGeomObject> newObject) {
    printf("\nDodawanie objektu o nazwie: %s\n", newObject->getName());
    
    (*this)[newObject->getName()] = newObject;

    // Nie konieczne, ale może przydatne
    if (this->find(newObject->getName()) == this->end()) {
        std::cerr << "Dodanie objektu do zbioru nie powiodło się!" << std::endl;
        return false;
    }

    return true;
}

std::shared_ptr<AbstractGeomObject> Scene::findGeomObject(const std::string &objectName) {
    iterator it = this->find(objectName);
    return (it != this->end()) ? it->second : nullptr;
}