#ifndef MENU_H
#define MENU_H


using namespace std;

#define DEBUG false

#include "MenuObject.h"
class Menu: public MenuObject{

  public:
    Menu(string name, string command, MenuObject* subMenu): MenuObject(name, command, subMenu)
    {
      size = vMenuObjects.size();
      this -> subMenu = subMenu;
      if(DEBUG) cout << "new menu, name: "  << name << ", "
                     << "command: " << command << ", "
                     << "size: " << size << endl;

    };
    ~Menu();

    int getSize(){return size;};

    MenuObject* getSubMenu();
    void setSubmenu(Menu* subMenu);

    void setpMenuObjListVal(int index, MenuObject* menuObj);
    void addNewCommand(MenuObject* menuObj);
    void deleteCommand(int index);

    void run();
    void menuItemsList();
    string getCommandName();
    int getCommandIndex(string commandName);
    void executeCommand(int commandIndex);
    void help(){cout << "no help\n" << endl;};
    void search(string commandName);
    bool builtInCommands(string expression);
    MenuObject* menuFromString(char [] charMenu);

  private:
    int size;
    int objectsNum;
    MenuObject* subMenu;
    vector<MenuObject*> vMenuObjects;


};

#endif
