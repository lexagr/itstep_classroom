#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;
struct Film
{
	char Name[20];
	char Direct[15];
	int Year;
	char Ganr[15];
	float Imdb;
	float Cena;
};
Film Vvod()
{
	Film tmp;
	cout << "������� �������� ������: ";
	gets_s(tmp.Name);
	cout << "������� ��������: ";
	gets_s(tmp.Direct);
	cout << "������� ��� ��������: ";
	cin >> tmp.Year;
	cin.ignore();
	cout << "������� ���� ������: ";
	gets_s(tmp.Ganr);
	cout << "������� ������� ������: ";
	cin >> tmp.Imdb;
	cin.ignore();
	cout << "������� ���� �����: ";
	cin >> tmp.Cena;
	cin.ignore();
	return tmp;
}
void Add(Film *&mas, int &n)
{
	mas = (Film*)realloc(mas, (n + 1) * sizeof(Film));
	mas[n] = Vvod();
	n++;
}
void Show(Film tmp)
{
	cout << tmp.Name << "\t" << tmp.Direct << "\t" << tmp.Year << "\t" << tmp.Ganr << "\t" << tmp.Imdb << "\t" << tmp.Cena << "\n";
}
void Print(Film *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		Show(mas[i]);
	}
}
void Del(Film *& mas, int &n, char *Nazv)
{
	int k = 0;
	for (int i = 0;i < n;i++)
	{
		while (i < n && stricmp(mas[i].Name, Nazv) == 0)
		{
			k = 1;
			for (int j = i;j < n - 1;j++)
			{
				mas[j] = mas[j + 1];
			}
			mas = (Film*)realloc(mas, (n - 1) * sizeof(Film));
			n--;
		}
	}
	if (k == 0)
	{
		cout << "��� ����������.\n";
	}
	else
	{
		cout << "�������� ���������.\n";
	}
}
void Find_Direct(Film *mas, int n, char *Fio)
{
	bool f = 0;
	for (int i = 0; i < n; i++)
	{
		if (stricmp(mas[i].Direct, Fio) == 0)
		{
			f = 1;
			Show(mas[i]);
		}
	}
	if (f == 0)
	{
		cout << "��� ����������.\n";
	}
}
void Sort_Imdb(Film *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (mas[j].Imdb < mas[j + 1].Imdb)
			{
				Film tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
}
void MaxImdb(Film *mas, int n, char *Ganr)
{
	int max = -1;
	for (int i = 0; i < n; i++)
	{
		if (stricmp(mas[i].Ganr, Ganr) == 0 && mas[i].Imdb>max)
		{
			max = mas[i].Imdb;
		}
	}
	if (max == -1)
	{
		cout << "��� ������� ������ �����.\n";
	}
	else
	{
		for (int i = 0;i<n;i++)
		{
			if (stricmp(mas[i].Ganr, Ganr) == 0 && mas[i].Imdb == max)
			{
				Show(mas[i]);
			}
		}
	}
}
void Sort_Name(Film *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (stricmp(mas[j].Name, mas[j + 1].Name)<0)
			{
				Film tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
}
void Write_File(Film *mas, int n, char *puth)
{
	FILE *pf = fopen(puth, "w");
	if (pf)
	{
		fwrite(&n, sizeof(n), 1, pf);
		fwrite(mas, sizeof(mas[0]), n, pf);
		fclose(pf);
	}
	else
	{
		cout << "Error.\n";
	}
}
void Read_File(Film *&mas, int &n, char *puth)
{
	FILE *pf = fopen(puth, "r");
	if (pf)
	{
		fread(&n, sizeof(n), 1, pf);
		mas = (Film*)malloc(n * sizeof(Film));
		fread(mas, sizeof(mas[0]), n, pf);
		fclose(pf);
	}
	else
	{
		cout << "Error.\n";
	}
}
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char ch;
	int n = 0;
	Film *Catalog = NULL;
	char str[20];
	do
	{
		system("cls");
		cout << "����:\n";
		cout << "1-���������� ������.\n";
		cout << "2-�������� ������.\n";
		cout << "3-����� ���� �������.\n";
		cout << "4-����� �� ��������.\n";
		cout << "5-������ � ������������ ��������� � �����.\n";
		cout << "6-���������� �� �������� ������.\n";
		cout << "7-������ � ����.\n";
		cout << "8-������ �� �����.\n";
		cout << "Esc-�����.\n";
		ch = getch();
		switch (ch)
		{
		case '1':system("cls");
			Add(Catalog, n);
			cout << "����� ��������.\n";
			Sleep(2000);
			break;
		case '2':system("cls");
			if (n != 0)
			{
				cout << "������� �������� ���������� ������: ";
				gets_s(str);
				Del(Catalog, n, str);
			}
			else
			{
				cout << "������� ����.\n";
			}
			Sleep(2000);
			break;
		case '3':system("cls");
			if (n != 0)
			{
				Print(Catalog, n);
				system("pause");
			}
			else
			{
				cout << "������� ����.\n";
				Sleep(2000);
			}
			break;
		case '4':system("cls");
			if (n != 0)
			{
				cout << "������� ������� ��������: ";
				gets_s(str);
				Find_Direct(Catalog, n, str);
			}
			else
			{
				cout << "������� ����.\n";
			}
			system("pause");
			break;
		case '5':system("cls");
			if (n != 0)
			{
				cout << "������� ����: ";
				gets_s(str);
				MaxImdb(Catalog, n, str);
			}
			else
			{
				cout << "������� ����.\n";
			}
			system("pause");
			break;
		case '6':system("cls");
			if (n != 0)
			{
				Sort_Name(Catalog, n);
				cout << "���������� �����������.\n";
			}
			else
			{
				cout << "������� ����.\n";
			}
			Sleep(2000);
			break;
		case '7':system("cls");
			if (n != 0)
			{
				Write_File(Catalog, n, "data.txt");
				cout << "������ �����������.\n";
			}
			else
			{
				cout << "������� ����.\n";
			}
			Sleep(2000);
			break;
		case '8':system("cls");
			Read_File(Catalog, n,"data.txt");
			cout << "������ �����������.\n";
			Sleep(2000);
			break;
		}
	} while (ch != 27);
	free(Catalog);
}