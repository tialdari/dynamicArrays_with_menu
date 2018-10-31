#ifndef MENUCOMMAND_H
#define MENUCOMMAND_H

#include "Command.h"


using namespace std;

#define DEBUG true


class MenuCommand: public MenuObject{

  public:
    MenuCommand(string name, string command, Command* pCommand, Menu* subMenu)
    : MenuObject(name, command)
    {
      this -> pCommand = pCommand;
      this -> subMenu = subMenu;
    };
    ~MenuCommand();

  //  Menu* getSubMenu(){return subMenu;};
    void run();
    void help(){pCommand -> description();};


  private:
    Command* pCommand;
    Menu* subMenu;

};

#endif
