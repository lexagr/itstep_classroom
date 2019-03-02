#include<iostream>
#include<conio.h>
using namespace std;
#include"Mass.h"
int main()
{
	Mass ob1(5);
	ob1.Rand();
	ob1.Print();
	Mass ob2(10);
	ob2.Rand();
	ob2.Print();
	cout << ob2(20,1,9);
}