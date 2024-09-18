#include "common.h"
#include "account_item.h"

int main()
{
    vector<AccountItem>items;
    loadDataFromFile(items);
    bool quit = false;
    while (!quit)
    {
        showMainTable();
        char key = readMenuSelection(3);
        switch (key)
        {
        case '1':
            showAccountingMenu();
            accounting(items);
            break;
        case '2':
            showQueryMenu();
            query(items);
            break;
        case '3':
            cout << "\n确认退出？（Y/N）:";
            if (readQuitConfirm() == 'Y')
                quit = true;
            break;

        default:
            break;
        }
        cout << endl;
    } 
    
    return 0;
}
    

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单