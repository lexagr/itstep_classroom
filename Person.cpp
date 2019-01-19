#include<iostream>
using namespace std;
struct Person
{
	char Fio[20];
	int Age;
};
Person Vvod()
{
	Person tmp;
	cout << "Vvedite Fio: ";
	gets_s(tmp.Fio);
	cout << "Vvedite Age: ";
	cin >> tmp.Age;
	cin.ignore();
	return tmp;
}
void Show(Person tmp)
{
	cout << "Fio: " << tmp.Fio << "\tAge: " << tmp.Age << "\n";
}
Person * Add(Person *mas, int &n)
{
	mas = (Person*)realloc(mas, (n + 1) * sizeof(Person));
	mas[n] = Vvod();
	n++;
	return mas;
}
Person * Del_Fio(Person *mas, int &n)
{
	char str[20];
	cout << "Vvedite Fio iskomogo: ";
	gets_s(str);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(mas[i].Fio, str) == 0)
		{
			for (int j = i; j < n - 1; j++)
			{
				mas[j] = mas[j + 1];
			}
			mas = (Person*)realloc(mas, (n - 1) * sizeof(Person));
			n--;
			i--;
		}
	}
	return mas;
}
void Print(Person *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		Show(mas[i]);
	}
}
int main()
{
	Person *baza = NULL;
	int n = 0;
	baza = Add(baza, n);
	baza = Add(baza, n);
	Print(baza, n);
	baza = Del_Fio(baza, n);
	Print(baza, n);
	system("pause");
}