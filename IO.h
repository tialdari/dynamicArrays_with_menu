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

};

#endif
