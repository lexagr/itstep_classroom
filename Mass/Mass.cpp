#include "Mass.h"
#include<iostream>
using namespace std;

Mass::Mass()
{
	cout << "Constr. bez param.\n";
	this->mas = NULL;
	this->size = 0;
}

Mass::Mass(int size)
{
	this->size = size;
	cout << "Constr. s param " << size << "\n";
	this->mas = (int*)malloc(size * sizeof(int));
}

Mass::Mass(const Mass & copy)
{
	cout << "Constr. copy. " << copy.size << "\n";
	size = copy.size;
	mas = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		mas[i] = copy.mas[i];
	}
}

Mass Mass::operator=(const Mass &copy)
{
	if (mas != NULL) free(mas);
	size = copy.size;
	mas = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		mas[i] = copy.mas[i];
	}
	return *this;
}

void Mass::Rand()
{
	for (int i = 0; i < this->size; i++)
	{
		this->mas[i] = rand() % 20;
	}
}

void Mass::Print()
{
	for (int i = 0; i < this->size; i++)
	{
		cout << this->mas[i] << "\t";
	}
	cout << "\n";
}

Mass::~Mass()
{
	cout << "Destr. " << this->size << "\n";
	free(this->mas);
}
