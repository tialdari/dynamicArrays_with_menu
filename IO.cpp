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
