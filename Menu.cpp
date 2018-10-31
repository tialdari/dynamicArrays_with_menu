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

/*
string Menu::printSubmenu(MenuObject* menuObj)
{

  if(menuObj -> getSubMenu() == NULL) return menuObj -> getName() + " -> ";
  else menuObj -> getSubMenu() -> printSubmenu() + menuObj -> getName();
}


Menu* Menu::getSubMenu()
{
  return subMenu;
}
*/

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
    if(DEBUG) cout << "menu's run method is running" << endl;

    cout << name << "(" << command << ")" << endl;

    menuItemsList();
    cout << "Type a command's name(press the enter key at the end): ";
    string commandName = getCommandName();
    if(commandName == "back") return;
    if(commandName == "help"){
      commandName = getCommandName();
      commandIndex = getCommandIndex(commandName);
      vMenuObjects[commandIndex] -> help();
    }

    commandIndex = getCommandIndex(commandName);
    executeCommand(commandIndex);
  }
}

void Menu::menuItemsList()
{
  int lastPos;
  for(int i = 0; i < size; i++){

    cout << " " << (i + 1) << ". ";
    cout << vMenuObjects[i] -> getName()
         << "(" << vMenuObjects[i] -> getCommand() << ")" << endl;
    lastPos = i + 2;
  }
  cout << " " << lastPos << ". Help(help <command name>)" << endl;
  cout << " " << lastPos << ". Go back(back)" << endl;
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

      if (DEBUG) cout << "commandName: " << commandName
                      << " vMenuObjects[i] -> getCommand(): "
                      << vMenuObjects[i] -> getCommand() << endl;

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
