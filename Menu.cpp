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
