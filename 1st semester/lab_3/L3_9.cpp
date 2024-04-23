#include<iostream>
using namespace std;
const int n=3,m=3,k=3;
int main()
{
	int mas1[m][n],mas2[n][k],mas3[m][k];
	cout<<"Vvedite m1:"<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mas1[i][j];
		}
	}
	cout<<endl<<"Vvedite m2:"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			cin>>mas2[i][j];
		}
	}
	cout<<endl;

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<k;j++)
		{
			int t=0;
			for(int z=0;z<n;z++)
			{
				t+=(mas1[i][z]*mas2[z][j]);	
			}
			mas3[i][j]=t;
			cout<<mas3[i][j]<<" ";	
		}
		cout<<endl;
	}
	return 0;
}
