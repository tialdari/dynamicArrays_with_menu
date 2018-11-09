#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <regex>
#include <stdlib.h>

#define DEBUG true

using namespace std;

 static int findWords(char* stringMenu, int size, int startIndex, char symbol, string& resultString, bool &pSucc);
 static bool findMenu(char* stringMenu, int &index, int size, bool &pSucc);
 static void error(char missingSymbol, int index, char* text, int size);
 static bool findCommands(char* stringMenu, int &index, int size, bool &pSucc);




int main(){

  string testString = "('menu glowne','main';('Podmenu1','menu1';['Uruchom przegladarke','internet','otwiera przegladarke'],('Podmenu1','menu1';)),('Podmenu2','menu2';['Test','test','pomoc dla test'], ['Default command','defcom','pomoc dla test']),['Napisz „Ala ma kota”','ala','napis o Ali'])";
  int size = testString.length() + 1;
  char* testCharArr = new char [size];
  strcpy (testCharArr, testString.c_str());

  string menuTestString = "('Podmenu1','menu1';)"; //['Uruchom przegladarke','internet'])";
  int mSize = menuTestString.length() + 1;
  char* testMCharArr = new char [mSize];
  strcpy (testMCharArr, menuTestString.c_str());

  bool succes;
  int index = 0;
  index = findMenu(testMCharArr, index, size, succes);

  return 0;
}


static int findWords(char* stringMenu, int size, int startIndex, char symbol, string& resultString, bool &pSucc){

  resultString = "";
  char currentSymbol = stringMenu[++startIndex];
  string currentStringSymbol;

  while(currentSymbol != symbol){
    if(startIndex >= size){
      if(DEBUG) cout << "ERROR: index out of range " << missingSymbol << endl;
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



static bool findMenu(char* stringMenu, int &index, int size, bool &pSucc){

  string result = "";
  int symbolIndex = 0;
  char symbol;
  bool ifContinue = true;

  const char menuSymbols[] = {'(', '\'', 'w', '\'', ',', '\'', 'w', '\'', ';'};
  int symbolsSize = 9;

  const char endSymbols[] = {'(', '[', ')'};
  int endSymbolsSize = 3;


  while(ifContinue){
    if(menuSymbols[symbolIndex] == stringMenu[index]){
      cout << menuSymbols[symbolIndex] << " " ;
      symbolIndex++;
      index++;
    }else if(menuSymbols[symbolIndex] == 'w'){
      symbolIndex++;
      index = findWords(stringMenu, size, index, '\'', result, pSucc);
      cout << "menu'name: " << result << endl;
    }else if(symbolIndex >= symbolsSize){
      pSucc = false;
      symbolIndex = 0;
      while(symbolIndex < endSymbolsSize && pSucc != true){
        cout << "beginning of inner loop" << endl;

        if(stringMenu[index] == endSymbols[symbolIndex]){
          cout << "beginning of if " << endl;

            symbol = endSymbols[symbolIndex];
            switch(symbol){
              case '(':
                symbolIndex = 0;
                index = findMenu(stringMenu, index, size, pSucc);
                pSucc = true;
                break;

              case '[':
                //fingCommand;
                pSucc = true;
                break;

              case ')':
                ifContinue = false;
                if(DEBUG) cout << "menu read succesfully";
                pSucc = true;
                break;

              default:
                error(menuSymbols[symbolIndex], symbolIndex, stringMenu, size);
                pSucc = true;
              }
            }else {
              error(menuSymbols[symbolIndex], symbolIndex, stringMenu, size);
              pSucc = true;
            }
            break;

        }
        cout << "end of inner loop" << endl;

    }else{
      error(menuSymbols[symbolIndex], symbolIndex, stringMenu, size);
    }
  }
  cout << "end of main loop" << endl;
/*
  if(nextIndex != 0){
    cout << "index != 0 ";
    return false;
  }else{
    nextIndex2 = findWords(stringMenu, size, nextIndex, '\'', result, pSucc);
    if(!error('\'', nextIndex, nextIndex2, stringMenu, pSucc)) return false;

    nextIndex = findWords(stringMenu, size, nextIndex2, '\'', result, pSucc);
    cout << "menu name: " << result << endl;

    nextIndex2 = findWords(stringMenu, size, nextIndex, ',', result, pSucc);
    if(!error(',', nextIndex, nextIndex2, stringMenu, pSucc)) return false;

    nextIndex = findWords(stringMenu, size, nextIndex2, '\'', result, pSucc);
    if(!error('\'', nextIndex2, nextIndex, stringMenu, pSucc)) return false;

    nextIndex2 = findWords(stringMenu, size, nextIndex, '\'', result, pSucc);
    cout << "menu's command name: " << result << endl;

    nextIndex = findWords(stringMenu, size, nextIndex2, ';', result, pSucc);
    if(!error(';', nextIndex2, nextIndex, stringMenu, pSucc)) return false;


    char* permittedSymbols = new char[3];
    permittedSymbols[0] = '(';
    permittedSymbols[1] = '[';
    permittedSymbols[2] = ')';

    pSucc = false;
    int symbolIndex;
    char symb;

    for(int i = 0; i < 3; i++){
      nextIndex2 = findWords(stringMenu, size, nextIndex, permittedSymbols[i], result, pSucc);
      if(pSucc == true){
        symbolIndex = i;
        break;
      }
    }
    symb = permittedSymbols[symbolIndex];
    if(symb == '(') cout << "new child menu" << endl;
    else if (symb == '['){
        cout << "commands children" << endl;
        cout << "nextIndex2 before findCommand: " << nextIndex2 << endl;
      //  findCommands(stringMenu, size, pSucc, nextIndex2);
        cout << "end of menu index: " << nextIndex2 << endl;

    }
    else if(symb == ')') cout << "end of menu def" << endl;

    nextIndex = findWords(stringMenu, size, nextIndex2, ')', result, pSucc);
    if(!error(')', nextIndex2, nextIndex, stringMenu, pSucc)) return false;


    if(DEBUG) cout << "menu read succesfully";
    return true;
    */
    return false;
  }



static bool findCommands(char* stringMenu, int size, bool &pSucc, int &prevIndex){

  string result;
  int nextIndex;
  int nextIndex2;
  cout << "nextIndex: " << prevIndex << endl;


  nextIndex = findWords(stringMenu, size, prevIndex, '\'', result, pSucc);
  //if(!error('\'', prevIndex, nextIndex, stringMenu, pSucc)) return false;

  nextIndex2 = findWords(stringMenu, size, nextIndex, '\'', result, pSucc);
  if(DEBUG) cout << "command name: " << result << endl;

  pSucc = false;
  ++nextIndex2;
  if(stringMenu[nextIndex2] == ','){
    nextIndex = findCommands(stringMenu, size, pSucc, nextIndex2);
    prevIndex = nextIndex;

  }else if(stringMenu[nextIndex2] == ']'){
    prevIndex = nextIndex2;
    cout << "nextIndex2: " << nextIndex2 << endl;
    cout << "prevIndex: " << prevIndex << endl;
    cout << "leaving the method" << endl;

    return true;
  }else{
    //error(',', 0, 2, stringMenu, pSucc);
    cout << "or " << endl;
  //  error(']', 0, 2, stringMenu, pSucc);
  }
  return false;
}

static void error(char missingSymbol, int index, char* text, int size){

    if(DEBUG) cout << "ERROR: missing " << missingSymbol << endl;
    for(int i = 0; i < size; i++){
      if(i == index) cout << "_";
      else cout << text[i];
    } cout << endl;

}
