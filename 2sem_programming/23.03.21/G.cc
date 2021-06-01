#include<iostream>

int main(){
int n; int m;

std::cin >> n >> m;

for(int i = 0; i < m; i++){
	std::cout << "|";
}

for(int i = 0; i < n; i++){
	std::cout << "=";
}

for(int i = 0; i < m; i++){
	std::cout << "|";
}

}
