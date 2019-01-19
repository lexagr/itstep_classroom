#include<iostream>
#include<conio.h>
using namespace std;
char *Gets(char *&str)
{
	char ch;
	int n = 0;
	str = NULL;
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
char * Del_Pos(char *str, int pos)
{
	strcpy_s(str + pos, strlen(str + pos+1) + 1, str + pos+1);
	str = (char*)realloc(str, strlen(str) + 1);
	return str;
}
char *Del_Simvol(char *str, const char *ch)
{
	char *tmp;
	while ((tmp = strpbrk(str, ch)) != NULL)
	{
		strcpy_s(tmp, strlen(tmp + 1) + 1, tmp + 1);
		str = (char*)realloc(str, strlen(str) + 1);
	}
	return str;
}
char *Ins_Simvol(char *str, char ch, int pos)
{
	str = (char*)realloc(str, strlen(str) + 2);
	char *tmp = (char*)malloc(strlen(str + pos) + 1);
	strcpy_s(tmp, strlen(str+pos)+1,str + pos);
	str[pos] = ch;
	strcpy_s(str + pos + 1, strlen(tmp)+1,tmp);
	return str;
}
char *Zamena_Simvola(char *str, char Old, char New)
{
	char *tmp;
	while ((tmp = strchr(str, Old)) != NULL)
	{
		*tmp = New;
	}
	return str;
}
int Kol_Simvola(char *str, const char *ch)
{
	char *tmp = str;
	int kol = 0;
	while ((tmp = strpbrk(tmp, ch)) != NULL)
	{
		kol++;
		tmp++;
	}
	return kol;
}
int Kol_B_C_D(char *str, int &kbukv, int &kdrugie)
{
	int kcifr = 0;
	kbukv = 0;
	kdrugie = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (isalpha(str[i]) != 0) kbukv++;
		else
			if (isdigit(str[i]) != 0) kcifr++;
			else kdrugie++;
	}
	return kcifr;
}
int Kol_Slov(char *str)
{
	int kol = 0;
	char *tmp;
	char *tek = strtok_s(str, " ,.-?:;!",&tmp);
	while (tek != NULL)
	{
		kol++;
		tek = strtok_s(NULL, " ,.-?:;!", &tmp);
	}
	return kol;
}
int Palindrom(char *str)
{
	str = Del_Simvol(str, " ,.-?:;!");
	char *tmp = (char*)malloc(strlen(str) + 1);
	strcpy_s(tmp, strlen(str)+1,str);
	_strrev(str);
	if (_stricmp(str, tmp) == 0)
		return 1;
	return 0;
}
int mystrcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2 && *str1 != 0)
	{
		str1++; str2++;
	}
	if (*str1 > *str2) return 1;
	if (*str1 < *str2) return -1;
	return 0;
}
int StringToNumber(const char *str)
{
	int f = 0;
	if (str[0] == '-') f = 1;
	int s = 0;
	for (int i = f; str[i] != 0; i++)
	{
		if (isdigit(str[i]) != 0)
		{
			s = s*10 + (str[i] - 48);
		}
	}
	if (f == 1) s = -s;
	return s;
}
char *NumberToString(int num)
{
	char *str = (char*)calloc(1,1);
	int f = 0;
	if (num < 0)
	{
		str = Ins_Simvol(str, '-', 0);
		f = 1;
	}
	num = abs(num);
	while (num != 0)
	{
		char ch = num % 10 + 48;
		str = Ins_Simvol(str, ch, f);
		num = num / 10;
	}
	return str;
}
char *Uppercase(char *str)
{
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	}
	return str;
}
char *mystrrev(char *str)
{
	int i = 0;
	int j = strlen(str) - 1;
	while (i < j)
	{
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++; j--;
	}
	return str;
}
char * Del_Slovo(char *str, const char *slovo)
{
	char *tmp;
	while ((tmp = strstr(str, slovo)) != NULL)
	{
		strcpy_s(tmp, strlen(tmp+strlen(slovo))+1,tmp + strlen(slovo));
		break;
	}
	str = (char*)realloc(str, strlen(str) + 1);
	return str;
}
char * Ins_Slovo(char *str, const char *slovo, int pos)
{
	for (int i = 0; slovo[i] != 0; i++)
	{
		str = Ins_Simvol(str, slovo[i], pos + i);
	}
	return str;
}
char * Zamena_Slova(char *str, const char *Old, const char *New)
{
	char *tmp;
	while ((tmp = strstr(str, Old)) != NULL)
	{
		strcpy_s(tmp, strlen(tmp + strlen(Old)) + 1,tmp + strlen(Old));
		int pos = tmp - str;
		str = (char*)realloc(str, strlen(str) + 1);
		str = Ins_Slovo(str, New, pos);
	}
	return str;
}
char * Text(char *str)
{
	char *tmp = str;
	int p = strspn(str, " ");
	if (str[p] >= 'a' && str[p] <= 'z') str[p] = str[p] - 32;
	while ((tmp = strpbrk(tmp, ".?!")) != NULL)
	{
		p=strspn(tmp + 1, " ");
		if (str[tmp+1-str+p] >= 'a' && str[tmp + 1 - str + p] <= 'z') str[tmp + 1 - str + p] = str[tmp + 1 - str + p] - 32;
		tmp++;
	}
	return str;
}
void Kol_Bukv(char *str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		int s = 0;
		for (int j = i; j < strlen(str); j++)
		{
			if (str[i] == str[j]) s++;
		}
		int f = 0;
		for (int k = 0; k < i; k++)
		{
			if (str[k] == str[i])
			{
				f = 1;
				break;
			}
		}
		if (f == 0)
			cout << str[i] << "\t" << s << "\n";
	}
}
char * mystrcpy(char *str1, const char *str2)
{
	char *tmp = str1;
	while (*str2 != 0)
	{
		*str1++ = *str2++;
	}
	*str1 = 0;
	return tmp;
}
char *mystrcat(char *str1, const char *str2)
{
	char *tmp = str1 + strlen(str1);
	while (*str2 != 0)
	{
		*tmp++ = *str2++;
	}
	*tmp = 0;
	return str1;
}
char *mystrchr(char *str, char ch)
{
	while (*str != 0)
	{
		if (*str == ch)
			return str;
		str++;
	}
	return NULL;
}
char *mystrstr(char *str1, const char *str2)
{
	const char *tmp1 = str2;
	char *tmp2;
	while (*str1 != 0)
	{
		tmp2 = str1;
		while (*str1 == *str2 && *str2!=0)
		{
			str1++; str2++;
		}
		if (*str2 == 0) return tmp2;
		str2 = tmp1;
		str1++;
	}
	return NULL;
}
int Kol_Pred(char *str)
{
	char *tmp;
	char *pr = strtok_s(str, ".?!\0", &tmp);
	int kol = 0;
	while (pr != NULL)
	{
		kol++;
		pr= strtok_s(NULL, ".?!\0", &tmp);
	}
	return kol;
}
char * Revers_Pred(char *str)
{
	int pos = strspn(str, " ");
	char *nach = str + pos;
	char *konec;
	while ((konec = strpbrk(nach, ".?!")) != NULL)
	{
		reverse(nach, konec);
		pos = strspn(konec + 1, " ");
		nach = konec + pos + 1;
	}
	return str;
}
int main()
{
	char *str;
	Gets(str);
	cout <<Revers_Pred(str);
}