#include<iostream>
#include<string>

using namespace std;

class TwoDShape{
protected:
	int width;
	int height;
public:
	TwoDShape(int w, int h){
		width = w;
		height = h;
	}

	void show(){
		cout << " width: " << width;
		cout << " height: " << height;
		cout << endl;
	}

};

class Triangle : public TwoDShape{
protected:
	string style;
public:
	Triangle(string s, int w, int h): TwoDShape(w, h){
		style = s;
	}

	void show(){
		cout << " width: " << width;
		cout << " height: " << height;
		cout << " style: " << style;
		cout << endl;
	}

};

class Colour_Triangle : public Triangle{
protected:
	string colour;
public:
	Colour_Triangle(string c, string s, int w, int h): Triangle(s, w, h){
		colour = c;
	}

	void show(){
		cout << " width: " << width;
		cout << " height: " << height;
		cout << " style: " << style;
		cout << " colour: " << colour;
		cout << endl;
	}
};

int main(){

	Colour_Triangle red_abc("red", "abc", 3, 4);

	red_abc.show();

	TwoDShape circle(5, 5);

	circle.show();

	Triangle abc("abc", 8, 10);

	abc.show();
}
	
