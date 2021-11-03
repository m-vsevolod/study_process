#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

float transform(float x){
	return x / 5;
} 

class coord{
protected:
	vector<float> num = {};
public:
	coord() = default;
	
	coord(vector<float> a): num(a) {}

	void set(vector<float> a){
		num = a;
	}
	
	virtual vector<float> get(){
		return num;
	}

	virtual void show(){
		for (int i = 0; i < num.size(); ++i){
			cout << num[i] << ' ';
		}
	}
};

class abscoord : public coord{
public:
	abscoord(coord a){
		vector<float> h;
		h = a.get();
		for(int i = 0; i < h.size(); ++i){
			num[i] = abs(h[i]);
		}		
	}

	abscoord(vector<float> a){
		for(int i = 0; i < a.size(); ++i){
			num.push_back(abs(a[i]));
		}
	}		

	abscoord() = default;

	void setabs(vector<float> a){
		for(int i = 0; i < a.size(); ++i){
			num[i] = abs(a[i]);
		}
	}	
}; 

class modcoord : public coord{
public:
	modcoord(coord a){
		vector<float> h;
		h = a.get();
		for(int i = 0; i < h.size(); ++i){
			num.push_back(transform(h[i]));
		}
	}

	modcoord(vector<float> h){
		for(int i = 0; i < h.size(); ++i){
			num.push_back(transform(h[i]));
		}
	}

	modcoord() = default;

	void setmod(vector<float> a){
		for(int i = 0; i < a.size(); ++i){
			num[i] = a[i];
		}
	}
};

int quadr(coord* p){ // только для векторов длины 2
	abscoord* a;
	modcoord* m;

	a = dynamic_cast<abscoord*>(p); // укажет nullptr если p не abscoord
	m = dynamic_cast<modcoord*>(p); // укажет nullptr если p не modcoord

	if (a != nullptr){
		return 1;
	}
	else if (m != nullptr){

		vector<float> h = m->get();

		if (h[0] > 0 and h[1] > 0){
			return 1;
		}

		if (h[0] < 0 and h[1] > 0){
			return 2;
		}

		if (h[0] < 0 and h[1] < 0){
			return 3;
		}

		if (h[0] > 0 and h[1] < 0){
			return 4;
		}

		if (h[0] == 0 and h[1] == 0){
			return 0;
		}
	}
	else {
		return -1;
	}
}

int main(){

	vector<float> p = {1.5, -1.7};

	modcoord a(p);


		
}		