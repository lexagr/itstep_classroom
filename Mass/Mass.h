#pragma once
class Mass
{
	int *mas;
	int size;
public:
	Mass();
	Mass(int);
	Mass(const Mass &);
	Mass operator=(const Mass &);
	void Rand();
	void Print();
	~Mass();
};

