#include<iostream>

int main(){
    int n;
    std::cin >> n;
    
    int *a = new int[n];
    
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    
    std::cout << (a[n - 1] + a[0] + a[1]) / 3 << ' ';
    for (int i = 1; i < n-1; i++){
        std::cout << ( a[i - 1] + a[i] + a[i + 1]) / 3 << ' ';
    }
    std::cout << (a[n - 2] + a[n - 1] + a[0]) / 3;
   
    delete [] a;
}