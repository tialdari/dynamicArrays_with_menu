#include<iostream>

using namespace std;

static int findWords(char* stringMenu, int size, int &startIndex, char symbol, string& resultString, bool &pSucc);
//static bool readMenu()

int main(){

  string testString = "('menu glowne','main';('Podmenu1','menu1';['Uruchom przegladarke','internet','otwiera przegladarke'],('Podmenu1','menu1';)),('Podmenu2','menu2';['Test','test','pomoc dla test'], ['Default command','defcom','pomoc dla test']),['Napisz „Ala ma kota”','ala','napis o Ali'])";
  int size = testString.length() + 1;
  char* testCharArr = new char [size];
  strcpy (testCharArr, testString.c_str());

  int index = 1;
  string result = "";
  bool succ = true;

  //readMenu();
  index = findWords(testCharArr, size, index, '\'', result, succ);



  return 0;
}


static int findWords(char* stringMenu, int size, int &startIndex, char symbol, string &resultString, bool &pSucc){

  resultString = "";
  char currentSymbol = stringMenu[++startIndex];
  string currentStringSymbol;

  while(currentSymbol != symbol){
    if(startIndex >= size){
      if(DEBUG) cout << "ERROR: index out of range" << endl;
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
