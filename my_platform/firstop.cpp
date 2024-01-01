#include"admin.h"
#include"user.h"
#include"check.h"
int firstop(string option)
{
    admin* ad = new admin;
    User* us = new User;
    if (option == "1")//管理员登录
    {
        int temp1; temp1 = ad->adsignin();
        if (temp1 == 1)//登录成功
        {
            cout << "********************************************************************************************************************" << endl;
            cout << endl << "1.View Goods 2.Search Goods 3.Remove Goods 4.View Order 5.Vide User 6.View User's Order 7.Block User 8.Exit" << endl;
            cout << endl;
            int flag = legal8(); int temp = 0;
            if (flag == 1)
                temp = ad->adfunction(option1);
            if (temp == 7)
            {
                
                cout << "-------------------------------------------------" << endl << endl;
                cout << "1.Admin Sign in  2.User Enroll  3.User Sign in  4.Exit" << endl << endl;
                cout << "Enter the number to select(1~4):";
                cin >> option1; firstop(option1);
            }
        }
    }
    //管理员登录okk
    else if (option == "2")//用户注册
    {
        us->enroll();
        system("pause");
        system("cls");
        cout << "******************************************************" << endl;
        cout << endl << "1.BUYER  2.SELLER  3.PERSONAL INFORMATION  4.EXIT" << endl;
        legal4(); us->usfunction(option1);

    }
    //用户注册okk
    else if (option == "3")//用户登录
    {
        int flag = us->user_login();
        if (flag == 1)//登录成功
        {
            cout << "******************************************************" << endl;
            cout << endl << "1.BUYER  2.SELLER  3.PERSONAL INFORMATION  4.EXIT" << endl;
            legal4(); us->usfunction(option1);
        }
    }
    //用户登录okk
    else if (option == "4")//退出程序
    {
        cout << endl << endl << "-----Thanks for using this program！Have a nice day！-----";
        cout << endl << endl << endl;
        return 4;
    }
    //退出程序okk
    else//指令不正确
    {
        cout << endl << endl << "-----Please enter the correct number ！-----" << endl;
        cout << "1.Admin Sign in  2.User Enroll  3.User Sign in  4.Exit" << endl;
        legal4();
        firstop(option1);
    }
    //指令不正确okk
}