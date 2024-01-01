#include"user.h"
#include"check.h"
void User::enroll()//用户注册
{

    fstream f; string str;
    f.open("user.txt", ios::in); string str_cin; string last_cin;
    while (getline(f, str_cin)) {//获得最后一行  
        last_cin = str_cin;
    }
    f.close();
    stringstream lastID1; lastID1 << last_cin; string lastID;
    getline(lastID1, lastID, ',');
    int a = lastID[3]; int b = lastID[2]; int c = lastID[1];
    int d = a - 48 + (b - 48) * 10 + (c - 48) * 100;
    d = d + 1; string ID;
    char IDS[4] = { 0 }; IDS[3] = (d % 10) + 48;;
    IDS[2] = ((d / 10) % 10) + 48; IDS[1] = (d / 100) + 48;
    IDS[0] = 'U';
    for (int i = 0; i <= 3; ++i)
    {
        ID = ID + IDS[i];
    }
    while (temID_check(ID) == 1)
    {
        ++d; ID = "\0";
        char IDS[4] = { 0 }; IDS[3] = (d % 10) + 48;;
        IDS[2] = ((d / 10) % 10) + 48; IDS[1] = (d / 100) + 48;
        IDS[0] = 'U';
        for (int i = 0; i <= 3; ++i)
        {
            ID = ID + IDS[i];
        }
    }
    f.open("user.txt", ios::out | ios::app);
    f << ID << ",";
    cout << "Name:";
    string name1; cin >> name1;
    f << name1 << ",";
    key_check(); f << key << ",";
    cout << "Phone number:";
    string phnum; cin >> phnum;
    f << phnum << ","; cout << "Address:";
    string address2;  getchar(); getline(cin, address2); f << address2 << ",";
    f << "0.0,active" << endl;
    cout << endl << endl << endl << "-----SUCCESS-----" << endl << endl;
    cout << endl << "-----Your userID:";
    cout << ID; cout << "! The user ID is unique, keep the user ID in mind! Your balance is 0.0$-----" << endl << endl;
    f.close();
    name = ID;
}
//用户注册okk
void User::usfunction(string option)
{
    com_check();
    if (option == "1")
    {
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "1.View goods 2.Buy goods 3.Search goods 4.My order 5.View details 6.Back" << endl;
        legal6(); Buyer buy;buy.buyer(option1);
    }
    //我是买家
    else if (option == "2")
    {
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << "1.List goods 2.View goods 3.Edit your listing 4.Romove goods 5.View order 6.Back" << endl;
        legal6();
        Seller sel;
        sel.seller(option1);
    }
    //我是卖家
    else if (option == "3")
    {
        cout << endl << endl;
        cout << "**********************************************" << endl;
        cout << "1.View 2.Modify 3.Recharge 4.Back" << endl;
        legal4(); message(option1);


    }
    //个人信息管理okk
    else if (option == "4")
    {
        cout << endl << endl << endl << "-----Exit Safely-----";
        cout << endl << endl << endl;
        system("pause");
        system("cls");
        cout << "-------------------------------------------------" << endl << endl;
        cout << "1.Admin Sign in  2.User Enroll  3.User Sign in  4.Exit" << endl << endl;
        cout << "Please enter a number to select(1~4):";
        cin >> option1; firstop(option1);
    }
    //注销登录okk
}
//用户功能
int User::user_login()
{
    string IDtemp, key;
    cout << endl << "UserID:";
    cin >> IDtemp;
    cout << "Password:";
    cin >> key;
    fstream f; f.open("user.txt", ios::in);
    string str_cin; string str; int flag = 0;
    name = IDtemp;
    while (getline(f, str_cin))//读取每一行
    {
        stringstream a;
        a << str_cin;
        int i = 1;
        while (getline(a, str, ','))//读取每一个
        {
            if (i == 1)//用户所在那行
            {
                if (IDtemp == str)//找到这个用户
                {
                    flag = 1;
                    stringstream b; b << str_cin;
                    for (int i = 1; i <= 3; ++i)
                    {
                        getline(b, str, ',');
                    }
                    if (str == key)
                    {
                        cout << endl << endl << "-----SUCCESS！-----" << endl << endl;
                        system("pause");
                        system("cls");
                        return 1;
                    }
                    else
                    {
                        int i;
                        for (i = 1; i <= 2; ++i)
                        {
                            cout << "The password " << i << " times wrong, " << "you can try only " << 3 - i << " times again! " << endl << "Enter your password：";
                            cin >> key;
                            if (key == str)
                            {
                                cout << endl << endl << "-----SUCCESS!-----" << endl << endl;
                                return 1;
                            }
                        }
                        if (i == 3)
                        {
                            cout << endl << endl << "-----FAILED-----" << endl << endl;
                            system("pause");
                            system("cls");
                            cout << "1.Admin Sign in  2.User Enroll  3.User Sign in  4.Exit" << endl;
                            cout << "Please enter a number to select(1~4):";
                            cin >> option1; firstop(option1);
                            return 2;
                        }
                    }
                }
                else
                    break;

            }

            i++;
        }
        if (flag == 1)
            break;
    }
    f.close();
    if (flag == 0)
    {
        cout << endl << endl << "-----The user is not registered! Please register!-----" << endl << endl << endl;
        cout << "1.Admin Sign in  2.User Enroll  3.User Sign in  4.Exit" << endl;
        cout << endl << endl;
        cout << "Please enter a number to select(1~4):";
        cin >> option1; firstop(option1);
        return 2;
    }
}
//用户登录okk
void User::message(string option)
{
    if (option == "1")
    {
        ususerpre();
        cout << endl << endl << endl;
        cout << "**********************************************" << endl;
        cout << "1.View 2.Modify 3.Recharge 4.Back" << endl;
        legal4(); message(option1);
    }
    //查看信息okk
    else if (option == "2" || option == "3")
    {
        string temop = "0"; double tembla = -3.0;
        string temID, tempho, temadd; double balance = 0;
        if (option == "2")
        {
            cout << "Please select the attributes that need to be modified (1.Username 2.Contact 3.Address):";
            cin >> temop;
        }
        else
        {
            cout << "Enter the top-up amount:";
            cin >> tembla;
        }
        fstream f; int i = 0; string str; ; string s; double bala;
        ofstream of; of.open("usertemp.txt", ios::out);
        f.open("user.txt", ios::in); string str_cin;
        while (getline(f, str_cin))
        {
            stringstream a;
            a << str_cin;
            while (getline(a, str, ','))
            {
                if (str == name)//找到了
                {

                    if (temop == "2")
                    {
                        of << name;
                        cout << "Enter new phone number:";
                        cin >> tempho;
                        for (int i = 1; i <= 6; ++i)
                        {
                            getline(a, str, ',');
                            if (i == 3)
                                str = tempho;

                            of << "," << str;
                        }
                        of << endl;
                        cout << endl << endl << "-----SUCCESS！-----" << endl << endl;
                        break;
                    }
                    else if (temop == "3")
                    {
                        of << name;
                        cout << "Enter new adress:";
                        getchar(); getline(cin, temadd);
                        for (int i = 1; i <= 6; ++i)
                        {
                            getline(a, str, ',');
                            if (i == 4)
                                str = temadd;

                            of << "," << str;
                        }
                        of << endl;
                        cout << endl << endl << "-----SUCCESS！-----" << endl << endl;
                        break;
                    }
                    else if (temop == "1")
                    {
                        cout << endl << endl;
                        cout << "ATTENTION！！！Usernames can only start with a U followed by three digits！！！" << endl << endl;
                        cout << "new userID:";
                        cin >> temID;
                        if (temID_check(temID) == 1)
                            cout << endl << endl << "-----The username is already registered！-----" << endl << endl;
                        else
                        {
                            str = temID; of << str;
                            for (int i = 1; i <= 6; ++i)
                            {
                                getline(a, str, ',');
                                of << ',' << str;
                            }of << endl;
                            cout << endl << endl << "-----SUCCESS！-----" << endl << endl;
                            //order 和commodity也要改！！！！



                            ofstream oof; ifstream of;
                            oof.open("ordertemp.txt", ios::out);
                            of.open("order.txt", ios::in);
                            while (getline(of, str_cin))
                            {
                                stringstream a;
                                a << str_cin; int i = 1;
                                while (getline(a, str, ','))
                                {

                                    if (str == name && i != 7)
                                    {
                                        str = temID;
                                        oof << str << ",";
                                    }
                                    else if (i == 7)
                                    {
                                        if (str == name)
                                        {
                                            str = temID; oof << str << endl;
                                        }
                                        else
                                            oof << str << endl;
                                        break;
                                    }
                                    else
                                    {
                                        oof << str << ",";

                                    }
                                    ++i;
                                }
                            }

                            of.close(); oof.close();
                            string strcopyo;
                            oof.open("order.txt", ios::out);
                            of.open("ordertemp.txt", ios::in);
                            while (getline(of, strcopyo))
                            {
                                oof << strcopyo << endl;
                            }
                            of.close(); oof.close();

                            ofstream cof; ifstream cf;
                            cof.open("comtemp.txt", ios::out);
                            cf.open("commodity.txt", ios::in);
                            while (getline(cf, str_cin))
                            {
                                stringstream a;
                                a << str_cin; int i = 1;
                                while (getline(a, str, ','))
                                {

                                    if (str == name)
                                    {
                                        str = temID;
                                        cof << str << ",";
                                    }
                                    else
                                    {
                                        if (i != 8)
                                            cof << str << ",";
                                        else
                                            cof << str << endl;

                                    }
                                    ++i;
                                }
                            }

                            cf.close(); cof.close();
                            string strcopy2;
                            cof.open("commodity.txt", ios::out);
                            cf.open("comtemp.txt", ios::in);
                            while (getline(cf, strcopy2))
                            {
                                cof << strcopy2 << endl;
                            }
                            cf.close(); cof.close();
                            name = temID;
                        }
                    }
                    else if (tembla != -3.0)
                    {
                        of << name;
                        for (int i = 1; i <= 6; ++i)
                        {
                            getline(a, str, ',');
                            if (i == 5)
                            {
                                stringstream bal;
                                bal << str;  bal >> bala;
                                bala = bala + tembla;
                                of << "," << setprecision(1) << setiosflags(ios::fixed) << bala;
                                continue;
                            }
                            of << "," << str;
                        }
                        of << endl;
                        cout << "SUCCESS！Your balance is:";
                        cout << setprecision(1) << setiosflags(ios::fixed) << bala << endl;
                    }
                }
                else
                {
                    of << str_cin << endl;
                    break;
                }
            }
        }
        f.close(); of.close();




        string strcopy;
        ofstream ofs; ofs.open("user.txt", ios::out);
        ifstream fs; fs.open("usertemp.txt", ios::in);
        while (getline(fs, strcopy))
        {
            ofs << strcopy << endl;
        }
        fs.close(); ofs.close();
        cout << endl << endl << endl;
        cout << "**********************************************" << endl;
        cout << "1.View 2.Modify 3.Recharge 4.Back" << endl;
        legal4(); message(option1);
    }
    //修改信息!
    else if (option == "4")
    {
        cout << "******************************************************" << endl;
        cout << endl << "1.BUYER  2.SELLER  3.PERSONAL INFORMATION  4.EXIT" << endl;
        legal4(); usfunction(option1);
    }
    //返回用户主界面okk
}
//个人信息管理