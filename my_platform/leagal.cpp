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
//��8��ѡ��ĺϷ��ж�okk
int legal4()
{
    cout << endl << endl << "Please enter a number to select(1~4):";
    cin >> option1;
    if (option1 == "1" || option1 == "2" || option1 == "3" || option1 == "4")
        return 1;
    else
        legal4();
}
//���ĸ�ѡ��ĺϷ��ж�okk
int legal6()
{
    cout << endl << endl << "Please enter a number to select(1~6):";
    cin >> option1;
    if (option1 == "1" || option1 == "2" || option1 == "3" || option1 == "4" || option1 == "5" || option1 == "6")
        return 1;
    else
        legal6();
}
//������ѡ��ĺϷ��ж�okk
int User::key_check()
{

    cout << "Enter your password��"; cin >> key;
    cout << "Enter the same password��"; string keytemp; cin >> keytemp;
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
//ע��ʱ��������Ҫһ��okk

int User::temID_check(string temID)
{
    int flag = 0; fstream f; f.open("user.txt", ios::in);
    string str_cin; string str;
    while (getline(f, str_cin))
    {
        stringstream a;
        a << str_cin;//���ÿһ��
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
//�޸��û�IDʱ���鿴�Ƿ�ע�������ע���=1 okk
