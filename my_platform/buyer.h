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
	void buyer(string option);//��ҹ���
	void buyordpre();//�û�����չʾ
private:
	void buysearch();//���������Ʒ
	
	void buycompre(); //�����Ʒչʾ
	void buycompre_detail();//�����Ʒ��ϸ��Ϣ
};
