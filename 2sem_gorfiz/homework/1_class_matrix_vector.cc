#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;

void size_error(){
	cout << "size error";
	exit(1);
}

class vec{

	int n;
	vector <float> a;

public:

	vec(){
		cout << "choose a size of the vector:" << endl;
		cin >> n;
		cout << "fill the vector with real numbers:" << endl;
		
		for (int i = 0; i < n; i++){
			float p;
			cin >> p;
			a.push_back(p);
		}

	}	

	~vec(){}

	void get_vec(){
		for(int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
	}
	
	bool comp(vec vv){
		if (this->n != vv.n){
			return false;
		}
		else {
		return true;
		}
	}

	void sum(vec vv){
		if( this->comp(vv)){
			for(int i = 0; i < this->n; i++){
				this->a[i] += vv.a[i];
			}
		}
		else { size_error();}
	}			

	void dif(vec vv){
		if( this->comp(vv)){
			for(int i = 0; i < this->n; i++){
				this->a[i] += vv.a[i];
			}
		}
		else { size_error(); }
	}

	float scal(vec vv){
		if( this->comp(vv)){
			float s = 0;
			for(int i = 0; i < this->n; i++){
				s += this->a[i] * vv.a[i];
			}
		return s;
		} else { size_error(); }

	}
};


class matr{

	int n;
	float** a;
	

public:
	matr(){
		cout << "choose a size of the matrix:" << endl;
		cin >> n;
		cout << "fill the matrix with real numbers:" << endl;
		
		a = new float* [n];

		for (int i = 0; i < n; i++){
			a[i] = new float [n];
		}

		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
	}

	~matr(){
		for(int i = 0; i < n; i++){
			delete[] a[i];
		}
		delete[] a;
	}

	void get_matr(){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cout << a[i][j] << " ";
			}
		cout << endl;
		}
	}

	float get_value(int i, int j){
		return a[i][j];
	}
		
	int get_n(){
		return n;
	}

	bool comp(matr &mm){
		if (this->n != mm.get_n()){
			return false;
		}
		else { return true;}
	}

	void sum(matr &mm){
		if (this->comp(mm)){
			for( int i = 0; i < n; i++){
				for ( int j = 0; j < n; j++){
					this->a[i][j] += mm.get_value(i, j);
				}
			}
		} else { size_error(); }
	}

	
	void dif(matr &mm){
		if (this->comp(mm)){
			for( int i = 0; i < n; i++){
				for ( int j = 0; j < n; j++){
					this->a[i][j] -= mm.get_value(i, j);
				}
			}
		} else { size_error(); }
	}
	
	void mult(matr &mm){
		
		float** c = new float* [n];
		for ( int i = 0; i < n; i++){
			c[i] = new float[n];
		}

		for ( int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				float s = 0;
				for (int r = 0; r < n; r++){
					s += a[i][r] * mm.get_value(r, j);
				}
				c[i][j] = s;
			}
		}
		
		for ( int i = 0; i < n; i++){
			for ( int j = 0; j < n; j++){
				a[i][j] = c[i][j];
			}
		}

		for ( int i = 0; i < n; i++){
			delete[] c[i];
		}
		delete[] c;
	}
};

int main() {

	cout << "type 'matrix' for matrices or 'vector' for vectors" << endl;
	
	string des;
	
	cin >> des;

	if ( des == "matrix" ) {

		matr f; matr g;

		cout << "available operators:" << endl;
		cout << "sum - to calculate the sum" << endl;
		cout << "dif - to calculate the difference" << endl;
		cout << "mult - to calculate the composition" << endl;
		cout << "stop - to stop the program" << endl;
	
		while (true) {
			cout << "choose an operator:" << endl;
			string optionm;
			cin >> optionm;
		
		if (optionm == "sum"){
			g.sum(f);
			cout << endl;
			g.get_matr();
		}

		else if (optionm == "dif"){
			g.dif(f);
			cout << endl;
			g.get_matr();
		}
	
		else if (optionm == "mult"){
			g.mult(f);
			cout << endl;
			g.get_matr();
		}

		else if (optionm == "stop"){
			break;
			return 0;
		}

		else { cout << "bad input"; }
	
		}

	} else if ( des == "vector" ) {
		
		vec a; vec b;

		cout << "available operators:" << endl;
		cout << "sum - to calculate the sum" << endl;
		cout << "dif - to calculate the difference" << endl;
		cout << "mult - to calculate the scalar composition" << endl;
		cout << "comp - to compare" << endl;
		cout << "stop - to stop the program" << endl;
		
		while(true){

			cout << "choose an operator:" << endl;
			string optionv;
			cin >> optionv;

			if ( optionv == "sum" ){
				b.sum(a);
				cout << endl;
				b.get_vec();
			}

			else if ( optionv == "dif" ){
				b.dif(a);
				cout << endl;
				b.get_vec();
			}
			
			else if ( optionv == "mult" ){
				b.scal(a);
				cout << endl;
				b.get_vec();
			}
		
			else if ( optionv == "stop" ){
				break;
				return 0;
			}
			
			else { cout << "bad input"; }
		}
	}
	else { cout << "bad input"; exit(1); }
}