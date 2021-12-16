#include<iostream>
#include<vector>

struct vec{
    std::vector<int> v[3];
    
	void show( vec r ){
		for(int i = 0; i < 3; i++){
			std::cout << r.v[i];
		}
	}
};

void vec::operator+( vec r, vec s ){
	vec j;
	j.v[0] = r.v[0] + s.v[0];
	j.v[1] = r.v[1] + s.v[1];
	j.v[2] = r.v[2] + s.v[2];
}

int main(){
	vec q;
	
	for(int i = 0; i < 3; i++){
		std::cin >> q.v[i];
	}

	std::cout << std::endl;	

	vec p;

	for(int i = 0; i < 3; i++){
		std::cin >> p.v[i];
	}

	std::cout << std::endl;	

	q + p;
	
	q.show();

}