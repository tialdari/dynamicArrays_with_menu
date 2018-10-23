#ifndef MENUCOMMAND_H
#define MENUCOMMAND_H

#include "Command.h"


using namespace std;

#define DEBUG true


class MenuCommand: public MenuObject{

  public:
    MenuCommand(string name, string command, Command* pCommand)
    : MenuObject(name, command)
    {
      this -> pCommand = pCommand;
    };
    ~MenuCommand();
    void run();


  private:
    Command* pCommand;

};

#endif
//    B(int a, int b) : A(a,b){}
