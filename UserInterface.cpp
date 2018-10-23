#include<iostream>
#include <string>
#include "UserInterface.h"
#include "CTableManager.h"

using namespace std;

UserInterface::UserInterface()
{
  cTableManager = new CTableManager();
}

UserInterface::~UserInterface()
{

}

void UserInterface::options()
{
  cout << "                                       \n";
  cout << "Choose one of the following options:   \n";
  cout << "                                       \n";
  cout << "1. Create the given number of array/s  \n";
  cout << "2. Get an array size                   \n";
  cout << "3. Delete an array                     \n";
  cout << "4. Delete all arrays                   \n";
  cout << "5. Rename an array                     \n";
  cout << "6. Clone an array                      \n";
  cout << "7. Get an array info                   \n";
  cout << "8. Change an array given cell value    \n";
  cout << "9. Change an array size                \n";

}

int UserInterface::getOptionNum()
{
  int optionNum;
  cout << "\nGive an option num: ";
  optionNum = getInt();

  while(optionNum > 9 || optionNum <= 0)
  {
    cout << "no such option, choose a num from 1 to 9";
    optionNum = getInt();
    cout << endl;
  }

  return optionNum;
}

bool UserInterface::execute(int optionNum)
{
  int arrIndx;
  string newName;
  int arrNum;

  switch(optionNum)
  {
  case 1:
    cout << "Give a number of arrays to create: ";
    arrNum = getInt();
    cTableManager -> createArrays(arrNum);
    confirm();
    return true;
  break;

  case 2:
    cout << "Give the index of the array which size you want to know: " << endl;
         arrIndx = getInt();
    cout << "The size of the array from the " << arrIndx << "index is "
         << cTableManager -> getArrSize(arrIndx);
    confirm();
    return true;
  break;

  case 3:
    cout << "Give the index of the array which you want to delete: " << endl;
    arrIndx = getInt();
    cTableManager -> deleteArray(arrIndx);
    cout << "The array from the " << arrIndx << "index was deleted " << endl;
    return true;

  break;

  case 4:
    cTableManager -> deleteAllArrays();
    cout << "All arrays have been deleted " << endl;
    return true;

  break;

  case 5:
    cout << "Give the index of the array which you want to rename: " << endl;
    arrIndx = getInt();

    cout << "Give a name: " << endl;
    newName = getString();

    cTableManager -> setArrName(arrIndx, newName);
    confirm();
    return true;

  break;

  case 6:
    cout << "Give the index of the array which you want to clone: " << endl;
    arrIndx = getInt();

    cTableManager -> cloneArr(arrIndx);
    confirm();
    return true;

  break;

  case 7:
    cout << "Give the index of the array which info you want: " << endl;
    arrIndx = getInt();
    cTableManager -> getArrInfo(arrIndx);
    return true;

  break;

  case 8:
    int innerIndx;
    int newValue;

    cout << "Give the index of the array ";
    cout << "which value you want to change: " << endl;
    arrIndx = getInt();

    cout << "Give the index inside the array: " << endl;
    innerIndx = getInt();

    cout << "Give the value: " << endl;
    newValue = getInt();

    cTableManager -> setArrValue(arrIndx, innerIndx, newValue);
    confirm();
    return true;
  break;

  case 9:

    int newSize;
    cout << "Give the index of the array which size you want to change: "
         << endl;
    arrIndx = getInt();

    cout << "give a new size: " << endl;
    newSize = getInt();

    cTableManager -> setArrSize(arrIndx, newSize);
    confirm();

    return true;
  break;

  default:
    cout << "no such option";
    return false;
  }

}

void UserInterface::confirm()
{
  cout << "\nThe action has been excecuted succesfully" << endl;
}

void UserInterface::ifContinue(bool &ifContinue)
{
  cout << "Do you want to continue?(Y/N)";

  string ifContinueFun = getString();

  if(ifContinueFun == "y" || ifContinueFun == "Y") ifContinue = true;
  else if(ifContinueFun == "n" || ifContinueFun == "N") ifContinue = false;
  else
  {

    ifContinueFun = getString();

    while(ifContinueFun != "y" && ifContinueFun != "Y"
          && ifContinueFun != "n" && ifContinueFun != "N")
    {
      cout << "no such option, write Y or N: " << endl;
      ifContinueFun = getString();
    }
    ifContinue = true;
  }
 }

int UserInterface::getInt()
{
  int someInt;

  while(!(cin >> someInt)){
      cout << "please, give a whole number: ";
      cin >> someInt;

      cin.clear();
      cin.ignore(10000, '\n');
  }

  return someInt;
}

string UserInterface::getString()
{
  string someString;
  cin >> someString;

  cin.clear();
  cin.ignore(10000, '\n');

  return someString;
}
