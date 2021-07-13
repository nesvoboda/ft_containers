namespace ft
{
	template <class T>
	struct less
	{
		bool operator()(const T &lhs, const T &rhs) const
		{
			return lhs < rhs; // assumes that the implementation uses a flat address space
		}
	};

	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		// (1) default constructor
		pair() : first(T1()), second(T2()){};

		// (2) copy / move constructor (and implicit conversion)
		template <class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second){};

		// (3) initialization constructor
		pair(const first_type &a, const second_type &b) : first(a), second(b){};
	};

	// (1)
	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	// (2)
	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs == rhs);
	}

	// (3)
	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}
	// (4)
	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(rhs < lhs);
	}
	// (5)
	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return rhs < lhs;
	}
	// (6)
	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs < rhs);
	}
}