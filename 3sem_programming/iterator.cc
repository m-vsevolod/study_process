#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template<typename> class Mvectoriterator; 

template<typename T> class Mvector {
	T* p = nullptr;						 // ����� ������, ���������� ��� ������
	unsigned sz = 0;					 // � ��� ����������� (���������� ���������)
public:
										 // �������� ���� "��������" ������ ������������ ��� ������ - ���������
	using iterator = Mvectoriterator<T>; // ������������ ������������ ����� ������ ��������� class_name::iterator,
										 // ������� �������� �� ���������� ����� ��� ���������
	Mvector() = default;
	Mvector(unsigned n) : sz(n), p(new T[n] {0}) {}		// ������������ �� ����������� � �� ������ �������������
	Mvector(const initializer_list<T>& a) : Mvector(a.size()) { auto i=0u; for(const auto& x : a) p[i++] = x; }

	Mvector(const Mvector&) = delete;					// ����������� � �������� ����������� ���������
	Mvector& operator=(const Mvector&) = delete;

	~Mvector() { delete [] p; }							// ���������� (���������: ������� ���������� ������ ����)

	friend std::istream& operator>>(std::istream& in, Mvector& b) {		// ����������� ��������� �����/������
		for(auto& x : b) in >> x;
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const Mvector<T>& b) {
		out << "(";
		for(const auto x : b) out << x << ' ';
		return out << "\b)";
	}
	iterator begin() const { return p; }	// ���������� ������ MvectorIterator<T> - �������� �� ������
	iterator end() const { return p+sz; }	// � �� ����� ������
};


template<typename T> class Mvectoriterator : public iterator<random_access_iterator_tag, T> {
	T* p = nullptr;
public:
	Mvectoriterator() = default; // creates a free iterator

	Mvectoriterator(T* x): p(x) {}; // creates an interator pointing to an object type T

	// p++ operator
	Mvectoriterator& operator++() {
		p++; 
		return *this; }

	// ++p operator
	Mvectoriterator operator++(int) { 
		T* h = p;
		++p;
		return h;}

	// p-- operator
	Mvectoriterator& operator--() {
		p--;
		return *this; }

	// --p operator
	Mvectoriterator operator--(int) {
		T* h = p;
		--p;
		return h; }

	// returns the "distance" between iterators
	ptrdiff_t operator-(const Mvectoriterator& r) const {
		return p - r.p; }

	// + action
	Mvectoriterator operator+(int r) {
		return Mvectoriterator(p + r);}

	// - action
	Mvectoriterator operator-(int r) {
		return Mvectoriterator(p - r);}

	// += action
	Mvectoriterator operator+=(int r) {
		p+=r; 
		return Mvectoriterator(p);}

	// -= action
	Mvectoriterator operator-=(int r) {
		p-=r;
		return Mvectoriterator(p);}

	// < operator
	bool operator<(const Mvectoriterator& r) const {
		return p < r.p; }

	// > operator
	bool operator>(const Mvectoriterator& r) const {
		return p > r.p;	}

	// == operator
	bool operator==(const Mvectoriterator& r) const {
		return p == r.p; }

	// != operator
	bool operator!=(const Mvectoriterator& r) const {
		return !(*this == r); }

	// dereference operator
	T& operator*() {
		return *p; }
		
};

int main() {
	Mvector<int> a {1, 10, 2, 9 ,3, 8, 4, 7, 5, 6, 2, 2, 2};				// ����������� �������
	for_each(a.begin(), a.end(), [](int i){ if(i%2) cout << i << ' '; });	// ����� �������� ���������
	cout << endl;
	std::sort(a.begin(), a.end());											// ����������
	cout << a;						// ���������� ������ ���� ��������� � ������� ��� STL �����
	pair<Mvector<int>::iterator, Mvector<int>::iterator> bounds;			// ������� ������� ������ ��������
	bounds=equal_range(a.begin(), a.end(), 2);								// ����� ������� [) ��������� ������ 2
	cout << " bounds at positions " << distance(a.begin(), bounds.first);	// ����� �������� 
	cout << " and " << (bounds.second - a.begin()) << endl;
}