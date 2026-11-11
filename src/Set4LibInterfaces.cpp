#include "Set4LibInterfaces.hh"

bool Set4LibInterfaces::addPlugin(const std::string &libName)
{
    printf("\nDodawanie pluginu: %s\n", libName.c_str());

    std::shared_ptr<LibInterface> lib = std::make_shared<LibInterface>();
    lib->init(libName);

    if (!(*lib).init(libName)) {
        std::cerr << "Dodanie pluginu do zbioru nie powiodło się!" << std::endl;
        return false;
    }

    (*this)[(*lib).getCmdName()] = lib;

    return true;
}

std::shared_ptr<LibInterface> Set4LibInterfaces::findPlugin(const std::string &cmdName)
{
    //return this->find(cmdName) != this->end() ? (*this)[cmdName] : nullptr;
    iterator it = this->find(cmdName);
    return (it != this->end()) ? it->second : nullptr;
}