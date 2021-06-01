#include<iostream>
#include<cmath>

class solver{
	float h = 0.1; 
	float init = 1;
	float* y = new float [11];
public:
	void solve(){
		y[0] = init;
		for (int i = 1; i < 11; i++){
			y[i] = y[i-1] + h * ( (i-1)*(i-1)*h*h - 2 * y[i-1]); 
		} 
	}

	void show(){
		for (int i = 0; i < 11; i++){
			std::cout << y[i] << " ";
		}
	}

};

int main(){
	
	solver q;
	
	q.solve();
	q.show();

}
		
		
	

