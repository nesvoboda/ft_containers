/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:25:06 by ashishae          #+#    #+#             */
/*   Updated: 2021/03/23 15:55:17 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>

template <typename iterator, typename T>
class reverse_iterator {
		iterator _iter;
		// listNode<T> *ptr;
		public:
			reverse_iterator() : _iter() {};
			// reverse_iterator(listNode<T> *_ptr) : iterator(_ptr) {};
			reverse_iterator(iterator it) : _iter(it) {};
			reverse_iterator(reverse_iterator const &it) : _iter(it) {};
			reverse_iterator& operator=(const reverse_iterator &operand) {iterator::operator=(operand); return(*this);}
			virtual ~reverse_iterator(void) {};
			reverse_iterator& operator++() {_iter.operator--(); return *this;}
			reverse_iterator& operator--() {_iter.operator++(); return *this;}
			T& operator*() {return _iter.operator*();}
			reverse_iterator operator++(int) {reverse_iterator retval = *this; ++(*this); return retval;}
			reverse_iterator operator--(int) {reverse_iterator retval = *this; --(*this); return retval;}
			bool operator==(reverse_iterator other) const {return _iter.operator==(other._iter);}
			bool operator!=(reverse_iterator other) const {return !(*this == other);}
			reverse_iterator &operator*() const {_iter.operator*(); return *this;}
};

template <typename T>
class listNode {

public:
	listNode(T v, listNode *n = NULL, listNode *p = NULL) : value(v), next(n), prev(p) {};
	~listNode() {};
	listNode(const listNode &copy) : value(copy.value), next(copy.next), prev(copy.next) {};
	listNode &operator= (const listNode &operand) {value = operand.value; next = operand.next; prev=operand.prev; return (*this);};
	
	T &getValue(void) {return value;};
	const T &getValue(void) const {return value;};

	listNode *getNext(void) const {return next;};
	listNode *getPrev(void) const {return prev;};

	void setValue(T v) {value = v;};
	void setNext(listNode *n) {next = n;};
	void setPrev(listNode *p) {prev = p;};
	
private:
	listNode();
	T value;
	listNode *next;
	listNode *prev;
};

template <typename T>
class list {
	

public:

	// (1) Default constructor
	explicit list(/*const allocator_type& alloc = allocator_type()*/) :
		start(NULL) {};

	// (2) Fill constructor
	explicit list(unsigned int n, const T& val = T() /*, const allocator_type& alloc = allocator_type()*/)
	{
		this->start = new listNode<T>(val, NULL, NULL);
		listNode<T> *cursor = this->start;
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
	};

	// TODO: (3) Range constructor

	// TODO: (4) Сopy constructor
	list(const list &copy);
	
	// template <class InputIterator>
	// list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	
	~list() {};
	
	list &operator= (const list &operand) {

		// We only need to manipulate things if we're not self-reassigning
		if (&operand != this)
		{
			// Delete whatever was here before;
			listNode<T> *tmp = this->start;
			listNode<T> *tmp2 = this->start;
			while (tmp->getNext() != NULL)
			{
				tmp = tmp->getNext();
			}
			tmp2 = tmp->getPrev();
			while (tmp2 != this->start)
			{
				delete tmp;
				tmp = NULL;

				tmp = tmp2;
				tmp2 = tmp->getPrev();
			}
			delete this->start;
			this->start = NULL;

			this->start = new listNode<T>(operand.start->getValue(), NULL, NULL);
			listNode<T> *cursor = operand.start->getNext();
			tmp = this->start;
			while (cursor != NULL)
			{
				tmp->setNext(new listNode<T>(*cursor));
				cursor = cursor->getNext();
				tmp = tmp->getNext();
			}
		}
		return (*this);
	};

	// Iterators

	class iterator: public std::iterator<std::bidirectional_iterator_tag, T> {
		listNode<T> *ptr;
		public:
			iterator() : ptr(NULL) {}
			iterator(listNode<T> *_ptr) : ptr(_ptr) {}
			iterator(iterator const &it) : ptr(it.ptr) {};
			iterator& operator=(const iterator &operand) {ptr = operand.ptr; return *this;}
			~iterator(void) {};
			iterator& operator++() {ptr = ptr->getNext(); return *this;}
			iterator& operator--() {ptr = ptr->getPrev(); return *this;}
			T& operator*() {return ptr->getValue();}
			iterator operator++(int) {iterator retval = *this; ++(*this); return retval;}
			iterator operator--(int) {iterator retval = *this; --(*this); return retval;}
			bool operator==(iterator other) const {return ptr == other.ptr;}
			bool operator!=(iterator other) const {return !(*this == other);}
			iterator &operator*() const {return ptr->getValue();}
	};
	iterator begin() {return iterator(this->start);}
	iterator end() {
		listNode<T> *cursor = this->start;
		while (cursor->getNext() != NULL)
			cursor = cursor->getNext();
		return iterator(cursor);
	}

	// class reverse_iterator: public iterator {
	// 	// listNode<T> *ptr;
	// 	public:
	// 		reverse_iterator() : iterator() {};
	// 		reverse_iterator(listNode<T> *_ptr) : iterator(_ptr) {};
	// 		reverse_iterator(iterator it) : iterator(it) {};
	// 		reverse_iterator(reverse_iterator const &it) : iterator(it) {};
	// 		reverse_iterator& operator=(const reverse_iterator &operand) {iterator::operator=(operand); return(*this);}
	// 		virtual ~reverse_iterator(void) {};
	// 		reverse_iterator& operator++() {iterator::operator--(); return *this;}
	// 		reverse_iterator& operator--() {iterator::operator++(); return *this;}
	// 		T& operator*() {return iterator::operator*();}
	// 		reverse_iterator operator++(int) {reverse_iterator retval = *this; ++(*this); return retval;}
	// 		reverse_iterator operator--(int) {reverse_iterator retval = *this; --(*this); return retval;}
	// 		bool operator==(reverse_iterator other) const {return iterator::operator==(other);}
	// 		bool operator!=(reverse_iterator other) const {return !(*this == other);}
	// 		reverse_iterator &operator*() const {return iterator::operator*;}
	// };
	reverse_iterator<iterator, T> reverse_iterator;
	iterator rbegin() {return reverse_iterator(this->start);}
	iterator rend() {
		return reverse_iterator(this->end());
	}

	class const_iterator: public iterator {
		listNode<T> *ptr;
		public:
			const_iterator() : ptr(NULL) {}
			const_iterator(listNode<T> *_ptr) : ptr(_ptr) {}
			const_iterator(const_iterator const &it) : ptr(it.ptr) {};
			const_iterator& operator=(const const_iterator &operand) {ptr = operand.ptr; return *this;}
			~const_iterator(void) {};
			const_iterator& operator++() {ptr = ptr->getNext(); return *this;}
			const_iterator& operator--() {ptr = ptr->getPrev(); return *this;}
			const T& operator*() {return ptr->getValue();}
			const_iterator operator++(int) {const_iterator retval = *this; ++(*this); return retval;}
			const_iterator operator--(int) {const_iterator retval = *this; --(*this); return retval;}
			bool operator==(const_iterator other) const {return ptr == other.ptr;}
			bool operator!=(const_iterator other) const {return !(*this == other);}
			const_iterator &operator*() const {return ptr->getValue();}
	};

	const_iterator cbegin() {return const_iterator(this->start);}
	const_iterator cend() {
		listNode<T> *cursor = this->start;
		while (cursor->getNext() != NULL)
			cursor = cursor->getNext();
		return const_iterator(cursor);
	}
	
	// Capacity

	bool empty(void) const {return start == NULL;};
	unsigned int size() const {
		unsigned int val = 0;
		listNode<T> *cursor = start;
		while (cursor->getNext() != NULL)
		{
			val += 1;
			cursor = cursor->getNext();
		}
		return val;
	};
	
	// Element access
	T &front(void) {return start->getValue();};
	const T &front(void) const {return start->getValue();};


public:
	listNode<T> *start;
};

#endif