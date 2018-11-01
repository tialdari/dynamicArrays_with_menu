#ifndef COMMAND_H
#define COMMAND_H

using namespace std;

#define DEBUG false

class Command{

  public:
    Command();
    virtual bool runCommand();
    virtual void description(){cout << "default description";};

  private:


};

#endif
