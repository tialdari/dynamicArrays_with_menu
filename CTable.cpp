#include<iostream>
#include "CTable.h"
#include <string>
//#include <typeinfo>


using namespace std;

CTable::CTable()
{
  s_name = INITIAL_NAME;
  size = INITIAL_SIZE;
  pArray = new int[size];
  if (DEBUG) cout << "bezp: " << s_name << endl;
}

CTable::CTable(string sName, int iTableLen)
{
  s_name = sName;
  size = iTableLen;
  pArray = new int[size];
  if (DEBUG) cout << "parametr: " << s_name << endl;
}

CTable::CTable(CTable &sourceCTable)
{
  s_name = sourceCTable.getName() + "_copy";
  size = sourceCTable.getSize();
  pArray = new int[size];
  for (int i = 0; i < size; i++)
  {
    pArray[i] = sourceCTable.getArray()[i];
  }
  if (DEBUG) cout << "copy: " << s_name << endl;
}

CTable::~CTable()
{
  if (DEBUG) cout << "deleting " << s_name << endl;
  delete [] pArray;
}


string CTable::getName()
{
  return s_name;
}

void CTable::vSetName(string sName)
{
  s_name = sName;
  if (DEBUG) cout << "name changed to: " << sName <<  endl;
}

int CTable::getSize()
{
  return size;
}

int* CTable::getArray()
{
  return pArray;
}

bool CTable::changeSize(int newSize)
{
    if(newSize < 0)
    {
      if (DEBUG) cout << "ERROR: size cannot be less than 0 " << endl;
      return false;
    }

  size = newSize;
  int* pNewArray = new int[size];

  for(int i = 0; i < size; i++)
  {
    pNewArray[i] = pArray[i];
  }

  delete [] pArray;
  pArray = pNewArray;

  if (DEBUG) cout << "size changed to: " << size << endl;
  return true;
}

bool CTable::setValue(int cellNumber, int value)
{
  if(cellNumber < 0)
  {
    if (DEBUG) cout << "ERROR: cell size cannot be less than 0 " << endl;
    return false;
  }else if(cellNumber >= size)
  {
    if (DEBUG) cout << "ERROR: cell num out of range " << endl;
    return false;
  }

  pArray[cellNumber] = value; //index bigger or equal than array size exists?
  if (DEBUG) cout << "cell no " << cellNumber
                  << " = " << value << endl;
  return true;
}

int CTable::getValue(int cellNumber)
{
    if(cellNumber < 0)
    {
      if (DEBUG) cout << "ERROR: cell number can't be less than 0" << endl;
      return 0;
    }else if(cellNumber >= size)
    {
      if (DEBUG) cout << "ERROR: cell number out of range!" << endl;
      return 0;
    }
    return pArray[cellNumber];

}

CTable* CTable::clone() //+
{
  CTable *pCloneTable;
  pCloneTable = new CTable();
  pCloneTable -> changeSize(size);

  if (DEBUG) cout << "cloning values to the new object" << endl;

  for(int i = 0; i < size; i++)
  {
    pCloneTable -> setValue(i, pArray[i]);
  }

  if (DEBUG) cout << "returning the " << s_name << " clone " << endl;
  return pCloneTable;
}
//returning a variable declared inside a function
//will unable to use the variable outside??

void CTable::copyParameters(CTable &sourceArray)
{
  int copiedSize = sourceArray.getSize();
  changeSize(copiedSize);

  int* copiedArray = sourceArray.getArray();

  for(int i = 0; i < size; i++)
  {
      pArray[i] = copiedArray[i];//why can't I use the arrow op here?
  }

  if (DEBUG) cout << "copied succesfully" << endl;
}

string CTable::getInfo()
{
  return s_name + " len: " + to_string(size) + " values: " + print();
}

string CTable::print()
{
  string arrValues;
  int lastComaPos = size - 2;

  for(int i = 0; i < size; i++)
  {
    arrValues += to_string(pArray[i]);
    if(i <= lastComaPos){
      arrValues += ", ";
    }
  }
  return arrValues;
}
