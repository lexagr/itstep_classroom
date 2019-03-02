#include<iostream>
using namespace std;
#include"Counter.h"
int main()
{
	Counter c(1,5);
	for (int i = 0; i < 10; i++)
	{
		cout << c.Get_tek() << "\n";
		c.Add();
	}
}
