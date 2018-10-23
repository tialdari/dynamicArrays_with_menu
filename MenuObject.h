#ifndef MENUOBJECT_H
#define MENUOBJECT_H

using namespace std;

#define DEBUG true

class MenuObject{

  public:

    virtual void run() = 0;
    string getName(){return name;};
    string getCommand(){return command;};

  protected:
    MenuObject(string name, string command) : name(name), command(name) {}
    string name;
    string command;

  private:

};

#endif
