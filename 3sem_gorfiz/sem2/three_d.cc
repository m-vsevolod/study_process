#include<iostream>

class three_d{
	int x;
	int y;
	int z;
public:
	three_d(int a, int b, int c){
		x = a;
		y = b;
		z = c;
	}

	void get(){
		std::cout << x <<" "<< y <<" "<< z;
	}

	void *operator new(size_t size){
		three_d *p = (three_d *)malloc(size);
		return p;
	}		
	
	void operator delete(void *p){
		free(p);
	}

	void *operator new[](size_t size){
		three_d *p = (three_d *)malloc(size);
		return p;	
	}

	void operator delete[](void *p){
		free(p);
	}
		
};

int main(){
	
}
