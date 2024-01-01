#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<sstream>
#include<stdio.h>

#include <ctime>
using namespace std;
extern string name, key, option1; 
int firstop(string op);//第一次选择
int legal4();//用户使用合法判断，1为合法
int legal6();//6个选择的检查
int legal8();
void fail(double price, int number, string buyID);//退款
void complete(string comID);//按照store退款
int datacheck(int month, int day);//检查是否需要下架
int success(string comID, double price, int number, string selID, string buyID);
//竞拍成功的人修改信息
void settlement(string num1, string comID);
void com_check();
//检查到商品时间超过24小时就下架,如果是售卖状态就结算


