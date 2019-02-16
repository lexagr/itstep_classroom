#pragma once
#include"Student.h"
class Grupa
{
	Student *mas;
	char Nazv[15];
	int size;
public:
	Grupa(const char *);
	void Add();
	void Print();
	~Grupa();
};

