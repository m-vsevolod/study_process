#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int gcd(int x, int y){
	int t;
	while (y != 0){
		t = x;
		x = y;
		y = t % y;
	}
	return abs(x);
}

class rat{

	int m;
	int n;

public:
	rat(int p, int q){
		if ( q == 0 ){
			cout << "bad input";
			exit(1);
		}
		else {
			if ( gcd(p, q) != 1){
				int del = gcd(p, q);
				p = p / del;
				q = q / del;
			}
		}
		if ( q < 0 ){
			q = -1 * q;
			p = -1 * p;
		}

		m = p; n = q;
	}
	
	rat() = default;
	~rat() = default;

	void show(){
	    if ( m == 0 ){ std::cout << 0;} else{
		std::cout << m << "/" << n;}
	}


	friend void sum ( rat x, int y );

};

void sum( rat x, int y ){

	x.m = x.m + y * x.n;
	x.n = x.n;

	int del = gcd(x.n, x.m);

	x.m = x.m / del;
	x.n = x.n / del;

	cout << x.m << " / " << x.n;
}

int main(){
	rat num1(3, 2);
	int num2 = 1;

	sum( num1, num2 );
}


