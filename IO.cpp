#include <iostream>
#include "IO.h"
#include<fstream>
#include<iostream>


IO::IO()
{
}

IO::~IO()
{
  if(DEBUG) cout << "deleting IO" << endl;
}

int IO::getInt(){

  int someInt;

  while(!(cin >> someInt)){
      cout << "please, give a whole number: ";
      cin >> someInt;

      cin.clear();
      cin.ignore(10000, '\n');
  }

  return someInt;
}

string IO::getString(){

  string someString;
  cout << "Type a command's name(press the enter key at the end): ";
  getline(cin, someString);

  cin.clear();
  cin.ignore(10000, '\n');

  return someString;
}

void IO::writeToFile(string fileName, string stringToWrite){

  fstream file;
  file.open(fileName, ios::out|ios::app);
  file << stringToWrite;
}

string IO::readFromFile(string fileName){

  fstream file;
  file.open(fileName, ios::in);

  if(file.good() == false){
    cout << "file doesn't exist!";
    exit(0);
  }

  string line;
  string resultString = "";

  while(getline(file, line)){
    resultString += line;
  }
  file.close();

  return resultString;
}

void IO::menuToString(Menu* menu){


}

int IO::readWord(char* stringMenu, int size, int &startIndex, string& resultString, bool &pSucc){
  resultString = "";
  char currentSymbol = stringMenu[++startIndex];

  const char baseSymbols[] = {'(', ')', '[', ']', ';',','};
  int baseSymbolsSize = 6;
  char symbol = '\'';

  string currentStringSymbol;

  while(currentSymbol != symbol){
    for(int i = 0; i < baseSymbolsSize; i++){
      if(baseSymbols[i] == currentSymbol){
        error('\'', startIndex, stringMenu, size);
        pSucc = false;
        return startIndex;
      }
    }
    if(startIndex >= size){
      pSucc = false;
      return startIndex;
    }
    currentStringSymbol = string(1, currentSymbol);
    resultString += currentStringSymbol;
    currentSymbol = stringMenu[++startIndex];
  }

  pSucc = true;

  return startIndex;
}

bool IO::readMenu(char* stringMenu, int size, int &startIndex, bool &pSucc){

  const char menuSymbols[] = {'(', '\'', 'w', '\'', ',', '\'', 'w', '\'', ';'};
  int mSymbolsSize = 9;

  const char endSymbols[] = {'(', '['};
  int endSymbolsSize = 2;

  pSucc = false;
  bool namesRead = pSucc;
  int symbolIndex = 0;
  char symbol = menuSymbols[symbolIndex];
  char inputSymbol = stringMenu[startIndex];
  string name;

  while(!namesRead){

    if(symbol == inputSymbol){

      if(symbol == ';') {
        pSucc = true;
      }

      symbol = menuSymbols[++symbolIndex];
      inputSymbol = stringMenu[++startIndex];

    }else if(symbol == 'w'){

      startIndex--;
      startIndex = readWord(stringMenu, size, startIndex, name, pSucc);
      if(pSucc == false){
        return false;
      }else pSucc = false;

      cout << "name: " << name << endl;
      symbolIndex += 2;
      symbol = menuSymbols[symbolIndex];
      inputSymbol = stringMenu[++startIndex];

    }else{
      error(symbol, startIndex, stringMenu, size);
      return false;
      pSucc = true;
    }
    namesRead = pSucc;
}

  pSucc = false;
  inputSymbol = stringMenu[startIndex];


  for(int i = 0; i < endSymbolsSize; i++){
    if(inputSymbol == endSymbols[i]){
       readChildren(stringMenu, size, startIndex, inputSymbol, pSucc);
       if(pSucc == false){
         error(')', startIndex, stringMenu, size);
         return false;
       }
       inputSymbol = stringMenu[startIndex];
    }
  }

  if(inputSymbol != ')'){
    error(symbol, startIndex, stringMenu, size);

    return false;
  }else{
    inputSymbol = stringMenu[++startIndex];
    return true;
  }
}

bool IO::readCommand(char* stringMenu, int size, int &startIndex, bool &pSucc){

  char inputSymbol = stringMenu[++startIndex];
  pSucc = false;
  bool commandRead = pSucc;
  string result;

  while(!commandRead){
    if(inputSymbol == '\''){
      startIndex = readWord(stringMenu, size, startIndex, result, pSucc);
      cout << "commandName: " << result << endl;
      inputSymbol = stringMenu[++startIndex];
    }
    if(inputSymbol == ','){
      inputSymbol = stringMenu[++startIndex];
    }else if(inputSymbol == ']'){
      ++startIndex;
      inputSymbol = stringMenu[startIndex];
      pSucc = true;
      return true;
    }else {
      error('s', startIndex, stringMenu, size);
      return false;
    }
  }return true;
}

bool IO::readChildren(char* stringMenu, int size, int &startIndex, char symbol, bool &pSucc){

  bool success = false;

    while(!success){

      switch(symbol){
        case '[':
          readCommand(stringMenu, size, startIndex, pSucc);
        break;

        case '(':
          readMenu(stringMenu, size, startIndex, pSucc);
        break;

        case ',':
          startIndex++;
        break;

        case ')':
          success = true;
        break;

        default:
          success = true;
          pSucc = false;
          return false;
      }
      symbol = stringMenu[startIndex];
  }

  pSucc = true;
  return true;
}

void IO::error(char missingSymbol, int index, char* text, int size){

    cout << "ERROR: missing symbol at '_' " << endl;
    for(int i = 0; i < size; i++){
      if(i == index) cout << "_";
      else cout << text[i];
    } cout << "\n\n" ;

}
