#include "Grupa.h"
#include<iostream>
using namespace std;
Grupa::Grupa(const char *str)
{
	strcpy_s(Nazv, str);
	size = 0;
	mas = NULL;
}

void Grupa::Add()
{
	mas = (Student *)realloc(mas, (size + 1) * sizeof(Student));
	mas[size].Vvod();
	size++;
}

void Grupa::Print()
{
	cout << "Nazv: " << Nazv << "\n";
	for (int i = 0; i < size; i++)
	{
		mas[i].Show();
	}
}

Grupa::~Grupa()
{
	free(mas);
}
