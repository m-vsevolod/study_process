#include<iostream>

int main(){

int n; std::cin >> n;

float** a = new float* [n];
float** b = new float* [n];
float** c = new float* [n];


for (int i = 0; i < n; i++){
	a[i] = new float [n];
	b[i] = new float [n];
	c[i] = new float [n];
}

for (int i = 0; i < n; i++){
	for (int j = 0; j < n; j++){
		std::cin >> a[i][j];
	}
}

for (int i = 0; i < n; i++){
	for (int j = 0; j < n; j++){
		std::cin >> b[i][j];
	}
}

for (int i = 0; i < n; i++){
	for (int j = 0; j < n; j++){
		float s = 0;
		for (int r = 0; r < n; r++){
			s += a[i][r] * b[r][j];
		}
		c[i][j] = s;
	}
}

for (int i = 0; i < n; i++){
	for (int j = 0; j < n; j++){
		std::cout << c[i][j] << " ";
		}
	std::cout << std::endl;
}
}