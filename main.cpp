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


using namespace std;

int main()
{


  CTableManager* cTableManager = new CTableManager();

  Menu* menu = new Menu("main menu", "main_menu", NULL);
  Menu* menu_1 = new Menu("Array Managment", "a_management", menu);

  menu -> addNewCommand(menu_1);

  MenuObject* createArrays = new MenuCommand("createArrays", "create_a", new CreateArrays(cTableManager), menu_1);

  MenuObject* setArrName = new MenuCommand("setArrName", "set_arr_n", new SetArrName(cTableManager), menu_1);
  MenuObject* setArrSize = new MenuCommand("setArrSize", "set_a_s", new SetArrSize(cTableManager), menu_1);
  MenuObject* setArrValue = new MenuCommand("setArrValue", "set_arr_v", new SetArrValue(cTableManager), menu_1);

  MenuObject* getArrInfo = new MenuCommand("getArrInfo", "get_arr_i", new GetArrInfo(cTableManager), menu_1);
  MenuObject* getArrSize = new MenuCommand("getArrSize", "get_arr_s", new GetArrSize(cTableManager), menu_1);

  MenuObject* cloneArr = new MenuCommand("cloneArr", "clone_a", new CloneArr(cTableManager), menu_1);

  MenuObject* deleteArray = new MenuCommand("deleteArray", "delete_a", new DeleteArray(cTableManager), menu_1);
  MenuObject* deleteAllArrays = new MenuCommand("deleteAllArrays", "delete_all_a", new DeleteAllArrays(cTableManager), menu_1);


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


  return 0;
}
