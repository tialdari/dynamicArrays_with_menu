#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <regex>
#include <stdlib.h>

#define DEBUG true;

using namespace std;


static int findWords(char* stringMenu, int size, int &startIndex, string& resultString, bool &pSucc);
static bool readMenu(char* stringMenu, int size, int &startIndex, bool &pSucc);
static void error(char missingSymbol, int index, char* text, int size);
static bool readChildren(char* stringMenu, int size, int &startIndex, char symbol, bool &pSucc);
static bool readCommand(char* stringMenu, int size, int &startIndex, bool &pSucc);




int main(){

  string testString = "('menu glowne','main';('Podmenu1','menu1';['Uruchom przegladarke','internet','otwiera przegladarke'],('Podmenu1','menu1';)),('Podmenu2','menu2';['Test','test','pomoc dla test'], ['Default command','defcom','pomoc dla test']),['Napisz „Ala ma kota”','ala','napis o Ali'])";
  int size = testString.length() + 1;
  char* testCharArr = new char [size];
  strcpy (testCharArr, testString.c_str());

  string testString2 = "('Podmenu1','menu1';['Uruchom przegladarke','internet','otwiera przegladarke']";
  int size2 = testString2.length() + 1;
  char* testCharArr2 = new char [size2];
  strcpy (testCharArr2, testString2.c_str());


  int index = 0;
  string result = "";
  bool succ = true;

  //readCommand(testCharArr2, size2, index, succ);
readChildren(testCharArr2, size2, index, '(', succ);
  //readMenu(testCharArr2, size2, index, succ);
//  index = findWords(testCharArr, size, index, '\'', result, succ);



  return 0;
}


static int findWords(char* stringMenu, int size, int &startIndex, string &resultString, bool &pSucc){

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
      //cout << "ERROR: index out of range" << endl;
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

  //readName()
  //readCommand()
  const char menuSymbols[] = {'(', '\'', 'w', '\'', ',', '\'', 'w', '\'', ';'};
  int mSymbolsSize = 9;

  const char endSymbols[] = {'(', '[', ')'};
  int endSymbolsSize = 3;

  pSucc = false;
  bool namesRead = pSucc;
  int symbolIndex = 0;
  char symbol = menuSymbols[symbolIndex];
  char inputSymbol = stringMenu[startIndex];
  string name;


  while(!namesRead){

    if(symbol == inputSymbol){
      //cout << "symbol: " << symbol << " inputSymbol: " << inputSymbol << endl;

      if(symbol == ';') {
        pSucc = true;
      }

      symbol = menuSymbols[++symbolIndex];
      inputSymbol = stringMenu[++startIndex];

    }else if(symbol == 'w'){

      startIndex--;
      startIndex = findWords(stringMenu, size, startIndex, name, pSucc);
      if(pSucc == false){
        cout << "wrong input!" << endl;
        return false;
      }else pSucc = false;

      cout << "name: " << name << endl;
      symbol = menuSymbols[++symbolIndex];
      symbol = menuSymbols[++symbolIndex];
      inputSymbol = stringMenu[++startIndex];

    }else{
      error(symbol, startIndex, stringMenu, size);
      pSucc = true;
    }
    namesRead = pSucc;
}

  pSucc = false;
  inputSymbol = stringMenu[startIndex];

  for(int i = 0; i < endSymbolsSize; i++){
    if(inputSymbol == endSymbols[i]){
      if(inputSymbol == endSymbols[2]){
        //cout << "menu read succesfully" << endl;
        return true;
      }
      //cout << "symbol for read Children: " << inputSymbol << endl;
      startIndex = readChildren(stringMenu, size, startIndex, inputSymbol, pSucc);
      if(pSucc == true) return true;
    }
  }
    error('[', startIndex, stringMenu, size);
    return false;


  //cout << "end of loop" << endl;
  //readChildren()

}


static bool readChildren(char* stringMenu, int size, int &startIndex, char symbol, bool &pSucc){

  pSucc = false;
  bool childrenRead = pSucc;
  //char symbol = menuSymbols[symbolIndex];
  char inputSymbol = stringMenu[startIndex];
  vector<char> usedSymbols;
  int vectorIndex = 0;


  while(!childrenRead){


    if(symbol == inputSymbol){


      //cout << "symbol for read Children inside read Chidlren: " << inputSymbol << endl;
      //cout << "symbol: " << symbol << endl;
      usedSymbols.push_back(symbol);
      switch(symbol){


        case '(':
          if(vectorIndex == 0 || usedSymbols[vectorIndex] == ','){
            startIndex = readMenu(stringMenu, size, startIndex, pSucc);
            vectorIndex++;
          }else {
          //  error(',', --startIndex, stringMenu, size);
            return false;
          }
          //static void error(char missingSymbol, int index, char* text, int size){

        break;

        case '[':
        //  cout << " reading commands in read children" << endl;
          if(vectorIndex == 0 || usedSymbols[vectorIndex] == ','){
            startIndex = readCommand(stringMenu, size, startIndex, pSucc);
            vectorIndex++;
          }else {
          //  cout << "startIndex: " << startIndex << endl;
            error(',', --startIndex, stringMenu, size);
            return false;
          }
        break;

        case ')':
          if(vectorIndex == 0 || usedSymbols[vectorIndex] == ')' ||
            usedSymbols[vectorIndex] == ']'){
              pSucc = true;
              return true;
          }else {
            error(')', --startIndex, stringMenu, size);
            return false;
          }
        break;

        case ',':
          if(vectorIndex == 0 || usedSymbols[vectorIndex] == ')' ||
            usedSymbols[vectorIndex] == ']'){
              startIndex = readChildren(stringMenu, size, startIndex, '(', pSucc);
              vectorIndex++;
          }else{
            error(')', --startIndex, stringMenu, size);
            return false;
          }
        break;
      }

    }else{
      error(symbol, startIndex, stringMenu, size);
      pSucc = true;
      return false;
    }
    childrenRead = pSucc;
  }
  return true;
}


static bool readCommand(char* stringMenu, int size, int &startIndex, bool &pSucc){

  char inputSymbol = stringMenu[++startIndex];
  pSucc = false;
  bool commandRead = pSucc;
  string result;

//cout << "reading command..." << endl;
//cout << "inputSymbol: " <<  inputSymbol << endl;

  while(!commandRead){
    if(inputSymbol == '\''){
      startIndex = findWords(stringMenu, size, startIndex, result, pSucc);
      cout << "commandName: " << result << endl;
      inputSymbol = stringMenu[++startIndex];
    }
    if(inputSymbol == ','){
      inputSymbol = stringMenu[++startIndex];
    }else if(inputSymbol == ']'){
      pSucc = true;
      return true;
    }else {
      error('s', startIndex, stringMenu, size);
      return false;
    }
  }return true;
}


static void error(char missingSymbol, int index, char* text, int size){

    cout << "ERROR: missing " << missingSymbol << endl;
    for(int i = 0; i < size; i++){
      if(i == index) cout << "_" << text[i];
      else cout << text[i];
    } cout << endl;

}
