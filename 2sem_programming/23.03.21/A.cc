#include<iostream>

int main(){

int n; int m;

std::cin >> n >> m;

for(int i = 0; i < m; i++){
	std::cout<<"*";
}

std::cout << std::endl;

if(n > 2){
    for(int i = 0; i < n - 2; i++){
        std::cout << "*";
        for(int j = 0; j < m - 2; j++){
            std::cout << " ";
        }
        std::cout << "*" << std::endl;
    }
}

for(int i = 0; i < m; i++){
	std::cout<<"*";
}
}