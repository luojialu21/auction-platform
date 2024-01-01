#include"admin.h"
#include"user.h"
void admin::adordpre()
{
    cout << "-------------------------------------------------------------------------------------------------------";
    cout << endl;
    fstream f;  string str;  string s;
    f.open("order.txt", ios::in); string str_cin;
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
    cout << endl;
}
void Buyer::buyordpre()
{
    cout << "-------------------------------------------------------------------------------------------------------";
    cout << endl;
    cout << std::left << setw(13) << "orderID";
    cout << std::left << setw(13) << "comID";
    cout << std::left << setw(13) << "unitPrice";
    cout << std::left << setw(13) << "number";
    cout << std::left << setw(13) << "date";
    cout << std::left << setw(13) << "sellerID" << endl;
    fstream f;  string str;  string s;
    f.open("order.txt", ios::in); string str_cin, buyer1;
    while (getline(f, str_cin))
    {
        stringstream a;
        a << str_cin;

        while (getline(a, str, ','))
        {
            buyer1 = str;
        }
        if (buyer1 == name)
        {
            stringstream b;
            b << str_cin;
            for (int i = 1; i <= 6; ++i)
            {
                getline(b, str, ',');
                cout << std::left << setw(13) << str;

            }
            cout << endl;
        }

    }
    f.close();
    cout << "-------------------------------------------------------------------------------------------------------";
    cout << endl;
}
void Seller::selordpre()
{
    cout << "-------------------------------------------------------------------------------------------------------";
    cout << endl;
    cout << std::left << setw(12) << "orderID";
    cout << std::left << setw(12) << " comName";
    cout << std::left << setw(12) << "  unitprice";
    cout << std::left << setw(12) << " number";
    cout << std::left << setw(12) << "    date";
    cout << std::left << setw(12) << "     buyerID" << endl;
    int flag = 0;
    fstream f; string str; ; string s;
    f.open("order.txt", ios::in); string str_cin;
    while (getline(f, str_cin))
    {
        stringstream a;
        a << str_cin; int j = 1;
        while (getline(a, str, ','))
        {

            if (str == name && j == 6)//ÕÒµ½×Ô¼º
            {
                flag = 1;
                stringstream b;
                b << str_cin; int i = 1;
                while (getline(b, str, ','))
                {

                    if (i != 6)
                        cout << std::left << setw(12) << str << " ";

                    ++i;
                }
                cout << endl;
            }
            ++j;
        }

    }
    f.close();
    cout << "-------------------------------------------------------------------------------------------------------";

    if (flag == 0)
    {
        cout << endl << endl;
        cout << "You haven't sold a product yet, please go ahead and list it!" << endl << endl;
    }

}
void admin::adordpre_detail()
{
    cout << endl << "Enter userID:";
    cin >> name;
    cout << endl << "SOLD:" << endl;
    Seller sel; sel.selordpre();
    cout << endl << endl << "BOUGHT:" << endl;
    Buyer buy; buy.buyordpre();
}