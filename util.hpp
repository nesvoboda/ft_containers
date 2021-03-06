#ifndef UTIL_HPP
#define UTIL_HPP

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
