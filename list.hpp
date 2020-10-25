/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:25:06 by ashishae          #+#    #+#             */
/*   Updated: 2020/10/25 18:16:45 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>

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

	// Default constructor
	explicit list(/*const allocator_type& alloc = allocator_type()*/) :
		start(NULL) {};

	// Fill constructor
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
	
	// template <class InputIterator>
	// list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	
	~list() {};
	list(const list &copy);
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
	
	T &front(void) {return start->getValue();};
	const T &front(void) const {return start->getValue();};
	
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

	class reverse_iterator: public iterator {
		// listNode<T> *ptr;
		public:
			reverse_iterator() : iterator() {};
			reverse_iterator(listNode<T> *_ptr) : iterator(_ptr) {};
			reverse_iterator(iterator it) : iterator(it) {};
			reverse_iterator(reverse_iterator const &it) : iterator(it) {};
			reverse_iterator& operator=(const reverse_iterator &operand) {iterator::operator=(operand); return(*this);}
			virtual ~reverse_iterator(void) {};
			reverse_iterator& operator++() {iterator::operator--(); return *this;}
			reverse_iterator& operator--() {iterator::operator++(); return *this;}
			T& operator*() {return iterator::operator*();}
			reverse_iterator operator++(int) {reverse_iterator retval = *this; ++(*this); return retval;}
			reverse_iterator operator--(int) {reverse_iterator retval = *this; --(*this); return retval;}
			bool operator==(reverse_iterator other) const {return iterator::operator==(other);}
			bool operator!=(reverse_iterator other) const {return !(*this == other);}
			reverse_iterator &operator*() const {return iterator::operator*;}
	};
	iterator rbegin() {return reverse_iterator(this->start);}
	iterator rend() {
		// listNode<T> *cursor = this->start;
		// while (cursor->getNext() != NULL)
		// 	cursor = cursor->getNext();
		// return iterator(cursor);
		return reverse_iterator(this->end());
	}


public:
	listNode<T> *start;
};

#endif