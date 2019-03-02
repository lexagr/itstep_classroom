#include<iostream>
using namespace std;
#include"Mass.h"
void F(Mass tmp)
{
	cout << "F.\n";
}
Mass F1()
{
	Mass tmp(3);
	cout << "F1.\n";
	return tmp;
}
int main()
{
	Mass obj1=5;
	obj1.Rand();
	obj1.Print();
	Mass obj2=3;
	obj2.Rand();
	obj2.Print();
	Mass obj3 = 7;
	obj3.Rand();
	obj3.Print();
	obj2=obj1=obj3;
	obj2.Print();
}
