#ifndef MAP_HPP
# define MAP_HPP

#include <memory>

#include "map_util.hpp"
#include "binary_tree.hpp"

namespace ft
{


	// template <class Key, class Val>
	// struct BSTNode {
	// 	BSTNode *left;
	// 	BSTNode *right;
	// 	BSTNode *parent;
	// 	Key key;
	// 	Val value;

	// 	BSTNode(BSTNode *_left, BSTNode *_right, BSTNode *_parent, const Key &_key, const Val &_value) : 
	// 		left(_left), right(_right), parent(_parent), key(_key), value(_value) {};
	// };


	// creating a base BST class to hold all logic. It will be easier to test the behavior this way.

	// For now, the design choices are as follows:
	// Empty tree contains an empty element for iterators to preserve validity.
	// template <class Key, class Val>
	// class BST {

	// 	BST(void) : _head(new BSTNode(NULL, NULL, NULL, Key(), Val())) {
			
	// 	}


	// 	pair <BSTNode *, bool> insert(BSTNode **target, const Key &key, const Val &val)
	// 	{
	// 		if 
	// 	}

	// 	pair<BSTNode *,bool> insert (const Key &key, const Val& val)
	// 	{

	// 	}

	// 	private:
	// 	BSTNode *head;
	// }

	template <class IteratorValue, class Key, class ContainerValue>
	class mapIterator {
	public:
		ABSTNode<Key, ContainerValue> *_ptr;

		mapIterator() : _ptr(NULL) {};
		mapIterator(ABSTNode<Key, ContainerValue> *ptr) : _ptr(ptr) {};
		IteratorValue &operator*(void) { return _ptr->value; };
	};


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
		typedef mapIterator<mapped_type, key_type, mapped_type> iterator; //	a bidirectional iterator to value_type	convertible to const_iterator
		// const_iterator	a bidirectional iterator to const value_type	TODO
		// reverse_iterator	reverse_iterator<iterator>	TODO
		// const_reverse_iterator	reverse_iterator<const_iterator>	TODO
		typedef ptrdiff_t difference_type;// TODO implement in iter traits	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
		typedef size_t size_type; //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t


		map() {};
		~map() {};
		// map(const map &copy) {}; // TODO
		// map &operator=(const map &operand); // TODO

		// void print_valtype(value_type val)
		// {
		// 	std::cout << "[key: " << val.first << ", val: " << val.second << "]";
		// }

		// void print_node(BSTNode<value_type> bstnode)
		// {
		// 	std::cout << "[BSTNode left: " << bstnode.left << ", right: " << bstnode.right << ", key: " << bstnode.value.first << ", val: " << bstnode.value.second << "]";
		// }

		pair<iterator,bool> insert (const value_type& val)
		{
			ft::pair<node_type *, bool> ret = _base.insert(val);

			return(pair<iterator, bool>(iterator(ret.first), ret.second));
		}

		// iterator begin() {
		// 	if (_head == NULL)
		// };


		// const_iterator begin() const;


		size_type size() const
		{
			return _base._size;
		}

		bool empty() const
		{
			return (size() == 0);
		}

	private:
		// BSTNode<value_type> *_head;
		BSTree<key_type, mapped_type, key_compare> _base;
		// size_type _size;
		typedef ABSTNode<key_type, mapped_type> node_type;

	};

} // namespace ft

#endif