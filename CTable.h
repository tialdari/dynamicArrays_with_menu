#ifndef CTABLE_H
#define CTABLE_H

using namespace std;

#define DEBUG false
#define INITIAL_SIZE 10
#define INITIAL_NAME "new array"

class CTable
{
   public:
     CTable();
     CTable(string sName, int iTableLen);
     CTable(CTable &sourceCTable);
     ~CTable();
     string getName();
     int getSize();
     int* getArray();
     void vSetName(string sName);
     bool changeSize(int newSize);
     bool setValue(int cellNumber, int value);
     int getValue(int cellNumber);
     CTable* clone();
     void copyParameters(CTable &sourceArray);
     string getInfo();
     string print();

   private:
     string s_name;
     int size;
     int* pArray;
};

#endif
