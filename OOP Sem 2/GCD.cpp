#include<iostream>
using namespace std;
int main()
{
	int a=662,d=414,r;
	do
	{
		r=a%d;
		a=d;
		d=r;
	}while(r!=0);
	cout<<a;
}
