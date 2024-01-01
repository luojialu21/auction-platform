#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<sstream>
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
using namespace std;
extern string name, key, option1;
class Buyer 
{
public:
	void buyer(string option);//买家功能
	void buyordpre();//用户订单展示
private:
	void buysearch();//买家搜索商品
	
	void buycompre(); //买家商品展示
	void buycompre_detail();//买家商品详细信息
};
