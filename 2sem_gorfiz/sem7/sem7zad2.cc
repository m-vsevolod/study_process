#include<iostream>



class base{
protected:
	int i, j;
public:
	void set(int a, int b){
		i = a;
		j = b;
	}

	void show(){
		cout << i << " " << j;
	}
};



class derived1 : public base{
	int k;
public:
	derived1(int x){ k = x;}
	void showk(){
		std::cout << k;
	}
};



class derived2 : public derived1{
	int m;
public:	
	setm(int x){
		m = x;
	}

	showm(){
		std::cout << m << " ";
};

int main(){
	derived2 ob;
	ob.set(1,2);
}
			
	