#ifndef BENCHMARKS_HPP

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
#include <vector>
#include <stack>
#include "../map.hpp"
#include "../vector.hpp"
#include "../stack.hpp"

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

// Vector benchmark
// Vector must be a vector of ints
template <typename VectorType>
std::clock_t v_insert_growing(size_t times, VectorType vector)
{
	Timer t;
	t.start();

	int tmp = 0;

	for (size_t i = 0; i < times; i++)
	{
		vector.push_back(i); // insert a constantly growing range of integers
		tmp = vector[i];
	}

	return t.stop();
}

template <typename StackType>
std::clock_t s_insert_growing(size_t times, StackType stack)
{
	Timer t;
	t.start();

	int tmp = 0;

	for (size_t i = 0; i < times; i++)
	{
		stack.push(i); // insert a constantly growing range of integers
	}

	for (size_t i = 0; i < times; i++)
	{
		tmp = stack.top();
		stack.pop();
	}

	return t.stop();
}

void benchmark_map()
{
	std::cout << "\033[1;34m--- MAP BENCHMARK ⚡ ---\033[0m" << std::endl;
	std::clock_t std;
	std::clock_t ft;

	std::map<int, bool> sm1;
	ft::map<int, bool> m1;

	std = insert_growing(200000, sm1);
	std::cout << "Std: " << std << std::endl;
	ft = insert_growing(200000, m1);
	std::cout << "Ft: " << ft << std::endl;

	std::cout << "Our map is " << (double) ft / (double) std << " times slower.   ";

	if (((double) ft / (double) std) < 20.0 )
	{
		std::cout << "\033[1;32m[PASS]\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[1;31m[FAIL]\033[0m" << std::endl;
	}
	

	std::cout << std::endl;
}

void benchmark_vector()
{
	std::cout << "\033[1;34m--- VECTOR BENCHMARK ⚡ ---\033[0m" << std::endl;
	std::clock_t std;
	std::clock_t ft;

	std::vector<int> sv1;
	ft::vector<int> v1;

	std = v_insert_growing(200000, sv1);
	std::cout << "Std: " << std << std::endl;
	ft = v_insert_growing(200000, v1);
	std::cout << "Ft: " << ft << std::endl;

	std::cout << "Our vector is " << (double) ft / (double) std << " times slower. ";

	if (((double) ft / (double) std) < 20.0 )
	{
		std::cout << "\033[1;32m[PASS]\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[1;31m[FAIL]\033[0m" << std::endl;
	}

	std::cout << std::endl;
}

void benchmark_stack()
{
	std::cout << "\033[1;34m--- STACK BENCHMARK ⚡ ---\033[0m" << std::endl;
	std::clock_t std;
	std::clock_t ft;

	std::stack<int> st1;
	ft::stack<int> s1;

	std = s_insert_growing(200000, st1);
	std::cout << "Std: " << std << std::endl;
	ft = s_insert_growing(200000, s1);
	std::cout << "Ft: " << ft << std::endl;

	std::cout << "Our stack is " << (double) ft / (double) std << " times slower. ";

	if (((double) ft / (double) std) < 20.0 )
	{
		std::cout << "\033[1;32m[PASS]\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[1;31m[FAIL]\033[0m" << std::endl;
	}

	std::cout << std::endl;
}

#endif // !BENCHMARKS_HPP