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
extern string name, key, option1;//选择
class Buyer; class Seller;
class User
{
public:
	void usfunction(string option);//用户的四个功能
	int user_login();//用户登录
	void enroll();//用户注册
private:
	
	
	friend class Buyer; 
	friend class Seller;
	void message(string option);//查看信息系统
	int temID_check(string temID);//用户名修改时重复检查
	int key_check();//注册时候密码两次一样
	void ususerpre();//用户个人信息展示
};
