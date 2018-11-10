#ifndef IO_H
#define IO_H

using namespace std;

#define DEBUG false

class IO{

  public:
    IO();
    ~IO();
    int getInt();
    string getString();
    void writeToFile(string fileName, string stringToWrite);
    string readFromFile(string fileName);
    void menuToString(Menu* menu);
    int readWord(char* stringMenu, int size, int &startIndex, string& resultString, bool &pSucc);
    bool readMenu(char* stringMenu, int size, int &startIndex, bool &pSucc);
    bool readChildren(char* stringMenu, int size, int &startIndex, char symbol, bool &pSucc);
    bool readCommand(char* stringMenu, int size, int &startIndex, bool &pSucc);
    void error(char missingSymbol, int index, char* text, int size);


};

#endif
