
#ifndef BINARY_TREE_HPP
# define BINARY_TREE_HPP

#include "map_util.hpp"
#include <unistd.h>

// What a bst node should have
// template <typename Content>
// struct ABSTNode
// {
// public:
// 	ABSTNode *left;
// 	ABSTNode *right;
// 	ABSTNode *parent;
// 	// Content content;
// 	Content key;

// 	bool fake; // for the end-element

// 	ABSTNode(ABSTNode *_left, ABSTNode *_right, ABSTNode *_parent, Content _content, bool _fake = false) :
// 		left(_left), right(_right), parent(_parent), key(_content), fake(_fake) {};

// 	Content toCompare(void) const {return content;};

// };


template <typename Key, typename Value>
struct ABSTNode
{
public:
	ABSTNode *left;
	ABSTNode *right;
	ABSTNode *parent;
	// // Content content;
	// Key key;
	// Value value;
	ft::pair<Key, Value> data;

	bool fake; // for the end-element

	ABSTNode(ABSTNode *_left, ABSTNode *_right, ABSTNode *_parent, Key _key, Value _value, bool _fake = false) :
		left(_left), right(_right), parent(_parent), data(ft::pair<Key, Value>(_key, _value)), fake(_fake) {};

	ABSTNode *immediateSuccessor(void)
	{
		if (this->right == NULL)
			return NULL;
		ABSTNode *cur =this->right;

		while (cur->left != NULL)
		{
			cur = cur->left;
		}
		return cur;
	}

	ABSTNode *immediatePredecessor(void)
	{
		if (this->left == NULL)
			return NULL;
		ABSTNode *cur =this->left;

		while (cur->right != NULL)
		{
			cur = cur->right;
		}
		return cur;
	}

	// Content toCompare(void) const {return content;};

};


// class IntNode : public ABSTNode<int>
// {
// 	IntNode() {};
// };

// A generic binary search tree
template <typename Key, typename Value, typename Compare = ft::less<Key> >
class BSTree
{
public:

	// Assumptions for now:
	// - an empty tree contains one empty node

	typedef ABSTNode<Key, Value> node_type;
	typedef ft::pair<const Key, Value> value_type;
	
	node_type *_head;
	size_t _size;
	Compare _comp;

	/////////////////
	BSTree(Compare comp = Compare()) : _head(new node_type(NULL, NULL, NULL, Key(), Value(), true)), _size(0), _comp(comp) {};

	BSTree(const BSTree &rhs) : _head(new node_type(NULL, NULL, NULL, Key(), Value(), true)), _size(0), _comp(Compare()) {
		clone_node(rhs._head);
	};

	void clone_node(node_type *other)
	{
		if (!other->fake)
		{
			insert(other->data);
		}

		if (other->left)
			clone_node(other->left);
		if (other->right)
			clone_node(other->right);
	}

	void clear(void)
	{
		free_node(_head);
		_head = new node_type(NULL, NULL, NULL, Key(), Value(), true);
		_size = 0;
	}

	BSTree &operator=(const BSTree &rhs)
	{
		clear();
		clone_node(rhs._head);
		return (*this);
	};

	~BSTree() { free_node(_head); _head = NULL;};

	ft::pair<node_type *,bool> insert (node_type *target, const value_type &val)
	{
		node_type *new_node = NULL;
		if (_comp(val.first, target->data.first))
		{
			if (target->left == NULL)
			{
				new_node = new node_type(NULL, NULL, target, val.first, val.second);
				target->left = new_node;
			}
			else
				return insert(target->left, val);
		}
		else if (_comp(target->data.first, val.first))
		{
			if (target->right == NULL)
			{
				new_node = new node_type(NULL, NULL, target, val.first, val.second);
				target->right = new_node;
			}
			else if (target->right->fake)
			{
				new_node = new node_type(NULL, NULL, target, val.first, val.second);
				node_type *tmp = target->right; // save the end element
				target->right = new_node;
				tmp->parent = target->right; // reattach end element to the new element
				new_node->right = tmp;
			}
			else
				return insert(target->right, val);
		}
		else
		{
			// delete new_node;
			return ft::pair<node_type *, bool>(target, false);
		}
		_size += 1;
		check_balance(new_node);
		return (ft::pair<node_type *, bool>(new_node, true));
	}

	ft::pair<node_type *,bool> insert (const value_type& val)
	{
		if (_size == 0)
		{
			node_type *tmp = _head;
			_head = new node_type(NULL, tmp, NULL, val.first, val.second);
			tmp->parent = _head;
			_size += 1;
			return ft::pair<node_type *, bool>(_head, true);
		}
		return insert(_head, val);
	}

	// size_t height(node_type *target)
	// {
	// 	if (target == NULL || (target->left == NULL && target->right == NULL))
	// 	{
	// 		return 0;
	// 	}
	// 	size_t left_height = 0;
	// 	if (target->left)
	// 		left_height = 1 + height(target->left);


	// 	size_t right_height = 0;
	// 	if (target->right)
	// 		right_height = 1 + height(target->right);

	// 	return left_height > right_height ? left_height : right_height;
	// }

	ssize_t height(node_type *target)
	{
		if (target == NULL)
		{
			return 0;
		}
		size_t left_height = 1 + height(target->left);
		size_t right_height = 1 + height(target->right);

		return left_height > right_height ? left_height : right_height;
	}

	node_type *left_rotate(node_type *grandparent)
	{
		node_type *tmp = grandparent->right;
		grandparent->right = tmp->left;

		if (tmp->left)
			tmp->left->parent = grandparent;

		tmp->left = grandparent;

		node_type *tmp2 = grandparent->parent;
		grandparent->parent = tmp;
		tmp->parent = tmp2;

		// // tmp parent

		// if (_head == grandparent)
		// 	_head = tmp;
		if (tmp2)
		{
			if (grandparent == tmp2->right)
				tmp2->right = tmp;
			else
				tmp2->left = tmp;
		}

		return tmp;
	}

	node_type *right_rotate(node_type *grandparent)
	{
		node_type *tmp = grandparent->left;

		grandparent->left = tmp->right;
		
		if (tmp->right)
			tmp->right->parent = grandparent;

		tmp->right = grandparent;

		node_type *tmp2 = grandparent->parent;
		grandparent->parent = tmp;
		tmp->parent = tmp2;

		if (_head == grandparent)
			_head = tmp;

		if (tmp2)
		{
			if (grandparent == tmp2->right)
				tmp2->right = tmp;
			else
				tmp2->left = tmp;
		}
		return tmp;

	}

	node_type *right_left_rotate(node_type *grandparent)
	{
		grandparent->right = right_rotate(grandparent->right);
		return left_rotate(grandparent);
	}

	node_type *left_right_rotate(node_type *grandparent)
	{
		grandparent->left = left_rotate(grandparent->left);
		return right_rotate(grandparent);
	}

	void rebalance(node_type *target)
	{
		if ((height(target->left) - height(target->right)) > 1) // left subtree bigger than right
		{
			if (height(target->left->left) > height(target->left->right))
			{
				// check problem
				target = right_rotate(target);
			}
			else
			{
				target = left_right_rotate(target);
			}
		}
		else
		{
			if (height(target->right->right) > height(target->right->left))
			{
				target = left_rotate(target);
			}
			else
				target = right_left_rotate(target);
		}
		if (target->parent == NULL)
			_head = target;
		
	}

	void check_balance(node_type *target)
	{
		ssize_t diffHeight = height(target->left) - height(target->right);
		if (diffHeight > 1 || diffHeight < -1)
		{
			rebalance(target);
		}
		if (target->parent == NULL)
			return;
		check_balance(target->parent);
	}

	void swap_content(BSTree &other)
	{
		node_type *tmp = _head;
		_head = other._head;
		other._head = tmp;

		size_t t = other._size;
		_size = other._size;
		other._size = t;
	}

	void swap(node_type *a, node_type *b)
	{
		node_type *aParent = a->parent;
		node_type *bParent = b->parent;

		if (aParent)
		{
			if (a == aParent->left)
				aParent->left = b;
			else
				aParent->right = b;
		}

		if (bParent)
		{
			if (b == bParent->left)
				bParent->left = a;
			else
				bParent->right = a;
		}

		a->parent = bParent;
		b->parent = aParent;

		node_type *aLeft = a->left;
		node_type *aRight = a->right;
		
		node_type *bLeft = b->left;
		node_type *bRight = b->right;

		if (aLeft)
			aLeft->parent = b;
		b->left = aLeft;

		if (aRight)
			aRight->parent = b;
		b->right = aRight;

		if (bLeft)
			bLeft->parent = a;
		a->left = bLeft;

		if (bRight)
			bRight->parent = a;
		a->right = bRight;
	}
	
	void erase(node_type *target)
	{
		// leaf node
		if (target->left == NULL && target->right == NULL)
		{
			if (target == target->parent->left) // if target is someone's left child
				target->parent->left = NULL;
			else
				target->parent->right = NULL;
			
		}
		else if (target->left == NULL || target->right == NULL) // one child
		{
			if (target->left == NULL) // if target has a right child
			{

				if (target->parent)
				{
					if (target == target->parent->left) // if target is someone's left child
						target->parent->left = target->right;
					else
						target->parent->right = target->right;
				}
				else
				{
					_head = target->right;
				}
				target->right->parent = target->parent;
			}
			else // if target has a left child
			{
				if (target->parent)
				{
					if (target == target->parent->left) // if target is someone's left child
						target->parent->left = target->left;
					else
						target->parent->right = target->left;
				}
				else
				{
					_head = target->left;
				}
				target->left->parent = target->parent;
			}
			
		}
		else
		{
			node_type *successor = target->immediateSuccessor();
			if (target == _head)
			{
				_head = successor;
				// successor->parent = NULL;
			}
			swap(target, successor);

			erase(target);
			return;
		}
		delete target;
		_size -= 1;
	}


	void free_node(node_type *target)
	{
		if (target->left)
			free_node(target->left);
		if (target->right)
			free_node(target->right);
		delete target;
	}

	node_type *find(node_type *target, const Key &k) const
	{
		if (target == NULL || target->fake)
			return NULL;

		if (_comp(k, target->data.first))
		{
			return find(target->left, k);
		}
		else if (_comp(target->data.first, k))
		{
			return find(target->right, k);
		}
		else
		{
			return target;
		}
	}

	node_type *find (const Key& k) const
	{
		return find(_head, k);
	}

	// node_type *lower_bound(const Key &k) const
	// {
	// 	node_type *cur = _head;

	// 	if (_comp(k, cur->data.first))

	// 	while (cur)
	// }
/*
	size_t contains(node_type *target, const Content& val)
	{
		if (target == NULL || (target->fake))
			return 0;
		if (target->content == val)
			return 1;
		if (target->content < val)
		{
			return contains(target->left);
		}
		return contains(target->right);
	}

	size_t count( const Content& val ) const
	{
		return contains(_head, val);
	} */

};

#endif