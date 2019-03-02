#include "Flat.h"
#include<iostream>
using namespace std;

Flat::Flat()
{
	mas = NULL;
	size = 0;
	Nomer = 0;
}

Flat::Flat(const Flat &copy)
{
	size = copy.size;
	Nomer = copy.Nomer;
	mas = new Human[size];
	for (int i = 0; i < size; i++)
	{
		mas[i] = copy.mas[i];
	}
}

Flat & Flat::operator=(const Flat &copy)
{
	if (this != &copy)
	{
		if (mas != NULL) delete[] mas;
		size = copy.size;
		Nomer = copy.Nomer;
		mas = new Human[size];
		for (int i = 0; i < size; i++)
		{
			mas[i] = copy.mas[i];
		}
	}
	return *this;
}

void Flat::Add_Human()
{
	Human tmp;
	tmp.Vvod();
	int f = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(tmp.GetFio(), mas[i].GetFio()) == 0)
		{
			f = 1;
			break;
		}
	}
	if (f == 0)
	{
		Human *New = new Human[size + 1];
		for (int i = 0; i < size; i++)
		{
			New[i] = mas[i];
		}
		New[size] = tmp;
		delete[] mas;
		mas = New;
		size++;
		cout << "Zaselen gilec.\n";
	}
	else
	{
		cout << "Takoi gilec uge yest.\n";
	}
}

void Flat::Del_Human()
{
	char str[20];
	cout << "Vvedite Fio: ";
	gets_s(str);
	int f = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(str, mas[i].GetFio()) == 0)
		{
			f = 1;
			break;
		}
	}
	if (f == 1)
	{
		Human *New = new Human[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (strcmp(str, mas[i].GetFio()) != 0)
			{
				New[j] = mas[i];
				j++;
			}
		}
		delete[] mas;
		mas = New;
		size--;
		cout << "Gilec viselen.\n";
	}
	else
	{
		cout << "Takogo gilca net.\n";
	}
}


void Flat::Print()
{
	cout << "Nomer Flat: " << Nomer << "\n";
	for (int i = 0; i < size; i++)
	{
		mas[i].Show();
	}
}

void Flat::SetNomer(int n)
{
	Nomer = n;
}

int Flat::Poisk_Fio(const char *str)
{
	int f = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(mas[i].GetFio(), str) == 0)
		{
			cout << "Gilec givet v kvartire: " << Nomer << "\n";
			mas[i].Show();
			f = 1;
		}
	}
	return f;
}

int Flat::GetSize()
{
	return size;
}

Flat::~Flat()
{
	delete[] mas;
}
