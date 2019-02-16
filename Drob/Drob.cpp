#include "Drob.h"
#include<iostream>
using namespace std;


Drob::Drob()
{
}

Drob::Drob(int a, int b)
{
	ch = a;
	zn = b;
}

void Drob::Show()
{
	cout << ch << "/" << zn << "\n";
}

Drob Drob::Add(Drob d2)
{
	Drob tmp;
	tmp.zn = zn * d2.zn;
	tmp.ch = ch * d2.zn + d2.ch*zn;
	return tmp;
}

