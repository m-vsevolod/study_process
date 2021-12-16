#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

void output(string name, string file) {
	std::ofstream resout(file, std::ios::app);
	if (resout.is_open()) {
        	resout << name << std::endl;
    	}
	resout.close();
}

// y' = f(x,y) = x^2 - 2y, y(0) = 1, x \in [0; 1]

float function(float x, float y){
	return x * x - 2 * y;
}



class solver{
protected:
	float n; 
	vector<float> data;
public:
	solver(){};

	virtual void solve() {};

	virtual void out() {
		for (int i = 0; i < n; ++i){
			output(to_string(data[i]), "output.txt");
		}
	};
};



class euler1 : public solver{
public:
	euler1(float x){
		n = x;
	}

	void solve(){
		data.push_back(1); // y(0) = 1
		data.push_back(1 + (1 / n) * function( 0, 1 ));
		
		for (int i = 2; i < n + 1; ++i){
			data.push_back(data[i - 1] + (1 / n) * function( (i - 1)/n, data[i - 1] ));
		}
	}
};



class euler2 : public solver{
public:
	euler2(float x){
		n = x;
	}

	void solve(){
		data.push_back(1); // y(0) = 1;
		float serv = 1 + 1 / (2*n) * function( 0 , 1 );
		data.push_back(1 + 1 / n * function( 1/n, serv ));

		for (int i = 2; i < n + 1; ++i){
			serv = data[i - 1] + 1 / (2*n) * function( (i - 1) / n, data[i - 1] );
			data.push_back(data[i - 1] + 1 / n * function( (i - 1)/n + 1/(2*n) , serv ));
		}
	}
};



class runge : public solver{
public:
	runge(float x){
		n = x;
	}

	void solve(){
		data.push_back(1); // y(0) = 1;

		float k1 = function( 0, 1 );
		float k2 = function( 1/(2*n), 1 + 1/(2*n) * k1 );
		float k3 = function( 1/(2*n), 1 + 1/(2*n) * k2 );
		float k4 = function( 1/n, 1 + 1/n * k3 );

		data.push_back(1 + 1/(6*n) * (k1 + 2*k2 + 2*k3 + k4) );
		
		for (int i = 2; i < n + 1; ++i){

			k1 = function( (i-1)/n, data[i-1]);
			k2 = function( (i-1)/n + 1/(2*n), data[i-1] + 1/(2*n) * k1);
			k3 = function( (i-1)/n + 1/(2*n), data[i-1] + 1/(2*n) * k2);
			k4 = function( (i-1)/n + 1/n, data[i-1] + 1/n * k3);

			data.push_back(data[i-1] + 1/(6*n) * (k1 + 2*k2 + 2*k3 + k4));
		}
	}
};
	


int main(){	
	euler2 equation(1000);

	equation.solve();

	equation.out();
}
	
	