#include <iostream>
#include <vector>
#include "MenuObject.h"
#include "Menu.h"
#include "MenuCommand.h"
#include "Command.h"
#include "IO.h"

using namespace std;

Menu::~Menu()
{
  cout << "deleting " << getName() << endl;
  cout << "deleting " << getName() << "'s objects" << endl;

  for(int i = 0; i < vMenuObjects.size(); i++)
  {
    cout << "deleting " << vMenuObjects[i] -> getName() << endl;
    delete vMenuObjects[i];
  }
}


MenuObject* Menu::getSubMenu()
{
  return subMenu;
}

void Menu::setvMenuObjects(vector<MenuObject*> newMenuObjects){
  this -> vMenuObjects = newMenuObjects;
}

void Menu::setSubmenu(Menu* subMenu)
{
  this -> subMenu = subMenu;
}

void Menu::addNewCommand(MenuObject* menuObj)
{

  //if the array doesn't already contain the object being added -> continue
  for(int i = 0; i < size; i++){
    if(vMenuObjects[i] == menuObj) {
      if(DEBUG){
         cout << "ERROR: the object you want to add ";
         cout << "is already in the array " << endl;
      }
      return;
    }
  }
  vMenuObjects.push_back(menuObj);
  size++;
  if (DEBUG) cout << "new command has been added to the " << name
                  << " at the index " << size - 1 << endl;

}

void Menu::deleteCommand(int index)
{
  if(index < 0){

    if (DEBUG) cout << "ERROR: cell number can't be less than 0" << endl;
    return;

  }else if (index >= size){

      if (DEBUG) {
        cout << "ERROR: index out of range " << endl;
      }
      return;

  }else{
    vMenuObjects.erase(vMenuObjects.begin() + index);
    if (DEBUG) cout << "the array cell no " << index
                    << " has been erased " << endl;
  }
}

void Menu::run()
{
  int commandIndex;

  while(true){

    cout << name << "(" << command << ")" << endl;

    menuItemsList();
    string commandName = getCommandName();
    if(builtInCommands(commandName) == true){}
    else if(commandName == "back") return;
    else{
      commandIndex = getCommandIndex(commandName);
      executeCommand(commandIndex);
    }
  }

}

void Menu::menuItemsList()
{
  int lastPos;
  for(int i = 0; i < size; i++){

    cout << " " << (i + 1) << ". ";
    cout << vMenuObjects[i] -> printSubmenu(vMenuObjects[i])
         << "(" << vMenuObjects[i] -> getCommand() << ")" << endl;
    lastPos = i + 2;
  }
  cout << " " << lastPos << ". Search(search)" << endl;
  cout << " " << lastPos + 1 << ". Help(help)" << endl;
  cout << " " << lastPos + 2 << ". Go back(back)" << endl;
}

string Menu::getCommandName(){

  IO io;
  return io.getString();
}

int Menu::getCommandIndex(string commandName)
{
  bool ifContinue = true;
  int commandNum;

  while(ifContinue)
  {
    for(int i = 0; i < size; i++){

      if(commandName == vMenuObjects[i] -> getCommand())
      {
        commandNum = i;
        return i;
      }
    }
    ifContinue = false;
     cout << "No such command! " << endl;
  }
  return -1;
}

void Menu::executeCommand(int commandIndex)
{
  if(commandIndex == -1){
    if (DEBUG) cout << "ERROR: no such command" << endl;
    return;

  }else if(commandIndex < 0){

    if (DEBUG) cout << "ERROR: cell number can't be less than 0" << endl;
    return;

  }else if(commandIndex >= size){

    if (DEBUG) cout << "ERROR: index out of range " << endl;
    return;

  }else vMenuObjects[commandIndex] -> run();

}

void Menu::search(string commandName){

  MenuObject* command;

  for(int i = 0; i < size; i++){

    command = vMenuObjects[i];
    if(command -> getCommand() == commandName){
      cout << printSubmenu(command) + "(" << command -> getCommand()
           << ")" << endl;
    }
    command -> search(commandName);
  }
}


bool Menu::builtInCommands(string expression){


    MenuObject* command;
    string commandName;

    for(int i = 0; i < size; i++){
      command = vMenuObjects[i];
      commandName = command -> getCommand();
      if(expression == "search " + commandName){
        search(commandName);
        return true;
      }else if(expression == "help " + commandName){
        command -> help();
        return true;
      }else if(expression == "back ") return true;
    }
    return false;
}

void Menu::menuToString(Menu* menu){


}

int Menu::readWord(char* stringMenu, int size, int &startIndex, string& resultString, bool &pSucc){
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

Menu* Menu::readMenu(char* stringMenu, int size, int &startIndex, bool &pSucc){

  Menu* menu = new Menu("test menu", "test_menu", NULL);

  const char menuSymbols[] = {'(', '\'', 'n', '\'', ',', '\'', 'c', '\'', ';'};
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

    }else if(symbol == 'n' || symbol == 'c'){

      startIndex--;
      startIndex = readWord(stringMenu, size, startIndex, name, pSucc);
      if(symbol == 'n'){
        menu -> setName(name);
      }else if(symbol == 'c'){
        menu -> setCommand(name);
      }
      if(pSucc == false){
        return menu;
      }else pSucc = false;

      cout << "name: " << name << endl;
      symbolIndex += 2;
      symbol = menuSymbols[symbolIndex];
      inputSymbol = stringMenu[++startIndex];

    }else{
      error(symbol, startIndex, stringMenu, size);
      pSucc = true;
      return menu;
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
         return menu;
       }
       inputSymbol = stringMenu[startIndex];
    }
  }

  if(inputSymbol != ')'){
    error(symbol, startIndex, stringMenu, size);
  }else{
    inputSymbol = stringMenu[++startIndex];
  }
  //menu -> setvMenuObjects(children);
  return menu;
}

MenuObject* Menu::readCommand(char* stringMenu, int size, int &startIndex, bool &pSucc){

  MenuObject* testCommand = new MenuCommand("testCommand", "test_ comm_n", NULL, new TestCommand());


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
      return testCommand;
    }else {
      error('s', startIndex, stringMenu, size);
      return testCommand;
    }
  }return testCommand;
}

bool Menu::readChildren(char* stringMenu, int size, int &startIndex, char symbol, bool &pSucc){

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

void Menu::error(char missingSymbol, int index, char* text, int size){

    cout << "ERROR: missing symbol at '_' " << endl;
    for(int i = 0; i < size; i++){
      if(i == index) cout << "_";
      else cout << text[i];
    } cout << "\n\n" ;

}
