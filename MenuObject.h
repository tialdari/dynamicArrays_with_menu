#ifndef MENUOBJECT_H
#define MENUOBJECT_H


using namespace std;

#define DEBUG false

class MenuObject{

  public:
    virtual ~MenuObject(){};
    virtual void run() = 0;
    string getName(){return name;};
    string getCommand(){return command;};
    virtual void help() = 0;
    virtual string printSubmenu(MenuObject* menuObj){
      if(menuObj -> getSubMenu() == NULL) return menuObj -> getName();
      else return menuObj -> printSubmenu(menuObj -> getSubMenu())
                  + " -> " + menuObj -> getName();};
    virtual MenuObject* getSubMenu() = 0;
    virtual void search(string commmandName) = 0;
    virtual bool searchUp(string commandName) = 0;
    virtual bool searchHorizontal(string commandName) = 0;
    virtual bool searchDown(string commandName) = 0;


  protected:
    MenuObject(string name, string command, MenuObject* subMenu)
    : name(name), command(command), subMenu(subMenu) {}
    string name;
    string command;
    MenuObject* subMenu;

  private:

};

#endif
