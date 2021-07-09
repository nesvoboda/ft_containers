#ifndef MAP_HPP
# define MAP_HPP

#include <memory>

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
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }
	// (2)	
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	// (3)	
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }
	// (4)	
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }
	// (5)	
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }
	// (6)	
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	template <class Val>
	struct BSTNode {
		BSTNode *left;
		BSTNode *right;
		BSTNode *parent;
		Val value;

		BSTNode(BSTNode *_left, BSTNode *_right, BSTNode *_parent, const Val &_value) : 
			left(_left), right(_right), parent(_parent), value(_value) {};
	};

	template <class T, class ptrT>
	class mapIterator {
	public:
		BSTNode<ptrT> *_ptr;

		mapIterator() : _ptr(NULL) {};
		mapIterator(BSTNode<ptrT> *ptr) : _ptr(ptr) {};
	};

	// template <class Val>
	// class BST {
		
	// 	private:
	// 	BSTNode *head;
	// }


	template <class Key,										// map::key_type
			  class T,											// map::mapped_type
			  class Compare = less<Key>,						// map::key_compare
			  class Alloc = std::allocator<pair<const Key, T> > // map::allocator_type
			  >
	class map
	{

	public:

		// Member types 

		typedef Key key_type; //	The first template parameter (Key)	
		typedef T mapped_type; //	The second template parameter (T)	
		typedef pair<const key_type,mapped_type> value_type;
		typedef Compare key_compare; //	The third template parameter (Compare)	defaults to: less<key_type>
		typedef Compare value_compare; // TODO doublecheck	Nested function class to compare elements	see value_comp
		typedef Alloc allocator_type; //	The fourth template parameter (Alloc)	defaults to: allocator<value_type>
		typedef typename allocator_type::reference reference; //	allocator_type::reference	for the default allocator: value_type&
		typedef typename allocator_type::const_reference const_reference;//	allocator_type::const_reference	for the default allocator: const value_type&
		typedef typename allocator_type::pointer pointer; //	allocator_type::pointer	for the default allocator: value_type*
		typedef typename allocator_type::const_pointer const_pointer;//	allocator_type::const_pointer	for the default allocator: const value_type*
		typedef mapIterator<T, value_type> iterator; //	a bidirectional iterator to value_type	convertible to const_iterator
		// const_iterator	a bidirectional iterator to const value_type	TODO
		// reverse_iterator	reverse_iterator<iterator>	TODO
		// const_reverse_iterator	reverse_iterator<const_iterator>	TODO
		typedef ptrdiff_t difference_type;// TODO implement in iter traits	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
		typedef size_t size_type; //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t


		map() : _head(NULL), _size(0) {};
		~map() {};
		// map(const map &copy) {}; // TODO
		// map &operator=(const map &operand); // TODO

		pair<iterator,bool> insert (const value_type& val)
		{
			if (_head == NULL)
			{
				_head = new BSTNode<value_type>(NULL, NULL, NULL, val);
				_size += 1;
				return pair<iterator, bool>(iterator(_head), true);
			}
			return pair<iterator, bool>(iterator(), true);
		}

	private:
		BSTNode<value_type> *_head;
		size_type _size;

	};

} // namespace ft

#endif