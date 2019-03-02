#pragma once
#include"Human.h"
class Flat
{
	Human *mas;
	int size;
	int Nomer;
public:
	Flat();
	Flat(const Flat &);
	Flat & operator=(const Flat &);
	void Add_Human();
	void Del_Human();
	void Print();
	void SetNomer(int);
	int Poisk_Fio(const char *);
	int GetSize();
	~Flat();
};

