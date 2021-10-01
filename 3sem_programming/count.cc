#include <iostream>
#include <list>

int main() {

	size_t n, m, counter = 1;
 	std::cin >> n >> m;
  	std::list<size_t> people;

  	for (size_t i = 1; i <= n; ++i) {
    		people.push_back(i);
  	}

  	for (auto i = people.begin(); n > 0; ++counter) {
    		if (counter % m == 0) {
      			if (n <= 3) {
        			std::cout << *i << '\n';
      			}
    	  		i = people.erase(i);
      			--n;
    		} else {
      			++i;
    		}
    		if (i == people.end()) {
      			i = people.begin();
    		}
  	}
}