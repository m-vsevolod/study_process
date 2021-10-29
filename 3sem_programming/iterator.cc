#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template<typename> class Mvectoriterator; 

template<typename T> class Mvector {
	T* p = nullptr;						 // Адрес памяти, выделенной под массив
	unsigned sz = 0;					 // и его размерность (количество элементов)
public:
										 // Описание типа "итератор" внутри пространства имён класса - позволяет
	using iterator = Mvectoriterator<T>; // использовать общепринятую форму записи итератора class_name::iterator,
										 // избежав указания на конкретную форму его релизации
	Mvector() = default;
	Mvector(unsigned n) : sz(n), p(new T[n] {0}) {}		// Конструкторы по размерности и по списку инициализации
	Mvector(const initializer_list<T>& a) : Mvector(a.size()) { auto i=0u; for(const auto& x : a) p[i++] = x; }

	Mvector(const Mvector&) = delete;					// Конструктор и оператор копирования запрещены
	Mvector& operator=(const Mvector&) = delete;

	~Mvector() { delete [] p; }							// Деструктор (необходим: объекты используют память кучи)

	friend std::istream& operator>>(std::istream& in, Mvector& b) {		// Доопределим операторы ввода/вывода
		for(auto& x : b) in >> x;
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const Mvector<T>& b) {
		out << "(";
		for(const auto x : b) out << x << ' ';
		return out << "\b)";
	}
	iterator begin() const { return p; }	// Возвращает объект MvectorIterator<T> - итератор на начало
	iterator end() const { return p+sz; }	// и на конец данных
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
	Mvector<int> a {1, 10, 2, 9 ,3, 8, 4, 7, 5, 6, 2, 2, 2};				// Определение объекта
	for_each(a.begin(), a.end(), [](int i){ if(i%2) cout << i << ' '; });	// Вывод нечётных элементов
	cout << endl;
	std::sort(a.begin(), a.end());											// Сортировка
	cout << a;						// Используем запись типа итератора в таповой для STL форме
	pair<Mvector<int>::iterator, Mvector<int>::iterator> bounds;			// Границы участка равных значений
	bounds=equal_range(a.begin(), a.end(), 2);								// Поиск участка [) элементов равных 2
	cout << " bounds at positions " << distance(a.begin(), bounds.first);	// Вывод индексов 
	cout << " and " << (bounds.second - a.begin()) << endl;
}