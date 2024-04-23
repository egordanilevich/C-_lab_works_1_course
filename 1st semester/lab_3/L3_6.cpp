#include<iostream>
using namespace std;
const int n=3,m=3;
int main()
{
	int mas[n][m],s=1;
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
		}
		cout<<endl;
	}
	int i=(n-1),j=0;
	while(i>=0 and j<m)
	{
		s*=mas[i][j];
		i--;
		j++;
	}
	cout<<endl;
	cout<<s<<endl;
	return 0;
}
