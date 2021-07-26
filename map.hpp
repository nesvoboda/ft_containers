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

	template <class IteratorValue, class NodeType>
	class mapIterator
	{
		typedef NodeType node_type;

	public:
		typedef IteratorValue value_type;
		typedef ptrdiff_t difference_type;
		NodeType *_ptr; //REMOVE BEFORE FLIGHT

		mapIterator() : _ptr(NULL){};
		mapIterator(NodeType *ptr) : _ptr(ptr){};

		// template <typename T, typename NT>
		mapIterator(const mapIterator &other) : _ptr(other._ptr){};
		~mapIterator(){};

		template <typename T, typename NT>
		mapIterator &operator=(const mapIterator &other)
		{
			_ptr = other._ptr;
			return (*this);
		};

		IteratorValue &operator*(void) const { return _ptr->data; };
		IteratorValue *operator->(void) const { return &(_ptr->data); };

		bool operator==(const mapIterator &rhs) const { return _ptr == rhs._ptr; };
		bool operator!=(const mapIterator &rhs) const { return _ptr != rhs._ptr; };

		operator mapIterator<const IteratorValue, NodeType>(void) const
		{
			return mapIterator<const IteratorValue, NodeType>(_ptr);
		}

		mapIterator &operator++()
		{
			node_type *successor = _ptr->immediateSuccessor();

			if (!successor)
			{
				node_type *cur = _ptr;
				while (cur->parent && cur->parent->left != cur)
				{
					cur = cur->parent;
				}
				_ptr = cur->parent;
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
				// if (_ptr == _ptr->parent->left)
				// 	_ptr = _ptr->parent;
				node_type *cur = _ptr;
				while (cur->parent && cur->parent->left != cur)
				{
					cur = cur->parent;
				}
				_ptr = cur->parent;
				
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
				node_type *cur = _ptr;
				while (cur->parent && cur->parent->right != cur)
				{
					cur = cur->parent;
				}
				_ptr = cur->parent;
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
				node_type *cur = _ptr;
				while (cur->parent && cur->parent->right != cur)
				{
					cur = cur->parent;
				}
				_ptr = cur->parent;
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

// TODO use allocator

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
		// typedef Compare value_compare;													   //	Nested function class to compare elements	see value_comp
		typedef Alloc allocator_type;													   //	The fourth template parameter (Alloc)	defaults to: allocator<value_type>
		typedef typename allocator_type::reference reference;							   //	allocator_type::reference	for the default allocator: value_type&
		typedef typename allocator_type::const_reference const_reference;				   //	allocator_type::const_reference	for the default allocator: const value_type&
		typedef typename allocator_type::pointer pointer;								   //	allocator_type::pointer	for the default allocator: value_type*
		typedef typename allocator_type::const_pointer const_pointer;					   //	allocator_type::const_pointer	for the default allocator: const value_type*
		typedef mapIterator<value_type, ABSTNode<const key_type, mapped_type> > iterator;			   //	a bidirectional iterator to value_type	convertible to const_iterator
		typedef mapIterator<const value_type, ABSTNode<const key_type, mapped_type> > const_iterator; //a bidirectional iterator to const value_type	
		typedef rev_iterator<iterator> reverse_iterator;								   // reverse_iterator<iterator>	
		typedef rev_iterator<const_iterator> const_reverse_iterator;					   // const_reverse_iterator	reverse_iterator<const_iterator>	
		typedef ptrdiff_t difference_type;												   // TODO implement in iter traits	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
		typedef size_t size_type;														   //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

		// map() : {};

		// Constructors

		// empty (1)	
		explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) : _base(comp), _allocator(alloc) {} ;

		// range (2)	
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _base(comp), _allocator(alloc) {
				while (first != last)
				{
					insert(*(first++));
				}
			};

		// copy (3)	
		map(const map &copy) : _base(copy._base), _allocator(copy._allocator) {};


		~map() {};
		map &operator=(const map &operand) {
			_base = operand._base;
			return (*this);
		};


		size_type max_size() const
		{
			// size_type max_nodes = std::numeric_limits<size_type>::max() / sizeof(value_type);
			size_type max_ptrdiff = std::numeric_limits<difference_type >::max();

			// return (max_nodes < max_ptrdiff ? max_nodes : max_ptrdiff); // this is the solution that reflects
			// my solution better, but the answer would be different from the standard library.
			
			return max_ptrdiff / ((sizeof(node_type) - sizeof(int) * 2) / 2); // this return corrseponds to the std lib.
		}

		pair<iterator, bool> insert(const value_type &val)
		{
			ft::pair<node_type *, bool> ret = _base.insert(val);

			return (pair<iterator, bool>(iterator(ret.first), ret.second));
		}

		iterator insert(iterator position, const value_type& val)
		{
			
			if (_base._size == 0 || position == end())
			{
				return iterator(_base.insert(val).first);
			}
			else
			{
				Compare comp;
				iterator posNext = position;
				posNext++;
				if (comp((*position).first, val.first) && !comp(lower_bound(position->first)->first, val.first))
					return iterator(_base.insert(position._ptr, val).first);
				else
					return iterator(_base.insert(val).first);
			}
			// (void) position;
			// return iterator(ret.first);
			// return _base.insert(position, val);
		}

		// range (3)	
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
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
			return const_iterator(cur);
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

		iterator find (const key_type& k)
		{
			node_type *ret = _base.find(k);

			if (ret == NULL)
				return end();
			else
				return iterator(ret);
		}

		const_iterator find (const key_type& k) const
		{
			node_type *ret = _base.find(k);

			if (ret == NULL)
				return end();
			else
				return const_iterator(ret);
		}

		size_type count (const key_type& k) const
		{
			node_type *ret = _base.find(k);
			if (ret == NULL)
				return 0;
			else
				return 1;
		}

		iterator lower_bound (const key_type& k)
		{
			iterator b = begin();

			while (b != end())
			{
				if (!(_base._comp(b->first, k)))
					return b;
				b++;
			}
			return end();
		}

		const_iterator lower_bound (const key_type& k) const
		{
			const_iterator b = begin();

			while (b != end())
			{
				if (!(_base._comp(b._ptr->data.first, k)))
					return const_iterator(b);
				b++;
			}
			return end();
		}

		iterator upper_bound (const key_type& k)
		{
			iterator b = begin();

			while (b != end())
			{
				if ((_base._comp(k, b._ptr->data.first)))
					return b;
				b++;
			}
			return end();

		}

		const_iterator upper_bound (const key_type& k) const
		{
			const_iterator b = begin();

			while (b != end())
			{
				if ((_base._comp(k, b._ptr->data.first)))
					return const_iterator(b);
				b++;
			}
			return end();
		}

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
		}

		pair<iterator,iterator>             equal_range (const key_type& k)
		{
			return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
		}

		allocator_type get_allocator() const
		{
			return _allocator;
		}

		BSTree<const key_type, mapped_type, key_compare> _base;
	private:
		// BSTNode<value_type> *_head;
		// size_type _size;
		typedef ABSTNode<const key_type, mapped_type> node_type;
		Alloc _allocator;
	};

	// (1)	
	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
						const map<Key,T,Compare,Alloc>& rhs )
	{
		return (lhs.size() == rhs.size() &&
				equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	// (2)	
	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
						const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	// (3)	
	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
						const map<Key,T,Compare,Alloc>& rhs )
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	// (4)	

	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
						const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs > rhs);
	}
	// (5)	
	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
						const map<Key,T,Compare,Alloc>& rhs )
	{
		return (rhs < lhs);
	}


	// (6)	
	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
						const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs < rhs);
	}

} // namespace ft

#endif