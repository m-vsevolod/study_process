#include<iostream>
#include<vector>

using std::vector;
using std::ostream;
using std::istream;
using std::cout;
using std::cin;

ostream &operator << ( ostream &stream, vector<int> obj ){
	for( int i = 0 ; i < obj.size() - 1; i++){
		stream << obj[i] << ", ";
	}
	stream << obj[obj.size() - 1] << ".";
	return stream;
}

istream &operator >> ( istream &stream, vector<int> obj ){
	char stop = '\n';
	char r = '1';
	while ( r != stop ){
		stream >> r;
		obj.push_back(r);
	}
	return stream;
}


int main(){
	vector<int> a = {1, 2, 3, 4, 5};
	
	cout << a;

	vector<int> b;

	cin >> b;

	cout << b;
}

	
	
	