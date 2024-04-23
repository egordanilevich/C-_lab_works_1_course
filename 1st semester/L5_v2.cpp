#include<iostream>
#include<cmath>
#include<string>
#include<list>
using namespace std;
bool error=false;
struct lec
{
	string type;
	string data;
	//lec* next=NULL;
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
void print(const list<lec> ::reverse_iterator it)//функция вывода
{
	cout<<(*it).type<<" : "<<(*it).data<<endl;
}
int main()
{
	int i=1;//
	string s;
	//lec *head=NULL,*ptr=NULL;//ссылки для работы со списком
	cout<<"VVedite: "<<endl;
	getline(cin,s);//ввод строки
	//ptr= new lec;//создание первой записи 
	lec first;
	list<lec> lecs;
	first.data=s[0];
	first.type=type(s[0]);
	lecs.push_back(first);
	//head=ptr;
	list<lec> ::reverse_iterator it=lecs.rbegin();
	while(s[i]!='\0')//перебор строки
	{
		cout<<"*";
		if(s[i]==' ')//тест пробелов
		{
			while(s[i]==' ') 
			{
				i++;
			}
			lec k;
			cout<<"*";
			k.data=s[i];
			k.type=type(s[i]);
			lecs.push_back(k);
			it=lecs.rbegin();
		}
		else//дозаполнение текущей
		{
			cout<<"*";
			//ptr->data+=s[i];
			(*it).data+=s[i];
			if((*it).type=="sravn ")
			{
				//cout<<"s"<<endl;
				if((*it).data!="<=" && (*it).data!=":=" && (*it).data!=">=")//тест сравнения
				{
					(*it).type="error ";
					//cout<<" 2error"<<endl;
					//return 0;
				}
			}
			else if((*it).type=="chislo" && !(s[i]>=48 && s[i]<=57 ))//тест числа
			{
				(*it).type="error ";
				//cout<<" 3error"<<endl;
				//return 0;
			}
		}
		if(error==true)//тест ошибки
		{
			(*it).type="error ";
			//cout<<"1error"<<endl;
			//return 0;
		}
		i++;
	}
	system("cls"); 
	//ptr=head;
	it=lecs.rbegin();
	while(it!=lecs.rend())//вывод
	{
		//cout<<"123";
		print(it);
		//ptr=ptr->next;
		it++;
	}
	return 0;
}
