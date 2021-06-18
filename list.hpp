/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:25:06 by ashishae          #+#    #+#             */
/*   Updated: 2021/06/15 11:31:40 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <memory>
# include <limits>
# include "revIterator.hpp"

class ListFrontBackSplit; // forward declaration for later

namespace ft
{

	template <typename T>
	void swap_val(T &a, T &b)
	{
		T buf = a;
		a = b;
		b = buf;
	}

	template <typename T, typename nodeT>
	class list_iterator
	{
		nodeT *ptr;

	public:
		typedef T value_type;
		list_iterator() : ptr(NULL) {}
		list_iterator(nodeT *_ptr) : ptr(_ptr) {}
		list_iterator(list_iterator const &it) : ptr(it.ptr){};

		list_iterator &operator=(list_iterator const &operand)
		{
			ptr = operand.ptr;
			return *this;
		}
		virtual ~list_iterator(void){};
		list_iterator &operator++()
		{
			ptr = ptr->getNext();
			return *this;
		}
		list_iterator &operator--()
		{
			ptr = ptr->getPrev();
			return *this;
		}

		T *operator->(void) { return &ptr->getValue(); };
		T &operator*() { return ptr->getValue(); }
		list_iterator operator++(int)
		{
			list_iterator retval = *this;
			++(*this);
			return retval;
		}
		list_iterator operator--(int)
		{
			list_iterator retval = *this;
			--(*this);
			return retval;
		}

		operator list_iterator<const T, nodeT>(void) const
		{
			return list_iterator<const T, nodeT>(this->ptr);
		}
		template <typename OtherType>
		bool operator==(const list_iterator<OtherType, nodeT> &other) const { return ptr == other.ptr; }
		template <typename OtherType>
		bool operator!=(const list_iterator<OtherType, nodeT> &other) const { return !(ptr == other.ptr); }
		list_iterator &operator*() const { return ptr->getValue(); }

		// We have to befriend constIterators to be able to compare with them.
		template <typename OtherType, typename OtherNodeType>
		friend class ::ft::list_iterator;
		// We also have to befriend the list for it to be able to use iterators as arguments.
		template <typename ValueType, typename Alloc>
		friend class list;
	};

	template <typename T>
	class listNode
	{

	public:
		listNode(T v, listNode *n = NULL, listNode *p = NULL) : value(v), next(n), prev(p){};
		~listNode(){};
		listNode(const listNode &copy) : value(copy.value), next(copy.next), prev(copy.next){};
		listNode &operator=(const listNode &operand)
		{
			value = operand.value;
			next = operand.next;
			prev = operand.prev;
			return (*this);
		};

		T &getValue(void) { return value; };
		const T &getValue(void) const { return value; };

		listNode *getNext(void) const { return next; };
		listNode *getPrev(void) const { return prev; };

		void setValue(T v) { value = v; };
		void setNext(listNode *n) { next = n; };
		void setPrev(listNode *p) { prev = p; };

	private:
		listNode();
		T value;
		listNode *next;
		listNode *prev;
	};

	template <bool B, class T = void>
	struct enable_if
	{
	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	// TODO: check allocator
	template <typename T, typename Alloc = std::allocator<T> >
	class list
	{

// In order to test private methods, we will have to add specific tests as
// friend classes
#ifdef UNIT_TEST
		friend class ::ListFrontBackSplit;
#endif

	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef value_type &reference;
		typedef listNode<T> node_type;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		typedef list_iterator<T, listNode<T> > iterator;
		typedef list_iterator<const T, listNode<T> > const_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

		// (1) Default constructor
		explicit list(const allocator_type &alloc = allocator_type())
		{
			_allocator = alloc;
			_start = new listNode<T>(T(), NULL, NULL);
			_start->setPrev(_start);
			_start->setNext(_start);
			this->_size = 0;
		};

		// (2) Fill constructor
		explicit list(unsigned int n, const T &val = T(), const allocator_type &alloc = allocator_type())
		{
			_allocator = alloc;

			_start = new listNode<T>(val, NULL, NULL);
			_start->setPrev(_start);
			_start->setNext(_start);
			_size = 0;
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
			_size = n;
		};

		// (3) Range constructor
		template <class InputIterator>
		list(typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type &alloc = allocator_type())
		{
			_allocator = alloc;
			_start = new listNode<T>(T(), NULL, NULL);
			_start->setPrev(_start);
			_start->setNext(_start);
			_size = 0;
			assign(first, last);
		}

		// (4) Сopy constructor
		list(const list &copy)
		{
			_allocator = copy._allocator;
			_start = new listNode<T>(T(), NULL, NULL);
			_start->setPrev(_start);
			_start->setNext(_start);
			_size = 0;
			assign(copy.begin(), copy.end());
		}

		// template <class InputIterator>
		// list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

		~list()
		{
			node_type *cur = _start;
			node_type *tmp;
			for (size_t i = 0; i < _size + 1; i++)
			{
				tmp = cur->getNext();
				delete cur;
				cur = tmp;
			}
		};
		list &operator=(const list &operand)
		{
			// We only need to manipulate things if we're not self-reassigning
			if (&operand != this)
			{
				assign(operand.begin(), operand.end());
			}
			return (*this);
		};

		// Iterators

		iterator begin() { return iterator(_start); }
		iterator end()
		{
			return iterator(_start->getPrev());
		}

		const_iterator begin() const { return const_iterator(this->_start); }
		const_iterator end() const { return const_iterator(_start->getPrev()); }

		typedef rev_iterator<iterator> reverse_iterator;
		reverse_iterator rbegin() { return reverse_iterator(this->end()); }
		reverse_iterator rend() { return reverse_iterator(this->begin()); }

		typedef rev_iterator<const_iterator> const_reverse_iterator;
		const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }

		// Capacity
		bool empty(void) const { return _size == 0; };
		size_type size() const { return _size; };

		// Element access
		T &front(void) { return _start->getValue(); };
		const T &front(void) const { return _start->getValue(); };

		T &back() { return *(--end()); };
		const T &back() const { return *(--end()); };

		// Modifiers
		template <class InputIterator>
		void assign(typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
		{
			clear();
			for (InputIterator iter = first; iter != last; iter++)
			{
				push_back(*iter);
			}
		}

		void assign(size_type n, const value_type &val)
		{
			clear();
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		void push_front(const value_type &val)
		{
			node_type *endNode = end().ptr;
			listNode<T> *new_element = new listNode<T>(val, _start, endNode);
			_start->setPrev(new_element);
			_start = new_element;
			_size++;
		}
		void pop_front()
		{
			// STD If empty, undefined behavior
			if (_size == 0)
			{
				return;
			}

			node_type *endNode = end().ptr;
			listNode<T> *newStart = _start->getNext();

			newStart->setPrev(endNode);

			delete _start;
			_start = newStart;
			_size--;
		}

		void push_back(const value_type &val)
		{

			node_type *endNode = end().ptr;

			node_type *prev = endNode->getPrev();
			node_type *newNode = new node_type(val, endNode, prev);

			// If this is the first element, start should be adjusted
			if (_size == 0)
			{
				_start = newNode;
				endNode->setNext(newNode);
			}

			if (prev)
				prev->setNext(newNode);
			endNode->setPrev(newNode);
			_size++;
		}

		void pop_back()
		{
			if (_size == 0)
			{
				// STL: Undefined behavior
				return;
			}

			node_type *endNode = end().ptr;

			// If list only has one element, we have to move its start point
			// to the 'end' element
			if (_size == 1)
				_start = endNode;

			listNode<T> *prev = endNode->getPrev();
			listNode<T> *before_prev = prev->getPrev();

			if (before_prev)
				before_prev->setNext(endNode);
			endNode->setPrev(before_prev);

			delete prev;

			_size--;
		}

		// single element (1)
		iterator insert(iterator position, const value_type &val)
		{
			listNode<T> *cur = position.ptr;
			listNode<T> *prev = cur->getPrev();
			listNode<T> *newElement = new listNode<T>(val, cur, prev);
			prev->setNext(newElement);
			if (cur == _start)
				_start = newElement; // if adding to the beginning, move start pointer
			cur->setPrev(newElement);

			_size++;
			return iterator(newElement);
		}

		// fill (2)
		void insert(iterator position, size_type n, const value_type &val)
		{
			for (size_t i = 0; i < n; i++)
				insert(position, val);
		}

		// range (3)
		template <class InputIterator>
		void insert(iterator position, typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
		{
			for (InputIterator iter = first; iter != last; iter++)
				insert(position, *iter);
		}

		iterator erase(iterator position)
		{
			if (_size == 0)
				return iterator(_start); // STL: undefined behavior

			listNode<T> *cur = position.ptr;
			listNode<T> *next = cur->getNext();
			listNode<T> *prev = cur->getPrev();

			prev->setNext(next);
			if (cur == _start)
				_start = next;

			next->setPrev(prev);
			delete cur;
			_size--;
			return iterator(next);
		}

		iterator erase(iterator first, iterator last)
		{
			while (first != last)
			{
				first = erase(first);
			}
			return last;
		}

		void swap(list &x)
		{
			swap_val(_start, x._start);
			swap_val(_size, x._size);
		}

		size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(listNode<value_type>); }

		void resize(size_type n, value_type val = value_type())
		{
			size_t cursize = size();

			if (cursize < n)
			{
				list<T, Alloc>::iterator e = end();
				for (size_t i = 0; i < (n - cursize); i++)
					insert(e, val);
			}
			else if (cursize > n)
			{
				list<T, Alloc>::iterator e = end();
				e--;
				for (size_t i = 0; i < (cursize - n); i++)
				{
					e = this->erase(e);
					e--;
				}
			}
		}

		void clear()
		{
			if (_size == 0)
				return;
			erase(begin(), end());
		}

		//entire list (1)
		void splice(iterator position, list &x)
		{
			if (x._size == 0)
				return; // STL: undefined behavior

			listNode<T> *our_right = position.ptr;
			listNode<T> *our_left = our_right->getPrev();
			listNode<T> *their_right = (--x.end()).ptr;
			listNode<T> *their_end = x.end().ptr;
			listNode<T> *their_left = x._start;

			if (their_right)
				their_right->setNext(our_right);
			our_right->setPrev(their_right);

			our_left->setNext(their_left);
			if (_size == 0)
				_start = their_left;

			their_left->setPrev(our_left);

			x._start = their_end;
			their_end->setPrev(their_end);

			_size += x._size;
			x._size = 0;
		}

		// single element (2)
		void splice(iterator position, list &x, iterator i)
		{
			if (i == x.end())
				return;

			listNode<T> *our_right = position.ptr;
			listNode<T> *our_left = our_right->getPrev();

			listNode<T> *their_cur = i.ptr;
			listNode<T> *their_prev = their_cur->getPrev();
			listNode<T> *their_next = their_cur->getNext();

			our_right->setPrev(their_cur);
			their_cur->setNext(our_right);

			our_left->setNext(their_cur);
			if (our_right == _start)
				_start = their_cur;
			their_cur->setPrev(our_left);

			their_prev->setNext(their_next);
			if (x._start == their_cur)
				x._start = their_next;
			their_next->setPrev(their_prev);
			_size += 1;
			x._size -= 1;
		}

		// element range (3)
		void splice(iterator position, list &x, iterator first, iterator last)
		{
			if (first == last)
				return;
			listNode<T> *our_right = position.ptr;
			listNode<T> *our_left = our_right->getPrev();

			listNode<T> *their_left = first.ptr;
			listNode<T> *their_left_prev = their_left->getPrev();
			listNode<T> *their_right = last.ptr->getPrev();
			listNode<T> *their_right_next = their_right->getNext();

			size_t elementsTransferred = 0;
			for (iterator it = first; it != last; it++)
				elementsTransferred++;

			our_left->setNext(their_left);
			if (our_right == _start)
				_start = their_left;
			their_left->setPrev(our_left);

			our_right->setPrev(their_right);
			their_right->setNext(our_right);

			their_left_prev->setNext(their_right_next);
			if (x != (*this) && x._start == their_left)
				x._start = their_right_next;
			their_right_next->setPrev(their_left_prev);

			_size += elementsTransferred;
			x._size -= elementsTransferred;
		}

		void remove(const value_type &val)
		{
			list<T, Alloc>::iterator iter = begin();
			list<T, Alloc>::iterator e = end();

			while (iter != e)
			{
				if (*iter == val)
					iter = erase(iter);
				else
					iter++;
			}
		}

		template <class Predicate>
		void remove_if(Predicate pred)
		{
			list<T, Alloc>::iterator iter = begin();
			list<T, Alloc>::iterator e = end();

			while (iter != e)
			{
				if (pred(*iter) == true)
					iter = erase(iter);
				else
					iter++;
			}
		}

		//(1)
		void unique()
		{
			if (size() <= 1)
				return;
			list<T, Alloc>::iterator iter = begin();
			list<T, Alloc>::iterator e = --end();

			list<T, Alloc>::iterator next = iter;
			while (iter != e)
			{
				next++;
				if (*iter == *next)
					iter = erase(iter);
				else
					iter++;
			}
		}

		// (2)
		template <class BinaryPredicate>
		void unique(BinaryPredicate binary_pred)
		{
			if (size() <= 1)
				return;

			list<T, Alloc>::iterator iter = begin();
			iter++;
			list<T, Alloc>::iterator e = end();

			list<T, Alloc>::iterator prev = begin();
			while (iter != e)
			{
				if (binary_pred(*prev, *iter))
				{
					iter = erase(iter);
					prev = iter;
					prev--;
				}
				else
				{
					iter++;
					prev++;
				}
			}
		}

		void merge(list &x)
		{
			if (&x == this)
				return;

			list<T, Alloc>::iterator our_iter = begin();
			list<T, Alloc>::iterator their_iter = begin();
			list<T, Alloc>::iterator our_e = end();

			while (our_iter != our_e)
			{
				while (x.size() && x.front() < *our_iter)
				{
					this->splice(our_iter, x, x.begin());
				}
				our_iter++;
			}
			if (x.size() != 0)
			{
				this->splice(end(), x);
			}
		}

		template <class Compare>
		void merge(list &x, Compare comp)
		{
			if (&x == this)
				return;

			list<T, Alloc>::iterator our_iter = begin();
			list<T, Alloc>::iterator their_iter = begin();
			list<T, Alloc>::iterator our_e = end();

			while (our_iter != our_e)
			{
				while (x.size() && comp(x.front(), *our_iter))
				{
					this->splice(our_iter, x, x.begin());
				}
				our_iter++;
			}
			if (x.size() != 0)
			{
				this->splice(end(), x);
			}
		}

		void reverse()
		{
			if (_size == 0)
				return;
			listNode<T> *cur = _start;

			listNode<T> *tmp = NULL;
			listNode<T> *prev = NULL;
			for (size_t i = 0; i < _size + 1; i++)
			{
				tmp = cur->getNext();
				cur->setNext(cur->getPrev());
				cur->setPrev(tmp);
				prev = cur;
				cur = tmp;
			}

			_start = prev->getNext();
		}

		// (1)
		void sort()
		{
			mergeSort(*this);
		}

		// (2)
		template <class Compare>
		void sort(Compare comp)
		{
			mergeSort(*this, comp);
		}

		allocator_type get_allocator() const
		{
			return _allocator;
		}

	private:
		listNode<T> *_start;
		size_type _size;
		Alloc _allocator;

		// Split the list in two halves
		void frontBackSplit(list<T, Alloc> &x)
		{
			size_t middle = size() / 2;

			iterator cur = begin();
			for (size_t i = 0; i < middle; i++)
			{
				cur++;
			}
			x.splice(x.begin(), *this, cur, this->end());
		}

		static void mergeSort(list<T, Alloc> &l)
		{
			if (l.size() <= 1)
				return;
			list<T, Alloc> right;

			l.frontBackSplit(right);
			mergeSort(l);
			mergeSort(right);
			l.merge(right);
		}

		template <typename Compare>
		static void mergeSort(list<T, Alloc> &l, Compare comp)
		{
			if (l.size() <= 1)
				return;
			list<T, Alloc> right;

			l.frontBackSplit(right);

			mergeSort(l, comp);
			mergeSort(right, comp);
			l.merge(right, comp);
		}
	};

	// Relative operators
	// (1)
	template <class Type, class Allocator>
	bool operator==(const list<Type, Allocator> &lhs, const list<Type, Allocator> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		typename ft::list<Type, Allocator>::const_iterator lhs_it = lhs.begin();
		typename ft::list<Type, Allocator>::const_iterator rhs_it = rhs.begin();
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (*lhs_it++ != *rhs_it++)
				return false;
		}
		return true;
	};

	// (2)
	template <class T, class Alloc>
	bool operator!=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	};

	// (3)
	template <class T, class Alloc>
	bool operator<(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
	{
		typename ft::list<T, Alloc>::const_iterator lhs_it = lhs.begin();
		typename ft::list<T, Alloc>::const_iterator rhs_it = rhs.begin();
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (*lhs_it != *rhs_it)
			{
				if (*lhs_it < *rhs_it)
					return true;
				return false;
			}
			lhs_it++;
			rhs_it++;
		}
		return lhs.size() < rhs.size();
	};

	// (4)
	template <class T, class Alloc>
	bool operator<=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
	{
		typename ft::list<T, Alloc>::const_iterator lhs_it = lhs.begin();
		typename ft::list<T, Alloc>::const_iterator rhs_it = rhs.begin();
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (*lhs_it != *rhs_it)
			{
				if (*lhs_it < *rhs_it)
					return true;
				return false;
			}
			lhs_it++;
			rhs_it++;
		}
		return lhs.size() <= rhs.size();
	};

	// (5)
	template <class T, class Alloc>
	bool operator>(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
	{
		typename ft::list<T, Alloc>::const_iterator lhs_it = lhs.begin();
		typename ft::list<T, Alloc>::const_iterator rhs_it = rhs.begin();
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (*lhs_it != *rhs_it)
			{
				if (*lhs_it > *rhs_it)
					return true;
				return false;
			}
			lhs_it++;
			rhs_it++;
		}
		return lhs.size() > rhs.size();
	};

	// (6)
	template <class T, class Alloc>
	bool operator>=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
	{
		typename ft::list<T, Alloc>::const_iterator lhs_it = lhs.begin();
		typename ft::list<T, Alloc>::const_iterator rhs_it = rhs.begin();
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (*lhs_it != *rhs_it)
			{
				if (*lhs_it > *rhs_it)
					return true;
				return false;
			}
			lhs_it++;
			rhs_it++;
		}
		return (lhs.size() >= rhs.size());
	};

	template <class T, class Alloc>
	void swap (list<T,Alloc>& x, list<T,Alloc>& y)
	{
		x.swap(y);
	}

} // namespace ft
#endif