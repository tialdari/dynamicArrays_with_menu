#ifndef CTABLEMANAGERCOMMANDS_H
#define CTABLEMANAGERCOMMANDS_H

#define DEBUG true


using namespace std;


class ChangeSize: public Command{

  public:
    ChangeSize();
    ChangeSize(CTableManager &cTableManager);
    ~ChangeSize();
    bool runCommand();

  private:
    CTableManager cTableManager;
    IO io;
};

class CreateArrays: public Command{

  public:
    CreateArrays();
    CreateArrays(CTableManager &cTableManager);
    ~CreateArrays();
    bool runCommand();

  private:
    CTableManager cTableManager;
    IO io;

};

class SetArrValue: public Command{

  public:
    SetArrValue();
    SetArrValue(CTableManager &cTableManager);
    ~SetArrValue();
    bool runCommand();

  private:
    CTableManager cTableManager;
    IO io;

};

class DeleteArray: public Command{

  public:
    DeleteArray();
    DeleteArray(CTableManager &cTableManager);
    ~DeleteArray();
    bool runCommand();

  private:
    CTableManager cTableManager;
    IO io;

};

class DeleteAllArrays: public Command{

  public:
    DeleteAllArrays();
    DeleteAllArrays(CTableManager &cTableManager);
    ~DeleteAllArrays();
    bool runCommand();

  private:
    CTableManager cTableManager;
    IO io;

};

class SetArrName: public Command{

  public:
    SetArrName();
    SetArrName(CTableManager &cTableManager);
    ~SetArrName();
    bool runCommand();

  private:
    CTableManager cTableManager;
    IO io;

};

class GetArrInfo: public Command{

  public:
    GetArrInfo();
    GetArrInfo(CTableManager &cTableManager);
    ~GetArrInfo();
    bool runCommand();

  private:
    CTableManager cTableManager;
    IO io;

};

class GetArrSize: public Command{

  public:
    GetArrSize();
    GetArrSize(CTableManager &cTableManager);
    ~GetArrSize();
    bool runCommand();

  private:
    CTableManager cTableManager;
    IO io;

};

class SetArrSize: public Command{

  public:
    SetArrSize();
    SetArrSize(CTableManager &cTableManager);
    ~SetArrSize();
    bool runCommand();

  private:
    CTableManager cTableManager;
    IO io;

};

class CloneArr: public Command{

  public:
    CloneArr();
    CloneArr(CTableManager &cTableManager);
    ~CloneArr();
    bool runCommand();

  private:
    CTableManager cTableManager;
    IO io;

};

#endif
