
#include "map_util.hpp"

// What a bst node should have
template <typename Content>
struct ABSTNode
{
public:
	ABSTNode *left;
	ABSTNode *right;
	ABSTNode *parent;
	Content content;
	bool fake; // for the end-element

	ABSTNode(ABSTNode *_left, ABSTNode *_right, ABSTNode *_parent, Content _content, bool _fake = false) :
		left(_left), right(_right), parent(_parent), content(_content), fake(_fake) {};

	// I plan to use this operator to compare nodes
	// and later overload it depending on how I use it.
	// template <typename Content>
	bool operator<(const ABSTNode<Content> &b) const
	{
		return (content < b.content);
	}

	// template <typename Content>
	bool operator>(const ABSTNode<Content> &b) const
	{
		return (content > b.content);
	}

	// template <typename Content>
	bool operator<(const Content &b) const
	{
		return (content < b);
	}

	// template <typename Content>
	bool operator>(const Content &b) const
	{
		return (content > b);
	}
};

// class IntNode : public ABSTNode<int>
// {
// 	IntNode() {};
// };

// A generic binary search tree
template <typename NodeType, typename Content>
class BSTree
{
public:

	// Assumptions for now:
	// - an empty tree contains one empty node

	typedef NodeType node_type;
	
	node_type *_head;
	size_t _size;

	/////////////////
	BSTree() : _head(new NodeType(NULL, NULL, NULL, Content(), true)), _size(0) {};

	pair<node_type *,bool> insert (node_type *target, const Content& val)
	{
		if (val < target->content)
		{
			if (target->left == NULL)
			{
				target->left = new NodeType(NULL, NULL, target, val);
				_size += 1;
				return pair<node_type *, bool>(target->left, true);
			}
			return insert(target->left, val);
		}
		if (val > target->content)
		{
			if (target->right == NULL)
			{
				target->right = new NodeType(NULL, NULL, target, val);
				_size += 1;
				return pair<node_type *, bool>(target->right, true);
			}

			if (target->right->fake)
			{
				NodeType *tmp = target->right; // save the end element
				target->right = new NodeType(NULL, tmp, target, val);
				tmp->parent = target->right; // reattach end element to the new element
				_size += 1;
				return (pair<node_type *, bool>(target->right, true));
			}

			return insert(target->right, val);
		}
		return pair<node_type *, bool>(target, false);
	}

	pair<node_type *,bool> insert (const Content& val)
	{
		if (_size == 0)
		{
			node_type *tmp = _head;
			_head = new NodeType(NULL, tmp, NULL, val);
			tmp->parent = _head;
			_size += 1;
			return pair<node_type *, bool>(_head, true);
		}
		return insert(_head, val);
	}

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
	}

};