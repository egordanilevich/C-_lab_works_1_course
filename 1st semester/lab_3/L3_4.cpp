#include<iostream>
using namespace std;
const int n=5,m=5;
int main()
{
	int mas[n][m],s=0;
	cout<<"Vvedite:"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>mas[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<mas[i][j]<<" ";
			if(i>j) s+=mas[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<s<<endl;
	return 0;
}
