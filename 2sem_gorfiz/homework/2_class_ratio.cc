#include<iostream>

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

	rat(){
		std::cout << "type a numerator and a denomenator of the fraction, separate them by space:";
		std::cout << std::endl;
		std::cin >> m >> n;
		if ( n == 0 ){
			std::cout << "bad input";
			exit(1);
		} else{
			if ( gcd(m, n) != 1 ){
				int del = gcd(m,n);
				m = m / del;
				n = n / del;
			}
		}
		if (n < 0){
			m = -1 * m;
			n = -1 * n;
		}
	}

	~rat(){}

	void get(){
	    if ( m == 0 ){ std::cout << 0;} else{
		std::cout << m << "/" << n;}
	}

	void sum( rat a ){
		this->m = this->m * a.n + a.m * this->n;		
		this->n = this->n * a.n;

		int sub = gcd(this->m, this->n);
	
		this->m = this->m / sub;
		this->n = this->n / sub;
	}

	void dif( rat a ){
		this->m = this->m * a.n + a.m * this->n;
		this->n = this->n * a.n;
	
		int sub = gcd(this->m, this->n);
	
		this->m = this->m / sub;
		this->n = this->n / sub;
	}

	void mult( rat a ){
		this->m = this->m * a.m;
		this->n = this->n * a.n;
		
		int sub = gcd(this->m, this->n);

		this->m = this->m / sub;
		this->n = this->n /sub;
	}

	void div( rat a ){
		this->m = this->m * a.n;
		this->n = this->n * a.m;

		int sub = gcd(this->m, this->n);

		this->m = this->m / sub;
		this->n = this->n / sub;
	}

	void comp(rat a ){
		this->m = this->m * a.n - a.m * this->n;
		this->n = this->n * a.n;
	
		int sub = gcd(this->m, this->n);
	
		this->m = this->m / sub;
		this->n = this->n / sub;

		if( m == 0){
			std::cout << "fractions are equal";
		} else if( m > 0 ){
			std::cout << "the first fraction is greater than the second";
		} else { 
			std::cout << "the second fraction is greater than the first";
		}
	}
};

int main(){

	rat num1;
	rat num2;

	std::cout << "choose an operator. type:" << std::endl;
	std::cout << "sum - to calculate the sum of these rations," << std::endl ;
	std::cout << "dif - to calculate the difference between these rations," << std::endl ;
	std::cout << "mult - to calculate the composition of there rations," << std::endl ;
	std::cout << "comp - to compare these rations." << std::endl ;

	std::cout << std::endl;

	std::string choice;

	std::cin >> choice;
	
	if (choice == "sum"){
		num1.sum(num2);
		std::cout << std::endl;
		num1.get();
	} else if (choice == "dif"){
		num1.dif(num2);
		std::cout << std::endl;
		num1.get();
	} else if (choice == "mult"){
		num1.mult(num2);
		std::cout << std::endl;
		num1.get();
	} else if (choice == "comp"){
		std::cout << std::endl;
		num1.comp(num2);
	} else {
		std::cout << std::endl << "bad input";
		exit(1);
	}
}