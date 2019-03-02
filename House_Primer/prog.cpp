#include<iostream>
#include<conio.h>
using namespace std;
#include"House.h"
int main()
{
	House d(20);
	char ch;
	do
	{
		system("cls");
		cout << "Menu.\n";
		cout << "1 - Zaselenie v kvartiru.\n";
		cout << "2 - Viselenie s kvartiri.\n";
		cout << "3 - Poisk gilca.\n";
		cout << "4 - Vivod kvartiri.\n";
		cout << "5 - Vivod doma.\n";
		cout << "Esc - Exit.\n";
		ch = _getch();
		switch (ch)
		{
		case '1':system("cls");
			d.Zaselenie();
			system("pause");
			break;
		case '2':system("cls");
			d.Viselenie();
			system("pause");
			break;
		case '3':system("cls");
			d.Poisk_Gilca();
			system("pause");
			break;
		case '4':system("cls");
			d.Print_Flat();
			system("pause");
			break;
		case '5':system("cls");
			d.Print();
			system("pause");
			break;
		}
	} while (ch != 27);
}