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

class matr;

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
	
	friend vec vec_matr( vec str, matr mat );
};

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
			sum.n = x.n;
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
			dif.n = x.n;
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
		mult.n = x.n;
		return mult;
	    }
	}

	friend vec vec_matr( vec str, matr mat );
		
};

vec vec_matr( vec str, matr mat ){
	if ( str.n != mat.n ){
		size_error();
	}
	else {
		vec out;
		for ( int i = 0; i < mat.n; i++ ){
			float s = 0;
			for ( int j = 0; j < mat.n; j++ ){
				s += str.a[j] * mat.a[j][i];
			}
			out.a.push_back(s);
		}
		out.n = str.n;
		return out;
	}
}

int main(){
	vector<float> qq = {1, 2, 3, 4};
	matr q(qq);
	vector<float> ee = {1, 0};
	vec e(ee);

	vec_matr( e, q ).get();
}