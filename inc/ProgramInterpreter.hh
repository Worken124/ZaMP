#ifndef PROGRAMINTERPRETER_HH
#define PROGRAMINTERPRETER_HH


#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include "xmlinterp.hh"

#include "Set4LibInterfaces.hh"
#include "Scene.hh"
#include "ComChannel.hh"
#include "Configuration.hh"


#define PLUGIN_NAME__move "libInterp4Move.so"
#define PLUGIN_NAME__set "libInterp4Set.so"


class ProgramInterpreter {
    private:
        std::istringstream commandStream;
        Set4LibInterfaces set4LibInterfaces; 
        Scene scene;
        ComChannel channel;
        Configuration config;

        xercesc::DefaultHandler* _setFeatures(xercesc::SAX2XMLReader *pParser, Configuration &rConfig);
        bool _loadGrammar(xercesc::SAX2XMLReader *pParser, const char *sFileName);

        
        void _execCommands(std::istringstream &strumien);

    public:
        bool execProgram(const char* filename);
        bool readXML(const char* sFileName, Configuration &rConfig);

        ProgramInterpreter();
};






void readFromFile(const char* filename);


#endif