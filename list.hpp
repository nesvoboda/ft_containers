/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:25:06 by ashishae          #+#    #+#             */
/*   Updated: 2021/06/05 19:02:24 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

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

template <typename T>
class list
{

public:
	typedef T value_type;
	// TODO
	// typedef allocator_type
	typedef value_type &reference;
	typedef const value_type &const_reference;
	typedef value_type *pointer;
	typedef const value_type *const_pointer;
	typedef size_t size_type;

	// (1) Default constructor
	explicit list(/*const allocator_type& alloc = allocator_type()*/)
	{
		_start = new listNode<T>(T(), NULL, NULL);
	};

	// (2) Fill constructor
	explicit list(unsigned int n, const T &val = T() /*, const allocator_type& alloc = allocator_type()*/)
	{

		// if (n == 0)
		// {
		// 	_start = new listNode<T>(T(), NULL, NULL);
		// 	return;
		// }
		/*
		_start = new listNode<T>(val, NULL, NULL);
		listNode<T> *cursor = _start;
		listNode<T> *tmp = NULL;
		for (unsigned int i = 1; i < n; i++)
		{
			tmp = new listNode<T>(val, NULL, cursor);
			cursor->setNext(tmp);
			cursor = tmp;
		}

		// Element for the end iterator
		tmp = new listNode<T>(T(), NULL, cursor);
		cursor->setNext(tmp);
		*/
		_start = new listNode<T>(val, NULL, NULL);
		for (size_t i = 0; i < n; i++) {
			listNode<T> *newElem = new listNode<T>(val, _start, NULL);
			_start->setPrev(newElem);
			_start = newElem;
		}
	};

	// TODO: (3) Range constructor

	// TODO: (4) Сopy constructor
	// list(const list &copy);

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
/*
	list &operator=(const list &operand)
	{

		// We only need to manipulate things if we're not self-reassigning
		if (&operand != this)
		{
			// Delete whatever was here before;
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
			// delete cur;

			// _start = NULL;
			// TODO
			// Copy the operand
			// listNode<T> *cursorTheirs = operand->_start;

			// while (cursorTheirs != NULL)
			// {

			// }
			// _start = new listNode<T>(operand._start->getValue(), NULL, NULL);
			// listNode<T> *cursor = operand._start->getNext();
			// prev = _start;
			// while (cursor != NULL)
			// {
			// 	prev->setNext(new listNode<T>(*cursor));
			// 	cursor = cursor->getNext();
			// 	prev = prev->getNext();
			// }
		}
		return (*this);
	}; */

	// Iterators

	class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
		friend class list;
		listNode<T> *ptr;

		listNode<T> *internalPtr(void) { return ptr; };

	public:
		iterator() : ptr(NULL) {}
		iterator(listNode<T> *_ptr) : ptr(_ptr) {}
		iterator(iterator const &it) : ptr(it.ptr){};
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

	typedef reverse_iterator<iterator, T> reverse_iterator;
	reverse_iterator rbegin() { return reverse_iterator(_start); }
	reverse_iterator rend()
	{
		return reverse_iterator(this->end());
	}

	// Capacity

	bool empty(void) const {
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

	// TODO assign
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

	void push_back (const value_type& val)
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
	iterator insert (iterator position, const value_type& val)
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
	void insert (iterator position, size_type n, const value_type& val)
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

public:
	listNode<T> *_start;
};

#endif