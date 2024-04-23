#include<iostream>
#include<cmath>
#include<windows.h>
using namespace std;
int main()
{
	double n=0,i=0;
	cin>>n;
	while(i<n)
	{
		double x;
		x=sin(i);
		for(int j=0;j<((x+1)*35);j++)
		{
			cout<<" ";
			//Sleep(1);
		}
		cout<<"*"<<endl;
		//cout<<"@";
		i+=0.21;
		Sleep(10);
	}
	return 0;
}
