#include<iostream>
using namespace std;
const int n=10;
int main()
{
	int mas[n],s=0;
	cout<<"Vvedite:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>mas[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<mas[i]<<" ";
		s+=mas[i];
	}
	cout<<endl;
	cout<<s<<endl;
	return 0;
}
