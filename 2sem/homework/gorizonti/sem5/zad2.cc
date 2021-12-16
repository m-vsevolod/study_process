#include<iostream>
#include<vector>



void incr(std::vector<int> m){
	int sub = 0;
	for (int i = 0; i < 10; i++){
	for (int j = 0; j < 10 - i - 1; j++){
		if (m[j] > m[j+1]){
			sub = m[j];
			m[j] = m[j+1];
			m[j+1] = sub;
		}
	}
	}
	for (int i = 0; i < 10; i++){
		std::cout << m[i] << ' ';
	}
}



void decr(std::vector<int> m){
	int sub = 0;
	for (int i = 0; i < 10; i++){
	for (int j = 0; j < 10 - i - 1; j++){
		if (m[i] < m[j+1]){
			sub = m[j];
			m[j] = m[j+1];
			m[j+1] = sub;
		}
	}
	}
	for (int i = 0; i < 10; i++){
		std::cout << m[i] << ' ';
	}
}



void psort(void(*p)(std::vector<int> m), std::vector<int> m){ p(m); }

int main(){

	std::vector<int> vec;

	for(int i = 0; i < 10; i++){
		int s = rand() % 5;
		vec.push_back(s);
		std::cout << vec[i] << ' ';
	}

	std::cout << std::endl;

	void (*p)(std::vector<int>);

	p = incr;
	
	psort(p, vec);

	std::cout << std::endl;

	p = decr;

	psort(p, vec);

}