#pragma once
class Human
{
	char * Fio;
	int Age;
	char* Gets();
public:
	Human();
	Human(const Human &);
	Human & operator=(const Human &);
	void Vvod();
	void Show();
	char *GetFio();
	~Human();
};

