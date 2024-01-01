#include"admin.h"
#include"user.h"
void admin::aduserpre()
{
    cout << "-------------------------------------------------------------------------------------------------------";
    cout << endl;
    fstream f; int i = 0; string str; ; string s;
    f.open("user.txt", ios::in); string str_cin;
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
void User::ususerpre()
{
    cout << "------------------------------------------------" << endl;
    fstream f; int i = 0; string str; ; string s;
    f.open("user.txt", ios::in); string str_cin;
    while (getline(f, str_cin))
    {
        stringstream a;
        a << str_cin;

        while (getline(a, str, ','))
        {
            if (str == name)
            {
                stringstream b; b << str_cin; getline(b, str, ',');
                cout << "NAME:" << str << endl;
                getline(b, str, ','); getline(b, str, ','); getline(b, str, ',');
                cout << "PHONE:" << str << endl;
                getline(b, str, ',');
                cout << "ADDRESS:" << str << endl;
                getline(b, str, ',');
                cout << "BALANCE:" << str << endl;

            }

        }
    }
    f.close();
    cout << "------------------------------------------------";
    cout << endl;
}