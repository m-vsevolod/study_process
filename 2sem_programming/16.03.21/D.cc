#include<iostream>

int main(){

int n;
int sub;
int *a = new int [n];
std::cin >> n;

for (int i = 0; i < n; i++){
	std::cin >> a[i];
}

for (int i = 0; i < n - 1; i++){
	for (int j = 0; j < n - i - 1; j++){
		if (a[j] > a[j+1]){
			sub = a[j];
			a[j] = a[j+1];
			a[j+1] = sub;
		}
	}
}

for (int i = 0; i < n - 1; i++){
	std::cout << a[i] << ' ';
}
std::cout << a[n-1];

}