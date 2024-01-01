#define _CRT_SECURE_NO_WARNINGS
#include"user.h"
#include"check.h"

void Buyer::buyer(string option)
{
    if (option == "1")
    {
        buycompre();
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "1.View Goods 2.Buy 3.Search 4.My Order 5.View Details 6.Back" << endl;
        legal6(); buyer(option1);
    }
    //查看商品列表okk
    else if (option == "2")
    {
        cout << "Please enter goods ID:"; string comID; cin >> comID;
        cout << "Please enter number:"; int num; cin >> num;
        fstream fu; fu.open("user.txt", ios::in);
        string str_cin, str;
        while (getline(fu, str_cin))
        {
            stringstream a; a << str_cin;
            getline(a, str, ',');

            if (str == name)
            {
                stringstream b; b << str_cin; getline(b, str, ',');
                getline(b, str, ','); getline(b, str, ','); getline(b, str, ',');
                getline(b, str, ',');
                getline(b, str, ','); goto end2;
            }

        }
        fu.close();
    end2:;
        double balance;
        balance = stod(str); string strprice, strnum, strseller;
        fstream fc; fc.open("commodity.txt", ios::in);
        while (getline(fc, str_cin))
        {
            stringstream a; a << str_cin;
            getline(a, str, ',');

            if (str == comID)
            {
                stringstream b; b << str_cin; string state;
                while (getline(b, str, ','))
                {
                    state = str;
                }
                if (state != "removed")
                {
                    getline(a, str, ','); getline(a, strprice, ',');
                    getline(a, strnum, ','); getline(a, str, ',');
                    getline(a, strseller, ','); goto end3;
                }
                else
                {
                    cout << endl << "-----The goods was removed-----" << endl;
                    goto end4;
                }
            }

        }
        fc.close();
    end3:;
        double price; price = stod(strprice); double myprice;
        cout << "Unit Price:" << setprecision(1) << setiosflags(ios::fixed) << price << endl;
        cout << endl << "Please enter your bid(your bid must be higher than unit price):";
        cin >> myprice;
        if (myprice < price)
            cout << endl << "Bid Failed!" << endl;
        else if (num > stod(strnum))
            cout << "You have purchased more than stored!" << endl;
        else
        {
            if (balance >= (num * myprice))
            {
                fstream fo;
                fo.open("store.txt", ios::out | ios::app);
                fo << comID << ",";
                fo << setprecision(1) << setiosflags(ios::fixed) << myprice << ",";
                fo << num << ",";
                fo << strseller << "," << name << ",0" << endl;
                fo.close();
                //增加临时订单okk

                cout << "**********************************************************************" << endl;
                cout << "ATENTION!!!" << endl;
                cout << "Time:";
                time_t dp;
                dp = time(0);
                struct tm* ds;
                ds = localtime(&dp);
                char date[20];
                strftime(date, 30, "2022-%m-%d", ds);
                string d; d = date;
                cout << date;
                cout << endl;
                cout << "Unit Price:" << setprecision(1) << setiosflags(ios::fixed) << price << endl;
                cout << "Number:" << num << endl;
                cout << "The prepayment is successful!" << endl;
                cout << "Your balance:" << setprecision(1) << setiosflags(ios::fixed) << balance - num * price << endl;
                cout << endl << "If the bid fails, the system will automatically refund you!" << endl;
                cout << "*********************************************************************" << endl;
            }
            else
            {
                cout << endl << endl;
                cout << "-----Insufficient balance! Transaction failed!!!-----" << endl;
                cout << endl << "Tips: You can increase your balance by selling goods and recharging!" << endl << endl;
            }
        }
    end4:;

        cout << endl << endl << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "1.View Goods 2.Buy 3.Search 4.My Order 5.View Details 6.Back" << endl;
        legal6(); buyer(option1);
    }
    //购买商品okk
    else if (option == "3")
    {
        buysearch();
        cout << endl << endl << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "1.View Goods 2.Buy 3.Search 4.My Order 5.View Details 6.Back" << endl;
        legal6(); buyer(option1);
    }
    //搜索商品okk
    else if (option == "4")
    {
        buyordpre();
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "1.View Goods 2.Buy 3.Search 4.My Order 5.View Details 6.Back" << endl;
        legal6(); buyer(option1);
    }
    //查看历史订单okk
    else if (option == "5")
    {
        buycompre_detail();
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "1.View Goods 2.Buy 3.Search 4.My Order 5.View Details 6.Back" << endl;
        legal6(); buyer(option1);
    }
    //查看商品详细信息okk
    else if (option == "6")
    {
        system("pause");
        system("cls");
        cout << "******************************************************" << endl;
        cout << endl << "1.BUYER  2.SELLER  3.PERSONAL INFORMATION  4.EXIT" << endl;
        legal4(); User user;
        user.usfunction(option1);
    }
    //返回用户主界面okk
}
//买家功能okk