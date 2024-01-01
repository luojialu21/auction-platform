#include"check.h"
string name, option1, key;
int main()
{
    cout << "============================================================" << endl;
    cout << "        Welcome to the Merchandise Auction Platform" << endl;
    cout << "=============================================================" << endl<<endl<<endl;
    system("pause");
    system("cls");

    cout << "---------------------------------------------------------------" << endl ;
    cout << "1.Admin Sign in  2.User Enroll  3.User Sign in  4.Exit" << endl << endl;
    cout << "Please enter a number to select(1~4):";
    cin >> option1; firstop(option1);


    return 0;
}
