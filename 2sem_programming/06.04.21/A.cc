#include<iostream>
#include<vector>

void F(int n) {
	std::cout << n;
        if (n >= 3) {
                F(n / 2);
                F(n - 1);
        }
}

int main(){
	
	int k;
	
	std::cin >> k;

	F(k);
}	