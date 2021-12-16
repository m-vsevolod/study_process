#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

void output(string name, string file) {
	std::ofstream resout(file, std::ios::app);
	if (resout.is_open()) {
        	resout << name << std::endl;
	}
	resout.close();
}



class Errors {

public:
	void virtual perr() = 0;
	virtual ~Errors() = default;
};



class CurErr : public Errors {

	double c, t, h;

public:
	
	CurErr(double c, double t, double h): c(c), t(t), h(h) {}

	void perr() override {
		cout << "curant error";
	}

	bool test() {
		if (c * t / h < 1){
			return true;
		}
		else {
			return false;
		}
	}
};

class NewErr : public Errors {
public:
	void perr() override {
		cout << "newerr";
	}
};


class scheme {

protected:

	vector<double> prev;
	vector<double> pres;

public:
	scheme(int param_N) {
        	prev.resize(param_N);
        	pres.resize(param_N);
    	}
};



class CIR : public scheme{

	double t; 
	int T; 
    	double h;
    	int N; 
    	double c = 1; 

public:

    	CIR(int param_N, int param_T) : scheme(param_N) {
        	N = param_N; 500
        	T = param_T; 250
        	h = 1 / (double)N;
        	t = 0.01 * h / c;

		CurErr error(c, t, h);
		if (error.test()){
			throw error;
		}
    	}

    	void present_output() {
        	for (int i = 0; i < N; i++) {
            		output(std::to_string(pres[i]), "cir_scheme.txt");
        	}
        	cout << std::endl;
    	}

    	void get_solve(vector<double> init) {
        	pres = init;

        	for (int i = 0; i < T; ++i) {
            		prev = pres;
            		pres.clear();

            		double res_init = prev[0] - (c * t / h) * (prev[0] - 0);

            		pres.push_back(res_init);

            		for (int j = 1; j < N; ++j) {
                		double res = prev[j] - c * t / h * (prev[j] - prev[j - 1]);
                		pres.push_back(res);
            		}
		}
    	}

    	void get_result() {
        	for (int i = 0; i < pres.size(); ++i) {
            		cout << pres[i] << " ";
        	}
    	}

};



class LW : public scheme{

    	double t; 
    	int T; 
    	double h;
    	int N; 
	double c = 1;

public:

    	LW(int param_N, int param_T) : scheme(param_N) {
        	N = param_N;
        	T = param_T;
        	h = 1 / (double)N;
        	t = 0.01 * h / c; 
    	}

    	void present_output() {
        	for (int i = 0; i < N; i++) {
            		output(std::to_string(pres[i]), "lw_scheme.txt");
        	}
        	cout << std::endl;
    	}

    	void get_solve(vector<double> init) {
        	pres = init;

        	for (int i = 0; i < T; i++) {
            		prev = pres;
            		pres.clear();

           		double res_init = prev[0] - 0.5 * (c * t / h) * (prev[1] - 0) + 
			0.5 * (c * t / h) * (c * t / h) * (prev[1] - 2 * prev[0] + 0);

            		pres.push_back(res_init);

            		for (int j = 1; j < N - 1; j++) {
                		double res = prev[j] - 0.5 * (c * t / h) * (prev[j + 1] - prev[j - 1])
				+ 0.5 * (c * t / h) * (c * t / h) * (prev[j + 1] - 2 * prev[j] + prev[j - 1]);
                		pres.push_back(res);
            		}

			double res_fin = prev[N - 1] - c * t / (2 * h) * (0 - prev[N - 2])
	    		+ c * c * t * t / (2 * h * h) * (0 - 2 * prev[N - 1] + prev[N - 2]);

            		pres.push_back(res_fin);
        	}
    	}

    	void get_result() {
        	for (int i = 0; i < pres.size(); ++i) {
            		cout << pres[i] << " ";
        	}	
    	}
};



int main() {

    	int N = 500;
    	int T = 250;

    	vector<double>initial;

    	for (int i = 0; i < N; ++i) {
        	if ((i > 0.2 * N) and (i < 0.4 * N)) {
            	initial.push_back(1);
        	}
        	else {
            	initial.push_back(0);
        	}
    	}

    	for (int i = 0; i < N; ++i) {
        	output(std::to_string(initial[i]), "initial.txt");
    	}
	
	try{
    		CIR cir(N, T);
    		cir.get_solve(initial);
    		cir.present_output(); 
	}
	
	catch(CurErr error){
		error.perr();
	}

	catch(...){
		cout << "unknown error";
	}
}