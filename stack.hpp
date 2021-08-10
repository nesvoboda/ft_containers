#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{

	template <class T, class Container = vector<T> >
	class stack
	{
	protected:
		Container c;

	public:
		typedef T value_type;			  //	The first template parameter (T)	Type of the elements
		typedef Container container_type; //	The second template parameter (Container)	Type of the underlying container
		typedef size_t size_type;		  //	an unsigned integral type	usually the same as size_t

		explicit stack(const container_type &ctnr = container_type()) : c(ctnr){};

		bool empty() const
		{
			return c.empty();
		}

		value_type &top()
		{
			return c.back();
		}

		const value_type &top() const
		{
			return c.back();
		}

		void push(const value_type &val)
		{
			c.push_back(val);
		}

		void pop()
		{
			c.pop_back();
		}

		size_type size() const
		{
			return c.size();
		}

		bool operator==(const stack &rhs) const
		{
			return this->c == rhs.c;
		};

		bool operator!=(const stack &rhs) const
		{
			return this->c != rhs.c;
		};

		bool operator<(const stack &rhs) const
		{
			return this->c < rhs.c;
		};

		bool operator<=(const stack &rhs) const
		{
			return this->c <= rhs.c;
		};

		bool operator>(const stack &rhs) const
		{
			return this->c > rhs.c;
		};

		bool operator>=(const stack &rhs) const
		{
			return this->c >= rhs.c;
		}
	};

}

#endif // !STACK_HPP