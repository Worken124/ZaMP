#ifndef CONFIGURATION_HH
#define CONFIGURATION_HH

#include <list>
#include <string>

#include "GeomObject.hh"



class Configuration {
    private:
        std::list<std::string> libraries;
        std::list<GeomObject> objects;
        
    public:
        void addlibrary(const std::string &libName) {libraries.push_back(libName);};
        const std::list<std::string> &getLibraries() const {return libraries;};

        void addObject(const GeomObject &object) {objects.push_back(object);};
        const std::list<GeomObject> &getObjects() const {return objects;};
};



#endif