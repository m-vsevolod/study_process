#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double a[12];
	double b;
	for(int i=0;i<12;i+=3){
		cin>>a[i];
		cin>>a[i+1];
		cin>>a[i+2];
}
for(int i=0;i<9;i+=3){
	a[3+i] = a[3+i] - a[0];
	a[4+i] = a[4+i] - a[1];
	a[5+i] = a[5+i] - a[2];}
b = (a[3]*a[7]*a[11]+a[4]*a[8]*a[9]+a[6]*a[10]*a[5]-a[5]*a[7]*a[9]-a[4]*a[6]*a[11]-a[8]*a[10]*a[3])/6;
if (b < 0) { b = b * (-1);}
cout<<fixed<<setprecision(4)<<b;
return 0;
}