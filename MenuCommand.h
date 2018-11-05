#ifndef MENUCOMMAND_H
#define MENUCOMMAND_H

#include "Command.h"


using namespace std;

#define DEBUG false


class MenuCommand: public MenuObject{

  public:
    MenuCommand(string name, string command, MenuObject* subMenu, Command* pCommand)
    : MenuObject(name, command, subMenu)
    {
      this -> subMenu = subMenu;
      this -> pCommand = pCommand;
    };
    ~MenuCommand();

  //  Menu* getSubMenu(){return subMenu;};
    void run();
    void help(){pCommand -> description();};
    void search(string commandName){cout << "search command for a MenuCommand";};
    bool searchUp(string commandName){cout << "searchUp command for a MenuCommand"; return false;};
    bool searchHorizontal(string commandName){cout << "searchHorizontal command for a MenuCommand"; return false;};
    bool searchDown(string commandName){cout << "searchDown command for a MenuCommand";return false;};
    MenuObject* getSubMenu(){return subMenu;};

  private:
    Command* pCommand;
    MenuObject* subMenu;

};

#endif
