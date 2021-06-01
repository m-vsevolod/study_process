#include<iostream>
#include<cmath>
#include<iomanip>

using std::cout;
using std::cin;
using std::setprecision;
using std::fixed;

int main(){
	float h_0;
	float k;
	float m;
	
	float v;
	
	cin >> k; cin >> h_0; cin >> m;

	v = h_0 * sqrt( 2 * k / m );

	cout << fixed << setprecision(1) << v;
}

	