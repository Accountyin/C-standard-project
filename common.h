#pragma once
//���ڷ���һЩ�����ӿڣ��궨�壬��ֹ����ΰ���
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#define INCOME  "����"
#define EXPAND  "֧��"
#define FILENAME "AccountBook.txt"

using namespace std;
// �˵���������
void showMainTable();
void showAccountingMenu();
void showQueryMenu();
//��ȡ�����������У��
char readMenuSelection();
char readQuitConfirm();
int readAccount();
