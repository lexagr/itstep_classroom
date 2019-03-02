#include "Mass.h"
#include <iostream>
using namespace std;


Mass::Mass()
{
	this->mas = NULL;
	this->size = 0;
}

Mass::Mass(int size)
{
	cout << "Constr. s param. " << size << "\n";
	this->size = size;//(*this).size
	this->mas = (int*)malloc(this->size * sizeof(int));
}

Mass::Mass(const Mass &copy)
{
	cout << "Constr. copy." << copy.size << "\n";
	this->size = copy.size;
	this->mas = (int*)malloc(this->size * sizeof(int));
	/*for (int i = 0; i < this->size; i++)
	{
		this->mas[i] = copy.mas[i];
	}*/
	memcpy(this->mas, copy.mas, sizeof(int)*this->size);
}

void Mass::Rand()
{
	for (int i = 0; i < this->size; i++)
	{
		this->mas[i] = rand() % 25;
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

Mass & Mass::operator=(const Mass &copy)
{
	if (this->mas != NULL) free(mas);
	this->size = copy.size;
	this->mas = (int*)malloc(this->size * sizeof(int));
	memcpy(this->mas, copy.mas, sizeof(int)*this->size);
	return *this;
}

Mass::~Mass()
{
	cout << "Destr. " << this->size << "\n";
	free(mas);
}
