#include"check.h"
#include"user.h"
int legal8()
{
    cout << endl << endl << "Please enter a number to select(1~8):";
    cin >> option1;
    if (option1 == "1" || option1 == "2" || option1 == "3" || option1 == "4" || option1 == "5" || option1 == "6" || option1 == "7"||option1=="8")
        return 1;
    else
        legal8();
}
//有8个选择的合法判断okk
int legal4()
{
    cout << endl << endl << "Please enter a number to select(1~4):";
    cin >> option1;
    if (option1 == "1" || option1 == "2" || option1 == "3" || option1 == "4")
        return 1;
    else
        legal4();
}
//有四个选择的合法判断okk
int legal6()
{
    cout << endl << endl << "Please enter a number to select(1~6):";
    cin >> option1;
    if (option1 == "1" || option1 == "2" || option1 == "3" || option1 == "4" || option1 == "5" || option1 == "6")
        return 1;
    else
        legal6();
}
//有六个选择的合法判断okk
int User::key_check()
{

    cout << "Enter your password："; cin >> key;
    cout << "Enter the same password："; string keytemp; cin >> keytemp;
    if (key == keytemp)
    {
        return 1;
    }
    else
    {
        cout << endl << "-----Your password is wrong! Try again!-----" << endl;
        key_check();
    }
}
//注册时两次密码要一样okk

int User::temID_check(string temID)
{
    int flag = 0; fstream f; f.open("user.txt", ios::in);
    string str_cin; string str;
    while (getline(f, str_cin))
    {
        stringstream a;
        a << str_cin;//获得每一行
        while (getline(a, str, ','))
        {
            if (temID == str)
            {
                flag = 1; return flag;
            }
            else
                break;
        }
    }
    return flag;
}
//修改用户ID时，查看是否被注册过，被注册过=1 okk
