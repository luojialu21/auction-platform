#include"admin.h"
#include"user.h"
void admin::adsearch()
{
    string::size_type idx;
    fstream f; int i = 0; string str; ; string s;
    f.open("commodity.txt", ios::in); string str_cin;
    cout << "Please enter commodity name:"; string temp; cin >> temp;
    cout << endl << endl; int flag = 0;
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
    while (getline(f, str_cin))
    {
        stringstream a;
        a << str_cin;//获得每一行
        int i = 1;
        while (getline(a, str, ','))
        {
            if (i == 2)//商品名称所在字符串
            {
                idx = str.find(temp);
                if (idx != string::npos)//找到相关商品
                {
                    stringstream b; b << str_cin;
                    while (getline(b, str, ','))
                    {
                        cout << std::left << setw(12) << str << " ";
                    }
                    cout << endl; flag = 1;
                }
                else
                    break;

            }
            i++;
        }

    }
    f.close();
    cout << "-------------------------------------------------------------------------------------------------------";
    cout << endl;
    if (flag == 0)
        cout << "-----NOT FOUND！-----";
}
void Buyer::buysearch()
{
    cout << "Please enter commodity name:";
    string temp; getchar(); getline(cin, temp);
    cout << "--------------------------------------------------------------------------------------";
    cout << endl;
    cout << std::left << setw(12) << "comID:";
    cout << std::left << setw(12) << " comName:";
    cout << std::left << setw(12) << "  price:";
    cout << std::left << setw(12) << "   sellerID:";
    cout << std::left << setw(12) << "    addedDate:" << endl;
    fstream f; string str; int flag = 0;
    f.open("commodity.txt", ios::in); string str_cin;
    string::size_type idx;
    while (getline(f, str_cin))
    {
        stringstream a; a << str_cin;
        while (getline(a, str, ','))
        {
            getline(a, str, ',');
            idx = str.find(temp);
            if (idx != string::npos)//找到商品
            {

                for (int i = 1; i <= 6; ++i)
                {
                    getline(a, str, ',');
                }
                if (str == "onAuction")
                {
                    flag = 1;
                    stringstream b; b << str_cin; int i = 1;
                    while (getline(b, str, ','))
                    {
                        if (i != 4 && i != 5 && i != 8)
                            cout << std::left << setw(12) << str << " ";
                        ++i;
                    }
                    cout << endl;
                }
                else
                    break;
            }
            else
                break;
        }

    }
    f.close();
    cout << "---------------------------------------------------------------------------------------";
    cout << endl << endl << endl;
    if (flag == 0)
        cout << "-----NOT FOUND！-----";
}