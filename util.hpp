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

	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2)) // or: if (!pred(*first1,*first2)), for version 2
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

}

#endif // !UTIL_HPP
