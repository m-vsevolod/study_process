#include<iostream>

#include<fstream>

#include<cmath>



int main() {


	std::ofstream resout;

	resout.open("function.txt");

 
	double u = 0.05; // константа u


	double zerodots[11]; // массив начальных данных
	
double dots[11]; // рабочий массив



	    /* заполнение начальными данными */

    for ( int i = 1; i < 11; i++){
        double x = i;
        zerodots[i] = std::exp(-0.5*x*x+2.5) ;
    }
    zerodots[0]=0;

    /* итерационное вычисление функции от времени */

    for ( int t = 0; t <= 100; t++){

        resout << t << "." << std::endl;

        for ( int j = 0; j < 11; j++){
            resout << zerodots[j] << std::endl;
        }


        dots[0] = 0;
        for ( int j = 1; j < 11; j++ ){
            dots[j] = (zerodots[j] - u * ( zerodots[j] - zerodots[j-1]));
        }

        /* переобозначение массивов */

        std::swap(zerodots, dots);

        resout << std::endl << std::endl << std::endl;

    }

    resout.close();
}