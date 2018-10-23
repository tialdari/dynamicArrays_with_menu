#ifndef USERINTERFACE_H
#define USERINTERFACE_H

using namespace std;

class UserInterface
{
  public:
    UserInterface();
    ~UserInterface();

    void options();
    int getOptionNum();
    bool execute(int optionNum);
    void confirm();
    void ifContinue(bool &ifContinue);
    int getInt();
    string getString();

  private:
    CTableManager *cTableManager;
};

#endif
