#define _CRT_SECURE_NO_WARNINGS
#include"user.h"
#include"check.h"
void Seller::seller(string option)
{
    if (option == "1")
    {
        fstream f; int i = 0; string str; ; string s; int flag = 1;
        f.open("user.txt", ios::in); string str_cin;
        while (getline(f, str_cin) && flag != 0)
        {
            stringstream a;
            a << str_cin;

            while (getline(a, str, ',') && flag == 1)
            {
                if (str == name)
                {
                    stringstream b;
                    b << str_cin;
                    while (getline(b, str, ','))
                    {
                        if (str == "inactive")
                        {
                            flag = 0;
                            cout << "----You are inactive！You cannot list goods!---- " << endl;
                            break;
                        }
                    }

                }

            }

        }
        //检查是否被封禁
        if (flag == 1)
        {
            cout << "Enter name:";
            string commodityName;  getchar(); getline(cin, commodityName);;
            cout << "Enter price:";
            double price; cin >> price;
            cout << "Enter number:";
            string number; cin >> number;
            cout << "Enter description:";
            string description;  getchar(); getline(cin, description);
            cout << endl << endl << "Please check the information！" << endl << endl;
            cout << "***************************" << endl;
            cout << "Name:" << commodityName << endl;
            cout << "Price:" << setprecision(1) << setiosflags(ios::fixed) << price << endl;
            cout << "Number:" << number << endl;
            cout << "Description:" << description << endl;
            cout << "***************************" << endl;
            cout << endl << endl;
            cout << "Are you sure you want to list the product?（y/n)";
            string choice; cin >> choice; string commodityID, sellerID, addedDate, state;
            if (choice == "y")
            {
                fstream f; string str; string last_str;
                f.open("commodity.txt", ios::in); string str_cin;
                while (getline(f, str_cin)) {//获得最后一行  
                    last_str = str_cin;

                }
                f.close();
                stringstream lastID1; lastID1 << last_str; string lastID;
                getline(lastID1, lastID, ',');
                int a = lastID[3]; int b = lastID[2]; int c = lastID[1];
                int d = a - 48 + (b - 48) * 10 + (c - 48) * 100;
                f.open("commodity.txt", ios::out | ios::app);
                f << "M" << setw(3) << setfill('0');
                f << d + 1 << ",";
                time_t dp;
                dp = time(0);
                struct tm* ds;
                ds = localtime(&dp);
                char date[20];
                strftime(date, 30, "2022-%m-%d", ds);
                string ddd; ddd = date;
                
                
                f << commodityName << "," << setprecision(1) << setiosflags(ios::fixed) << price << "," << number << "," << description << "," << name << ",";
                f << ddd << ",";
                f << "onAuction" << endl;
                f.close();
                cout << "-----SUCCESS！-----" << endl << endl;
            }
            else
            {
                cout << "-----FAIL！-----" << endl << endl;
            }
        }


        cout << endl << endl << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "1.List goods 2.View goods 3.Edit your listing 4.Romove goods 5.View order 6.Back" << endl;
        legal6(); seller(option1);

    }
    //发布商品okk
    else if (option == "2")
    {
        selcompre();
        cout << endl << endl << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << "1.List goods 2.View goods 3.Edit your listing 4.Romove goods 5.View order 6.Back" << endl;
        legal6(); seller(option1);
    }
    //查看发布商品okk
    else if (option == "3")
    {
        string comID;
        cout << "Enter commodityID:"; cin >> comID;
        cout << "Please enter the modified product attributes (1.Price 2.Description):";
        string op; cin >> op; double price; string description;
        int flag = 0;
        if (op == "1")
        {
            cout << "Enter new price:"; cin >> price;
            cout << "Please check the information！" << endl;
            cout << "----------------------------------------------------------------------------------------------";
            cout << endl;
        }
        else if (op == "2")
        {
            getchar();
            cout << "Enter new description:";
            getline(cin, description);
            cout << "Please check the information！" << endl;
            cout << "----------------------------------------------------------------------------------------------";
            cout << endl;
        }
        ifstream f; string str; ; string s;
        f.open("commodity.txt", ios::in); string str_cin;
        ofstream of; of.open("comotemp.txt", ios::out);
        while (getline(f, str_cin))
        {
            stringstream a; a << str_cin;
            while (getline(a, str, ','))
            {
                if (str == comID)//找到该商品
                {
                    for (int j = 1; j <= 5; ++j)
                        getline(a, str, ',');
                    if (str == name)//是该用户发布的
                    {
                        flag = 1;
                        stringstream b; b << str_cin;
                        getline(b, str, ','); cout << "commodityID:" << str << endl;
                        getline(b, str, ','); cout << "commodityname:" << str << endl;
                        if (op == "1")
                        {
                            getline(b, str, ','); cout << "price:" << setprecision(1) << setiosflags(ios::fixed) << price << endl;
                        }
                        else
                        {
                            getline(b, str, ','); cout << "price:" << str << endl;
                        }
                        if (op == "2")
                        {
                            getline(b, str, ','); getline(b, str, ',');
                            cout << "description:" << description << endl;
                        }
                        else
                        {
                            getline(b, str, ','); getline(b, str, ',');
                            cout << "description:" << str << endl;
                        }
                        cout << endl << "----------------------------------------------------------------------------------------------";
                        cout << endl;
                        cout << endl << "Confirm changes？（y/n):"; string yn; cin >> yn;
                        if (yn == "y")//修改
                        {
                            stringstream c; c << str_cin;
                            if (op == "1")//修改价格
                            {
                                of << comID; getline(c, str, ',');
                                for (int j = 1; j <= 7; ++j)
                                {
                                    getline(c, str, ',');
                                    if (j == 2)
                                    {
                                        of << "," << setprecision(1) << setiosflags(ios::fixed) << price;
                                        continue;
                                    }
                                    of << "," << str;
                                }
                                of << endl; break;
                            }
                            else if (op == "2")
                            {
                                of << comID; getline(c, str, ',');
                                for (int j = 1; j <= 7; ++j)
                                {
                                    getline(c, str, ',');
                                    if (j == 4)
                                    {
                                        of << "," << description;
                                        continue;
                                    }
                                    of << "," << str;
                                }
                                of << endl; break;
                            }

                        }
                        else
                        {
                            cout << endl << endl << "-----FAIL！-----" << endl << endl;
                            goto end;
                        }
                    }
                    else
                    {
                        cout << endl << "----------------------------------------------------------------------------------------------";
                        cout << endl;
                        cout << endl << endl << "-----FAIL！-----" << endl << endl;
                        goto end;
                    }
                }
                else
                {
                    of << str_cin << endl; break;
                }//不是这个商品
            }

        }
        f.close(); of.close();

        if (flag == 0)
        {
            cout << endl << "----------------------------------------------------------------------------------------------";
            cout << endl;
            cout << endl << endl << "-----FAIL！-----" << endl << endl;
        }
        else if (flag == 1)
        {
            cout << endl << endl << "-----SUCCESS!-----" << endl << endl;
            string strcopy;
            ofstream ofs; ofs.open("commodity.txt", ios::out);
            ifstream fs; fs.open("comotemp.txt", ios::in);
            while (getline(fs, strcopy))
            {
                ofs << strcopy << endl;
            }
            fs.close(); ofs.close();
        }
    end:;

        cout << endl << endl << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << "1.List goods 2.View goods 3.Edit your listing 4.Romove goods 5.View order 6.Back" << endl;
        legal6(); seller(option1);
    }
    //修改商品信息okk
    else if (option == "4")
    {
        selwithdraw();
        cout << endl << endl << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << "1.List goods 2.View goods 3.Edit your listing 4.Romove goods 5.View order 6.Back" << endl;
        legal6(); seller(option1);
    }
    //下架商品okk
    else if (option == "5")
    {
        selordpre();
        cout << endl << endl << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << "1.List goods 2.View goods 3.Edit your listing 4.Romove goods 5.View order 6.Back" << endl;
        legal6(); seller(option1);
    }
    //查看历史订单okk
    else if (option == "6")
    {
        cout << endl << endl;
        system("pause");
        system("cls");
        cout << "******************************************************" << endl;
        cout << endl << "1.BUYER  2.SELLER  3.PERSONAL INFORMATION  4.EXIT" << endl;
        legal4(); User user;user.usfunction(option1);
    }
    //返回用户主界面okk
}
//卖家功能okk