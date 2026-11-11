#include "LibInterface.hh"  
#include <iostream>
#include <cstring>

using namespace std;

AbstractInterp4Command *LibInterface::CreateCmdInterp()
{
   return _pCreateInterp() ? _pCreateInterp() : nullptr;
}

bool LibInterface::init(const string &libName)
{
    _LibHandler = dlopen(libName.c_str(), RTLD_LAZY);
    if (!_LibHandler)
    {
        std::cerr << "!!! Brak wtyczki: " << libName << std::endl;
        return false;
    }

    void *pFun = dlsym(_LibHandler, "CreateCmdInterp");
    if (!pFun)
    {
        cerr << "!!! Nie znaleziono funkcji CreateCmd w " << libName << endl;
        return false;
    }
    _pCreateInterp = reinterpret_cast<AbstractInterp4Command *(*)(void)>(pFun);

    pFun = dlsym(_LibHandler, "GetCmdName");
    if (!pFun)
    {
        cerr << "!!! Nie znaleziono funkcji GetCmdName w " << libName << endl;
        return false;
    }
    const char *(*pGetCmdName)(void) = reinterpret_cast<const char *(*)(void)>(pFun);
    _CmdName = pGetCmdName();

    return true;
}

const std::string &LibInterface::getCmdName() const
{
    return _CmdName;
}

  /*
  
        std::string _CmdName;
        void *_LibHandler = nullptr;
        AbstractInterp4Command *(*InterpreterCommand)(void) = nullptr;





  void *pLibHnd_Move = dlopen(PLUGIN_NAME__move,RTLD_LAZY);
  AbstractInterp4Command *(*pCreateCmdInterp_Move)(void);
  void *pFun;

  if (pLibHnd_Move) {
    cout << endl
	 << ":)  Wtyczka \"" << PLUGIN_NAME__move << "\" zostala poprawnie zaladowana."
	 << endl;
  } else {
     cerr << "!!! Brak wtyczki: " PLUGIN_NAME__move << endl;
     return 1;
  }


  pFun = dlsym(pLibHnd_Move,"CreateCmdInterp");
  if (pFun) {
    cout  << ":)  Funkcja \"CreateCmdInterp\" zostala znaleziona we wtyczce "
	  << "\"" << PLUGIN_NAME__move << "\"." << endl;
  } else {
     cerr << "!!! Nie znaleziono funkcji CreateCmdInterp" << endl;
     return 1;
  }
  pCreateCmdInterp_Move = reinterpret_cast<AbstractInterp4Command* (*)(void)>(pFun);


  AbstractInterp4Command *pInterp = pCreateCmdInterp_Move();

  */