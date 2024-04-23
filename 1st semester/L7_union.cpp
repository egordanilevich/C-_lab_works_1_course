#include<iostream>
#include <string>
#include <locale>
#include <algorithm>
#include <cctype>
using namespace std;

const int n = 3;//кол-во

enum doljnost 
{
	teacher, 
	trainees,
	support,
	error
};

struct worker
{
	int number = 0;
	string fio;
	int oklad  = 0;
	doljnost dolj;
	char pol;
	union 
	{
		struct
		{
			int Seniority1;
			char degree[32];
			char chair1[32];	
		};
		struct
		{
			int course;
			char chair2[32];
		};
		struct
		{
			int Seniority3;
			char edu[32];
			char type[32];
		};
	};
};
istream& operator>>(istream& is, doljnost& f)
{
    string s;
    is >> s;
    if (s == "teacher") f = teacher;
    else if (s=="trainees") f= trainees;
    else if (s=="support") f= support;
    else f=error;//ошибка должности
    return is;
}

int main()
{
	worker w_list[n];
	bool error=false;
	string d;
	for(int i=0;i<n;i++)
	{
		cout<<"Worker #"<<i+1<<endl<<"Enter number:";
		cin>>w_list[i].number;
		cin.get();
		cout<<"Enter name: ";
		getline(cin,w_list[i].fio);
		cout<<"Enter the position: ";
		cin>>w_list[i].dolj;
		//cout<<w_list[i].dolj<<endl<<endl;
		cout<<"Enter the salary: ";
		cin>>w_list[i].oklad;
		cout<< "Enter a gender(m/f): " ;
		cin >> w_list[i].pol;
		if(w_list[i].pol!='m' && w_list[i].pol!='f')//тест пола
		{
			cout<<"pol "<<w_list[i].pol<<" error"<<endl;
			w_list[i].pol='e';
		}
		cout<<endl;
		cin.get();
		
		switch (w_list[i].dolj) // должность 4 вариант - ошибка
		{
			case teacher:
				cout<<"enter seinority: ";
				cin>>w_list[i].Seniority1;
				cout<<"enter degree: ";
				cin>>w_list[i].degree;
				cout<<"enter chair: ";
				cin>>w_list[i].chair1;
				break; 
			case trainees:
				cout<<"enter course: ";
				cin>>w_list[i].course;
				cout<<"enter chair: ";
				cin>>w_list[i].chair2;
				break; 
			case support:
				cout<<"enter seinority: ";
				cin>>w_list[i].Seniority3;
				cout<<" enter edu: ";
				cin>>w_list[i].edu;
				cout<<"enter type: ";
				cin>>w_list[i].type;
				break; 
			default:
				cout<<"error"<<endl;
				error=true;
				//return 0;
		}
		system("cls");
	}
	bool cont=true;
	int k=0;
	char c;
	while(cont==true)
	{
			cout << "Select number: " << endl;
			cin >> k;
			system("cls");
			if(k>0 and k<=n)
			{
				cout << "worker #: " <<k<<endl;
				cout<<"ID" << w_list[k-1].number<<endl;
				cout << "full name: "<< w_list[k-1].fio<<endl;
				cout << "the salary: " <<  w_list[k-1].oklad << endl;
				cout << "gender: "<< w_list[k-1].pol << endl;
				if (w_list[k - 1].dolj == 0)
				{
					cout<<"seinority: "<<w_list[k-1].Seniority1<<endl;
					cout<<"degree: "<<w_list[k-1].degree<<endl;
					cout<<"chair: "<<w_list[k-1].chair1<<endl;
				}
				else if (w_list[k - 1].dolj == 1)
				{
					cout<<"enter course: "<<w_list[k-1].course<<endl;
					cout<<"enter chair: "<<w_list[k-1].chair2<<endl;
				}
				else if (w_list[k - 1].dolj == 2)
				{
				cout<<"enter seniority: "<<w_list[k-1].Seniority3<<endl;
				cout<<"enter edu: "<<w_list[k-1].edu<<endl;
				cout<<"enter type: "<<w_list[k-1].type<<endl;
				}
				else
				{
					cout << "error "<< endl;
				}
			}
			else
			{
				cout<<"error: the record does not exist!"<<endl;
			}
			cout<<"continue: (y/n)";
			cin>>c;
			system("cls");
			tolower(c);
			if(c!='y') cont=false;
	}
	return 0;
}
