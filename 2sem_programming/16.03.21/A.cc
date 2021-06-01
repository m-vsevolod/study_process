#include<iostream>

int main(){
    int n; int m;
    std::cin>>n>>m;
    
    int *a = new int[n];
    int *b = new int[n];
    
    while ( m >= n ){
        m = m - n;
    }
    
    for (int i = 0; i < n; i++){
        std::cin>>a[i];
    }
    
    for (int i = 0; i < n; i++){
        if ( i + m >= n ){
            b[i] = a[i + m - n];
        }
        else {
            b[i] = a[i + m];
        }
    }
    
    for (int i = 0; i < n - 1; i++){
        std::cout<<b[i]<<" ";
    }
    std::cout<<b[n-1];
    
    delete[] a;
    delete[] b;
}