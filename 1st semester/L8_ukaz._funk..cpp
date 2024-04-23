#include <iostream>
using namespace std;

double calc(double(*operation)(double a,double b), double a, double b);
double sum(double a,double b)//сумма
{
	return a+b;
}
double sub(double a,double b)//разность
{
	return a-b;
}
double mul(double a,double b)//произведение
{
	return a*b;
}
double div(double a,double b)//частное
{
	return a/b;
}

int main()
{
	double a=0,b=0,c=0;
	setlocale(LC_ALL, "Russian");
	double(*operation)(double a,double b);
	char znak;//знак действи€
	unsigned short int d=1;//метка цикла/0-завершение, 1-начинаем с нул€, 2-используем предъидущее значение
	while(d==1 || d==2)
	{
		system("cls");
		if(d==1)//действи€ сначала
		{
			cin>>a;
			system("cls");
			cout<<a<<" ";
			cin>>znak;
			system("cls");
			cout<<a<<" "<<znak<<" ";
			cin>>b;
			system("cls");
			switch(znak)//выбор по действию и присвоение указателю
			{
				case'+':
					operation=sum;
					break;
				case'-':
					operation=sub;
					break;
				case'*':
					operation=mul;
					break;
				case'/':
					operation=div;
					break;
				default:
					cout<<"error"<<endl;
					return 0;		
			}
			c=operation(a,b);
			cout<<a<<" "<<znak<<" "<<b<<" = "<<c<<endl;
	
		}
		else if(d==2)// действи€ с предъидущим
		{
			a=c;
			c=0;
			cout<<a<<" ";
			cin>>znak;
			system("cls");
			cout<<a<<" "<<znak<<" ";
			cin>>b;
			system("cls");
			switch(znak)//выбор по действию и присвоение указателю
			{
				case'+':
					operation=sum;
					break;
				case'-':
					operation=sub;
					break;
				case'*':
					operation=mul;
					break;
				case'/':
					operation=div;
					break;
				default:
					cout<<"error"<<endl;
					return 0;		
			}
			c=calc(div,a,b);
			cout<<a<<" "<<znak<<" "<<b<<" = "<<c<<endl;
	
		}
		else//ошибка
		{
			cout<<"error"<<endl;
			d=1;
			break;
		}
		cout<<"¬ведите:"<<endl<<"1-начать сначала"<<endl<<"2-продолжить с текущим"<<endl<<"0-завершить"<<endl;//завершение
		cin>>d;
	}
	return 0;
}
double calc(double(*operation)(double a,double b), double a, double b)
{
	return operation(a,b);	
}
