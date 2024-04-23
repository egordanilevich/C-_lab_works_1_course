#include <iostream>
using namespace std;

double calc(double(*operation)(double a,double b), double a, double b);
double sum(double a,double b)//�����
{
	return a+b;
}
double sub(double a,double b)//��������
{
	return a-b;
}
double mul(double a,double b)//������������
{
	return a*b;
}
double div(double a,double b)//�������
{
	return a/b;
}

int main()
{
	double a=0,b=0,c=0;
	setlocale(LC_ALL, "Russian");
	double(*operation)(double a,double b);
	char znak;//���� ��������
	unsigned short int d=1;//����� �����/0-����������, 1-�������� � ����, 2-���������� ����������� ��������
	while(d==1 || d==2)
	{
		system("cls");
		if(d==1)//�������� �������
		{
			cin>>a;
			system("cls");
			cout<<a<<" ";
			cin>>znak;
			system("cls");
			cout<<a<<" "<<znak<<" ";
			cin>>b;
			system("cls");
			switch(znak)//����� �� �������� � ���������� ���������
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
		else if(d==2)// �������� � �����������
		{
			a=c;
			c=0;
			cout<<a<<" ";
			cin>>znak;
			system("cls");
			cout<<a<<" "<<znak<<" ";
			cin>>b;
			system("cls");
			switch(znak)//����� �� �������� � ���������� ���������
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
		else//������
		{
			cout<<"error"<<endl;
			d=1;
			break;
		}
		cout<<"�������:"<<endl<<"1-������ �������"<<endl<<"2-���������� � �������"<<endl<<"0-���������"<<endl;//����������
		cin>>d;
	}
	return 0;
}
double calc(double(*operation)(double a,double b), double a, double b)
{
	return operation(a,b);	
}
