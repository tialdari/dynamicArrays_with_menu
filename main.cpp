#include <iostream>
#include<string>
#include<vector>
#include "MenuObject.h"
#include "MenuObject.cpp"
#include "Menu.h"
#include "Menu.cpp"
#include "MenuCommand.h"
#include "MenuCommand.cpp"
#include "Command.h"
#include "IO.h"
#include "IO.cpp"
#include "CTableManagerCommands.cpp"
#include "CTableManagerCommands.h"
#include "CTable.h"
#include "CTable.cpp"
#include<fstream>
#include<iostream>

using namespace std;

int main()
{
/*
  char c_childrenNum = 0;
  const char endSymbols[] = {c_childrenNum,'(', '['};
  int endSymbolsSize = 3;

  int i_childrenNum = c_childrenNum;
  cout << "in_childrenNum: " << i_childrenNum << endl;

  for(int i = 0; i < endSymbolsSize; i++){
    cout << endSymbols[i] << ". ";
    }


*/
  IO io;
  //string testString = io.readFromFile("test.txt");

string testString = "('menu glowne','main';3,('Podmenu1a','menu1';2,['Uruchom przegladarke','internet','otwiera przegladarke'],('Podmenu1b','menu1';0)),('Podmenu2','menu2';2,['Test','test','pomoc dla test'],['Default command','defcom','pomoc dla test']),['Napisz „Ala ma kota”','ala','napis o Ali'])";
string testString2 = "('menu glowne','main';2,['testCommand','test_','testComDescrip'],['Uruchom przegladarke','internet','otwiera przegladarke'])";
string testString3 = "('Podmenu2','menu2';2,['Test','test','pomoc dla test'],['Default command','defcom','pomoc dla test'])";
string testString4 = "('menu glowne','main';('Podmenu1','menu1';['Uruchom przegladarke','internet','otwiera przegladarke'],('Podmenu1','menu1';)),('Podmenu2','menu2';['Test','test','pomoc dla test'],['Default command','defcom','pomoc dla test']),['Napisz „Ala ma kota”','ala','napis o Ali'])";



  int size = testString.length() + 1;
  char* testCharArr = new char [size];
  strcpy (testCharArr, testString.c_str());

  int size2 = testString2.length() + 1;
  char* testCharArr2 = new char [size2];
  strcpy (testCharArr2, testString2.c_str());

  int size4 = testString4.length() + 1;
  char* testCharArr4 = new char [size4];
  strcpy (testCharArr4, testString4.c_str());


  int index = 0;
  bool succ = true;

  Menu* menu = new Menu("", "", NULL);

  menu = menu -> readMenu(testCharArr, size, index, NULL, succ);
  //menu -> run();

   testString2 =  menu -> menuObjectToString();

  if(testString == testString2) cout << "readMenuObject method works correctly" << endl;

  delete menu;


/*

 CTableManager* cTableManager = new CTableManager();

  Menu* menu = new Menu("main menu", "main_menu", NULL);
  Menu* menu_1 = new Menu("Array Managment", "a_management", menu);

  menu -> addNewCommand(menu_1);

  MenuObject* createArrays = new MenuCommand("createArrays", "create_a", menu_1, new CreateArrays(cTableManager));

  MenuObject* setArrName = new MenuCommand("setArrName", "set_arr_n", menu_1, new SetArrName(cTableManager));
  MenuObject* setArrSize = new MenuCommand("setArrSize", "set_a_s", menu_1, new SetArrSize(cTableManager));
  MenuObject* setArrValue = new MenuCommand("setArrValue", "set_arr_v", menu_1, new SetArrValue(cTableManager));

  MenuObject* getArrInfo = new MenuCommand("getArrInfo", "get_arr_i", menu_1, new GetArrInfo(cTableManager));
  MenuObject* getArrSize = new MenuCommand("getArrSize", "get_arr_s", menu_1, new GetArrSize(cTableManager));

  MenuObject* cloneArr = new MenuCommand("cloneArr", "clone_a", menu_1, new CloneArr(cTableManager));

  MenuObject* deleteArray = new MenuCommand("deleteArray", "delete_a", menu_1, new DeleteArray(cTableManager));
  MenuObject* deleteAllArrays = new MenuCommand("deleteAllArrays", "delete_all_a", menu_1, new DeleteAllArrays(cTableManager));


  menu_1 -> addNewCommand(createArrays);

  menu_1 -> addNewCommand(setArrName);
  menu_1 -> addNewCommand(setArrSize);
  menu_1 -> addNewCommand(setArrValue);

  menu_1 -> addNewCommand(getArrInfo);
  menu_1 -> addNewCommand(getArrSize);

  menu_1 -> addNewCommand(cloneArr);

  menu_1 -> addNewCommand(deleteArray);
  menu_1 -> addNewCommand(deleteAllArrays);



  menu -> run();


  delete cTableManager;
  delete menu;


  cout << "end of programme";

*/


  return 0;
}
