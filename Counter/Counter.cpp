#include "Counter.h"
#include <iostream>
using namespace std;
Counter::Counter(int a, int b)
{
	min = a;
	max = b;
	tek = min;
}

void Counter::Add()
{
	tek++;
	if (tek > max)
		tek = min;
}
