#include <iostream>
#include "MenuObject.h"
#include "Menu.h"
#include "MenuCommand.h"
#include "Command.h"

using namespace std;


Menu::~Menu()
{
  if(DEBUG) cout << "deleting menu" << endl;
  vector<MenuObject*>().swap(vMenuObjects);
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
    commandIndex = getCommandIndex();
    if(commandIndex == -1) return;
    executeCommand(commandIndex);
  }
}

void Menu::menuItemsList()
{
  int lastPos;
  for(int i = 0; i < size; i++){

    cout << " " << (i + 1) << ". " << vMenuObjects[i] -> getName()
           << "(" << vMenuObjects[i] -> getCommand() << ")" << endl;
    lastPos = i + 2;
  }
  cout << " " << lastPos << ". Go back(back)" << endl;
}

string Menu::getCommandName(){

  string commandName;
  cout << "Type a command's name(press the enter key at the end): ";
  cin >> commandName;

  return commandName;
}

int Menu::getCommandIndex()
{
  string commandName;
  bool ifContinue = true;
  int commandNum = 0;

  while(ifContinue)
  {
    commandName = getCommandName();
    if(commandName == "back") return -1;

    for(int i = 0; i < 1; i++){

      if(commandName == vMenuObjects[i] -> getCommand())
      {
        commandNum = i;
        return i;
        ifContinue = false;
      }
      else cout << "No such command! " << endl;
    }
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
