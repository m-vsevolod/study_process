#include<iostream>

class base1{
public:
base1(){
	std::cout << " base1 ";
}

~base1(){
	std::cout << " base1 finish ";
}
};

class base2{
public:
base2(){
	std::cout << " base2 ";
}

~base2(){
	std::cout << " base2 finish ";
}
};

class base3{
public:
base3(){
	std::cout << " base3 ";
}

~base3(){
	std::cout << " base3_finish";
}
};

class r: public base1, public base2, public base3{
public:
r(){
	std::cout << "r";
}
~r(){
	std::cout << "r finish";
}
};

int main(){
	r object;
}

