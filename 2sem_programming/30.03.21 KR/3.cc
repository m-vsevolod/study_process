#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
	int m; int n; int k;

	cin >> m >> n >> k;
	
	char** a = new char* [m];
	for ( int i = 0; i < m; i++){
		a[i] = new char [n];
	}

	for (int i = 0; i < m; i++){
		for ( int j = 0; j < n; j++){
			a[i][j] = '*';
		}
	}

	int** p = new int* [k];
	for ( int i = 0; i < k; i++){
		p[i] = new int [2];
	}

	for ( int i = 0; i < k; i++){
		for ( int j = 0; j < 2; j++){
			cin >> p[i][j];
		}
	}

	for ( int i = 0; i < m; i++){
		for ( int j = 0; j < n; j++){
			for ( int r = 0; r < k; r++){
				if (( p[r][0] == i ) && ( p[r][1] == j )){
					a[i][j] = 'T';
				}
			}
		}
	}

	for ( int j = 0; j < n; i++){
		for ( int i = 0; i < m; j++){
			cout << a[j][i] << ' ';
		}
		cout << endl;
	}

	for ( int i = 0; i < m; i++){
		delete[] a[i];
	}
	delete[] a;

	for ( int i = 0; i < k; i++){
		delete[] p[i];
	}
	delete[] p;
	
}
		
