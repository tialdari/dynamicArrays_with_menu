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

  protected:
    MenuObject(string name, string command) : name(name), command(command) {}
    string name;
    string command;

  private:

};

#endif
