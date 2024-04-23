#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	char flag='Y',type;//флаг цикла
	while(flag=='Y' or flag=='y')
	{
		cout<<"figura: ";
		cin>>type;
		switch(type)
		{
			case 'R':
				float a,b;
				cout<<"vvedite storoni: ";
				cin>>a>>b;
				cout<<a*b<<endl;
				break;
			case 'T':
				float s,h;
				cout<<"vvedite storonu i visotu: ";
				cin>>s>>h;
				cout<<s*h*0.5<<endl;
				break;
			case 'C':
				float r;
				cout<<"vvedite ragius: ";
				cin>>r;
				cout<<M_PI*(r*r)<<endl;
				break;
				default:
					cout<<"error"<<endl;
					break;
		}
		cout<<"continue?... Y/N: ";
		cin>>flag;
	}
	return 0;
}
