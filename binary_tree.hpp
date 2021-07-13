
#ifndef BINARY_TREE_HPP
# define BINARY_TREE_HPP

#include "map_util.hpp"

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
	// Content content;
	Key key;
	Value value;

	bool fake; // for the end-element

	ABSTNode(ABSTNode *_left, ABSTNode *_right, ABSTNode *_parent, Key _key, Value _value, bool _fake = false) :
		left(_left), right(_right), parent(_parent), key(_key), value(_value), fake(_fake) {};

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
	BSTree() : _head(new node_type(NULL, NULL, NULL, Key(), Value(), true)), _size(0), _comp(Compare()) {};

	ft::pair<node_type *,bool> insert (node_type *target, const value_type &val)
	{
		if (_comp(val.first, target->key))
		{
			if (target->left == NULL)
			{
				target->left = new node_type(NULL, NULL, target, val.first, val.second);
				_size += 1;
				return ft::pair<node_type *, bool>(target->left, true);
			}
			return insert(target->left, val);
		}
		if (_comp(target->key, val.first))
		{
			if (target->right == NULL)
			{
				target->right = new node_type(NULL, NULL, target, val.first, val.second);
				_size += 1;
				return ft::pair<node_type *, bool>(target->right, true);
			}

			if (target->right->fake)
			{
				node_type *tmp = target->right; // save the end element
				target->right = new node_type(NULL, tmp, target, val.first, val.second);
				tmp->parent = target->right; // reattach end element to the new element
				_size += 1;
				return (ft::pair<node_type *, bool>(target->right, true));
			}

			return insert(target->right, val);
		}
		return ft::pair<node_type *, bool>(target, false);
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