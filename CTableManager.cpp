#include<iostream>
#include <string>
#include "CTable.h"
#include "CTableManager.h"
#include "UserInterface.h"


using namespace std;

CTableManager::CTableManager()
{
  size = INITIAL_SIZE;
  pStorageArray = new CTable*[size];

  for(int i = 0; i < size; i ++)
  {
    pStorageArray[i] = new CTable();

  }
}

CTableManager::~CTableManager()
{
  delete [] pStorageArray;
  if (DEBUG) cout << "deleting cTableManager " << endl;
}

CTable** CTableManager::getStorageArray()
{
  return pStorageArray;
}

int CTableManager::getStorageSize()
{
  return size;
}

bool CTableManager::changeStorageSize(int newSize)
{
  if(newSize < 0)
  {
    if (DEBUG) cout << "ERROR: size cannot be less than 0 " << endl;
    return false;
  }

  size = newSize;
  CTable** pNewArray;
  pNewArray = new CTable*[size];

  for(int i = 0; i < size; i++)
  {
    pNewArray[i] = pStorageArray[i];
  }

  delete [] pStorageArray;
  pStorageArray = pNewArray;

  if (DEBUG) cout << "size changed to: " << size << endl;
  return true;
}

bool CTableManager::createArrays(int arrNum)
{
  if(arrNum < 0)
  {
    if (DEBUG) cout << "ERROR: number cannot be less than 0 " << endl;
    return false;
  }

  size += arrNum;

  changeStorageSize(size);

  if(DEBUG) cout << arrNum << " new arrays created " << endl;
  return true;
}

bool CTableManager::setArrValue(int arrIndx, int cellNum, int value)
{

  if(indxControl(arrIndx) == false) return false;

  CTable* chosenArr = pStorageArray[arrIndx];

  int arrSize = chosenArr -> getSize();

  string arrName = chosenArr -> getName();

  pStorageArray[arrIndx] -> getArray()[cellNum] = value;

  if (DEBUG) cout << "array index: " << arrIndx
                  << " -> cell value no: " << cellNum << " "
                  << "changed to: " << value << endl;
  return true;
}

bool CTableManager::deleteArray(int arrIndx)
{

  if(indxControl(arrIndx) == false) return false;

  size -= 1;
  CTable** newPStorageArray;
  newPStorageArray = new CTable*[size];
  int sndIndex = 0;

  for(int i = 0; i < size; i++)
  {
    if(i != arrIndx)
    {
      newPStorageArray[i] = pStorageArray[sndIndex];
      sndIndex++;
    }else
    {
      sndIndex++;
    }
  }

  delete [] pStorageArray;
  pStorageArray = newPStorageArray;

  if(DEBUG) cout << "deleting the array from the index " << arrIndx
                     << " " << endl;

  return true;
}

bool CTableManager::deleteAllArrays()
{
  size = 0;

  CTable** newPStorageArray;
  newPStorageArray = new CTable*[size];

  delete [] pStorageArray;

  pStorageArray = newPStorageArray;
  return true;

  if(DEBUG) cout << "deleting all the arrays from the storage " << endl;

}

bool CTableManager::setArrName(int arrIndx, string newName)
{
    if(indxControl(arrIndx) == false) return false;

    pStorageArray[arrIndx] -> vSetName(newName);
    return true;
}

string CTableManager::getArrInfo(int arrIndx)
{
    if(indxControl(arrIndx) == false) return "";

    cout << pStorageArray[arrIndx] -> getInfo() << endl;

    return pStorageArray[arrIndx] -> getInfo();
}

int CTableManager::getArrSize(int arrIndx)
{
  if(indxControl(arrIndx) == false) return 0;

  return pStorageArray[arrIndx] -> getSize();
}

bool CTableManager::setArrSize(int arrIndx, int newSize)
{
  if(indxControl(arrIndx) == false) return false;
  pStorageArray[arrIndx] -> changeSize(newSize);

  return true;
}

bool CTableManager::cloneArr(int arrIndx)
{
  if(indxControl(arrIndx) == false) return false;

  CTable* cloneArr = pStorageArray[arrIndx] -> clone();
  size += 1;
  setArrSize(arrIndx, size);
  pStorageArray[size - 1] = cloneArr;

  cout << "The array from the index " << arrIndx
       << "has been copied and added to the end of the table" << endl;

  return true;
}

bool CTableManager::indxControl(int index)
{
  if(index < 0 || index >= size)
  {
    if (DEBUG) cout << "ERROR: array index out of range! " << endl;
    return false;
  }else{
    return true;
  }
}

int CTableManager::getInt(){

  int someInt;

  while(!(cin >> someInt)){
      cout << "please, give a whole number: ";
      cin >> someInt;

      cin.clear();
      cin.ignore(10000, '\n');
  }

  return someInt;
}
