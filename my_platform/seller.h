#include<string>
#include<sstream>
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
using namespace std;
extern string name, key, option1;
class Seller
{
public:
	void seller(string option);//卖家功能
	void selordpre();
private:
	void selcompre();//卖家商品展示
	
	void selwithdraw();//卖家下架商品
}; 
