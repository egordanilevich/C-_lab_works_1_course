//Данилевич Егор Денисови 11ПИ
//передача параметров в функцию через указатель
#include<iostream>
#include<cstdlib>

using namespace std;

const int n=3,m=3;

int sum_g(int **mas,const int a,const int b)//сумма по главной диагонали
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
	int **mas;
	mas = (int**) malloc(n*sizeof(int*));
	cout<<"Vvedite:"<<endl;
	for(int i=0;i<n;i++)
	{
		mas[i]= (int*) malloc(m*sizeof(int));
		for(int j=0;j<m;j++)
		{
			cin>>mas[i][j];
		}
	}
	cout<<endl;
	cout<<sum_g(mas,n,m)<<endl;
	return 0;
}
