#include <iostream>

template <typename T> // takes into account the comment about different data types
class Grid {
private:
	T* memory;
	size_t x_size, y_size;
public:

	// allocates memory for a one-dimension array
	
	Grid(size_t x_size, size_t y_size): x_size(x_size), y_size(y_size), memory(new T[x_size*y_size]){ };

	// constructor for making copies

	Grid(Grid const& copy) : Grid(copy.x_size, copy.y_size){
		for (size_t pos = 0; pos != x_size * y_size; ++pos){
			memory[pos] = copy.memory[pos];
		}
	}

	// deconstructor to free the allocated memory

	~Grid() {
		delete[] memory;
	}

	T operator()(size_t x_idx, size_t y_idx) const {
		return memory[(x_idx - 1) + x_size * (y_idx - 1)];
	}

	T& operator()(size_t x_idx, size_t y_idx) {
		return memory[(x_idx - 1) + x_size * (y_idx - 1)];
	}

	// returns the size

	size_t get_xsize() const {
		return x_size;
	}

	size_t get_ysize() const {
		return y_size;
	}

	// assignment operator

	Grid& operator = (T value) {
		for (size_t pos = 0; pos != x_size * y_size; ++pos) {
			memory[pos] = value;
		}
		return *this;
	}

	// << overloading

	friend std::ostream& operator << (std::ostream& out, Grid const& grid) {
		for (T i = 1; i != grid.y_size + 1; ++i) {
			for (T j = 1; j != grid.x_size + 1; ++j) {
				out << grid.memory[(j - 1) + grid.x_size * (i - 1)] << ' ';
			}
			out << std::endl;
		}
		out << std::endl;
		return out;
	}

	// >> overloading

	friend std::istream& operator>>(std::istream& in, Grid& grid) {
		for (T i = 0; i != grid.y_size*grid.x_size; ++i) {
			in >> grid.memory[i];
		}
		return in;
	}
};

int main(){
	Grid<int> g1(5,3); // creates a matrix 3 x 5
	g1 = 3; // fills it with 3
	std::cout << g1; // shows it

	std::cout << g1(1,1) << std::endl; // element (1,1)

	Grid<int> g2(5,3);
	std::cin >> g2; // fills the matrix using the keyboard
	std::cout << std::endl << g2; 

	Grid<int> g3(g1); // copies g1
	std::cout << g3;
	g3(1,1) = 5;
	std::cout << "changes have passed \n" <<g3;
}
	
	