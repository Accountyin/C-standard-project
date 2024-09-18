#include "common.h"
char readMenuSelection(int options)
{
	string str;
	while (true)
	{
		getline(cin,str);
		if(str.size() !=1 || str[0]-'0' <= 0 ||  str[0]-'0' >options)
		{
			cout << "�������������ѡ��";
		}
		else 
		{
			break;
		}
	}
	return toupper(str[0]);
}

//ȷ���˳���Ϣ��ȷ�Ϻ��˳�
char readQuitConfirm()
{
	string str;
	while (true)
	{
		getline(cin,str);
		// ���кϷ���У��
		if (str.size() != 1 || toupper(str[0]) != 'Y' && toupper(str[0]) != 'N')
			cout << "����������������루Y/N����";
		else
			break;
	}

	// ����Ϸ�
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
		cerr << "�����쳣: " << e.what() << endl;
		cout << "�����������ȷ�������֣�";
	}
	return amount;
}
