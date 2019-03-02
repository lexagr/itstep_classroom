#pragma once
class Mass
{
	int *mas;
	int size;
public:
	Mass();
	explicit Mass(int);
	Mass(const Mass &);
	Mass & operator=(const Mass &);
	Mass operator+(const Mass &);
	Mass operator+(const int &);
	Mass & operator++();
	Mass operator++(int);
	bool operator==(const Mass &);
	bool operator!=(const Mass &);
	int operator[](int);
	int operator()(int,int,int);
	explicit operator int();
	void Rand() const;
	void Print() const;
	~Mass();
	friend Mass operator+(const int &, Mass &);
};


