#include<iostream>
using namespace std;
void Rand_Int(int *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 25;
	}
}
void Print_Int(int *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << "\t";
	}
	cout << "\n";
}
void Rand_Double(double *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand()/32767.0*25;
	}
}
void Print_Double(double *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << "\t";
	}
	cout << "\n";
}
