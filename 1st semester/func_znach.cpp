//Данилевич Егор Денисови 11ПИ
//передача параметров в функцию по значению
#include<iostream>

using namespace std;



int sum_g(const int a,const int b,int mas[a][])//сумма по главной диагонали
{
	int sum=0;
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			cout<<mas[i][j]<<" ";
			if(i==j) sum+=mas[i][j];
		}
		cout<<endl;
	}
	return sum;
}
int main()
{
	const int n=3,m=3;
	int mas[n][m];
	cout<<"Vvedite:"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>mas[i][j];
		}
	}
	cout<<endl;
	cout<<sum_g(n,m,mas)<<endl;
	return 0;
}
