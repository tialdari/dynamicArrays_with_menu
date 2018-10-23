#ifndef MENU_H
#define MENU_H

using namespace std;

#define DEBUG true

class Menu: public MenuObject{

  public:
    Menu(string name, string command): MenuObject(name, command)
    {
      size = vMenuObjects.size();
      if(DEBUG) cout << "new menu, name: "  << name << ", "
                     << "command: " << command << ", "
                     << "size: " << size << endl;

    };
    ~Menu();

    void setpMenuObjListVal(int index, MenuObject* menuObj);
    void addNewCommand(MenuObject* menuObj);
    void deleteCommand(int index);

    void run();
    void menuItemsList();
    string getCommandName();
    int getCommandIndex();
    void executeCommand(int commandIndex);

  private:
    int size;
    int objectsNum;
    vector<MenuObject*> vMenuObjects;

};

#endif

// B() : A(0, 0){} // Calls A's constructor, initializing a and b in A to 0.
