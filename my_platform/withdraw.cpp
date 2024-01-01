#include"admin.h"
#include"user.h"
void admin::adwithdraw()
{
    ifstream f; ofstream of; int i = 0; string str; ; string s;
    f.open("commodity.txt", ios::in); string str_cin;
    of.open("comofftemp.txt", ios::out);
    cout << "Please enter commodityID:"; string temp; cin >> temp;
    cout << endl << endl;

    int flag = 0; cout << "Are you sure you want to take the item off the shelves?" << endl;
    cout << "-------------------------------------------------------------------------------------------------------";
    cout << endl;
    cout << std::left << setw(12) << "comID:";
    cout << std::left << setw(12) << " comName:";
    cout << std::left << setw(12) << "  price:";
    cout << std::left << setw(12) << " number:";
    cout << std::left << setw(12) << "    description:";
    cout << std::left << setw(12) << "  sellerID:";
    cout << std::left << setw(12) << "   addedDate:";
    cout << std::left << setw(12) << "     state:" << endl;
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
                    cout << "Enter your option（y/n):"; cin >> op;
                    if (op == "y")//下架
                    {
                        flag = 1; stringstream c; c << str_cin;
                        while (getline(c, str, ','))
                        {
                            if (str == "onAuction" || str == "removed")
                            {
                                of << "removed" << endl;
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
        cout << endl << endl << "-----FAILED!-----" << endl << endl;
    }
    else if (flag == 1)
    {
        cout << endl << endl << "-----SUCCESS!-----" << endl << endl;
        string strcopy;
        ofstream ofs; ofs.open("commodity.txt", ios::out);
        ifstream fs; fs.open("comofftemp.txt", ios::in);
        while (getline(fs, strcopy))
        {
            ofs << strcopy << endl;
        }
        fs.close(); ofs.close();
    }
}
void Seller::selwithdraw()
{
    cout << "Enter commodityID:"; string temp; cin >> temp;
    cout << endl << endl;
    cout << "Are you sure you want to take the item off the shelves?" << endl;
    cout << "----------------------------------------------------------------------------------------------";
    cout << endl;
    cout << std::left << setw(12) << "comID:";
    cout << std::left << setw(12) << " comName:";
    cout << std::left << setw(12) << "  price:";
    cout << std::left << setw(12) << " number:";
    cout << std::left << setw(12) << "   sellerID:";
    cout << std::left << setw(12) << "     addedDate:";
    cout << std::left << setw(12) << "     state:" << endl;
    int flag = 0;
    ifstream f; string str; ; string s;
    f.open("commodity.txt", ios::in); string str_cin;
    ofstream of; of.open("comotemp.txt", ios::out);
    while (getline(f, str_cin))
    {
        stringstream a;
        a << str_cin;
        while (getline(a, str, ','))
        {
            if (str == temp)//找到该商品
            {
                for (int j = 1; j <= 5; ++j)
                {
                    getline(a, str, ',');
                }
                if (str == name)//是该用户发布的
                {
                    flag = 1;
                    stringstream b;
                    b << str_cin; int i = 1;
                    while (getline(b, str, ','))
                    {

                        if (i != 5)
                            cout << std::left << setw(12) << str << " ";

                        ++i;
                    }
                    cout << endl << "----------------------------------------------------------------------------------------------";
                    cout << endl;
                    cout << endl << "Enter your option（y/n):"; string yn; cin >> yn;
                    if (yn == "y")//下架
                    {
                        stringstream c; c << str_cin;
                        while (getline(c, str, ','))
                        {
                            if (str == "onAuction" || str == "removed")
                            {
                                of << "removed" << endl;
                                break;
                            }


                            of << str << ",";
                        }
                        break;
                    }
                    else//不下架
                    {
                        cout << endl << endl << "-----FAILED!-----" << endl << endl;
                        goto end1;
                    }
                }
                else
                {
                    cout << endl << "----------------------------------------------------------------------------------------------";
                    cout << endl;
                    cout << endl << endl << "-----FAILED!-----" << endl << endl;
                    goto end1;
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
        cout << endl << endl << "-----FAILED!-----" << endl << endl;
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

end1:;
}