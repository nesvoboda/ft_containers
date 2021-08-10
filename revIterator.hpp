#ifndef REVITERATOR_HPP
#define REVITERATOR_HPP

#include "util.hpp"

namespace ft
{

	template <class iterator>
	class rev_iterator
	{
		iterator _iter;

	public:
		typedef typename iterator_traits<iterator>::iterator_category iterator_category;
		typedef typename iterator_traits<iterator>::value_type value_type;
		typedef typename iterator_traits<iterator>::difference_type difference_type;
		typedef typename iterator_traits<iterator>::pointer pointer;
		typedef typename iterator_traits<iterator>::reference reference;

		rev_iterator() : _iter(){};

		explicit rev_iterator(iterator it) : _iter(it){};

		template <typename otherIterator>
		rev_iterator(const rev_iterator<otherIterator> &it) : _iter(it.base()){};

		rev_iterator(rev_iterator<iterator> const &it) : _iter(it._iter){};
		rev_iterator &operator=(const rev_iterator &operand)
		{
			_iter = operand._iter;
			return (*this);
		}
		iterator base() const { return _iter; };
		virtual ~rev_iterator(void){};

		rev_iterator &operator++()
		{
			_iter = _iter.operator--();
			return *this;
		}
		rev_iterator &operator--()
		{
			_iter = _iter.operator++();
			return *this;
		}
		value_type &operator*() const
		{
			return (--iterator(_iter)).operator*();
		}
		value_type &operator[](size_t b)
		{
			return *(this->operator+(b));
		}

		rev_iterator operator++(int)
		{
			rev_iterator retval = *this;
			++(*this);
			return retval;
		}
		rev_iterator operator--(int)
		{
			rev_iterator retval = *this;
			--(*this);
			return retval;
		}
		value_type *operator->(void) const { return &this->operator*(); };

		// Only for randomAccess

		rev_iterator operator+(int i) const
		{
			return rev_iterator(_iter.operator-(i));
		}
		rev_iterator operator-(int i) const
		{
			return rev_iterator(_iter.operator+(i));
		}
		difference_type operator-(const rev_iterator &rhs) const
		{
			return rhs.base().operator-((this->base()));
		}

		rev_iterator &operator+=(int i)
		{
			_iter.operator-=(i);
			return (*this);
		}

		rev_iterator &operator-=(int i)
		{
			_iter.operator+=(i);
			return (*this);
		}

		//

		template <typename OtherIterator>
		bool operator==(const rev_iterator<OtherIterator> &other) const
		{
			return _iter == other.base();
		}
		template <typename OtherIterator>
		bool operator!=(const rev_iterator<OtherIterator> &other) const { return !(*this == other); }

		bool operator<(const rev_iterator &rhs) const
		{
			return base() > rhs.base();
		}

		template <typename OtherIterator>
		bool operator<(const rev_iterator<OtherIterator> &rhs) const
		{
			return base() > rhs.base();
		}

		bool operator>(const rev_iterator &rhs) const
		{
			return base() < rhs.base();
		}

		template <typename OtherIterator>
		bool operator>(const rev_iterator<OtherIterator> &rhs) const
		{
			return base() < rhs.base();
		}

		bool operator<=(const rev_iterator &rhs) const
		{
			return base() >= rhs.base();
		}

		template <typename OtherIterator>
		bool operator<=(const rev_iterator<OtherIterator> &rhs) const
		{
			return base() >= rhs.base();
		}

		bool operator>=(const rev_iterator &rhs) const
		{
			return base() <= rhs.base();
		}

		template <typename OtherIterator>
		bool operator>=(const rev_iterator<OtherIterator> &rhs) const
		{
			return base() <= rhs.base();
		}
	};

	template <typename iterator>
	rev_iterator<iterator> operator+(typename rev_iterator<iterator>::difference_type n, const rev_iterator<iterator> &rhs)
	{
		return rhs.operator+(n);
	};

}

#endif