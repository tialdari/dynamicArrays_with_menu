#include <iostream>
#include "MenuObject.h"
#include "Menu.h"
#include "MenuCommand.h"
#include "Command.h"

using namespace std;


//    MenuCommand(string name, string command, Command* pCommand): MenuObject(name, command){};
//    MenuCommand(string name, string command, Command* pCommand): MenuObject(name, command){};




MenuCommand::~MenuCommand()
{
  if(DEBUG) cout << "deleting menu's command" << endl;
  delete pCommand;
}

void MenuCommand::run()
{
  if(DEBUG) cout << "menu command's run method is running" << endl;

  pCommand -> runCommand();
}
