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
class admin
{
public:
	int adsignin();
	int adfunction(string option);
private:
	void adcompre();
	void adordpre();
	void adsearch();
	void adwithdraw();
	void aduserpre();
	void adordpre_detail();
};
