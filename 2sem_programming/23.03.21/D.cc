#include<iostream>
#include<cmath>

int main(){

int n;

std::cin >> n;

float* a = new float[n];

float s = 0; float R = 0;

for ( int i = 0; i < n; i++ ){
	std::cin >> a[i];
	s += a[i] * a[i];
}

R = pow( s , 0.5);

std::cout << std::fixed << std::setprecision(4) << R;

delete[] a;

}
