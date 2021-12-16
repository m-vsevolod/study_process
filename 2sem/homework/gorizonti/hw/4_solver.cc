#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

float f_1( float x, float y ){
	return 	x * x - 2 * y;
}

float f_2( float x, float y ){
	return x * x - 2 * y + 3;
}

class solver{
	vector<float> out;
	float init;
public:
	void solve( float (*func)(float, float)) {

		init = 1;
		out.push_back(init); // - y(0) = 1 - starting point

		for (int i = 1; i < 11; i++){
			init = out[i - 1] + 0.1 * func(0.1 * ( i - 1 ), out[i - 1]);
			out.push_back(init);
		}
	}

	void get(){
		for ( int i = 0; i < out.size(); i++){
			cout << out[i] << " ";
	    }
	}
};	

int main(){

	solver f1;
	solver f2;

	f1.solve(f_1);
	
	f1.get();

	cout << endl;

	f2.solve(f_2);

	f2.get();

}