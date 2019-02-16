#include<iostream>
using namespace std;
#include"Drob.h"
int main()
{
	Drob d1(1,3), d2(2,5);
	Drob rez = d1.Add(d2);
	rez.Show();
}