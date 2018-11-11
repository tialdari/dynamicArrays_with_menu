#ifndef CTABLEMANAGERCOMMANDS_H
#define CTABLEMANAGERCOMMANDS_H

#define DEBUG false


using namespace std;



class CreateArrays: public Command{

  public:
    CreateArrays();
    CreateArrays(CTableManager *cTableManager);
    ~CreateArrays();
    bool runCommand();

  private:
    CTableManager* cTableManager;
    IO io;

};

class SetArrValue: public Command{

  public:
    SetArrValue();
    SetArrValue(CTableManager *cTableManager);
    ~SetArrValue();
    bool runCommand();
    void description();

  private:
    CTableManager* cTableManager;
    IO io;

};

class DeleteArray: public Command{

  public:
    DeleteArray();
    DeleteArray(CTableManager *cTableManager);
    ~DeleteArray();
    bool runCommand();
    void description();


  private:
    CTableManager* cTableManager;
    IO io;

};

class DeleteAllArrays: public Command{

  public:
    DeleteAllArrays();
    DeleteAllArrays(CTableManager *cTableManager);
    ~DeleteAllArrays();
    bool runCommand();
    void description();


  private:
    CTableManager* cTableManager;
    IO io;

};

class SetArrName: public Command{

  public:
    SetArrName();
    SetArrName(CTableManager *cTableManager);
    ~SetArrName();
    bool runCommand();
    void description();


  private:
    CTableManager* cTableManager;
    IO io;

};

class GetArrInfo: public Command{

  public:
    GetArrInfo();
    GetArrInfo(CTableManager *cTableManager);
    ~GetArrInfo();
    bool runCommand();
    void description();


  private:
    CTableManager* cTableManager;
    IO io;

};

class GetArrSize: public Command{

  public:
    GetArrSize();
    GetArrSize(CTableManager *cTableManager);
    ~GetArrSize();
    bool runCommand();
    void description();


  private:
    CTableManager* cTableManager;
    IO io;

};

class SetArrSize: public Command{

  public:
    SetArrSize();
    SetArrSize(CTableManager *cTableManager);
    ~SetArrSize();
    bool runCommand();
    void description();


  private:
    CTableManager* cTableManager;
    IO io;

};

class CloneArr: public Command{

  public:
    CloneArr();
    CloneArr(CTableManager *cTableManager);
    ~CloneArr();
    bool runCommand();
    void description();


  private:
    CTableManager* cTableManager;
    IO io;

};

#endif
