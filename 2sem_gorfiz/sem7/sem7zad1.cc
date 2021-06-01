#include<iostream>

class vehicle{
	int wheels;
	int passengers;
public:
	vehicle(){}

	void set_wheels(int w){
		wheels = w;
	}

	int get_wheels(){
		return wheels;
	}

	void set_passengers(int p){
		passengers = p;
	}

	int get_passengers(){
		return passengers;
	}
	
	void show(){

	    get_passengers();
	    get_wheels();
	}
};



class truck : public vehicle{
	int cargo;
public:
	truck(){}

	void set_cargo(int c){
		cargo = c;
	}

	void get_cargo(){
		std::cout << " cargo "<< cargo;
	}
	
    void show(){
	    get_passengers();
	    get_wheels();
	    get_cargo();
	}       
};



class automobile : public vehicle{
	int type;
public:
	automobile(){}
	
	void set_type(int t){
		type = t;
	}

	void get_type(){
		std::cout << " type " << type;
	}
	
	void show(){
	    get_passengers();
	    get_wheels();
	    get_type();
	}
};



int main(){
	automobile benz;
	
	benz.set_wheels(4);
	benz.set_passengers(2);
	benz.set_type(1);
	
	benz.show();
}
		