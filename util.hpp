#ifndef UTIL_HPP
#define UTIL_HPP

#define ABS(x) x < 0 ? -x : x;
#define MAX(x, y) x > y ? x : y;

namespace ft
{
	template <typename T>
	void swap_val(T &a, T &b)
	{
		T buf = a;
		a = b;
		b = buf;
	}

	template <typename T>
	T min(T a, T b)
	{
		return a < b ? a : b;
	}

}

#endif // !UTIL_HPP
