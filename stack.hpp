#ifndef STACK_HPP
#define STACK_HPP

#include "Vector.hpp"

namespace ft
{

	template <class T, class Container = vector<T> >
	class stack
	{
		Container _base;

	public:

	typedef T value_type; //	The first template parameter (T)	Type of the elements
		typedef Container container_type; //	The second template parameter (Container)	Type of the underlying container
		typedef size_t size_type; //	an unsigned integral type	usually the same as size_t

		explicit stack (const container_type& ctnr = container_type()) : _base(ctnr) {};

		bool empty() const
		{
			return _base.empty();
		}

		value_type& top()
		{
			return _base.back();
		}

		const value_type& top() const
		{
			return _base.back();
		}

		void push (const value_type& val)
		{
			_base.push_back(val);
		}

		void pop()
		{
			_base.pop_back();
		}

		size_type size() const
		{
			return _base.size();
		}

		friend bool operator== (const stack& lhs, const stack& rhs)
		{
			return lhs._base == rhs._base;
		};

		friend bool operator!= (const stack& lhs, const stack& rhs)
		{
			return lhs._base != rhs._base;
		};

		friend bool operator<  (const stack& lhs, const stack& rhs)
		{
			return lhs._base < rhs._base;
		};

		friend bool operator<= (const stack& lhs, const stack& rhs)
		{
			return lhs._base <= rhs._base;
		};

		friend bool operator>  (const stack& lhs, const stack& rhs)
		{
			return lhs._base > rhs._base;
		};

		friend bool operator>= (const stack& lhs, const stack& rhs)
		{
			return lhs._base >= rhs._base;
		}


	};

}

#endif // !STACK_HPP