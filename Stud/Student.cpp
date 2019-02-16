#include "Student.h"
#include<iostream>
using namespace std;
void Student::Vvod()
{
	cout << "Vvedite Fio: ";
	cin >> Fio;
	cout << "Vvedite Age: ";
	cin >> Age;
}

void Student::Show()
{
	cout << "Fio: " << Fio << "\tAge: " << Age << "\n";
}
