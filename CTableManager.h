#ifndef CTABLEMANAGER_H
#define CTABLEMANAGER_H

#include "CTable.h"

using namespace std;

#define DEBUG false
#define INITIAL_SIZE 10

class CTableManager
{
  public:
    CTableManager();
    ~CTableManager();

    CTable** getStorageArray();
    int getStorageSize();
    bool changeStorageSize(int newSize);

    bool createArrays(int ArrNum);
    bool setArrName(int arrIndx, string newName);
    bool setArrSize(int arrIndx, int newSize);
    bool setArrValue(int arrIndx, int cellNum, int value);
    string getArrInfo(int arrIndx);
    int getArrSize(int arrIndx);
    bool cloneArr(int arrIndx);
    bool deleteArray(int arrIndx);
    bool deleteAllArrays();

    bool indxControl(int index);
    int getInt();


  private:
    int size;
    CTable** pStorageArray;
};

#endif
