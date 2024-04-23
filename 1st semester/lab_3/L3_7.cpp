#include<iostream>
using namespace std;
const int n=5,m=5;
int main()
{
	int mas[n][m],max=0;
	cout<<"Vvedite:"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>mas[i][j];
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<mas[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++)
	{
		if(i%2!=0)
		{
			for(int j=0;j<m;j++)
			{
				if(mas[i][j]>max) max=mas[i][j];
			}
			cout<<"stroka: "<<i+1<<" max: "<<max<<endl;
		}
	}
	return 0;
}
