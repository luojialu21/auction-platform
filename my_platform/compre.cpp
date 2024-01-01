#include"user.h"
#include"admin.h"
void admin::adcompre()
{
    cout << "-------------------------------------------------------------------------------------------------------";
    cout << endl;
    fstream f; int i = 0; string str; ; string s;
    f.open("commodity.txt", ios::in); string str_cin;
    while (getline(f, str_cin))
    {
        stringstream a;
        a << str_cin;

        while (getline(a, str, ','))
        {
            cout << std::left << setw(12) << str << " ";
        }
        cout << endl;
    }
    f.close();
    cout << "-------------------------------------------------------------------------------------------------------";
}
void Seller::selcompre()
{
    cout << "-------------------------------------------------------------------------------------------------------";
    cout << endl;
    cout << std::left << setw(12) << "comID";
    cout << std::left << setw(12) << " comName";
    cout << std::left << setw(12) << "  price";
    cout << std::left << setw(12) << " number";
    cout << std::left << setw(12) << "    addedDate";
    cout << std::left << setw(12) << "     state" << endl;
    int flag = 0;
    fstream f; string str; ; string s;
    f.open("commodity.txt", ios::in); string str_cin;
    while (getline(f, str_cin))
    {
        stringstream a;
        a << str_cin;
        while (getline(a, str, ','))
        {
            if (str == name)//找到自己
            {
                flag = 1;
                stringstream b;
                b << str_cin; int i = 1;
                while (getline(b, str, ','))
                {

                    if (i != 5 && i != 6)
                        cout << std::left << setw(12) << str << " ";

                    ++i;
                }
                cout << endl;
            }
        }

    }
    f.close();
    cout << "-------------------------------------------------------------------------------------------------------";

    if (flag == 0)
    {
        cout << endl << endl;
        cout << "You haven't listed a product yet, please go ahead and list it" << endl << endl;
    }
}
void Buyer::buycompre()
{
    cout << "--------------------------------------------------------------------------------------";
    cout << endl;
    cout << std::left << setw(12) << "comID";
    cout << std::left << setw(12) << " comName";
    cout << std::left << setw(12) << "  price";
    cout << std::left << setw(12) << "   sellerID";
    cout << std::left << setw(12) << "    addedDate" << endl;
    fstream f; string str; int flag = 0;
    f.open("commodity.txt", ios::in); string str_cin;
    while (getline(f, str_cin))
    {
        stringstream a; a << str_cin;
        while (getline(a, str, ','))
        {
            for (int i = 1; i <= 7; ++i)
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

    }
    f.close();
    cout << "---------------------------------------------------------------------------------------";
    cout << endl << endl << endl;

}
void Buyer::buycompre_detail()
{
    cout << "Please enter commodity ID:";
    string temp; cin >> temp;
    fstream f; string str; int flag = 0;

    f.open("commodity.txt", ios::in); string str_cin;
    while (getline(f, str_cin))
    {
        stringstream a; a << str_cin;
        getline(a, str, ',');
        if (str == temp)//找到商品
        {

            for (int i = 1; i <= 7; ++i)
            {
                getline(a, str, ',');
            }
            if (str == "onAuction")
            {
                flag = 1;
                stringstream b; b << str_cin;
                cout << "------------------------------------------------" << endl;
                getline(b, str, ','); cout << "commodityID:" << str << endl;
                getline(b, str, ','); cout << "name:" << str << endl;
                getline(b, str, ','); cout << "price:" << str << endl;
                getline(b, str, ','); getline(b, str, ',');  cout << "description:" << str << endl;
                getline(b, str, ','); cout << "seller:" << str << endl;
                getline(b, str, ','); cout << "added date:" << str << endl;
                cout << "------------------------------------------------" << endl;
            }
            else
                break;
        }
    }
    f.close();

    cout << endl << endl << endl;
    if (flag == 0)
        cout << "-----Not Found-----" << endl << endl;

}