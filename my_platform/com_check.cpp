#include"check.h"
#define _CRT_SECURE_NO_WARNINGS
void fail(double price, int number, string buyID)
{
    fstream fus; int i = 0;  double bala; string str_cin, str;
    ofstream ofus; ofus.open("usertemp.txt", ios::out);
    fus.open("user.txt", ios::in);
    while (getline(fus, str_cin))
    {
        stringstream a;
        a << str_cin;
        while (getline(a, str, ','))
        {
            if (str == buyID)
            {
                ofus << buyID;
                for (int i = 1; i <= 6; ++i)
                {
                    getline(a, str, ',');
                    if (i == 5)
                    {
                        stringstream bal;
                        bal << str;  bal >> bala;
                        bala = bala + number * price;
                        ofus << "," << setprecision(1) << setiosflags(ios::fixed) << bala;
                        continue;
                    }
                    ofus << "," << str;
                }
                ofus << endl;

            }
            //退款
            else
            {
                ofus << str_cin << endl;
                break;
            }

        }
    }
    fus.close(); ofus.close();
    string strcopy;
    ofstream ofs; ofs.open("user.txt", ios::out);
    ifstream fs; fs.open("usertemp.txt", ios::in);
    while (getline(fs, strcopy))
    {
        ofs << strcopy << endl;
    }
    fs.close(); ofs.close();





}
//退款
void complete(string comID)
{
    ifstream f; f.open("store.txt", ios::in);
    ofstream of; of.open("storetemp.txt", ios::out);
    string str_cin, str;
    while (getline(f, str_cin))
    {
        stringstream a; a << str_cin;
        getline(a, str, ',');
        if (str == comID)
        {
            double price; stringstream s; getline(a, str, ',');
            s << str; s >> price;
            getline(a, str, ','); int number; stringstream n;
            n << str; n >> number;
            getline(a, str, ','); getline(a, str, ',');
            string buyID; fail(price, number, buyID);
        }
        else
            of << str_cin << endl;
    }
    f.close(); of.close();

    f.open("storetemp.txt", ios::in); of.open("store.txt", ios::out);
    string strcopy;
    while (getline(f, strcopy))
    {
        of << strcopy << endl;
    }
    f.close(); of.close();
    //删除所有comID信息
}
//按照store退款

int datacheck(int month, int day)
{
    time_t dp;
    dp = time(0);
    struct tm* ds;
    ds = localtime(&dp);
    char date[20];
    strftime(date, 30, "2022-%m-%d", ds);
    string d; d = date;
    int sysmonth = (d[5] - 48) * 10 + d[6] - 48;
    int sysday = (d[8] - 48) * 10 + d[9] - 48;
    if (sysmonth > month)
        return 1;
    else if (sysday > day)
        return 1;
    else
        return 0;
}
//检查是否需要下架
int success(string comID, double price, int number, string selID, string buyID)
{//删除store里面的最大，商品数量--，订单++，余额++，--
    string str, str_cin; string strcopy;
    ifstream fss; fss.open("store.txt", ios::in); int flagg = 0;
    ofstream ofss; ofss.open("storetemp.txt", ios::out);
    while (getline(fss, str_cin))
    {
        flagg = 1;
        stringstream a; a << str_cin;
        getline(a, str, ',');
        if (str == comID)
        {
            getline(a, str, ','); stringstream prid; prid << str;
            double price1d; prid >> price1d;
            if (price1d == price) {
                getline(a, str, ',');
                int num1; stringstream numd; numd << str; numd >> num1;
                if (num1 == number) {
                    getline(a, str, ',');
                    if (str == selID) {
                        getline(a, str, ',');
                        if (str == buyID)
                            continue;
                    }
                }
            }
        }
        ofss << str_cin << endl;
    }
    fss.close(); ofss.close();
    if (flagg == 0)
        return 0;//没有需要处理的订单
    ofstream ofsss; ofsss.open("store.txt", ios::out);
    ifstream fsss; fsss.open("storetemp.txt", ios::in);

    while (getline(fsss, strcopy))
    {
        ofsss << strcopy << endl;

    }
    fsss.close(); ofsss.close();

    //store去掉这个订单



    fstream fcs; int numb;
    ofstream ofcs; ofcs.open("comtemp.txt", ios::out);
    fcs.open("commodity.txt", ios::in);
    while (getline(fcs, str_cin))
    {
        stringstream a;
        a << str_cin;
        while (getline(a, str, ','))
        {
            if (str == comID)
            {
                ofcs << comID;
                for (int i = 1; i <= 6; ++i)
                {
                    getline(a, str, ',');
                    if (i == 3)
                    {
                        stringstream number1;
                        number1 << str;  number1 >> numb;
                        numb = numb - number;
                        ofcs << "," << numb;
                        continue;
                    }
                    ofcs << "," << str;
                }
                ofcs << ",removed" << endl;
                break;
            }
            else
            {
                ofcs << str_cin << endl;
                break;
            }

        }
    }
    fcs.close(); ofcs.close();

    ofstream ous; ous.open("commodity.txt", ios::out);
    ifstream ufs; ufs.open("comtemp.txt", ios::in);
    while (getline(ufs, strcopy))
    {
        ous << strcopy << endl;
    }
    ufs.close(); ous.close();
    //商品数量减少





    fstream fus; int i = 0;  double bala;
    ofstream ofus; ofus.open("usertemp.txt", ios::out);
    fus.open("user.txt", ios::in);
    while (getline(fus, str_cin))
    {
        stringstream a;
        a << str_cin;
        while (getline(a, str, ','))
        {
            if (str == selID)//卖家余额增加
            {
                ofus << selID;
                for (int i = 1; i <= 6; ++i)
                {
                    getline(a, str, ',');
                    if (i == 5)
                    {
                        stringstream bal;
                        bal << str;  bal >> bala;
                        bala = bala + number * price;
                        ofus << "," << setprecision(1) << setiosflags(ios::fixed) << bala;
                        continue;
                    }
                    ofus << "," << str;
                }
                ofus << endl;
            }
            else
            {
                ofus << str_cin << endl;
                break;
            }
        }
    }
    fus.close(); ofus.close();

    ofstream ofs; ofs.open("user.txt", ios::out);
    ifstream fs; fs.open("usertemp.txt", ios::in);
    while (getline(fs, strcopy))
    {
        ofs << strcopy << endl;
    }
    fs.close(); ofs.close();
    //卖家余额增加okk


    fstream fo; string last_str;
    fo.open("order.txt", ios::in);
    while (getline(fo, str_cin)) {//获得最后一行  
        last_str = str_cin;
    }
    fo.close();
    stringstream lastID1; lastID1 << last_str; string lastID;
    getline(lastID1, lastID, ',');
    int a = lastID[3]; int b = lastID[2]; int c = lastID[1];
    int d = a - 48 + (b - 48) * 10 + (c - 48) * 100;
    fo.open("order.txt", ios::out | ios::app);
    fo << "T" << setw(3) << setfill('0');
    fo << d + 1 << ",";
    fo << comID << ",";
    fo << setprecision(1) << setiosflags(ios::fixed) << price << ",";
    fo << number << ",";
    time_t dp;
    dp = time(0);
    struct tm* ds;
    ds = localtime(&dp);
    char date[20];
    strftime(date, 30, "2022-%m-%d", ds);
    string ddd; ddd = date;
    fo << date << ",";
    fo << selID << "," << buyID << endl;
    fo.close();
    //order增加订单okk


    return numb;
}
//竞拍成功的人修改信息
void settlement(string num1, string comID)
{
    ifstream f; f.open("store.txt", ios::in); int flag = 0;

    string str, str_cin, buyID, selID; int number;
    double price = 0.0, temp = 0.0; int cnt; int flagp = 0;
    stringstream x; x << num1; int num; x >> num;
    do {
        while (getline(f, str_cin))
        {
            stringstream a; a << str_cin;
            getline(a, str, ',');
            if (comID == str)
            {
                flagp = 1;//有人竞拍
                while (getline(a, str, ','))
                {
                    stringstream pri;
                    pri << str; pri >> temp;
                    if (price < temp)
                    {
                        price = temp; stringstream cnt;
                        getline(a, str, ','); cnt << str; cnt >> number;
                        getline(a, str, ','); selID = str;
                        getline(a, str, ','); buyID = str;
                    }
                    else
                        break;
                }
            }
        } //找到最大出价
        if (flagp == 0)//没人竞拍
            break;
        if (num >= number)//储存量大于购买量
            flag = success(comID, price, number, selID, buyID);
        else//储存数量不足
        {
            flag = success(comID, price, num, selID, buyID);
            fail(price, number - num, buyID);
            //退款
        }
        num = flag;//剩余商品储存量
        f.close(); f.open("store.txt", ios::in);
        price = 0.0; flagp = 0;
    } while (flag != 0);  //M00x没有人买了，或者卖空了
    f.close();
    //要删除所有comID在store中的信息并且退款
    complete(comID);

}

void com_check()
{
    ifstream f; int i = 0; string str;
    f.open("commodity.txt", ios::in); string str_cin;
    string comID, number;
    while (getline(f, str_cin)) {//获得每一行
        stringstream a; a << str_cin; int i = 1;
        while (getline(a, str, ','))
        {//获得每一个
            if (i == 7)
            {
                int x = str[9] - 48, b = str[8] - 48;
                int day = b * 10 + x;//日
                x = str[6] - 48; b = str[5] - 48;
                int month = b * 10 + x;//月
                if (datacheck(month, day) == 1)
                {
                    getline(a, str, ',');
                    if (str == "onAuction")
                    {
                        stringstream d; d << str_cin;
                        getline(d, str, ','); comID = str;
                        getline(d, str, ','); getline(d, str, ',');
                        getline(d, str, ','); number = str;
                        settlement(number, comID);
                        break;
                    }
                    else if (str == "removed")
                        break;
                    break;
                }
            }
            //商品时间所在字符串
            i++;
        }
    }
    f.close();

}
//检查到商品时间超过24小时就下架,如果是售卖状态就结算