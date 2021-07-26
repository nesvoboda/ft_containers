#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

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

	};

}

#endif // !STACK_HPP