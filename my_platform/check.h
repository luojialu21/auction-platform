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
int firstop(string op);//��һ��ѡ��
int legal4();//�û�ʹ�úϷ��жϣ�1Ϊ�Ϸ�
int legal6();//6��ѡ��ļ��
int legal8();
void fail(double price, int number, string buyID);//�˿�
void complete(string comID);//����store�˿�
int datacheck(int month, int day);//����Ƿ���Ҫ�¼�
int success(string comID, double price, int number, string selID, string buyID);
//���ĳɹ������޸���Ϣ
void settlement(string num1, string comID);
void com_check();
//��鵽��Ʒʱ�䳬��24Сʱ���¼�,���������״̬�ͽ���


