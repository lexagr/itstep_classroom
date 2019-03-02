#include "Human.h"
#include<iostream>
using namespace std;

char* Human::Gets()
{
	char ch;
	int n = 0;
	char *str = NULL;
	while ((ch = getchar()) != '\n')
	{
		str = (char*)realloc(str, n + 1);
		str[n] = ch;
		n++;
	}
	str = (char*)realloc(str, n + 1);
	str[n] = 0;
	return str;
}

Human::Human()
{
	Fio = NULL;
}

Human::Human(const Human &copy)
{
	Age = copy.Age;
	Fio = (char*)malloc(strlen(copy.Fio) + 1);
	strcpy_s(Fio, strlen(copy.Fio)+1,copy.Fio);
}

Human & Human::operator=(const Human &copy)
{
	if (this != &copy)
	{
		if (Fio != NULL) free(Fio);
		Age = copy.Age;
		Fio = (char*)malloc(strlen(copy.Fio) + 1);
		strcpy_s(Fio, strlen(copy.Fio) + 1, copy.Fio);
	}
	return *this;
}

void Human::Vvod()
{
	cout << "Vvedite Fio: ";
	if (Fio != NULL) free(Fio);
	Fio = Gets();
	cout << "Vvedite Age: ";
	cin >> Age;
	cin.ignore();
}

void Human::Show()
{
	cout << "Fio: " << Fio << "\tAge: " << Age << "\n";
}

char * Human::GetFio()
{
	return Fio;
}


Human::~Human()
{
	free(Fio);
}
