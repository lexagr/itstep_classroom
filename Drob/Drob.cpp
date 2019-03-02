#include "Drob.h"
#include <iostream>
using namespace std;
void Drob::NOD()
{
	int a = ch, b = zn;
	while (a != b)
	{
		if (a > b) a = a - b;
		else b = b - a;
	}
	ch = ch / a;
	zn = zn / a;
}
Drob::Drob(int a, int b)
{
	ch = a;
	zn = b;
}

void Drob::Print()
{
	cout << ch << "/" << zn << "\n";
}

Drob Drob::Add(Drob tmp)
{
	Drob r;
	r.zn = zn * tmp.zn;
	r.ch = ch * tmp.zn + tmp.ch*zn;
	r.NOD();
	return r;
}
