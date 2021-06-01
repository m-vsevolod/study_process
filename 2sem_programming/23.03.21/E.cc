#include<iostream>
#include<cmath>
#include<iomanip>

int main(){
	float h;
	float v;

	std::cin >> h >> v;

	float l = v * pow( 2 * h / 9.81 , 0.5);

	std::cout << std::fixed << std::setprecision(4) << l;
}