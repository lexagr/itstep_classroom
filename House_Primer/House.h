#pragma once
#include"Flat.h"
class House
{
	Flat *dom;
	int size;
	char Adress[25];
public:
	House(int);
	void Zaselenie();
	void Viselenie();
	void Print();
	void Print_Flat();
	void Poisk_Gilca();
	~House();
};

