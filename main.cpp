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

  CTableManager cTableManager;

  Menu* menu = new Menu("main menu", "main_menu");
  Menu* menu_1 = new Menu("Array Managment", "a_managment");

  menu -> addNewCommand(menu_1);

  MenuObject* createArrays = new MenuCommand("createArrays", "create_a", new ChangeSize(cTableManager));
  
  MenuObject* setArrName = new MenuCommand("setArrName", "set_arr_n", new ChangeSize(cTableManager));
  MenuObject* setArrSize = new MenuCommand("setArrSize", "set_a_s", new ChangeSize(cTableManager));
  MenuObject* setArrValue = new MenuCommand("setArrValue", "set_arr_v", new ChangeSize(cTableManager));

  MenuObject* getArrInfo = new MenuCommand("getArrInfo", "get_arr_i", new ChangeSize(cTableManager));
  MenuObject* getArrSize = new MenuCommand("getArrSize", "get_arr_s", new ChangeSize(cTableManager));

  MenuObject* cloneArr = new MenuCommand("cloneArr", "clone_a", new ChangeSize(cTableManager));

  MenuObject* deleteArray = new MenuCommand("deleteArray", "delete_a", new ChangeSize(cTableManager));
  MenuObject* deleteAllArrays = new MenuCommand("deleteAllArrays", "delete_all_a", new ChangeSize(cTableManager));


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


  return 0;
}
