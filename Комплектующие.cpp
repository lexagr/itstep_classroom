#include<iostream>
using namespace std;
#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
struct Video
{
	char Firma[15];
	int Ram;
	int Chastota;
};
struct Proc
{
	char Firma[10];
	int Core;
	int Chastota;
	int Cash;
};
struct Mather
{
	char Firma[15];
	char ChipSet[10];
	int Soket;
	char Ram[5];
};
union Komplect
{
	Video V;
	Proc P;
	Mather M;
};
struct Element
{
	int ID;
	Komplect K;
};
Video Vvod_Video()
{
	Video tmp;
	cout << "Введите название видеокарты: ";
	cin >> tmp.Firma;
	cout << "Введите объем памяти видеокарты: ";
	cin >> tmp.Ram;
	cout << "Введите частоту видеокарты: ";
	cin >> tmp.Chastota;
	return tmp;
}
Proc Vvod_Proc()
{
	Proc tmp;
	cout << "Введите название процессора: ";
	cin >> tmp.Firma;
	cout << "Введите кол-во ядер процессора: ";
	cin >> tmp.Core;
	cout << "Введите частоту процессора: ";
	cin >> tmp.Chastota;
	cout << "Введите объем кеша процессора: ";
	cin >> tmp.Cash;
	return tmp;
}
Mather Vvod_Mather()
{
	Mather tmp;
	cout << "Введите название материнки: ";
	cin >> tmp.Firma;
	cout << "Введите название чипсета: ";
	cin >> tmp.ChipSet;
	cout << "Введите название сокета: ";
	cin >> tmp.Soket;
	cout << "Введите поддерживаемую память: ";
	cin >> tmp.Ram;
	return tmp;
}
void Print_Video(Video v)
{
	cout << v.Firma << " " << v.Chastota << " " << v.Ram << "\n";
}
void Print_Proc(Proc p)
{
	cout << p.Firma << " " << p.Core << " " << p.Chastota << " " << p.Cash << "\n";
}
void Print_Mather(Mather m)
{
	cout <<  m.Firma << " " << m.ChipSet << " " << m.Ram << " " << m.Soket << "\n";
}
void Add(Element *&Old, int &n)
{
	Old = (Element*)realloc(Old, (n + 1) * sizeof(Element));
	cout << "Что вы будите добавлять? (1-Video,2-Proc,3-Mather): ";
	char ch = getch();
	switch (ch)
	{
	case '1':system("cls");
		Old[n].ID = 1;
		Old[n].K.V = Vvod_Video();
		break;
	case '2':system("cls");
		Old[n].ID = 2;
		Old[n].K.P = Vvod_Proc();
		break;
	case '3':system("cls");
		Old[n].ID = 3;
		Old[n].K.M = Vvod_Mather();
		break;
	}
	n++;
}
void Print(Element *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (mas[i].ID == 1)
		{
			Print_Video(mas[i].K.V);
		}
		if (mas[i].ID == 2)
		{
			Print_Proc(mas[i].K.P);
		}
		if (mas[i].ID == 3)
		{
			Print_Mather(mas[i].K.M);
		}
	}
}
void OnlyVideo(Element *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (mas[i].ID == 1)
		{
			Print_Video(mas[i].K.V);
		}
	}
}
void main()
{
	setlocale(LC_ALL, "rus");
	int n = 0;
	Element *Mas = NULL;
	char ch;
	do
	{
		system("cls");
		cout << "МЕНЮ:\n";
		cout << "1 - Добавление комплектующего.\n";
		cout << "2 - Печать комплектующих.\n";
		cout << "3 - Печать видеокарт.\n";
		cout << "0 - Выход.\n";
		ch = getch();
		switch (ch)
		{
		case '1':system("cls");
			Add(Mas, n);
			cout << "Добавление произошло.\n";
			Sleep(2000);
			break;
		case '2':system("cls");
			Print(Mas, n);
			system("pause");
			break;
		case '3':system("cls");
			OnlyVideo(Mas, n);
			system("pause");
			break;
		case '0':free(Mas);
		}
	} while (ch != '0');
}