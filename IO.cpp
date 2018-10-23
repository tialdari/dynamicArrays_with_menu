#include <iostream>
#include "IO.h"


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
  cout << "please, write a name ";
  cin >> someString;

  cin.clear();
  cin.ignore(10000, '\n');

  return someString;
}
