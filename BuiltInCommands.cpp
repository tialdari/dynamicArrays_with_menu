#include <iostream>
#include "CTableManager.h"
#include "CTableManager.cpp"
#include "IO.h"
#include "Command.h"
#include "Command.cpp"
#include "Menu.h"

using namespace std;

Help::Help(){
  if(DEBUG) cout << "new Help command" << endl;
}

Help::Help(Menu* menu){
  this -> menu = menu;
  if(DEBUG) cout << "new Help command with menu" << endl;
}

Help::~Help(){
  if(DEBUG) cout << "deleting Help command" << endl;
}

bool Help::runCommand(){

  return true;
}
void description();
