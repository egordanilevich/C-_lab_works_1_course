#include<iostream>
#include<cmath>
#include<string>
using namespace std;
bool error=false;
struct lec
{
	string type;
	string data;
	lec* next=NULL;
};
string type(const char &s)//функция определения типа лексемы
{
	cout<<"  //  "<<s<<"  //  "<<endl;
	if(s=='>' || s=='<' || s==':') return"sravn ";
	else if(s>=48 && s<=57) return"chislo";
	else if(( s>=65 && s<=90 ) || ( s>=97 && s<=122 )) return"identf";
	else
	{
		//error=true;
		return"error ";
	}
}
void print(lec a)//функция вывода
{
	cout<<a.type<<" : "<<a.data<<endl;
}
int main()
{
	int i=1;//
	string s;
	lec *head=NULL,*ptr=NULL;//ссылки для работы со списком
	cout<<"VVedite: "<<endl;
	getline(cin,s);//ввод строки
	ptr= new lec;//создание первой записи 
	ptr->data=s[0];
	ptr->type=type(s[0]);
	ptr->next=head;
	head=ptr;
	while(s[i]!='\0')//перебор строки
	{
		cout<<"*";
		if(s[i]==' ')//тест пробелов
		{
			while(s[i]==' ') 
			{
				i++;
			}
			cout<<"*";
			ptr= new lec;//создание новой записи 
			cout<<"*";
			ptr->data=s[i];
			ptr->type=type(s[i]);
			ptr->next=head;
			head=ptr;
		}
		else//дозаполнение текущей
		{
			cout<<"*";
			ptr->data+=s[i];
			if(ptr->type=="sravn ")
			{
				//cout<<"s"<<endl;
				if(ptr->data!="<=" && ptr->data!=":=" && ptr->data!=">=")//тест сравнения
				{
					ptr->type="error ";
					//cout<<" 2error"<<endl;
					//return 0;
				}
			}
			else if(ptr->type=="chislo" && !(s[i]>=48 && s[i]<=57 ))//тест числа
			{
				ptr->type="error ";
				//cout<<" 3error"<<endl;
				//return 0;
			}
		}
		if(error==true)//тест ошибки
		{
			ptr->type="error ";
			//cout<<"1error"<<endl;
			//return 0;
		}
		i++;
	}
	system("cls"); 
	ptr=head;
	while(ptr!=NULL)//вывод
	{
		print(*ptr);
		ptr=ptr->next;
	}
	return 0;
}
