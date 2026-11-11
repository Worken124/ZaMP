
#include "ProgramInterpreter.hh"


using namespace std;

void ProgramInterpreter::execCommands(std::istringstream &strumien)
{
    while (strumien) {
        string command;
        strumien >> command;
        cout << "Wykonuję komendę: " << command << endl;

        std::shared_ptr<LibInterface> currentCommandInt = set4LibInterfaces.findPlugin(command);
        if (!currentCommandInt) {
            cerr << "Nie znaleziono wtyczki dla komendy: " << command << endl;
            continue;
        }

        AbstractInterp4Command *currentCommand = currentCommandInt->CreateCmdInterp();
        cout << currentCommand << endl;
        currentCommand->PrintSyntax();              
        currentCommand->ReadParameters(strumien);
        
    }
}

bool ProgramInterpreter::execProgram(const char *filename)
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

    commandStream.str(outstream.str());

    execCommands(commandStream);

    return true;
}