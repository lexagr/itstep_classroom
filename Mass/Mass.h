#pragma once
class Mass
{
	int *mas;
	int size;
public:
	Mass();
	Mass(int);
	Mass(const Mass &);
	void Rand();
	void Print();
	Mass & operator=(const Mass &);
	~Mass();
};

