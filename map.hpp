#ifndef MAP_HPP
#define MAP_HPP

#include <memory>

#include "map_util.hpp"
#include "binary_tree.hpp"
#include "revIterator.hpp"
#include "util.hpp"

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
	class mapIterator
	{
		typedef ABSTNode<Key, ContainerValue> node_type;

	public:
		typedef IteratorValue value_type;
		typedef ptrdiff_t difference_type;
		ABSTNode<Key, ContainerValue> *_ptr; //REMOVE BEFORE FLIGHT

		mapIterator() : _ptr(NULL){};
		mapIterator(ABSTNode<Key, ContainerValue> *ptr) : _ptr(ptr){};
		mapIterator(const mapIterator &other) : _ptr(other._ptr){};
		~mapIterator(){};

		mapIterator &operator=(const mapIterator &other)
		{
			_ptr = other._ptr;
			return (*this);
		};

		IteratorValue &operator*(void) { return _ptr->data; };
		IteratorValue *operator->(void) const { return &(_ptr->data); };

		bool operator==(const mapIterator &rhs) const { return _ptr == rhs._ptr; };
		bool operator!=(const mapIterator &rhs) const { return _ptr != rhs._ptr; };

		operator mapIterator<const IteratorValue, Key, ContainerValue>(void) const
		{
			return mapIterator<const IteratorValue, Key, ContainerValue>(_ptr);
		}

		mapIterator &operator++()
		{
			node_type *successor = _ptr->immediateSuccessor();

			if (!successor)
			{
				if (_ptr == _ptr->parent->left)
					_ptr = _ptr->parent;
			}
			else
				_ptr = successor;
			return (*this);
		};

		mapIterator operator++(int)
		{
			node_type *old = _ptr;
			node_type *successor = _ptr->immediateSuccessor();

			if (!successor)
			{
				if (_ptr == _ptr->parent->left)
					_ptr = _ptr->parent;
			}
			else
				_ptr = successor;
			return (mapIterator(old));
		};

		mapIterator &operator--()
		{
			node_type *successor = _ptr->immediatePredecessor();

			if (!successor)
			{
				if (_ptr == _ptr->parent->right)
					_ptr = _ptr->parent;
			}
			else
				_ptr = successor;
			return (*this);
		};

		mapIterator operator--(int)
		{
			node_type *old = _ptr;
			node_type *successor = _ptr->immediatePredecessor();

			if (!successor)
			{
				if (_ptr == _ptr->parent->right)
					_ptr = _ptr->parent;
			}
			else
				_ptr = successor;
			return (mapIterator(old));
		};

		// We need this to be able to access the underlying pointer (for instance,
		// to erase an element). Map iterator doesn't have base() in std.
		template <class, class, class, class>
		friend class map;
	};

	template <class Key,									   // map::key_type
			  class T,										   // map::mapped_type
			  class Compare = less<Key>,					   // map::key_compare
			  class Alloc = std::allocator<pair<const Key, T> > // map::allocator_type
			  >
	class map
	{
	public:
		// Member types

		typedef Key key_type;  //	The first template parameter (Key)
		typedef T mapped_type; //	The second template parameter (T)
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare; //	The third template parameter (Compare)	defaults to: less<key_type>
		// typedef Compare value_compare;													   // TODO doublecheck	Nested function class to compare elements	see value_comp
		typedef Alloc allocator_type;													   //	The fourth template parameter (Alloc)	defaults to: allocator<value_type>
		typedef typename allocator_type::reference reference;							   //	allocator_type::reference	for the default allocator: value_type&
		typedef typename allocator_type::const_reference const_reference;				   //	allocator_type::const_reference	for the default allocator: const value_type&
		typedef typename allocator_type::pointer pointer;								   //	allocator_type::pointer	for the default allocator: value_type*
		typedef typename allocator_type::const_pointer const_pointer;					   //	allocator_type::const_pointer	for the default allocator: const value_type*
		typedef mapIterator<value_type, const key_type, mapped_type> iterator;			   //	a bidirectional iterator to value_type	convertible to const_iterator
		typedef mapIterator<const value_type, const key_type, mapped_type> const_iterator; //a bidirectional iterator to const value_type	TODO
		typedef rev_iterator<iterator> reverse_iterator;								   // reverse_iterator<iterator>	TODO
		typedef rev_iterator<const_iterator> const_reverse_iterator;					   // const_reverse_iterator	reverse_iterator<const_iterator>	TODO
		typedef ptrdiff_t difference_type;												   // TODO implement in iter traits	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
		typedef size_t size_type;														   //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

		map(){};
		~map(){};
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

		pair<iterator, bool> insert(const value_type &val)
		{
			ft::pair<node_type *, bool> ret = _base.insert(val);

			return (pair<iterator, bool>(iterator(ret.first), ret.second));
		}

		iterator begin()
		{
			node_type *cur = _base._head;
			while (cur->left != NULL)
			{
				cur = cur->left;
			}
			return iterator(cur);
		}
		const_iterator begin() const
		{
			node_type *cur = _base._head;
			while (cur->left != NULL)
			{
				cur = cur->left;
			}
			return const_iterator(cur);
		}

		iterator end()
		{
			node_type *cur = _base._head;
			while (cur->right != NULL)
			{
				cur = cur->right;
			}
			return iterator(cur);
		}

		const_iterator end() const
		{
			node_type *cur = _base._head;
			while (cur->right != NULL)
			{
				cur = cur->right;
			}
			return iterator(cur);
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
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

		mapped_type &operator[](const key_type &k)
		{
			// ft::pair<iterator, bool> ret = insert(ft::pair<key_type, mapped_type>(k, mapped_type()));
			// return (*(ret.first)).second;
			return (*((this->insert(ft::pair<key_type, mapped_type>(k, mapped_type()))).first)).second;
		}

		void erase(iterator position)
		{
			_base.erase(position._ptr);
		}

		size_type erase(const key_type &k)
		{
			iterator b = begin();
			size_type ret = 0;

			while (b != end())
			{
				if (b->first == k)
				{
					erase(b++);
					ret++;
				}
				else
					b++;
			}
			return ret;
		}

		void erase(iterator first, iterator last)
		{
			while (first != last)
			{
				erase(first++);
			}
		}

		void swap(map &x)
		{
			_base.swap_content(x._base);
			// swap_val(_base._head, x._base._head);
			// swap_val(_base._size, x._base._size);
		}

		void clear()
		{
			_base.clear();
		}

		key_compare key_comp() const
		{
			return _base._comp;
		}

		// template <class Key, class T, class Compare, class Alloc>
		class value_compare
		{ // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class map;

		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {} // constructed with map's comparison object
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator()(const value_type &x, const value_type &y) const
			{
				return comp(x.first, y.first);
			}
		};

		value_compare value_comp() const
		{
			return value_compare(_base._comp);
		}

	private:
		// BSTNode<value_type> *_head;
		BSTree<const key_type, mapped_type, key_compare> _base;
		// size_type _size;
		typedef ABSTNode<const key_type, mapped_type> node_type;
	};

} // namespace ft

#endif