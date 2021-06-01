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

	void get(){
	    if ( m == 0 ){ std::cout << 0;} else{
		std::cout << m << "/" << n;}
	}

	rat operator+ (rat x){
		rat sum;
		
		sum.m = m * x.n + x.m * n;
		sum.n = n * x.n;

		int sub = gcd(sum.m, sum.n);

		sum.m = sum.m / sub;
		sum.n = sum.n / sub;

		return sum;
	}
	
	rat operator- (rat x){
        	rat dif;
  
       		dif.m = m * x.n - x.m * n;
		dif.n = x.n * n;

		int sub = gcd(dif.m, dif.n);

		dif.m = dif.m / sub;
		dif.n = dif.n / sub;

		return dif;
	}

	rat operator * (rat x){
		rat mult;

		mult.m = m * x.m;
		mult.n = n * x.n;

		int sub = gcd(mult.m, mult.n);

		mult.m = mult.m / sub;
		mult.n = mult.n / sub;

		return mult;
	}

	rat operator / (rat x){
		rat div;

		div.m = m * x.n;
		div.n = n * x.m;

		int sub = gcd(div.m, div.n);

		div.m = div.m / sub;
		div.n = div.n / sub;

		return div;
	}
};

int main(){

	rat num1(3, 2);
	rat num2(2, 3);

	rat sum;

	sum = num1 + num2;

	sum.get();

	cout << endl;

	rat dif;

	dif = num1 - num2;

	dif.get();

	cout << endl;

	rat mult;
	
	mult = num1 * num2;

	mult.get();

	cout << endl;

	rat div;

	div = num1 / num2;

	div.get();

}