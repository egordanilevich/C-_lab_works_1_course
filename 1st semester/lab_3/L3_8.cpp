#include<iostream>
using namespace std;
const int n=5,m=5;
int main()
{
	int mas[n][m],min;
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
	for(int j=0;j<m;j++)
	{
		if(j%2==0)
		{
			min=mas[0][j];
			for(int i=0;i<n;i++)
			{
				if(mas[i][j]<min) min=mas[i][j];
			}
			cout<<"stolb: "<<j+1<<" min: "<<min<<endl;
		}
	}
	return 0;
}
