#pragma once
//用于放置一些函数接口，宏定义，防止被多次包含
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#define INCOME  "收入"
#define EXPAND  "支出"
#define FILENAME "AccountBook.txt"

using namespace std;
// 菜单函数（）
void showMainTable();
void showAccountingMenu();
void showQueryMenu();
//读取键盘输入进行校验
char readMenuSelection();
char readQuitConfirm();
int readAccount();
