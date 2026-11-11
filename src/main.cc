#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "Set4LibInterfaces.hh"
#include "ProgramInterpreter.hh"

using namespace std;


int main(int argc, char *argv[])
{
    ProgramInterpreter program;

    if (argc < 2) {
        cerr << "Błąd wywołania!" << endl;
        cerr << "./program  nazwa_pliku  ustawienia" << endl;
        return 1;
    }
    //program.readFromFile(argv[1]);
    program.execProgram(argv[1]);

}


/*



*/