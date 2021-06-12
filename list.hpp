/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:25:06 by ashishae          #+#    #+#             */
/*   Updated: 2021/06/12 17:41:39 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <numeric>
#include <type_traits>

struct __false_type {};

class ListFrontBackSplit; // forward declaration for later

namespace ft {

	template <typename iterator, typename T>
	class reverse_iterator
	{
		iterator _iter;

	public:
		reverse_iterator() : _iter(){};
		reverse_iterator(iterator it) : _iter(it){};
		reverse_iterator(reverse_iterator<iterator, T> const &it) : _iter(it._iter){};
		reverse_iterator &operator=(const reverse_iterator &operand)
		{
			_iter = operand._iter;
			return (*this);
		}
		virtual ~reverse_iterator(void){};
		reverse_iterator &operator++()
		{
			_iter.operator--();
			return *this;
		}
		reverse_iterator &operator--()
		{
			_iter.operator++();
			return *this;
		}
		T &operator*()
		{
			iterator i = _iter;
			i--;
			return i.operator*();
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator retval = *this;
			++(*this);
			return retval;
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator retval = *this;
			--(*this);
			return retval;
		}
		bool operator==(reverse_iterator other) const { return _iter.operator==(other._iter); }
		bool operator!=(reverse_iterator other) const { return !(*this == other); }
		// reverse_iterator &operator*() const {return _iter.operator*(); return *this;}
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

	

	template <typename T>
	class list
	{

	// In order to test private methods, we will have to add specific tests as
	// friend classes
	#ifdef UNIT_TEST
		friend class ::ListFrontBackSplit;
	#endif

	public:
		typedef T value_type;
		// TODO
		// typedef allocator_type
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;


		// (1) Default constructor
		explicit list(/*const allocator_type& alloc = allocator_type()*/)
		{
			_start = new listNode<T>(T(), NULL, NULL);
		};

		// (2) Fill constructor
		explicit list(unsigned int n, const T &val = T() /*, const allocator_type& alloc = allocator_type()*/)
		{
			_start = new listNode<T>(val, NULL, NULL);
			for (size_t i = 0; i < n; i++)
			{
				listNode<T> *newElem = new listNode<T>(val, _start, NULL);
				_start->setPrev(newElem);
				_start = newElem;
			}
		};

		// (3) Range constructor
		template <class InputIterator>
		list(InputIterator first, InputIterator last /*, const allocator_type& alloc = allocator_type()*/)
		{
			_start = new listNode<T>(T(), NULL, NULL);
			assign(first, last);
		}

		// (4) Сopy constructor
		list(const list &copy)
		{
			_start = new listNode<T>(T(), NULL, NULL);
			assign(copy.begin(), copy.end());
		}

		// template <class InputIterator>
		// list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

		~list()
		{
			// if (_start == NULL)
			// 	return;

			listNode<T> *cur = _start;

			while (cur->getNext() != NULL)
			{
				cur = cur->getNext();
			}
			listNode<T> *prev = cur;
			while (cur->getPrev() != NULL)
			{
				prev = cur;
				cur = cur->getPrev();
				delete prev;
			}
			delete cur;
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

		// TODO delete tag
		class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
		{
			friend class list;
			listNode<T> *ptr;

			// TODO move to arrow
			listNode<T> *internalPtr(void) { return ptr; };

		public:
			iterator() : ptr(NULL) {}
			iterator(listNode<T> *_ptr) : ptr(_ptr) {}
			iterator(const iterator &it) : ptr(it.ptr){};
			iterator &operator=(const iterator &operand)
			{
				ptr = operand.ptr;
				return *this;
			}
			~iterator(void){};
			iterator &operator++()
			{
				ptr = ptr->getNext();
				return *this;
			}
			iterator &operator--()
			{
				ptr = ptr->getPrev();
				return *this;
			}
			T &operator*() { return ptr->getValue(); }
			iterator operator++(int)
			{
				iterator retval = *this;
				++(*this);
				return retval;
			}
			iterator operator--(int)
			{
				iterator retval = *this;
				--(*this);
				return retval;
			}
			bool operator==(iterator other) const { return ptr == other.ptr; }
			bool operator!=(iterator other) const { return !(*this == other); }
			iterator &operator*() const { return ptr->getValue(); }
		};

		iterator begin() { return iterator(_start); }
		iterator end()
		{
			listNode<T> *cursor = _start;
			while (cursor->getNext() != NULL)
				cursor = cursor->getNext();

			return iterator(cursor);
		}

		class const_iterator : public iterator
		{
			listNode<T> *ptr;

		public:
			const_iterator() : ptr(NULL) {}
			const_iterator(listNode<T> *_ptr) : ptr(_ptr) {}
			const_iterator(const_iterator &it) : ptr(it.ptr){};
			const_iterator(const iterator &it) : ptr(it.ptr){};
			const_iterator &operator=(const const_iterator &operand)
			{
				ptr = operand.ptr;
				return *this;
			}
			~const_iterator(void){};
			const_iterator &operator++()
			{
				ptr = ptr->getNext();
				return *this;
			}
			const_iterator &operator--()
			{
				ptr = ptr->getPrev();
				return *this;
			}
			T &operator*() { return ptr->getValue(); }
			const_iterator operator++(int)
			{
				const_iterator retval = *this;
				++(*this);
				return retval;
			}
			const_iterator operator--(int)
			{
				const_iterator retval = *this;
				--(*this);
				return retval;
			}
			bool operator==(const_iterator other) const { return ptr == other.ptr; }
			bool operator!=(const_iterator other) const { return !(*this == other); }
			const_iterator &operator*() const { return ptr->getValue(); }
		};

		const_iterator begin() const { return const_iterator(this->_start); }
		const_iterator end() const
		{
			listNode<T> *cursor = this->_start;
			while (cursor->getNext() != NULL)
				cursor = cursor->getNext();
			return const_iterator(cursor);
		}

		typedef reverse_iterator<iterator, T> reverse_iterator;
		reverse_iterator rbegin() { return reverse_iterator(_start); }
		reverse_iterator rend()
		{
			return reverse_iterator(this->end());
		}

		// Capacity

		bool empty(void) const
		{
			// return _start == NULL;
			return _start->getNext() == NULL;
		};
		unsigned int size() const
		{
			unsigned int val = 0;
			listNode<T> *cursor = _start;
			while (cursor->getNext() != NULL)
			{
				val += 1;
				cursor = cursor->getNext();
			}
			return val;
		};

		// Element access
		T &front(void) { return _start->getValue(); };
		const T &front(void) const { return _start->getValue(); };

		T &back()
		{
			// STD: Undefined behavior if empty
			listNode<T> *cur = _start;
			while (cur->getNext() != NULL)
			{
				cur = cur->getNext();
			}
			return cur->getPrev()->getValue();
		};
		const T &back() const
		{
			listNode<T> *cur = _start;
			while (cur->getNext() != NULL)
			{
				cur = cur->getNext();
			}
			return cur->getPrev()->getValue();
		};

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
			if (_start == NULL)
			{
				_start = new listNode<T>(T(), NULL, NULL); // element for END
			}
			listNode<T> *new_element = new listNode<T>(val, _start, NULL);
			_start->setPrev(new_element);
			_start = new_element;
		}
		void pop_front()
		{
			// STD If empty, undefined behavior
			if (_start->getNext() == NULL)
			{
				return;
			}

			listNode<T> *newStart = _start->getNext();

			newStart->setPrev(NULL);

			delete _start;
			_start = newStart;
		}

		void push_back(const value_type &val)
		{
			// if (_start == NULL)
			// {
			// 	_start = new listNode<T>(val, NULL, NULL);
			// 	_start->setNext(new listNode<T>(T(), NULL, _start)); // END
			// 	return;
			// }

			listNode<T> *cur = _start;
			while (cur->getNext() != NULL)
			{
				cur = cur->getNext();
			}
			listNode<T> *prev = cur->getPrev();

			listNode<T> *newElem = new listNode<T>(val, cur, prev);

			// If this is the first element, start should be adjusted
			if (_start->getNext() == NULL)
				_start = newElem;

			if (prev)
				prev->setNext(newElem);
			cur->setPrev(newElem);
		}

		void pop_back()
		{
			if (_start->getNext() == NULL)
			{
				// STL: Undefined behavior
				return;
			}

			listNode<T> *cur = _start;

			while (cur->getNext() != NULL)
				cur = cur->getNext();

			// If list only has one element, we have to move its start point
			// to the 'end' element
			if (_start->getNext()->getNext() == NULL)
				_start = cur;

			listNode<T> *prev = cur->getPrev();
			listNode<T> *before_prev = prev->getPrev();

			if (before_prev)
				before_prev->setNext(cur);
			cur->setPrev(before_prev);

			delete prev;
		}

		// single element (1)
		iterator insert(iterator position, const value_type &val)
		{
			listNode<T> *cur = position.internalPtr();
			listNode<T> *prev = position.internalPtr()->getPrev();
			listNode<T> *newElement = new listNode<T>(val, cur, prev);
			if (prev)
				prev->setNext(newElement);
			else
				_start = newElement; // if adding to the beginning, move start pointer
			cur->setPrev(newElement);
			return iterator(newElement);
		}

		// fill (2)
		void insert(iterator position, size_type n, const value_type &val)
		{
			listNode<T> *cur = position.internalPtr();
			listNode<T> *prev = position.internalPtr()->getPrev();

			listNode<T> *newElement;
			for (size_t i = 0; i < n; i++)
			{
				newElement = new listNode<T>(val, cur, prev);
				cur->setPrev(newElement);
				cur = newElement;
			}
			if (prev)
				prev->setNext(newElement);
			else
				_start = newElement; // if adding to the beginning, move start pointer
		}

		// range (3)
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last)
		{
			// typedef typename std::numeric_limits<InputIterator>::is_integer _Integral;
			listNode<T> *cur = position.internalPtr();
			listNode<T> *prev = position.internalPtr()->getPrev();

			listNode<T> *newElement;
			for (; first != last; ++first)
			{
				newElement = new listNode<T>(*first, cur, prev);
				cur->setPrev(newElement);

				if (prev)
					prev->setNext(newElement);
				else
					_start = newElement; // if adding to the beginning, move start pointer
				prev = newElement;
			}
		}

		iterator erase(iterator position)
		{
			if (_start->getNext() == NULL)
				return iterator(_start); // STL: undefined behavior

			listNode<T> *cur = position.internalPtr();
			listNode<T> *next = cur->getNext();
			listNode<T> *prev = cur->getPrev();

			if (prev)
				prev->setNext(next);
			else
				_start = next;

			next->setPrev(prev);
			delete cur;
			return iterator(next);
		}

		iterator erase(iterator first, iterator last)
		{
			while (first != last)
			{
				erase(first++);
			}
			return last;
		}

		void swap(list &x)
		{
			listNode<T> *buf = _start;
			_start = x._start;
			x._start = buf;
		}

		size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(listNode<value_type>); }

		void resize(size_type n, value_type val = value_type())
		{
			size_t cursize = size();

			if (cursize < n)
			{
				list<T>::iterator e = end();
				for (size_t i = 0; i < (n - cursize); i++)
					insert(e, val);
			}
			else if (cursize > n)
			{
				list<T>::iterator e = end();
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
			listNode<T> *cur = _start;
			listNode<T> *tmp;

			while (cur->getNext() != NULL)
			{
				tmp = cur;
				cur = cur->getNext();
				delete tmp;
			}
			cur->setPrev(NULL);
			_start = cur;
		}

		//entire list (1)
		void splice(iterator position, list &x)
		{
			// if (x == *this)
			// 	return; // STL: undefined behavior

			if (x.size() == 0)
				return;

			listNode<T> *our_right = position.internalPtr();
			listNode<T> *our_left = our_right->getPrev();
			listNode<T> *their_right = (--x.end()).internalPtr();
			listNode<T> *their_end = x.end().internalPtr();
			listNode<T> *their_left = x._start;

			if (their_right)
				their_right->setNext(our_right);
			our_right->setPrev(their_right);

			if (our_left)
				our_left->setNext(their_left);
			else
				_start = their_left;

			their_left->setPrev(our_left);

			x._start = their_end;
			their_end->setPrev(NULL);
		}

		// single element (2)
		void splice(iterator position, list &x, iterator i)
		{
			if (i == x.end())
				return;

			listNode<T> *our_right = position.internalPtr();
			listNode<T> *our_left = our_right->getPrev();

			listNode<T> *their_cur = i.internalPtr();
			listNode<T> *their_prev = their_cur->getPrev();
			listNode<T> *their_next = their_cur->getNext();

			our_right->setPrev(their_cur);
			their_cur->setNext(our_right);

			if (our_left)
				our_left->setNext(their_cur);
			else
				_start = their_cur;
			their_cur->setPrev(our_left);

			if (their_prev)
				their_prev->setNext(their_next);
			else
				x._start = their_next;
			if (their_next)
				their_next->setPrev(their_prev);
		}

		void debug()
		{
			listNode<T> *cur = _start;
			std::cout << "Start: " << cur << std::endl;
			while (cur->getNext() != NULL)
			{
				std::cout << cur->getValue() << "(" << cur << ")"
						<< " -> ";
				cur = cur->getNext();
			}
			std::cout << std::endl;
		}

		// element range (3)
		void splice(iterator position, list &x, iterator first, iterator last)
		{
			if (first == last)
				return;
			listNode<T> *our_right = position.internalPtr();
			listNode<T> *our_left = our_right->getPrev();

			listNode<T> *their_left = first.internalPtr();
			listNode<T> *their_left_prev = their_left->getPrev();
			listNode<T> *their_right = last.internalPtr()->getPrev();
			listNode<T> *their_right_next = their_right->getNext();

			if (our_left)
				our_left->setNext(their_left);
			else
				_start = their_left;
			their_left->setPrev(our_left);

			our_right->setPrev(their_right);
			their_right->setNext(our_right);

			if (their_left_prev)
				their_left_prev->setNext(their_right_next);
			else
				x._start = their_right_next;
			their_right_next->setPrev(their_left_prev);
		}

		void remove(const value_type &val)
		{
			list<T>::iterator iter = begin();
			list<T>::iterator e = end();

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
			list<T>::iterator iter = begin();
			list<T>::iterator e = end();

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
			list<T>::iterator iter = begin();
			list<T>::iterator e = --end();

			list<T>::iterator next = iter;
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

			list<T>::iterator iter = begin();
			iter++;
			list<T>::iterator e = end();

			list<T>::iterator prev = begin();
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

			list<T>::iterator our_iter = begin();
			list<T>::iterator their_iter = begin();
			list<T>::iterator our_e = end();

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

			list<T>::iterator our_iter = begin();
			list<T>::iterator their_iter = begin();
			list<T>::iterator our_e = end();

			while (our_iter != our_e)
			{
				while (comp(x.front(), *our_iter))
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
			if (_start->getNext() == NULL)
				return;
			listNode<T> *cur = _start;
			listNode<T> *old_start = _start;

			listNode<T> *tmp = NULL;
			listNode<T> *prev = NULL;
			while (cur->getNext() != NULL)
			{
				tmp = cur->getNext();
				cur->setNext(cur->getPrev());
				cur->setPrev(tmp);
				prev = cur;
				cur = tmp;
			}

			old_start->setNext(cur); // set END element as last
			cur->setPrev(old_start);

			prev->setPrev(NULL);
			_start = prev;
		}

		void sort()
		{
			mergeSort(*this);
		}


	private:
		listNode<T> *_start;

		// Split the list in two halves
		void frontBackSplit(list<T> &x)
		{
			size_t middle = size() / 2;

			// listNode<T> *cur = _start;
			iterator cur = begin();
			for (size_t i = 0; i < middle; i++)
			{
				cur++;
			}
			x.splice(x.begin(), *this, cur, this->end());
		}

		static void mergeSort(list<T> &l)
		{
			if (l.size() == 1)
				return;
			list<T> right;

			l.frontBackSplit(right);
			mergeSort(l);
			mergeSort(right);
			l.merge(right);

		}

		

	};

}
#endif