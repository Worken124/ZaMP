
#include "ProgramInterpreter.hh"


using namespace std;
using namespace xercesc;


DefaultHandler *ProgramInterpreter::_setFeatures(SAX2XMLReader *pParser, Configuration &rConfig)
{
   pParser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
   pParser->setFeature(XMLUni::fgSAX2CoreValidation, true);
   pParser->setFeature(XMLUni::fgXercesDynamic, false);
   pParser->setFeature(XMLUni::fgXercesSchema, true);
   pParser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);

   pParser->setFeature(XMLUni::fgXercesValidationErrorAsFatal, true);

   DefaultHandler* pHandler = new XMLInterp4Config(rConfig);
   pParser->setContentHandler(pHandler);
   pParser->setErrorHandler(pHandler);

   return pHandler;
}


bool ProgramInterpreter::_loadGrammar(SAX2XMLReader *pParser,const char* sFileName)
{
    try {
     
        if (!pParser->loadGrammar("config/config.xsd", xercesc::Grammar::SchemaGrammarType,true)) {
            cerr << "!!! Plik grammar/actions.xsd, '" << endl
                 << "!!! ktory zawiera opis gramatyki, nie moze zostac wczytany."
                 << endl;
            return false;
        }
        pParser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse,true);
        pParser->parse(sFileName);
    }
    catch (const XMLException& Exception) {
        char* sMessage = XMLString::transcode(Exception.getMessage());
        cerr << "Informacja o wyjatku: \n" << "   " << sMessage << "\n";
        XMLString::release(&sMessage);
        return false;
    }
    catch (const SAXParseException& Exception) {
        char* sMessage = XMLString::transcode(Exception.getMessage());
        char* sSystemId = xercesc::XMLString::transcode(Exception.getSystemId());

        cerr << "Blad! " << endl
             << "    Plik:  " << sSystemId << endl
             << "   Linia: " << Exception.getLineNumber() << endl
             << " Kolumna: " << Exception.getColumnNumber() << endl
             << " Informacja: " << sMessage 
             << endl;

        XMLString::release(&sMessage);
        XMLString::release(&sSystemId);
        return false;
   }
   catch (...) {
        cout << "Zgloszony zostal nieoczekiwany wyjatek!\n" ;
        return false;
   }

   return true;

}

void ProgramInterpreter::_execCommands(std::istringstream &strumien)
{
    string command;
    while (strumien >> command) {
        //cout << "Wykonuję komendę: " << command << endl;

        std::shared_ptr<LibInterface> currentCommandInt = set4LibInterfaces.findPlugin(command);
        if (!currentCommandInt) {
            cerr << "Nie znaleziono wtyczki dla komendy: " << command << endl;
            continue;
        }

        AbstractInterp4Command *currentCommand = currentCommandInt->CreateCmdInterp();
        //cout << currentCommand << endl;

        //currentCommand->PrintSyntax();              
        currentCommand->ReadParameters(strumien);
        currentCommand->ExecuteCmd(scene, &channel);

        delete currentCommand;
    }
}




static bool _loadFile(const char *filename, std::istringstream &stream)
{
    FILE *file = fopen(filename, "r");
    if (!file) {
        cerr << "Nie można otworzyć pliku: " << filename << endl;
        return false;
    }

    char buffer[256];
    std::ostringstream outstream;
    
    while(fgets(buffer, sizeof(buffer), file)){
        outstream << buffer;
    }
    fclose(file);

    stream.str(outstream.str());
    return true;
}

bool ProgramInterpreter::execProgram(int argc, char *argv[])
{   
    std::vector<std::thread> threads;

    for (int i = 1; i < argc; ++i) {
        const char *filename = argv[i];

        threads.emplace_back([this, filename] { // Majstersztyk lambd

            std::istringstream commandStream;
            
            if (!_loadFile(filename, commandStream)) return;
            _execCommands(commandStream);
        }        
        );
    }

    for (std::thread &thread: threads) {
        if(thread.joinable()) {
            thread.join();
        }
    }

    return true;
}

bool ProgramInterpreter::readXML(const char *sFileName, Configuration &rConfig)
{
    try {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cerr << "Error during initialization! :\n";
        cerr << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
        return false;
    }

    SAX2XMLReader* pParser = XMLReaderFactory::createXMLReader();
    DefaultHandler *pHandler = _setFeatures(pParser, rConfig);
    
    if (!_loadGrammar(pParser, sFileName)) return false;

    delete pParser;
    delete pHandler;
    return true;

}

ProgramInterpreter::ProgramInterpreter() { 
    //TYMCZASOWO - NIE MA XML
    //set4LibInterfaces.addPlugin(PLUGIN_NAME__move);
    //set4LibInterfaces.addPlugin(PLUGIN_NAME__set);

    
    readXML("config/config.xml", config);

    //Biblioteki
    for (const std::string &libName : config.getLibraries()) {
        set4LibInterfaces.addPlugin(libName);
    }

    //Figury
    for (const std::shared_ptr<GeomObject> obj : config.getObjects()) {
        scene.addGeomObject(obj);
    }
}


