#include "common.h"
char readMenuSelection(int options)
{
	string str;
	while (true)
	{
		getline(cin,str);
		if(str.size() !=1 || str[0]-'0' <= 0 ||  str[0]-'0' >options)
		{
			cout << "输入错误，请重新选择：";
		}
		else 
		{
			break;
		}
	}
	return toupper(str[0]);
}

//确认退出信息，确认后退出
char readQuitConfirm()
{
	string str;
	while (true)
	{
		getline(cin,str);
		// 进行合法性校验
		if (str.size() != 1 || toupper(str[0]) != 'Y' && toupper(str[0]) != 'N')
			cout << "输入错误，请重新输入（Y/N）：";
		else
			break;
	}

	// 输入合法
	return toupper(str[0]);

}


int readAccount()
{
	int amount;
	string str;
	getline(cin,str);
	try
	{
		amount = stoi(str);
	}
	catch (exception &e)
	{
		cerr << "捕获到异常: " << e.what() << endl;
		cout << "输入错误，请正确输入数字：";
	}
	return amount;
}
