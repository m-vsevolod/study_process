#include <set>
#include <random>
#include <string>
#include <fstream>

using std::endl;
using std::vector;
using std::string;


void output(string name, string file) {
	std::ofstream resout(file, std::ios::app);
	if (resout.is_open()) {
		resout << name << std::endl;
	}
	resout.close();
}



class Predicate {
public:
	virtual bool contains(int s) const {
		return true;
	}
};



class DiscreteState: public Predicate {
private:
	int const state;
public:
	DiscreteState(int state): state(state) {}

	bool contains(int s) const {
		return s == state;
	}
};



class SegmentState: public Predicate {
private:
	int const beg, end;
public:
	SegmentState(): beg(0), end(-1) {}
	SegmentState(int beg, int end): beg(beg), end(end) {}
	
	bool contains(int s) const {
		return s >= beg && s <= end;
	}
};



class SetState: public Predicate {
private:
	std::set<int> const states;
public:
	SetState(): states() {}
	SetState(std::set<int> const &src): states(src) {}
	
	bool contains(int s) const {
		return states.count(s) > 0;
	}
};



// пересечение отрезка и набора точек
class States1: public Predicate {
private:
	const Predicate& s1;
	const Predicate& s2;
public:
	States1(const Predicate& s1, const Predicate& s2): s1(s1), s2(s2) {};
	
	bool contains(int s) const {
		return s1.contains(s) && s2.contains(s);
	}
};



// объединение отрезка и набора точек
class States2: public Predicate {
private:
	const Predicate& s1;
	const Predicate& s2;
public:
	States2(const Predicate& s1, const Predicate& s2): s1(s1), s2(s2) {};
	
	bool contains(int s) const {
		return s1.contains(s) || s2.contains(s); 
	}
};



// исключение точек из отрезка
class States3: public Predicate {
private:
	const Predicate& s1;
	const Predicate& s2;
public:
	States3(const Predicate& s1, const Predicate& s2): s1(s1), s2(s2) {};

	bool contains(int s) const {
		return !s1.contains(s) && s2.contains(s);
	}
};



class ProbabilityTest {
private:
	unsigned seed;
	int test_min, test_max;
	unsigned test_count;
public:
	ProbabilityTest(unsigned seed, int test_min, int test_max, unsigned test_count):
	seed(seed), test_min(test_min), test_max(test_max), test_count(test_count) { }

	float operator()(Predicate const &s) const {

		std::default_random_engine rng(seed);
        	std::uniform_int_distribution<int> dstr(test_min,test_max);
		unsigned good = 0;

		for (unsigned cnt = 0; cnt != test_count; ++cnt){
			if (s.contains(dstr(rng))) ++good;
		}
		
		return static_cast<float>(good) / static_cast<float>(test_count);
	}

	void tc_change(int n){
		test_count = n;
	}
};



int main(int argc, const char * argv[]){

	SegmentState s(0,10);
	SetState ss({1, 3, 5, 7, 23, 48, 57, 60, 90, 99});

    	ProbabilityTest pt(10,0,100,100000);

 	for (unsigned i = 0; i < 1000; i++) {
		output(std::to_string(pt(s)), "segment.txt");
		output(std::to_string(pt(ss)), "set.txt");
		pt.tc_change(1000 + 1000 * (i + 1));
	}

        return 0;
}


