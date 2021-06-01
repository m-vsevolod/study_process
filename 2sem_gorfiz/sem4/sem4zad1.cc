#include<iostream>

void show(int** a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            std::cout << a[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
    
void show(int* a, int n){
    for (int i = 0; i < n; i ++){
        std::cout << a[i] << ' ';
    }
}
    
int main(){
    int m; //stroki
    int n; //stolbtsi
    
    std::cin >> m >> n;
    
    std::cout << std::endl;
    
    int* c = new int [n];
    int **d = new int* [n];
    
    for (int i = 0; i < m; i++){
        d[i] = new int [n];
    }
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            d[i][j] = rand() % 5;
        }
        c[i] = rand() % 5;
    }
    
    show(d, m, n);
    
    std::cout << std::endl;
    
    show(c, n);
    
    for(int i = 0; i < m; i++){
        delete[] d[i];
    }
    delete[] d;
    delete[] c;
}
            