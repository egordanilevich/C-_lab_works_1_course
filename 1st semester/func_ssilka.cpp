//Данилевич Егор Денисови 11ПИ
//передача параметров в функцию по cсылке
#include<iostream>

using namespace std;

const int n=3,m=3;

int sum_g(int mas[][3], int n)//сумма по главной диагонали
{
	int sum=0;
	for (int i=0; i<n; i++)
	{
	 
        for (int j=0; j<3; j++)
		{
			cout<<mas[i][j]<<" ";
			if(i==j) sum += mas[i][j];
		}
		cout<<endl;
    }
	return sum;
}
int main()
{
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
	cout<<sum_g(mas,n)<<endl;
	return 0;
}
