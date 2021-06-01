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

class matr{
    int n;
	vector<vector<float>> a;
public:
	matr(vector<float> x){
		if ( sqrt(x.size()) != ceil( sqrt( x.size() ) ) ) {
			size_error();
		}
		else {
			n = sqrt(x.size());
			for  ( int i = 0; i < n; i++ ){
				a.push_back({}); 
				for ( int j = 0; j < n; j++ ){
					a[i].push_back(x[ j + i * n ]);
				}
			}
		}
	}

	matr() = default;
	~matr() = default;
	
	void get(){
		for ( int i = 0; i < n; i++ ){
			for ( int j = 0; j < n; j++){
				cout << a[i][j] << " ";
		    	}
		    cout << endl;
	    }
	}

	matr operator + ( matr x ){
		if ( x.n != a.size() ){
			size_error();
		}
		else {
			vector<float> s;
			for ( int i = 0; i < x.n; i++ ){
			    for ( int j = 0; j < x.n; j++){
			    	s.push_back( a[i][j] + x.a[i][j] );
			    }
			}
			matr sum(s);
			return sum;
		}
	}
	

	matr operator - ( matr x ){
		if ( x.n != a.size() ){
			size_error();
		}
		else {
			vector<float> d;
			for ( int i = 0; i < x.n; i++ ){
			    for ( int j = 0; j < x.n; j++){
			    	d.push_back( a[i][j] - x.a[i][j] );
			    }
			}
			matr dif(d);
			return dif;
		}
	}

	matr operator * ( matr x ){
		if ( x.n != a.size() ){
			size_error();
		}
		else { 
			vector<float> m;
			for ( int i = 0; i < x.n; i++){
				for ( int j = 0; j < x.n; j++){
					float d = 0;
					for ( int r = 0; r < x.n; r++){
						d += x.a[r][j] * a[i][r];
					}
					m.push_back(d);
				}
			}
		matr mult(m);
		return mult;
	    }
	}
		
};

int main(){
	
	vector<float> p = {1, 2, 3, 4};
	vector<float> q = {4, 3, 2, 1};

	matr pp(p); matr qq(q);

	matr sum;

	sum = pp + qq;

	sum.get();

	cout << endl;

	matr dif;

	dif = pp - qq;

	dif.get();

	cout << endl;

	matr mult;

	mult = pp * qq;

	mult.get();
	
}							