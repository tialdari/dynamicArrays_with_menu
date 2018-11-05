#include <iostream>
#include <vector>
#include "MenuObject.h"
#include "Menu.h"
#include "MenuCommand.h"
#include "Command.h"

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
    cout << "Type a command's name(press the enter key at the end): ";
    string commandName = getCommandName();
    if(commandName == "back") return;
    else if(commandName == "search"){
      cout << "command name: ";
      commandName = getCommandName();
      search(commandName);
    }
    else if(commandName == "help"){
      cout << "command name: ";
      commandName = getCommandName();
      commandIndex = getCommandIndex(commandName);
      vMenuObjects[commandIndex] -> help();
    }else {
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
  cout << " " << lastPos + 1 << ". Go back(back)" << endl;
}

string Menu::getCommandName(){

  string commandName;
  cin >> commandName;
  return commandName;
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
        ifContinue = false;
      }
    }
     cout << "No such command! " << endl;
  }
  return 0;
}

void Menu::executeCommand(int commandIndex)
{
  if(commandIndex < 0){

    if (DEBUG) cout << "ERROR: cell number can't be less than 0" << endl;
    return;

  }else if(commandIndex >= size){

    if (DEBUG) cout << "ERROR: index out of range " << endl;
    return;

  }else vMenuObjects[commandIndex] -> run();

}

void Menu::search(string commandName){

   bool downSearch = searchDown(commandName);
   bool upSearch = searchUp(commandName);

   if(downSearch == false && upSearch == false){
       cout << "no such command " << endl;
    }
}

bool Menu::searchUp(string commandName){
    if(subMenu != NULL){
      if(subMenu -> searchDown(commandName) == true) return true;
      else return subMenu -> searchUp(commandName);
    }else return false;
  }


bool Menu::searchHorizontal(string commandName){
  for(int i = 0; i < size; i++){

    if(vMenuObjects[i] -> getCommand() == commandName){
      vMenuObjects[i] -> printSubmenu(vMenuObjects[i] -> getSubMenu());
      if (DEBUG) cout << "command found!" << endl;
      return true;
    }
  }return false;
}

bool Menu::searchDown(string commandName){
  for(int i = 0; i < size; i++){
    if(vMenuObjects[i] -> searchHorizontal(commandName) == true) return true;
  }
  for(int i = 0; i < size; i++){
    if(vMenuObjects[i] -> searchDown(commandName) == true) return true;
  }
  return false;
}
