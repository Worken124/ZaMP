#ifndef LIBINTERFACE_HH
#define LIBINTERFACE_HH

#include <map>
#include <string>
#include <dlfcn.h>

#include "AbstractInterp4Command.hh"

/*!
 * \file
 * \brief Klasa identyfikator wtyczki
 *
 *  Klasa podaje informacje o nazwie wtyczki, referencje do niej,
 */
class LibInterface {
    private:
        std::string _CmdName;
        void *_LibHandler = nullptr;
        AbstractInterp4Command *(*_pCreateInterp)(void) = nullptr;
    public:
        AbstractInterp4Command *CreateCmdInterp();
        bool init(const std::string &LibName);
        const std::string &getCmdName() const;
        LibInterface() = default;
        ~LibInterface() {if(_LibHandler) dlclose(_LibHandler);}

};

#endif