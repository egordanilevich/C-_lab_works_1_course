#include<iostream>
#include<cmath>
#define PI 3.14159265
using namespace std;
const int n=10;
class sin_c
{
	double current=0,step=(2*PI)/n;
	public:
		sin_c()
		{ }
		double next()
		{
			double t=sin(current);
			current+=step;
			return t;
		}
};
int main()
{
	double b=0;
	sin_c a;
	cout<<sin(PI-0.00001)<<endl;
	for(int i=0;i<10;i++)
	{
		b=a.next();
		cout<<b<<endl;
	}
	return 0;
}
