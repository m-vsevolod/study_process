#include<iostream>
#include<vector>
#include<cmath>

using std::vector;
using std::cout;
using std::endl;



class size{
protected:
	int n;
public:

	size() = default;

	size(int x){
		n = x;
	}		
};



class vec: protected size{
protected:
	vector<float> a;
public:
	vec(int x, vector<float> vec): size(x){
		a = vec;
	}

	void show_vector(){
		for ( int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
};



class matrix: protected size{
protected:
	vector<float> a;
public:

	matrix() = default;
	
	matrix(int x, vector<float> mat): size(x){
		a = mat;
	}

	void show_matrix(){
		if ( sqrt(n) - ceil(sqrt(n)) == 0 ){
			for ( int i = 0; i < n; i+=sqrt(n)){
				for ( int j = 0; j < sqrt(n); j++){
					cout << a[j+i] << ' ';
				}
				cout << endl;
			}
			cout << endl;
		}
		else {
			cout << "error size";
		}
	}

};



int main(){

	vector<float> p = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	matrix pm(p.size(), p);

	vec pv(p.size(), p);

	pv.show_vector();

	cout << endl;

	pm.show_matrix();

}


	
		
		

