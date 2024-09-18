//对于查账，记账功能函数的实现
#include "common.h"
#include "account_item.h"

void loadDataFromFile(vector<AccountItem>& items)
{
	//读取对应的文件数据（ifstream对象-->vector中）
	ifstream input(FILENAME);
	AccountItem item;
	while (input>>item.itemType>>item.amount>>item.detail)
	{
		items.push_back(item);
	}
	input.close();
}

void accounting(vector<AccountItem>& items)
{
	char key = readMenuSelection(3);
	switch (key)
	{
	case '1':
		income(items);
		break;
	case '2':
		expand(items);
		break;
	case '3':
		break;
	default:
		break;
	}
}

void insertInfoFile(AccountItem& item)
{
	ofstream output(FILENAME, ios::out | ios::app);
	output << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;
	output.close();
}
//1.记录功能
//记录每笔收入
void income(vector<AccountItem>& items)
{
	AccountItem item;
	item.itemType = INCOME;
	cout << "\n本次的收入为：";
	item.amount = readAccount();

	cout << "\n备注为：";
	getline(cin,item.detail);
	// 添加到vector中
	items.push_back(item);
	// 写入文件做持久化保存
	insertInfoFile(item);

	// 显示成功信息
	cout << "\n------------------------记账成功！--------------------------\n" << endl;
	cout << "\n请按回车键返回主菜单..." << endl;

	string line;
	getline(cin, line);

}

//记录支出
void expand(vector<AccountItem>& items)
{
	AccountItem item;
	item.itemType = EXPAND;
	cout << "\n本次支出金额：";
	item.amount = readAccount();

	cout << "\n备注为：";
	getline(cin,item.detail);
	items.push_back(item);

	insertInfoFile(item);
	// 显示成功信息
	cout << "\n------------------------记账成功！--------------------------\n" << endl;
	cout << "\n请按回车键返回主菜单..." << endl;

	string line;
	getline(cin,line);
}

//2.查询功能
void query(const vector<AccountItem>& items)
{
	char key = readMenuSelection(4);

	switch (key)
	{
	case '1':   // 1 - 查询所有账目，并统计总收支
		queryItems(items);
		break;
	case '2':   // 2 - 查询收入，统计总收入
		queryItems(items, INCOME);
		break;
	case '3':   // 3 - 查询支出，统计总支出
		queryItems(items, EXPAND);
		break;
	default:
		break;
	}
}
void queryItems(const vector<AccountItem>& items)
{
	cout << "---------------- 查询结果 ---------------------" << endl;
	cout << "\n类型\t\t金额\t\t备注\n" << endl;

	// 遍历所有账目，统计总收支
	int total = 0;
	for (auto item : items)
	{
		printItems(item);
		total += item.amount;
	}

	// 输出信息
	cout << "===================================================\n" << endl;
	cout << "总收支：" << total << endl;
	cout << "\n请按回车键返回主菜单..." << endl;

	string line;
	getline(cin, line);

}
void queryItems(const vector<AccountItem>& items, const string itemType)
{
	cout << "---------------- 查询结果 ---------------------" << endl;
	cout << "\n类型\t\t金额\t\t备注\n" << endl;
	int total = 0;
	for (auto item : items)
	{
		if (item.itemType != itemType) continue;	
		printItems(item);
		total += item.amount;
		
	}
	cout << "===================================================\n" << endl;
	cout << ((itemType == INCOME) ? "总收入：" : "总支出：") << total << endl;
	cout << "\n请按回车键返回主菜单..." << endl;
	string line;
	getline(cin,line);
}
void printItems(const AccountItem& item)
{
	cout << item.itemType << "\t\t" << item.amount << "\t\t" << item.detail << endl;
}

