#ifndef PROGRAMINTERPRETER_HH
#define PROGRAMINTERPRETER_HH


#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>

#include "Set4LibInterfaces.hh"
#include "Scene.hh"


#define PLUGIN_NAME__move "libInterp4Move.so"
#define PLUGIN_NAME__set "libInterp4Set.so"


class ProgramInterpreter {
    private:
        std::istringstream commandStream;
        Set4LibInterfaces set4LibInterfaces; 
        Scene scene;

        void execCommands(std::istringstream &strumien);

    public:
        bool execProgram(const char* filename);
        bool readXML(const char* filename);

        ProgramInterpreter() { //TYMCZASOWO - NIE MA XML
            scene = Scene();
            set4LibInterfaces.addPlugin(PLUGIN_NAME__move);
            set4LibInterfaces.addPlugin(PLUGIN_NAME__set);
        };
};






void readFromFile(const char* filename);


#endif