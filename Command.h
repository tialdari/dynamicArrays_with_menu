#ifndef COMMAND_H
#define COMMAND_H

using namespace std;

#define DEBUG true

class Command{

  public:
    Command();
    virtual bool runCommand();

  private:

};

#endif