#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	char flag='Y',type;//флаг цикла
	while(flag=='Y' or flag=='y')
	{
		bool ok=true,s=true;
		char a[10];
		cout<<"Vvedite: ";
		cin>>a;
		//cout<<a<<endl;
		int i=0,n=0,state=1;
		while(a[i]!='\0')
		{
			a[i]=toupper(a[i]);
			if(a[i]!='X' and a[i]!='V' and a[i]!='I')
			{
				s=false;
			}
			i++;
		}
		i=0;
		while(a[i]!='\0' and ok==true)
			{
				switch (state)
				{
					case 1:
						switch(a[i])
						{
						
						case 'X':
							n=10;
							state=2;
							break;
						
						case 'V':
							n=5;
							state=3;
							break;
						case'I':
						
							n=1;
							state=6;
							break;
						}
						break;
					case 2:
						switch(a[i])
						{
						
						case 'X':
						
							n+=10;
							state=2;
							break;
						case'V':
						
							n+=5;
							state=3;
							break;
						case'I':
						
							n+=1;
							state=6;
							break;
						}
						break;
					case 3:
						switch(a[i])
						{
						
						case 'X':
						
							ok=false;
							break;						
						case 'V':
						
							ok=false;
							break;
						case'I':
						
							n+=1;
							state=4;
							break;
						}
						break;
					case 4:
						switch(a[i])
						{
						case'X':
						
							ok=false;
							break;
						case'V':
						
							ok=false;
							break;
						case'I':
						
							n+=1;
							state=5;
							break;
						}
						break;
					case 5:
						switch(a[i])
						{
						case 'X':
						
							ok=false;
							break;
						case 'V':
						
							ok=false;
							break;
						case 'I':
						
							n+=1;
							state=7;
							break;
						}
						break;
					case 6:
						switch(a[i])
						{
						case 'X':
						
							n+=8;
							state=7;
							break;
						case 'V':
						
							n+=3;
							state=7;
							break;
						case 'I':
						
							n+=1;
							state=5;
							break;
						}
						break;
					case 7:
						switch(a[i])
						{
						case 'X':
						
							ok=false;
							break;
						case 'V':
						
							ok=false;
							break;
						case 'I':
						
							ok=false;
							break;
						}
						break;
				}
				i++;
			}
		if(s==false) cout<<"neverni simvol"<<endl;
		else if(ok==false) cout<<"chislo vvedeno neverno"<<endl;
		else cout<<n<<endl;
		cout<<"continue?... Y/N: ";
		cin>>flag;
	}
	return 0;
}
