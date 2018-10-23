#include <iostream>
#include "CTableManager.h"
#include "CTableManager.cpp"
#include "IO.h"
#include "CTableManagerCommands.h"
#include "Command.h"
#include "Command.cpp"




using namespace std;


  ChangeSize::ChangeSize(){
    if(DEBUG) cout << "new ChangeSize command";
  }

  ChangeSize::ChangeSize(CTableManager &cTableManager){ //pasamos por valor!!!
    if(DEBUG) cout << "new ChangeSize command with a cTableManager";
    this -> cTableManager = cTableManager;
  }

  ChangeSize::~ChangeSize(){
    if(DEBUG) cout << "deleting ChangeSize command";
  }

  bool ChangeSize::runCommand(){

    if(DEBUG) cout << "running ChangeSize command";

    cout << "Give the index of the array which size you want to change: "
         << endl;
    int arrIndx = io.getInt();

    cout << "give a new size: " << endl;
    int newSize = io.getInt();

    cTableManager.setArrSize(arrIndx, newSize);
    return true;
  }



  CreateArrays::CreateArrays(){
    if(DEBUG) cout << "new CreateArrays command";
  }

  CreateArrays::~CreateArrays(){
    if(DEBUG) cout << "deleting CreateArrays command";
  }

  CreateArrays::CreateArrays(CTableManager &cTableManager){
    if(DEBUG) cout << "new CreateArrays command with a cTableManager";
    this -> cTableManager = cTableManager;
  }

  bool CreateArrays::runCommand(){

    if(DEBUG) cout << "running CreateArrays command";
    cout << "Give a number of arrays to create: ";
    int arrNum = io.getInt();
    cTableManager.createArrays(arrNum);
    return true;
  }



  SetArrValue::SetArrValue(){
    if(DEBUG) cout << "new SetArrValue command";
  }

  SetArrValue::~SetArrValue(){
    if(DEBUG) cout << "deleting SetArrValue command";
  }

  SetArrValue::SetArrValue(CTableManager &cTableManager){
    if(DEBUG) cout << "new SetArrValue command with a cTableManager";
    this -> cTableManager = cTableManager;
  }

  bool SetArrValue::runCommand(){

    if(DEBUG) cout << "running SetArrValue command";
    int arrIndx;
    int innerIndx;
    int newValue;

    cout << "Give the index of the array ";
    cout << "which value you want to change: " << endl;
    arrIndx = io.getInt();

    cout << "Give the index inside the array: " << endl;
    innerIndx = io.getInt();

    cout << "Give the value: " << endl;
    newValue = io.getInt();

    cTableManager.setArrValue(arrIndx, innerIndx, newValue);
    return true;

  }



  DeleteArray::DeleteArray(){
    if(DEBUG) cout << "new DeleteArray command";
  }

  DeleteArray::~DeleteArray(){
    if(DEBUG) cout << "deleting DeleteArray command";
  }

  DeleteArray::DeleteArray(CTableManager &cTableManager){
    if(DEBUG) cout << "new DeleteArray command with a cTableManager";
    this -> cTableManager = cTableManager;
  }

  bool DeleteArray::runCommand(){

    if(DEBUG) cout << "running DeleteArray command";
    cout << "Give the index of the array which you want to delete: " << endl;
    int arrIndx = io.getInt();
    cTableManager.deleteArray(arrIndx);
    cout << "The array from the " << arrIndx << "index was deleted " << endl;
    return true;
  }



  DeleteAllArrays::DeleteAllArrays(){
    if(DEBUG) cout << "new DeleteAllArrays command";
  }

  DeleteAllArrays::~DeleteAllArrays(){
    if(DEBUG) cout << "deleting DeleteAllArrays command";
  }

  DeleteAllArrays::DeleteAllArrays(CTableManager &cTableManager){
    if(DEBUG) cout << "new DeleteAllArrays command with a cTableManager";
    this -> cTableManager = cTableManager;
  }

  bool DeleteAllArrays::runCommand(){

    if(DEBUG) cout << "running DeleteAllArrays command";
    cTableManager.deleteAllArrays();
    cout << "All arrays have been deleted " << endl;
    return true;
  }



  SetArrName::SetArrName(){
    if(DEBUG) cout << "new SetArrName command";
  }

  SetArrName::~SetArrName(){
    if(DEBUG) cout << "deleting SetArrName command";
  }

  SetArrName::SetArrName(CTableManager &cTableManager){
    if(DEBUG) cout << "new SetArrName command with a cTableManager";
    this -> cTableManager = cTableManager;
  }

  bool SetArrName::runCommand(){

    if(DEBUG) cout << "running SetArrName command";

    cout << "Give the index of the array which you want to rename: " << endl;
    int arrIndx = io.getInt();

    cout << "Give a name: " << endl;
    string newName = io.getString();

    cTableManager.setArrName(arrIndx, newName);
    return true;
  }



  GetArrInfo::GetArrInfo(){
      if(DEBUG) cout << "new GetArrInfo command";
    }

  GetArrInfo::~GetArrInfo(){
      if(DEBUG) cout << "deleting GetArrInfo command";
    }

  GetArrInfo::GetArrInfo(CTableManager &cTableManager){
      if(DEBUG) cout << "new GetArrInfo command with a cTableManager";
      this -> cTableManager = cTableManager;
    }

  bool GetArrInfo::runCommand(){

      if(DEBUG) cout << "running GetArrInfo command";

      cout << "Give the index of the array which info you want: " << endl;
      int arrIndx = io.getInt();
      cTableManager.getArrInfo(arrIndx);
      return true;
    }



  GetArrSize::GetArrSize(){
    if(DEBUG) cout << "new GetArrSize command";
  }

  GetArrSize::~GetArrSize(){
    if(DEBUG) cout << "deleting GetArrSize command";
  }

  GetArrSize::GetArrSize(CTableManager &cTableManager){
    if(DEBUG) cout << "new GetArrSize command with a cTableManager";
    this -> cTableManager = cTableManager;
  }

  bool GetArrSize::runCommand(){

    if(DEBUG) cout << "running GetArrSize command";

    cout << "Give the index of the array which size you want to know: " << endl;
    int arrIndx = io.getInt();
    cout << "The size of the array from the " << arrIndx << "index is "
         << cTableManager.getArrSize(arrIndx);
    return true;

  }




  SetArrSize::SetArrSize(){
    if(DEBUG) cout << "new SetArrSize command";
  }

  SetArrSize::~SetArrSize(){
    if(DEBUG) cout << "deleting SetArrSize command";
  }

  SetArrSize::SetArrSize(CTableManager &cTableManager){
    if(DEBUG) cout << "new SetArrSize command with a cTableManager";
    this -> cTableManager = cTableManager;
  }

  bool SetArrSize::runCommand(){

    if(DEBUG) cout << "running SetArrSize command";

    cout << "Give the index of the array which size you want to change: "
         << endl;
    int arrIndx = io.getInt();

    cout << "give a new size: " << endl;
    int newSize = io.getInt();

    cTableManager.setArrSize(arrIndx, newSize);
    return true;

  }


  CloneArr::CloneArr(){
    if(DEBUG) cout << "new CloneArr command";
  }

  CloneArr::~CloneArr(){
    if(DEBUG) cout << "deleting CloneArr command";
  }

  CloneArr::CloneArr(CTableManager &cTableManager){
    if(DEBUG) cout << "new CloneArr command with a cTableManager";
    this -> cTableManager = cTableManager;
  }

  bool CloneArr::runCommand(){

    if(DEBUG) cout << "running CloneArr command";

    cout << "Give the index of the array which you want to clone: " << endl;
    int arrIndx = io.getInt();
    cTableManager.cloneArr(arrIndx);

    return true;
  }
