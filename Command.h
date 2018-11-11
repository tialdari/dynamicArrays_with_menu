#ifndef COMMAND_H
#define COMMAND_H

using namespace std;

#define DEBUG false

class Command{

  public:
    Command();
    virtual bool runCommand();
    virtual void description(){cout << "default description";};

};

class TestCommand : public Command{

  public:
    TestCommand(){
      if(DEBUG) cout << "new testCommand command" << endl;
    }
    ~TestCommand(){
      if(DEBUG) cout << "deleting testCommand" << endl;
    }
    bool runCommand(){
      cout << "test command running" << endl;
      return true;
    }
    void description(){
      cout << "test command's description" << endl;
    }

};

#endif
