#include<iostream>

#define DEBUG true;

using namespace std;


static int findWords(char* stringMenu, int size, int &startIndex, char symbol, string& resultString, bool &pSucc);
static bool readMenu(char* stringMenu, int size, int &startIndex, bool &pSucc);


int main(){

  string testString = "('menu glowne','main';('Podmenu1','menu1';['Uruchom przegladarke','internet','otwiera przegladarke'],('Podmenu1','menu1';)),('Podmenu2','menu2';['Test','test','pomoc dla test'], ['Default command','defcom','pomoc dla test']),['Napisz „Ala ma kota”','ala','napis o Ali'])";
  int size = testString.length() + 1;
  char* testCharArr = new char [size];
  strcpy (testCharArr, testString.c_str());

  string testString2 = "('menu glowne','main';";
  int size2 = testString2.length() + 1;
  char* testCharArr2 = new char [size2];
  strcpy (testCharArr2, testString2.c_str());


  int index = 0;
  string result = "";
  bool succ = true;

  readMenu(testCharArr2, size2, index, succ);
//  index = findWords(testCharArr, size, index, '\'', result, succ);



  return 0;
}


static int findWords(char* stringMenu, int size, int &startIndex, char symbol, string &resultString, bool &pSucc){

  resultString = "";
  char currentSymbol = stringMenu[++startIndex];

  string currentStringSymbol;

  while(currentSymbol != symbol){
    if(startIndex >= size){
      cout << "ERROR: index out of range" << endl;
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

      if(symbol == ';') pSucc = true;
      symbol = menuSymbols[++symbolIndex];
      inputSymbol = stringMenu[++startIndex];

    }else if(symbol == 'w'){

      startIndex--;
      startIndex = findWords(stringMenu, size, startIndex, '\'', name, pSucc);
      cout << "name: " << name << endl;
      pSucc = false;
      symbol = menuSymbols[++symbolIndex];
      symbol = menuSymbols[++symbolIndex];
      inputSymbol = stringMenu[++startIndex];

    }else{
      cout << "ERROR: symbol not found" << endl;
      pSucc = true;
    }
    namesRead = pSucc;

  }
  cout << "end of loop" << endl;
  //readChildren()

  return true;
}

//static int findWords(char* stringMenu, int size, int &startIndex, char symbol, string &resultString, bool &pSucc){
