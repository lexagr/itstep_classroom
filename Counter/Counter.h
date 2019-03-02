#pragma once
class Counter
{
	int min;
	int max;
	int tek;
public:
	Counter(int,int);
	void Add();
	int Get_tek() { return tek; }
};

