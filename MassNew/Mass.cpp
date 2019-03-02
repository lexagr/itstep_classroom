#include "Mass.h"
#include<iostream>
using namespace std;

Mass::Mass()
{
	mas = NULL;
	size = 0;
}

Mass::Mass(int n)
{
	size = n;
	mas = (int*)malloc(n * sizeof(int));
}

Mass::Mass(const Mass &copy)
{
	size = copy.size;
	mas = (int*)malloc(size * sizeof(int));
	memcpy(mas, copy.mas, size * sizeof(int));
}

Mass & Mass::operator=(const Mass &copy)
{
	if (this != &copy)
	{
		if (mas != NULL) free(mas);
		size = copy.size;
		mas = (int*)malloc(size * sizeof(int));
		memcpy(mas, copy.mas, size * sizeof(int));
	}
	return *this;
}

Mass Mass::operator+(const Mass &ob)
{
	Mass tmp;
	tmp.size = (size < ob.size) ? size : ob.size;
	tmp.mas = (int*)malloc(tmp.size * sizeof(int));
	for (int i = 0; i < tmp.size; i++)
	{
		tmp.mas[i] = mas[i] + ob.mas[i];
	}
	return tmp;
}

Mass Mass::operator+(const int &num)
{
	Mass tmp;
	tmp.size = size;
	tmp.mas = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		tmp.mas[i] = mas[i] + num;
	}
	return tmp;
}

Mass & Mass::operator++()
{
	mas = (int*)realloc(mas, (size + 1) * sizeof(int));
	mas[size] = 1000;
	size++;
	return *this;
}

Mass Mass::operator++(int n)
{
	Mass tmp = *this;
	mas = (int*)realloc(mas, (size + 1) * sizeof(int));
	mas[size] = 1000;
	size++;
	return tmp;
}

bool Mass::operator==(const Mass &ob)
{
	if (size != ob.size) return false;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] != ob.mas[i]) return false;
	}
	return true;
}

bool Mass::operator!=(const Mass &ob)
{
	return !(*this == ob);
}

int Mass::operator[](int ind)
{
	if (ind < 0)
	{
		cout << "Vash index <0.\n";
		return mas[0];
	}
	if (ind > size - 1)
	{
		cout << "Vash index >" << size - 1 << "\n";
		return mas[size - 1];
	}
	return mas[ind];
}

int Mass::operator()(int num,int l,int r)
{
	for (int i = l; i <= r; i++)
	{
		if (mas[i] == num)
			return i;
	}
	return -1;
}

Mass::operator int()
{
	int s = 0;
	for (int i = 0; i < size; i++)
	{
		s = s + mas[i];
	}
	return s;
}

void Mass::Rand() const
{
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 25;
	}
}

void Mass::Print() const
{
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << "\t";
	}
	cout << "\n";
}

Mass::~Mass()
{
	free(mas);
}

Mass operator+(const int &num, Mass &ob)
{
	Mass tmp;
	tmp.size = ob.size;
	tmp.mas = (int*)malloc(tmp.size * sizeof(int));
	for (int i = 0; i < tmp.size; i++)
	{
		tmp.mas[i] = num + ob.mas[i];
	}
	return tmp;
}
//Mass operator+(const int &num, Mass &ob)
//{
//	Mass tmp = ob + num;
//	return tmp;
//}
