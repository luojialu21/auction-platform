#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<sstream>
#include<stdio.h>
#include"buyer.h"
#include"seller.h"
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
using namespace std;
extern string name, key, option1;//ѡ��
class Buyer; class Seller;
class User
{
public:
	void usfunction(string option);//�û����ĸ�����
	int user_login();//�û���¼
	void enroll();//�û�ע��
private:
	
	
	friend class Buyer; 
	friend class Seller;
	void message(string option);//�鿴��Ϣϵͳ
	int temID_check(string temID);//�û����޸�ʱ�ظ����
	int key_check();//ע��ʱ����������һ��
	void ususerpre();//�û�������Ϣչʾ
};
