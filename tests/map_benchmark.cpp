#include <ctime>

class Timer {

	std::clock_t _start;

public:
	Timer() { _start = 0; };

	~Timer() {};

	void start() {
		_start = std::clock();
	}

	std::clock_t stop() {
		return std::clock() - _start;
	}

};

#include <iostream>
#include <map>
#include "map.hpp"

// mapType must be a map to int, bool.
template <typename MapType>
std::clock_t insert_growing(size_t times, MapType map)
{
	Timer t;
	t.start();

	for (size_t i = 0; i < times; i++)
	{
		map[i] = true; // insert a constantly growing range of integers
		// which is a worst-case scenario for an unbalanced map.
		map.find(i);
	}

	return t.stop();
}

int main(void)
{
	std::clock_t std;
	std::clock_t ft;


	std::map<int, bool> sm1;
	ft::map<int, bool> m1;

	std = insert_growing(200000, sm1);
	std::cout << "Std: " << std << std::endl;
	ft = insert_growing(200000, m1);
	std::cout << "Ft: " << ft << std::endl;

	std::cout << "Ft is " << (double) ft / (double) std << " times slower" << std::endl;

}