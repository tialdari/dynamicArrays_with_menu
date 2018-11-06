#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <regex>
#include <stdlib.h>

#define DEBUG true

using namespace std;

 static int findWords(char* stringMenu, int size, int startIndex, char symbol, string& resultString);
 static bool findMenu(char* stringMenu, int size);
 static bool error(char missingSymbol, int fstIndex, int sndIndex, char* text);




int main(){

  string testString = "('menu glowne','main';('Podmenu1','menu1';['Uruchom przegladarke','internet','otwiera przegladarke'],('Podmenu1','menu1';)),('Podmenu2','menu2';['Test','test','pomoc dla test'], ['Default command','defcom','pomoc dla test']),['Napisz „Ala ma kota”','ala','napis o Ali'])";
  int size = testString.length() + 1;
  char* testCharArr = new char [size];
  strcpy (testCharArr, testString.c_str());

  string menuTestString = "('menu glowne','main')";
  int mSize = menuTestString.length() + 1;
  char* testMCharArr = new char [mSize];
  strcpy (testMCharArr, menuTestString.c_str());

  findMenu(testMCharArr, mSize);

  return 0;
}


static int findWords(char* stringMenu, int size, int startIndex, char symbol, string& resultString){

  resultString = "";
  char currentSymbol = stringMenu[++startIndex];
  string currentStringSymbol;

  while(currentSymbol != symbol){
    if(startIndex >= size){
      cout << "ERROR: index out of range" << endl;
      return startIndex;
    }
    currentStringSymbol = string(1, currentSymbol);
    resultString += currentStringSymbol;
    currentSymbol = stringMenu[++startIndex];
  }

  return startIndex;
}

static bool findMenu(char* stringMenu, int size){

  string result;
  int nextIndex = findWords(stringMenu, size, -1, '(', result);
  int nextIndex2;

  if(nextIndex != 0){
    cout << "index != 0 ";
    return false;
  }else{
    nextIndex2 = findWords(stringMenu, size, nextIndex, '\'', result);
    if(!error('\'', nextIndex, nextIndex2, stringMenu)) return false;

    nextIndex = findWords(stringMenu, size, nextIndex2, '\'', result);
    cout << "menu name: " << result << endl;

    nextIndex2 = findWords(stringMenu, size, nextIndex, ',', result);
    if(!error(',', nextIndex, nextIndex2, stringMenu)) return false;

    nextIndex = findWords(stringMenu, size, nextIndex2, '\'', result);
    if(!error('\'', nextIndex2, nextIndex, stringMenu)) return false;

    nextIndex2 = findWords(stringMenu, size, nextIndex, '\'', result);
    cout << "menu's command name: " << result << endl;

    nextIndex = findWords(stringMenu, size, nextIndex2, ';', result);
    if(!error(';', nextIndex2, nextIndex, stringMenu)) return false;

    nextIndex2 = findWords(stringMenu, size, nextIndex, ')', result);
    if(!error(')', nextIndex, nextIndex2, stringMenu)) return false;


    cout << "menu read succesfully";
    return true;
  }

}

static bool error(char missingSymbol, int fstIndex, int sndIndex, char* text){

  if(abs(fstIndex - sndIndex) != 1){
    if(DEBUG) cout << "ERROR: missing " << missingSymbol << endl;
    for(int i = 0; i < sndIndex; i++){
      cout << text[i];
    }
    cout << "_" << endl;
    return false;
  }
  return true;
}
