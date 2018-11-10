#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <regex>
#include <stdlib.h>

#define DEBUG true;

using namespace std;


static int readWord(char* stringMenu, int size, int &startIndex, string& resultString, bool &pSucc);
static bool readMenu(char* stringMenu, int size, int &startIndex, bool &pSucc);
static void error(char missingSymbol, int index, char* text, int size);
static bool readChildren(char* stringMenu, int size, int &startIndex, char symbol, bool &pSucc);
static bool readCommand(char* stringMenu, int size, int &startIndex, bool &pSucc);

int main(){

  string testString = "('menu glowne','main';('Podmenu1','menu1';['Uruchom przegladarke','internet','otwiera przegladarke'],('Podmenu1','menu1';)),('Podmenu2','menu2';['Test','test','pomoc dla test'],['Default command','defcom','pomoc dla test']),['Napisz „Ala ma kota”','ala','napis o Ali'])";
  int size = testString.length() + 1;
  char* testCharArr = new char [size];
  strcpy (testCharArr, testString.c_str());

  string testString2 = "('Podmenu1','menu1';['Uruchom przegladarke','internet','otwiera przegladarke'],('Podmenu1','menu1';)))";
  int size2 = testString2.length() + 1;
  char* testCharArr2 = new char [size2];
  strcpy (testCharArr2, testString2.c_str());

  string testString3 = "['Uruchom przegladarke','internet','otwiera przegladarke']";
  int size3 = testString3.length() + 1;
  char* testCharArr3 = new char [size3];
  strcpy (testCharArr3, testString3.c_str());

  string testString4 = "('Podmenu1','menu1';)";
  int size4 = testString4.length() + 1;
  char* testCharArr4 = new char [size];
  strcpy (testCharArr4, testString4.c_str());


  int index2 = 0;
  int index3 = 0;
  int index4 = 0;

  string result = "";
  bool succ = true;

  readMenu(testCharArr, size, index2, succ);
/*
  readWord(testCharArr2, size2, index2, result, succ);
  cout << "word: " << result << endl;
  readCommand(testCharArr3, size3, index3, succ);
  */

  return 0;
}


static int readWord(char* stringMenu, int size, int &startIndex, string &resultString, bool &pSucc){

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

static bool readMenu(char* stringMenu, int size, int &startIndex, bool &pSucc){

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

//  cout << "inputSymbol: " << inputSymbol << endl;
  if(inputSymbol != ')'){
//    cout << "menu error" << endl;
    error(symbol, startIndex, stringMenu, size);

    return false;
  }else{
    //cout << "menu read succesfully" << endl;
    inputSymbol = stringMenu[++startIndex];
    return true;
  }
}

static bool readCommand(char* stringMenu, int size, int &startIndex, bool &pSucc){

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

static bool readChildren(char* stringMenu, int size, int &startIndex, char symbol, bool &pSucc){

//  cout << "readChildren... " << endl;
  bool success = false;

    //symbol is to be sure that the input symbol is the one from string menu and nothing more
//    stringMenu symbols are to follow next symbols, so at the beginning or end of each loop
  //  it's obligatory to go to the next stringMenu symbol
  //  if the input symbol doesn't match any of the cases return false with an error

    while(!success){

      switch(symbol){
        case '[':
          readCommand(stringMenu, size, startIndex, pSucc);
          //cout << "commands read succesfully" << endl;
        break;

        case '(':
          readMenu(stringMenu, size, startIndex, pSucc);
        //  cout << "menu read succesfully" << endl;
        break;

        case ',':
          //cout << "next child" << endl;
          startIndex++;
        break;

        case ')':
        //  cout << "children read succesfully" << endl;
          success = true;
        break;

        default:
        //  error(symbol, startIndex, stringMenu, pSucc);
          success = true;
          pSucc = false;
          return false;
      }
      symbol = stringMenu[startIndex];
    //  cout << "startIndex: " << startIndex << endl;
    //  cout << "symbol: " << symbol << endl;
  }

//  cout << "children read succesfully" << endl;
  pSucc = true;
  return true;
}

static void error(char missingSymbol, int index, char* text, int size){

    cout << "ERROR: missing symbol at '_' " << endl;
    for(int i = 0; i < size; i++){
      if(i == index) cout << "_";
      else cout << text[i];
    } cout << "\n\n" ;

}
