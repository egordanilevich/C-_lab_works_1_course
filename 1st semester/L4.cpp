#include<iostream>
#include<cmath>
#include<string>
const int n=3;
using namespace std;
struct worker
{
	string fio;
	unsigned int oklad;
	char pol;
	string doljnost;
};
int main()
{
	setlocale(LC_ALL, "Russian");
	worker m[n];
	bool error=false;
	for(int i=0;i<n;i++)
	{
		cout<<"сотрудник "<<i+1<<": "<<endl<<endl;
		cout<<"Введите Ф.И.О.: ";
		getline(cin,m[i].fio);
		cout<<"Введите должность: ";
		getline(cin,m[i].doljnost);
		cout<<"Введите оклад: ";
		cin>>m[i].oklad;
		cout<<"Введите пол:";
		cin>>m[i].pol;
		cin.get();//убирает символ конца строки
		system("cls");//очистка экрана))) 
	}
	for(int i=0;i<n;i++)
	{
		cout<<m[i].fio<<endl;
		cout<<m[i].oklad<<endl;
		cout<<m[i].doljnost<<endl;
		cout<<m[i].pol<<endl<<endl;
		
		//system("cls"); 
	}
	unsigned int fond=0;
	unsigned short mans=0,womens=0;
	unsigned int fmans=0,fwomens=0;
	for(int i=0;i<n;i++)
	{
		if(m[i].pol=='m') 
		{
			mans++;
			fmans+=m[i].oklad;
		}
		else if(m[i].pol=='w')
		{
			womens++;
			fwomens+=m[i].oklad;
		}	
		else 
		{
			error=true;
			cout<<"oшибка"<<endl;
			return 0;
		}
	}
	fond=fmans+fwomens;
	cout<<"Фонд зарплаты фирмы: "<<fond<<endl;
	cout<<"мужчин: "<<mans<<" женщин: "<<womens<<endl;	
	cout<<"Фонд зарплаты мужчин: "<<fmans<<" Фонд зарплаты женщин: "<<fwomens<<endl;	
	return 0;
}
