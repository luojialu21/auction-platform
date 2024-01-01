#include"admin.h"
#include"check.h"
int admin::adsignin()//管理员登录
{
    cout << "Please enter the administrator's name:";
    cin >> name;
    if (name != "admin")
    {
        cout << endl << endl << "-----Name Erorr-----" << endl;
        adsignin();
    }
    else
    {
        cout << "Enter your password:";
        cin >> key;
        if (key == "123456")
        {
            cout << endl << endl << endl << "-----SUCCESS-----"<<endl<<endl;
            system("pause");
            system("cls");
            return 1;
        }
        else
        {
            int i;
            for (i = 1; i <= 2; ++i)
            {
                cout << "The password " << i << " times error," << "you can try only " << 3 - i << " times again ! " << endl << "Enter your password:";
                cin >> key;
                if (key == "123456")
                {
                    cout << endl << endl << "-----SUCCESS-----" << endl << endl;
                    system("pause");
                    system("cls");
                    return 1;
                }
            }
            if (i == 3)
            {
                cout << endl << endl << "-----Login Failed-----" << endl << endl;
                system("pause");
                system("cls");
                cout << "1.Admin Login  2.User Enroll  3.User Login  4.Exit" << endl;
                cout << "Please enter a number to select(1~4):";
                cin >> option1; firstop(option1);
                return 2;
            }
            else
                return 1;
        }
    }


}
//管理员登录okk
int admin::adfunction(string option)
{
    com_check();
    if (option == "1")
        adcompre();
    //查看所有商品okk   
    else if (option == "2")
        adsearch();
    //搜索商品okk
    else if (option == "3")
        adwithdraw();
    //下架商品okk
    else if (option == "4")
        adordpre();
    //查看所有订单okk
    else if (option == "5")//查看所有用户
        aduserpre();
    //查看所有用户okk
    else if (option == "6")//查看用户订单
        adordpre_detail();
    else if (option == "7")//封禁用户
    {
        ifstream f; ofstream of; int i = 0; string str; ; string s;
        f.open("user.txt", ios::in); string str_cin;
        of.open("usertemp.txt", ios::out);
        cout << "Enter UserID:"; string temp; cin >> temp;
        cout << endl << endl;

        int flag = 0; cout << "Are you sure you want to block the user?" << endl;
        cout << "-------------------------------------------------------------------------------------------------------";
        cout << endl;
        cout << std::left << setw(12) << "userID";
        cout << std::left << setw(12) << " username";
        cout << std::left << setw(12) << "  password";
        cout << std::left << setw(12) << "   phone";
        cout << std::left << setw(12) << "    address";
        cout << std::left << setw(12) << "     balance";
        cout << std::left << setw(12) << "      state" << endl;

        while (getline(f, str_cin)) {//获得每一行
            stringstream a; a << str_cin; int i = 1;
            while (getline(a, str, ',')) {//获得每一个
                if (i == 1) {
                    if (str == temp) {//找到相关商品
                        stringstream b; b << str_cin;
                        while (getline(b, str, ','))
                        {
                            cout << std::left << setw(12) << str << " ";
                        }
                        cout << endl;
                        string op;
                        cout << "-------------------------------------------------------------------------------------------------------";
                        cout << endl;
                        cout << "Enter your choice（y/n):"; cin >> op;
                        if (op == "y")
                        {
                            flag = 1; stringstream c; c << str_cin;
                            while (getline(c, str, ','))
                            {
                                if (str == "active" || str == "inactive")
                                {
                                    of << "inactive" << endl;
                                    break;
                                }

                                of << str << ",";
                            }
                            break;
                        }
                        else//不下架
                        {
                            flag = 0;
                        }
                    }
                    else
                        of << str_cin << endl;//不是这个商品
                }
                //商品名称所在字符串

                i++;
            }
        }
        f.close(); of.close();

        if (flag == 0)
        {
            cout << endl << endl << "-----FAILED-----" << endl << endl;
        }
        else if (flag == 1)
        {
            cout << endl << endl << "-----SUCCESS-----" << endl << endl;
            string strcopy;
            ofstream ofs; ofs.open("user.txt", ios::out);
            ifstream fs; fs.open("usertemp.txt", ios::in);
            while (getline(fs, strcopy))
            {
                ofs << strcopy << endl;
            }
            fs.close(); ofs.close();

            ifstream cf; ofstream cof; string cstr;
            cf.open("commodity.txt", ios::in); string cstr_cin;
            cof.open("comofftemp.txt", ios::out);
            while (getline(cf, cstr_cin)) {//获得每一行
                stringstream a; a << cstr_cin; int ci = 1;
                while (getline(a, cstr, ',')) {//获得每一个
                    if (ci == 6)
                    {
                        if (cstr == temp) {//找到相关商品
                            stringstream c; c << cstr_cin;
                            while (getline(c, cstr, ','))
                            {
                                if (cstr == "onAuction" || cstr == "removed")
                                {
                                    cof << "removed" << endl;
                                    break;
                                }
                                cof << cstr << ",";
                            }
                            break;
                        }
                        else
                            cof << cstr_cin << endl;//不是这个商品
                    } //商品名称所在字符串
                    ci++;
                }
            }
            cf.close(); cof.close();
            string cstrcopy;
            ofstream ccofs; ccofs.open("commodity.txt", ios::out);
            ifstream ccfs; ccfs.open("comofftemp.txt", ios::in);
            while (getline(ccfs, cstrcopy))
            {
                ccofs << cstrcopy << endl;
            }
            ccfs.close(); ccofs.close();

        }
    }
    //封禁用户okk
    else if (option == "8")//注销
    {
        cout << endl << endl << "-----You have exited safely-----" << endl;
        system("pause");
        system("cls");
        return 7;
    }
    //注销okk

    cout << endl << endl;
    cout << "******************************************************************************************************" << endl;
    cout << "1.View Goods 2.Search Goods 3.Remove Goods 4.View Order 5.Vide User 6.View User's Order 7.Block User 8.Exit" << endl;
    int flag = legal8(); int tem;
    if (flag == 1)
    {
        tem = adfunction(option1);
        if (tem == 7)
            return 7;
    }
}

//管理员功能okk