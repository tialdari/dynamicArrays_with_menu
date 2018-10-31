#include <iostream>
#include "CTableManager.h"
#include "CTableManager.cpp"
#include "IO.h"
#include "CTableManagerCommands.h"
#include "Command.h"
#include "Command.cpp"




using namespace std;


  CreateArrays::CreateArrays(){
    if(DEBUG) cout << "new CreateArrays command" << endl;
  }

  CreateArrays::~CreateArrays(){
    if(DEBUG) cout << "deleting CreateArrays command" << endl;
  }

  CreateArrays::CreateArrays(CTableManager *cTableManager){
    if(DEBUG) cout << "new CreateArrays command with a cTableManager" << endl;
    this -> cTableManager = cTableManager;
  }

  bool CreateArrays::runCommand(){

    if(DEBUG) cout << "running CreateArrays command" << endl;
    cout << "Give a number of arrays to create: " << endl;
    int arrNum = io.getInt();
    cTableManager -> createArrays(arrNum);
    return true;
  }

  void CreateArrays::description(){
    cout << "Creates given number of new array" << endl;
  }



  SetArrValue::SetArrValue(){
    if(DEBUG) cout << "new SetArrValue command" << endl;
  }

  SetArrValue::~SetArrValue(){
    if(DEBUG) cout << "deleting SetArrValue command" << endl;
  }

  SetArrValue::SetArrValue(CTableManager *cTableManager){
    if(DEBUG) cout << "new SetArrValue command with a cTableManager" << endl;
    this -> cTableManager = cTableManager;
  }

  bool SetArrValue::runCommand(){

    if(DEBUG) cout << "running SetArrValue command" << endl;
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

    cTableManager -> setArrValue(arrIndx, innerIndx, newValue);
    return true;

  }

  void SetArrValue::description(){
    cout << "Changes value of the given cell ";
    cout << "of the given array to the given value" << endl;
  }




  DeleteArray::DeleteArray(){
    if(DEBUG) cout << "new DeleteArray command" << endl;
  }

  DeleteArray::~DeleteArray(){
    if(DEBUG) cout << "deleting DeleteArray command" << endl;
  }

  DeleteArray::DeleteArray(CTableManager *cTableManager){
    if(DEBUG) cout << "new DeleteArray command with a cTableManager" << endl;
    this -> cTableManager = cTableManager;
  }

  bool DeleteArray::runCommand(){

    if(DEBUG) cout << "running DeleteArray command" << endl;
    cout << "Give the index of the array which you want to delete: ";
    int arrIndx = io.getInt();
    cTableManager -> deleteArray(arrIndx);
    cout << "The array from the " << arrIndx << " index has been deleted " << endl;
    return true;
  }

  void DeleteArray::description(){
    cout << "Deletes the chosen array" << endl;
  }



  DeleteAllArrays::DeleteAllArrays(){
    if(DEBUG) cout << "new DeleteAllArrays command" << endl;
  }

  DeleteAllArrays::~DeleteAllArrays(){
    if(DEBUG) cout << "deleting DeleteAllArrays command" << endl;
  }

  DeleteAllArrays::DeleteAllArrays(CTableManager *cTableManager){
    if(DEBUG) cout << "new DeleteAllArrays command with a cTableManager" << endl;
  }

  bool DeleteAllArrays::runCommand(){

    if(DEBUG) cout << "running DeleteAllArrays command" << endl;
    cTableManager -> deleteAllArrays();
    cout << "All arrays have been deleted " << endl;
    return true;
  }

  void DeleteAllArrays::description(){
    cout << "Deletes all arrays" << endl;
  }




  SetArrName::SetArrName(){
    if(DEBUG) cout << "new SetArrName command" << endl;
  }

  SetArrName::~SetArrName(){
    if(DEBUG) cout << "deleting SetArrName command" << endl;
  }

  SetArrName::SetArrName(CTableManager *cTableManager){
    if(DEBUG) cout << "new SetArrName command with a cTableManager" << endl;
    this -> cTableManager = cTableManager;
  }

  bool SetArrName::runCommand(){

    if(DEBUG) cout << "running SetArrName command" << endl;

    cout << "Give the index of the array which you want to rename: " << endl;
    int arrIndx = io.getInt();

    cout << "Give a name: " << endl;
    string newName = io.getString();

    cTableManager -> setArrName(arrIndx, newName);
    return true;
  }

  void SetArrName::description(){
    cout << "Sets the current name of a given array to the given name" << endl;
  }



  GetArrInfo::GetArrInfo(){
      if(DEBUG) cout << "new GetArrInfo command" << endl;
    }

  GetArrInfo::~GetArrInfo(){
      if(DEBUG) cout << "deleting GetArrInfo command" << endl;
    }

  GetArrInfo::GetArrInfo(CTableManager *cTableManager){
      if(DEBUG) cout << "new GetArrInfo command with a cTableManager" << endl;
      this -> cTableManager = cTableManager;
    }

  bool GetArrInfo::runCommand(){

      if(DEBUG) cout << "running GetArrInfo command" << endl;

      cout << "Give the index of the array which info you want: " << endl;
      int arrIndx = io.getInt();
      cTableManager -> getArrInfo(arrIndx);
      return true;
    }

  void GetArrInfo::description(){
      cout << "Given the parameters of the array of a given index" << endl;
  }




  GetArrSize::GetArrSize(){
    if(DEBUG) cout << "new GetArrSize command" << endl;
  }

  GetArrSize::~GetArrSize(){
    if(DEBUG) cout << "deleting GetArrSize command"<< endl;
  }

  GetArrSize::GetArrSize(CTableManager *cTableManager){
    if(DEBUG) cout << "new GetArrSize command with a cTableManager" << endl;
    this -> cTableManager = cTableManager;
  }

  bool GetArrSize::runCommand(){

    if(DEBUG) cout << "running GetArrSize command" << endl;

    cout << "Give the index of the array which size you want to know: " << endl;
    int arrIndx = io.getInt();
    cout << "The size of the array from the " << arrIndx << "index is "
         << cTableManager -> getArrSize(arrIndx);
    return true;

  }

  void GetArrSize::description(){
    cout << "Gives the size of the array of the given index" << endl;
  }





  SetArrSize::SetArrSize(){
    if(DEBUG) cout << "new SetArrSize command" << endl;
  }

  SetArrSize::~SetArrSize(){
    if(DEBUG) cout << "deleting SetArrSize command" << endl;
  }

  SetArrSize::SetArrSize(CTableManager *cTableManager){
    if(DEBUG) cout << "new SetArrSize command with a cTableManager" << endl;
    this -> cTableManager = cTableManager;
  }

  bool SetArrSize::runCommand(){

    if(DEBUG) cout << "running SetArrSize command" << endl;

    cout << "Give the index of the array which size you want to change: "
         << endl;
    int arrIndx = io.getInt();

    cout << "give a new size: " << endl;
    int newSize = io.getInt();

    cTableManager -> setArrSize(arrIndx, newSize);
    return true;

  }

  void SetArrSize::description(){
    cout << "Changes the current size of the given array ";
    cout << "to the given size" << endl;
  }



  CloneArr::CloneArr(){
    if(DEBUG) cout << "new CloneArr command" << endl;
  }

  CloneArr::~CloneArr(){
    if(DEBUG) cout << "deleting CloneArr command" << endl;
  }

  CloneArr::CloneArr(CTableManager *cTableManager){
    if(DEBUG) cout << "new CloneArr command with a cTableManager" << endl;
    this -> cTableManager = cTableManager;
  }

  bool CloneArr::runCommand(){

    if(DEBUG) cout << "running CloneArr command" << endl;

    cout << "Give the index of the array which you want to clone: " << endl;
    int arrIndx = io.getInt();
    cTableManager -> cloneArr(arrIndx);

    return true;
  }

  void CloneArr::description(){
    cout << "Clones the chosen array ";
    cout << "and adds it at the end of the storage" << endl;
  }
