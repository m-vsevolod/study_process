#include<iostream>
#include<vector>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void size_error(){
	cout << "size_error";
	exit(1);
}

class vec{
	int n;
	vector<float> a;
public:
	vec(vector<float> x){
		for ( int i = 0; i < x.size(); i++ ){
			a.push_back(x[i]);
		}
		n = x.size();
	}

	vec() = default;

	~vec() = default;

	void get(){
		for ( int i = 0; i < n; i++ ){
			cout << a[i] << " ";
		}
		cout << endl;
	}

	vec operator + (vec x){
		if ( x.n != a.size() ){
			size_error();
		}
		else { 
			vec out;
			for ( int i = 0; i < x.n; i++){
				out.a.push_back( a[i] + x.a[i] );
			}
			out.n = x.a.size();
			return out;
		}
	}
	
	vec operator - (vec x){
	   if ( x.n != a.size() ){
	        size_error();
	   }
	   else {
	       vec out;
	       for ( int i = 0; i < x.n; i++){
	           out.a.push_back( a[i] - x.a[i] );
	       }
	       out.n = x.a.size();
	       return out;
	   }
	}
	
	float operator * (vec x){
	    if ( x.n != a.size() ){
	        size_error();
	    }
	    else {
	        float s = 0;
	        for ( int i = 0; i < x.n; i++){
	            s += a[i] * x.a[i];
	        }
	        return s;
	    }
	}
};

int main(){
    
	vector<float> xx = {1, 2, 3};
	
	vec x(xx); vec y(xx);
		
	(x - y).get();

	cout << endl;

	(x + y).get();

	cout << endl;
	
	cout << x * y;

}