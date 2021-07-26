#ifndef UTIL_HPP
#define UTIL_HPP

#define ABS(x) x < 0 ? -x : x;
#define MAX(x, y) x > y ? x : y;

namespace ft
{

	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};

	// Our iterator traits will just consist of iterator's nested types
	template <class Iterator>
	struct iterator_traits {
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type        value_type;
		typedef typename Iterator::difference_type   difference_type;
		typedef typename Iterator::pointer           pointer;
		typedef typename Iterator::reference         reference;
	};

	// template <class T, T v>
	// struct integral_constant { // the definition of integral_constant to make
	// 	// is_integral work
	// 	static constexpr T value = v;
	// 	typedef T value_type;
	// 	typedef integral_constant<T,v> type;
	// 	constexpr operator T() { return v; }
	// };

	template<typename T, T Val>
	struct integral_constant {
		typedef integral_constant type;
		typedef T value_type;
		enum {
			value = Val
		};
	};

	typedef integral_constant<bool,true> true_type;
	typedef integral_constant<bool,false> false_type;

	template <class T> struct is_integral : public false_type {};

	// template<> struct is_integral<unsigned char> : public true_type {};

	template<> struct is_integral<bool> : public true_type {};
	template<> struct is_integral<char> : public true_type {};
	template<> struct is_integral<char16_t> : public true_type {};
	template<> struct is_integral<char32_t> : public true_type {};
	template<> struct is_integral<wchar_t> : public true_type {};
	template<> struct is_integral<signed char> : public true_type {};
	template<> struct is_integral<short int> : public true_type {};
	template<> struct is_integral<int> : public true_type {};
	template<> struct is_integral<long int> : public true_type {};
	template<> struct is_integral<long long int> : public true_type {};
	template<> struct is_integral<unsigned char> : public true_type {};
	template<> struct is_integral<unsigned short int> : public true_type {};
	template<> struct is_integral<unsigned int> : public true_type {};
	template<> struct is_integral<unsigned long int> : public true_type {};
	template<> struct is_integral<unsigned long long int> : public true_type {};


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

		template <bool B, class T = void>
	struct enable_if
	{
	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

}

#endif // !UTIL_HPP
