//���ڲ��ˣ����˹��ܺ�����ʵ��
#include "common.h"
#include "account_item.h"

void loadDataFromFile(vector<AccountItem>& items)
{
	//��ȡ��Ӧ���ļ����ݣ�ifstream����-->vector�У�
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
//1.��¼����
//��¼ÿ������
void income(vector<AccountItem>& items)
{
	AccountItem item;
	item.itemType = INCOME;
	cout << "\n���ε�����Ϊ��";
	item.amount = readAccount();

	cout << "\n��עΪ��";
	getline(cin,item.detail);
	// ��ӵ�vector��
	items.push_back(item);
	// д���ļ����־û�����
	insertInfoFile(item);

	// ��ʾ�ɹ���Ϣ
	cout << "\n------------------------���˳ɹ���--------------------------\n" << endl;
	cout << "\n�밴�س����������˵�..." << endl;

	string line;
	getline(cin, line);

}

//��¼֧��
void expand(vector<AccountItem>& items)
{
	AccountItem item;
	item.itemType = EXPAND;
	cout << "\n����֧����";
	item.amount = readAccount();

	cout << "\n��עΪ��";
	getline(cin,item.detail);
	items.push_back(item);

	insertInfoFile(item);
	// ��ʾ�ɹ���Ϣ
	cout << "\n------------------------���˳ɹ���--------------------------\n" << endl;
	cout << "\n�밴�س����������˵�..." << endl;

	string line;
	getline(cin,line);
}

//2.��ѯ����
void query(const vector<AccountItem>& items)
{
	char key = readMenuSelection(4);

	switch (key)
	{
	case '1':   // 1 - ��ѯ������Ŀ����ͳ������֧
		queryItems(items);
		break;
	case '2':   // 2 - ��ѯ���룬ͳ��������
		queryItems(items, INCOME);
		break;
	case '3':   // 3 - ��ѯ֧����ͳ����֧��
		queryItems(items, EXPAND);
		break;
	default:
		break;
	}
}
void queryItems(const vector<AccountItem>& items)
{
	cout << "---------------- ��ѯ��� ---------------------" << endl;
	cout << "\n����\t\t���\t\t��ע\n" << endl;

	// ����������Ŀ��ͳ������֧
	int total = 0;
	for (auto item : items)
	{
		printItems(item);
		total += item.amount;
	}

	// �����Ϣ
	cout << "===================================================\n" << endl;
	cout << "����֧��" << total << endl;
	cout << "\n�밴�س����������˵�..." << endl;

	string line;
	getline(cin, line);

}
void queryItems(const vector<AccountItem>& items, const string itemType)
{
	cout << "---------------- ��ѯ��� ---------------------" << endl;
	cout << "\n����\t\t���\t\t��ע\n" << endl;
	int total = 0;
	for (auto item : items)
	{
		if (item.itemType != itemType) continue;	
		printItems(item);
		total += item.amount;
		
	}
	cout << "===================================================\n" << endl;
	cout << ((itemType == INCOME) ? "�����룺" : "��֧����") << total << endl;
	cout << "\n�밴�س����������˵�..." << endl;
	string line;
	getline(cin,line);
}
void printItems(const AccountItem& item)
{
	cout << item.itemType << "\t\t" << item.amount << "\t\t" << item.detail << endl;
}

