#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "Set4LibInterfaces.hh"
#include "ProgramInterpreter.hh"
#include "Configuration.hh"

using namespace std;


int main(int argc, char *argv[])
{
    if (argc < 2) {
        cerr << "Błąd wywołania!" << endl;
        cerr << "./program  nazwa_pliku  ustawienia" << endl;
        return 1;
    }

    ProgramInterpreter program;

    //program.readFromFile(argv[1]);

    program.execProgram(argv[1]);

}


/*



*/