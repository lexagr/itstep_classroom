#include<iostream>
using namespace std;
#include"Drob.h"
int main()
{
	Drob d1(2, 30), d2(2, 5);
	Drob rez = d1.Add(d2);
	rez.Print();
}
