#include "House.h"
#include <iostream>
using namespace std;

House::House(int n)
{
	size = n;
	dom = new Flat[size];
	for (int i = 0; i < size; i++)
	{
		dom[i].SetNomer(i + 1);
	}
	cout << "Vvedite Adress: ";
	gets_s(Adress);
}

void House::Zaselenie()
{
	cout << "Vvedite nomer kvartiri: ";
	int Nom;
	cin >> Nom;
	cin.ignore();
	if (Nom <= size && Nom >= 1)
	{
		dom[Nom - 1].Add_Human();
	}
	else
	{
		cout << "Takogo nomera net.\n";
	}
}

void House::Viselenie()
{
	cout << "Vvedite nomer kvartiri: ";
	int Nom;
	cin >> Nom;
	cin.ignore();
	if (Nom <= size && Nom >= 1)
	{
		if (dom[Nom - 1].GetSize() != 0)
			dom[Nom - 1].Del_Human();
		else
			cout << "Kvartira pusta.\n";
	}
	else
	{
		cout << "Takogo nomera net.\n";
	}
}

void House::Print()
{
	cout << "Adress: " << Adress << "\n";
	int f = 0;
	for (int i = 0; i < size; i++)
	{
		if (dom[i].GetSize() != 0)
		{
			dom[i].Print();
			f = 1;
		}
	}
	if (f == 0)
		cout << "Dom pust.\n";
}

void House::Print_Flat()
{
	cout << "Vvedite nomer kvartiri: ";
	int Nom;
	cin >> Nom;
	cin.ignore();
	if (Nom <= size && Nom >= 1)
	{
		if (dom[Nom - 1].GetSize() != 0)
			dom[Nom - 1].Print();
		else
			cout << "Eta kvartira pusta.\n";
	}
	else
	{
		cout << "Takogo nomera net.\n";
	}
}

void House::Poisk_Gilca()
{
	char str[20];
	cout << "Vvedite Fio: ";
	gets_s(str);
	int f=0;
	for (int i = 0; i < size; i++)
	{
		if (dom[i].Poisk_Fio(str) == 1)
			f = 1;
	}
	if (f == 0)
		cout << "Takogo gilca net.\n";
}

House::~House()
{
	delete[] dom;
}
