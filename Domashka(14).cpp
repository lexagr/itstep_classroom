#include<iostream>
using namespace std;
char *Gets(char *&str)
{
	str = nullptr;
	int n = 0;
	char ch;
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
char * Copy(char *str, int n, int m)
{
	char *tmp = (char*)malloc(m - n + 2);
	strncpy_s(tmp,m-n+2,str+n,m-n+1);
	return tmp;
}
char * Del_Str(char *str, int n, int m)
{
	strcpy_s(str + n, strlen(str + m + 1) + 1, str + m + 1);
	str = (char*)realloc(str,strlen(str) + 1);
	return str;
}
void Vivod_Pos(char *str,char ch)
{
	char *tmp = str;
	while ((tmp = strchr(tmp, ch)) != NULL)
	{
		cout << tmp - str << "\t";
		tmp++;
	}
}
void Vivod_Pos_Rev(char *str, char ch)
{
	char *tmp = str;
	if((tmp = strrchr(tmp, ch)) != NULL)
	{
		cout << tmp - str << "\t";
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	char *str;
	Gets(str);
	Vivod_Pos_Rev(str, 'a');
	system("pause");
}