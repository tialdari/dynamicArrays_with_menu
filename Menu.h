#ifndef MENU_H
#define MENU_H

using namespace std;

#define DEBUG true

class Menu: public MenuObject{

  public:
    Menu(string name, string command, Menu* subMenu): MenuObject(name, command)
    {
      size = vMenuObjects.size();
      this -> subMenu = subMenu;
      if(DEBUG) cout << "new menu, name: "  << name << ", "
                     << "command: " << command << ", "
                     << "size: " << size << endl;

    };
    ~Menu();

    //string printSubmenu(MenuObject* menuObj);
  //  Menu* getSubMenu();
    void setSubmenu(Menu* subMenu);

    void setpMenuObjListVal(int index, MenuObject* menuObj);
    void addNewCommand(MenuObject* menuObj);
    void deleteCommand(int index);

    void run();
    void menuItemsList();
    string getCommandName();
    int getCommandIndex(string commandName);
    void executeCommand(int commandIndex);
    void help(){cout << "no help :(";};




  private:
    int size;
    int objectsNum;
    Menu* subMenu;
    vector<MenuObject*> vMenuObjects;

};

#endif
