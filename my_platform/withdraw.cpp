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
    while (getline(f, str_cin)) {//���ÿһ��
        stringstream a; a << str_cin; int i = 1;
        while (getline(a, str, ',')) {//���ÿһ��
            if (i == 1) {
                if (str == temp) {//�ҵ������Ʒ
                    stringstream b; b << str_cin;
                    while (getline(b, str, ','))
                    {
                        cout << std::left << setw(12) << str << " ";
                    }
                    cout << endl;
                    string op;
                    cout << "-------------------------------------------------------------------------------------------------------";
                    cout << endl;
                    cout << "Enter your option��y/n):"; cin >> op;
                    if (op == "y")//�¼�
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
                    else//���¼�
                    {
                        flag = 0;
                    }
                }
                else
                    of << str_cin << endl;//���������Ʒ
            }
            //��Ʒ���������ַ���

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
            if (str == temp)//�ҵ�����Ʒ
            {
                for (int j = 1; j <= 5; ++j)
                {
                    getline(a, str, ',');
                }
                if (str == name)//�Ǹ��û�������
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
                    cout << endl << "Enter your option��y/n):"; string yn; cin >> yn;
                    if (yn == "y")//�¼�
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
                    else//���¼�
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
            }//���������Ʒ
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