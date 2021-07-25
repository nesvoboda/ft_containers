#include "elementest.hpp"
#include "binary_tree.hpp"

#include <map>
#include <string>

TEST(BTreeConstruct)
{
	BSTree<int, bool> bt;

	// the empty tree has a single 'end' node to accomodate end iterators
	// in the future.
	ASSERT_EQ(bt._head->left, NULL);
	ASSERT_EQ(bt._head->right, NULL);
	ASSERT_EQ(bt._head->parent, NULL);
	ASSERT_EQ(bt._head->data.first, 0);

	ASSERT_EQ(bt._size, 0);
}

TEST(BTreeInsertToEmpty)
{
	BSTree<int, bool> bt;

	ft::pair<ABSTNode<int, bool> *, bool> ret = bt.insert(ft::pair<int, bool>(5, true));

	ASSERT_EQ(bt._size, 1);

	ASSERT_EQ(ret.first, bt._head);
	ASSERT_EQ(ret.second, true);

	ASSERT_EQ(bt._head->left, NULL);
	ASSERT_NEQ(bt._head->right, NULL);
	ASSERT_EQ(bt._head->parent, NULL);
	ASSERT_EQ(bt._head->data.first, 5);

	// 5
	//   x
	ASSERT_EQ(bt._head->bf, 1);

	ABSTNode<int, bool> *endElement = bt._head->right;

	ASSERT_EQ(endElement->left, NULL);
	ASSERT_EQ(endElement->right, NULL);
	ASSERT_NEQ(endElement->parent, NULL);
	ASSERT_EQ(endElement->parent, bt._head);
}

TEST(BTreeEraseHead)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(5, true));
	bt.insert(ft::pair<int, bool>(4, true));

	bt.erase(bt._head);
}

TEST(BTreeEraseHead2)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(5, true));
	// bt.insert(ft::pair<int, bool>(4, true));

	bt.erase(bt._head);

	ASSERT_EQ(bt._head->fake, 1);
	ASSERT_EQ(bt._head->left, NULL);
	ASSERT_EQ(bt._head->right, NULL);
	ASSERT_EQ(bt._head->parent, NULL);
}

TEST(BTreeEraseHead3)
{
	BSTree<int, bool> bt;

	ft::pair<ABSTNode<int, bool> *, bool> ret = bt.insert(ft::pair<int, bool>(5, true));
	ft::pair<ABSTNode<int, bool> *, bool> ret1 = bt.insert(ft::pair<int, bool>(6, true));
	// bt.insert(ft::pair<int, bool>(4, true));

	bt.erase(ret.first);
	bt.erase(ret1.first);

	ASSERT_EQ(bt._head->fake, 1);
	ASSERT_EQ(bt._head->left, NULL);
	ASSERT_EQ(bt._head->right, NULL);
	ASSERT_EQ(bt._head->parent, NULL);
}

// TEST(BinaryTreeHeight)
// {
// 		BSTree<int, bool> bt;

// 	bt.insert(ft::pair<int, bool>(6, true));

// 	ABSTNode<int, bool> *head = bt._head;

// 	head->left = new ABSTNode<int, bool>(NULL, NULL, head, 4, true);
// 	head->left->left = new ABSTNode<int, bool>(NULL, NULL, head->left, 2, true);
// 	head->left->right = new ABSTNode<int, bool>(NULL, NULL, head->left, 5, true);

// 	head->right = new ABSTNode<int, bool>(NULL, NULL, head, 10, true);
// 	head->right->left = new ABSTNode<int, bool>(NULL, NULL, head->right, 8, true);
// 	head->right->right = new ABSTNode<int, bool>(NULL, NULL, head->right, 11, true);
// 	head->right->left->right = new ABSTNode<int, bool>(NULL, NULL, head->right->left, 12, true);
// 	bt._size += 6;

// 	//         6
// 	//   4          10
// 	//2     5     8    11
// 	//              12

// 	ASSERT_EQ(bt.height(bt._head), 3);
// 	ASSERT_EQ(bt.height(bt._head->left), 1);
// }

TEST(BTreeHeight2)
{
	BSTree<int, bool> bt;
	bt._head = new ABSTNode<int, bool>(NULL, NULL, NULL, 4, true); // one node

	ASSERT_EQ(bt.height(bt._head), 1);

	bt._head->right = new ABSTNode<int, bool>(NULL, NULL, bt._head, 4, true); // one node
	ASSERT_EQ(bt.height(bt._head), 2);
	ASSERT_EQ(bt.height(bt._head->left), 0);
	ASSERT_EQ(bt.height(bt._head->right), 1);
}

TEST(BTreeInsertToNotEmptyGreater)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(5, true));

	ft::pair<ABSTNode<int, bool> *, bool> ret = bt.insert(ft::pair<int, bool>(6, true));

	//   6
	// 5    x

	ASSERT_EQ(bt._head->bf, 0);
	ASSERT_EQ(bt._head->left->bf, 0);
	ASSERT_EQ(bt._head->right->bf, 0);

	ASSERT_EQ(bt._size, 2);

	ASSERT_NEQ(bt._head->left, NULL);
	ASSERT_NEQ(bt._head->right, NULL);
	ASSERT_EQ(bt._head->parent, NULL);
	ASSERT_EQ(bt._head->data.first, 6);

	ABSTNode<int, bool> *newElement = bt._head;
	ASSERT_EQ(ret.first, newElement);
	ASSERT_EQ(ret.second, true);
	ASSERT_EQ(newElement->data.first, 6);

	ABSTNode<int, bool> *endElement = bt._head->right;

	ASSERT_EQ(endElement->left, NULL);
	ASSERT_EQ(endElement->right, NULL);
	ASSERT_NEQ(endElement->parent, NULL);
	ASSERT_EQ(endElement->parent, bt._head);
	ASSERT_EQ(endElement->fake, 1);

	ASSERT_EQ(bt._head->left->data.first, 5);
	ASSERT_EQ(bt._head->left->left, NULL);
	ASSERT_EQ(bt._head->left->right, NULL);
	ASSERT_EQ(bt._head->left->parent, bt._head);
}

TEST(BTreeInsertToNotEmptyLess)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(5, true));
	ft::pair<ABSTNode<int, bool> *, bool> ret = bt.insert(ft::pair<int, bool>(2, true));

	//   5
	//2     x

	ASSERT_EQ(bt._head->bf, 0);
	ASSERT_EQ(bt._head->left->bf, 0);
	ASSERT_EQ(bt._head->right->bf, 0);

	ASSERT_EQ(bt._size, 2);

	ASSERT_NEQ(bt._head->left, NULL);
	ASSERT_NEQ(bt._head->right, NULL);
	ASSERT_EQ(bt._head->parent, NULL);
	ASSERT_EQ(bt._head->data.first, 5);

	ABSTNode<int, bool> *newElement = bt._head->left;
	ASSERT_EQ(ret.first, newElement);
	ASSERT_EQ(ret.second, true);
	ASSERT_EQ(newElement->left, NULL);
	ASSERT_EQ(newElement->right, NULL);
	ASSERT_NEQ(newElement->parent, NULL);
	ASSERT_EQ(newElement->parent, bt._head);
	ASSERT_EQ(newElement->data.first, 2);

	ABSTNode<int, bool> *endElement = bt._head->right;

	ASSERT_EQ(endElement->left, NULL);
	ASSERT_EQ(endElement->right, NULL);
	ASSERT_NEQ(endElement->parent, NULL);
	ASSERT_EQ(endElement->parent, bt._head);
}

TEST(BTreeBalanceFactorRightHeavy)
{
	BSTree<int, bool> bt;

	ABSTNode<int, bool> *endNode = bt._head;

	bt._head = new ABSTNode<int, bool>(NULL, NULL, NULL, 5, true);
	bt._head->right = new ABSTNode<int, bool>(NULL, endNode, bt._head, 6, true);
	// bt._head->right = new ABSTNode<int, bool>(NULL, endNode, bt._head->right, 7, true);

	endNode->parent = bt._head->right;

	bt.update_nodes_up_to_root(bt._head->right);

	// 5
	//   6
	//     x

	ASSERT_EQ(bt._head->bf, 2);
	ASSERT_EQ(bt._head->right->bf, 1);
	ASSERT_EQ(bt._head->right->right->bf, 0);
}

TEST(BTreeBalanceFactorLeftHeavy)
{
	BSTree<int, bool> bt;

	ABSTNode<int, bool> *endNode = bt._head;

	bt._head = new ABSTNode<int, bool>(NULL, NULL, NULL, 5, true);
	bt._head->left = new ABSTNode<int, bool>(endNode, NULL, bt._head, 6, true);
	// bt._head->right = new ABSTNode<int, bool>(NULL, endNode, bt._head->right, 7, true);

	endNode->parent = bt._head->left;

	bt.update_nodes_up_to_root(bt._head->left);

	//     5
	//   6
	// x

	ASSERT_EQ(bt._head->bf, -2);
	ASSERT_EQ(bt._head->left->bf, -1);
	ASSERT_EQ(bt._head->left->left->bf, 0);
}


TEST(BTreeInsertExisting)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(5, true));
	ft::pair<ABSTNode<int, bool> *, bool> ret = bt.insert(ft::pair<int, bool>(5, true));

	ASSERT_EQ(bt._size, 1);

	ASSERT_EQ(ret.first, bt._head);
	ASSERT_EQ(ret.second, false);

	ASSERT_EQ(bt._head->left, NULL);
	ASSERT_NEQ(bt._head->right, NULL);
	ASSERT_EQ(bt._head->parent, NULL);
	ASSERT_EQ(bt._head->data.first, 5);

	ABSTNode<int, bool> *endElement = bt._head->right;

	ASSERT_EQ(endElement->left, NULL);
	ASSERT_EQ(endElement->right, NULL);
	ASSERT_NEQ(endElement->parent, NULL);
	ASSERT_EQ(endElement->parent, bt._head);

}

TEST(BtreeDetectEndElement)
{
	BSTree<int, bool> bt;
	bt.insert(ft::pair<int, bool>(5, true));
	bt.insert(ft::pair<int, bool>(2, true));
	bt.insert(ft::pair<int, bool>(3, true));
	std::cout << "---" << std::endl;
	bt.insert(ft::pair<int, bool>(4, true));

	ASSERT_EQ(bt._size, 4);

	std::cout << "HEad: " << bt._head->data.first << std::endl;
	std::cout << "HEad left: " << bt._head->left->data.first << std::endl;
	std::cout << "HEad left left: " << bt._head->left->left->data.first << std::endl;
	std::cout << "HEad left right: " << bt._head->left->right->data.first << std::endl;
	std::cout << "HEad right: " << bt._head->right->data.first << std::endl;

	// ASSERT_EQ(bt._head->height, 2);
	ASSERT_EQ(bt._head->left->height, 1);
	ASSERT_EQ(bt._head->right->height, 0);
	ASSERT_EQ(bt._head->left->left->height, 0);
	// ASSERT_EQ(bt._head->right->right->height, 0);

	// ASSERT_EQ(bt._head->left->data.first, 2);
	// ASSERT_EQ(bt._head->left->right->data.first, 3);
	// ASSERT_EQ(bt._head->left->right->right->data.first, 4);
	// ASSERT_EQ(bt._head->right->data.first, 5);
	// ASSERT_EQ(bt._head->right->right->fake, true);
}

TEST(ABSTNodeImmediateSuccessor)
{
	BSTree<int, bool> bt;
	ft::pair<ABSTNode<int, bool> *, bool> ret = bt.insert(ft::pair<int, bool>(5, true));
	bt.insert(ft::pair<int, bool>(4, true));
	bt.insert(ft::pair<int, bool>(2, true));
	bt.insert(ft::pair<int, bool>(10, true));
	bt.insert(ft::pair<int, bool>(45, true));
	bt.insert(ft::pair<int, bool>(7, true));
	bt.insert(ft::pair<int, bool>(8, true));

	std::map<int, bool> m1;

	// m1.max_size

	ASSERT_EQ(ret.first->immediateSuccessor()->data.first, 7);

}

TEST(ABSTNodeImmediatePredecessor)
{
	BSTree<int, bool> bt;
	ft::pair<ABSTNode<int, bool> *, bool> ret = bt.insert(ft::pair<int, bool>(5, true));
	bt.insert(ft::pair<int, bool>(7, true));
	bt.insert(ft::pair<int, bool>(4, true));
	bt.insert(ft::pair<int, bool>(2, true));
	bt.insert(ft::pair<int, bool>(10, true));
	bt.insert(ft::pair<int, bool>(45, true));

	// std::cout << "Head: " << bt._head->data.first << std::endl;
	// std::cout << "Head->left: " << bt._head->left->data.first << std::endl;
	// std::cout << "Head->left->left: " << bt._head->left->left->data.first << std::endl;
	// std::cout << "Head->left->right: " << bt._head->left->right->data.first << std::endl;
	// std::cout << "Head->right: " << bt._head->right->data.first << std::endl;
	// std::cout << "Head->right->left: " << bt._head->right->left->data.first << std::endl;
	// std::cout << "Head->right->right: " << bt._head->right->right->data.first << std::endl;

	// std::cout << ret.first->parent->data.first << std::endl;
	// std::cout << bt._head->immediatePredecessor()->data.first << std::endl;
	ASSERT_EQ(bt._head->immediatePredecessor()->data.first, 5);

}

TEST(BTreeEraseLeaf)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(6, true));

	ABSTNode<int, bool> *head = bt._head;

	head->left = new ABSTNode<int, bool>(NULL, NULL, head, 4, true);
	head->left->left = new ABSTNode<int, bool>(NULL, NULL, head->left, 2, true);
	head->left->right = new ABSTNode<int, bool>(NULL, NULL, head->left, 5, true);

	head->right = new ABSTNode<int, bool>(NULL, NULL, head, 10, true);
	head->right->left = new ABSTNode<int, bool>(NULL, NULL, head->right, 8, true);
	head->right->right = new ABSTNode<int, bool>(NULL, NULL, head->right, 12, true);
	bt._size += 6;

	//         6
	//   4          10
	//2     5     8     12

	bt.erase(head->right->left); // 8
	ASSERT_EQ(bt._size, 6);

	ASSERT_EQ(bt._head->data.first, 6);
	ASSERT_EQ(bt._head->parent, NULL);

	ASSERT_EQ(bt._head->left->data.first, 4);
	ASSERT_EQ(bt._head->left->parent, bt._head);

	ASSERT_EQ(bt._head->left->left->data.first, 2);
	ASSERT_EQ(bt._head->left->left->parent, bt._head->left);

	ASSERT_EQ(bt._head->left->right->data.first, 5);
	ASSERT_EQ(bt._head->left->right->parent, bt._head->left);
	
	ASSERT_EQ(bt._head->right->data.first, 10);
	ASSERT_EQ(bt._head->right->parent, bt._head);

	ASSERT_EQ(bt._head->right->right->data.first, 12);
	ASSERT_EQ(bt._head->right->right->parent, bt._head->right);

	ASSERT_EQ(bt._head->right->left, NULL);
}

TEST(BTreeEraseOneChild)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(6, true));

	ABSTNode<int, bool> *head = bt._head;

	head->left = new ABSTNode<int, bool>(NULL, NULL, head, 4, true);
	head->left->left = new ABSTNode<int, bool>(NULL, NULL, head->left, 2, true);
	// head->left->right = new ABSTNode<int, bool>(NULL, NULL, head->left, 3, true);

	head->right = new ABSTNode<int, bool>(NULL, NULL, head, 10, true);
	head->right->left = new ABSTNode<int, bool>(NULL, NULL, head->right, 8, true);
	head->right->right = new ABSTNode<int, bool>(NULL, NULL, head->right, 12, true);
	bt._size += 5;

	//         6
	//   4          10
	//2           8     12

	bt.erase(head->left); // 8
	ASSERT_EQ(bt._size, 5);

	ASSERT_EQ(bt._head->data.first, 6);

	ASSERT_EQ(bt._head->left->data.first, 2);
	ASSERT_EQ(bt._head->left->left, NULL);
	ASSERT_EQ(bt._head->left->right, NULL);
	// ASSERT_EQ(bt._head->left->right->data.first, 3);
	
	ASSERT_EQ(bt._head->right->data.first, 10);
	ASSERT_EQ(bt._head->right->right->data.first, 12);
	ASSERT_EQ(bt._head->right->left->data.first, 8);
}

TEST(BTreeEraseTwoChildren)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(6, true));

	ABSTNode<int, bool> *head = bt._head;

	head->left = new ABSTNode<int, bool>(NULL, NULL, head, 4, true);
	head->left->left = new ABSTNode<int, bool>(NULL, NULL, head->left, 2, true);
	head->left->right = new ABSTNode<int, bool>(NULL, NULL, head->left, 5, true);

	head->right = new ABSTNode<int, bool>(NULL, NULL, head, 10, true);
	head->right->left = new ABSTNode<int, bool>(NULL, NULL, head->right, 8, true);
	head->right->right = new ABSTNode<int, bool>(NULL, NULL, head->right, 12, true);
	bt._size += 6;

	//         6
	//   4          10
	//2     5     8     12

	// we want

	//         6
	//   5          10
	//2           8     12

	bt.erase(head->left); // 4
	ASSERT_EQ(bt._size, 6);

	ASSERT_EQ(bt._head->data.first, 6);
	ASSERT_EQ(bt._head->parent, NULL);

	ASSERT_EQ(bt._head->left->data.first, 5);
	ASSERT_EQ(bt._head->left->parent, bt._head);

	ASSERT_EQ(bt._head->left->left->data.first, 2);
	ASSERT_EQ(bt._head->left->left->parent, bt._head->left);

	ASSERT_EQ(bt._head->left->right, NULL);
	// ASSERT_EQ(bt._head->left->right->data.first, 3);
	
	ASSERT_EQ(bt._head->right->data.first, 10);
	ASSERT_EQ(bt._head->right->parent, bt._head);

	ASSERT_EQ(bt._head->right->right->data.first, 12);
	ASSERT_EQ(bt._head->right->right->parent, bt._head->right);

	ASSERT_EQ(bt._head->right->left->data.first, 8);
	ASSERT_EQ(bt._head->right->left->parent, bt._head->right);
}

TEST(BinaryTreeCopy)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(6, true));

	ABSTNode<int, bool> *head = bt._head;

	head->left = new ABSTNode<int, bool>(NULL, NULL, head, 4, true);
	head->left->left = new ABSTNode<int, bool>(NULL, NULL, head->left, 2, true);
	head->left->right = new ABSTNode<int, bool>(NULL, NULL, head->left, 5, true);

	head->right = new ABSTNode<int, bool>(NULL, NULL, head, 10, true);
	head->right->left = new ABSTNode<int, bool>(NULL, NULL, head->right, 8, true);
	head->right->right = new ABSTNode<int, bool>(NULL, NULL, head->right, 12, true);
	bt._size += 6;

	//         6
	//   4          10
	//2     5     8     12

	BSTree<int, bool> bt2 = bt;


	ASSERT_EQ(bt2._size, 7);

	ASSERT_EQ(bt2._head->data.first, 6);
	ASSERT_EQ(bt2._head->parent, NULL);

	ASSERT_EQ(bt2._head->left->data.first, 4);
	ASSERT_EQ(bt2._head->left->parent, bt2._head);

	ASSERT_EQ(bt2._head->left->left->data.first, 2);
	ASSERT_EQ(bt2._head->left->left->parent, bt2._head->left);


	ASSERT_NEQ(bt2._head->left->right, NULL);
	ASSERT_EQ(bt2._head->left->right->parent, bt2._head->left);
	
	ASSERT_EQ(bt2._head->right->data.first, 10);
	ASSERT_EQ(bt2._head->right->parent, bt2._head);

	ASSERT_EQ(bt2._head->right->right->data.first, 12);
	ASSERT_EQ(bt2._head->right->right->parent, bt2._head->right);

	// ASSERT_EQ(bt2._head->right->left->data.first, 8);
	// ASSERT_EQ(bt2._head->right->left->parent, bt2._head->right);

	// std::cout << "bt head: " << bt._head << std::endl;
	// std::cout << "bt2 head: " << bt2._head << std::endl;
}


TEST(BinaryTreeSwapContent)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(6, true));

	ABSTNode<int, bool> *head = bt._head;

	head->left = new ABSTNode<int, bool>(NULL, NULL, head, 4, true);
	head->left->left = new ABSTNode<int, bool>(NULL, NULL, head->left, 2, true);
	head->left->right = new ABSTNode<int, bool>(NULL, NULL, head->left, 5, true);

	head->right = new ABSTNode<int, bool>(NULL, NULL, head, 10, true);
	head->right->left = new ABSTNode<int, bool>(NULL, NULL, head->right, 8, true);
	head->right->right = new ABSTNode<int, bool>(NULL, NULL, head->right, 12, true);
	bt._size += 6;

	//         6
	//   4          10
	//2     5     8     12

	BSTree<int, bool> bt2;

	bt2.insert(ft::pair<int, bool>(7, true));

	ABSTNode<int, bool> *head2 = bt2._head;

	head2->left = new ABSTNode<int, bool>(NULL, NULL, head2, 5, true);
	head2->left->left = new ABSTNode<int, bool>(NULL, NULL, head2->left, 4, true);
	head2->left->right = new ABSTNode<int, bool>(NULL, NULL, head2->left, 6, true);

	head2->right = new ABSTNode<int, bool>(NULL, NULL, head2, 11, true);
	head2->right->left = new ABSTNode<int, bool>(NULL, NULL, head2->right, 9, true);
	head2->right->right = new ABSTNode<int, bool>(NULL, NULL, head2->right, 13, true);
	bt2._size += 6;


	//         7
	//   5          11
	//3     6     9     13



	bt.swap_content(bt2);


	ASSERT_EQ(bt2._size, 7);

	ASSERT_EQ(bt2._head->data.first, 6);
	ASSERT_EQ(bt2._head->parent, NULL);

	ASSERT_EQ(bt2._head->left->data.first, 4);
	ASSERT_EQ(bt2._head->left->parent, bt2._head);

	ASSERT_EQ(bt2._head->left->left->data.first, 2);
	ASSERT_EQ(bt2._head->left->left->parent, bt2._head->left);


	ASSERT_NEQ(bt2._head->left->right, NULL);
	ASSERT_EQ(bt2._head->left->right->parent, bt2._head->left);
	
	ASSERT_EQ(bt2._head->right->data.first, 10);
	ASSERT_EQ(bt2._head->right->parent, bt2._head);

	ASSERT_EQ(bt2._head->right->right->data.first, 12);
	ASSERT_EQ(bt2._head->right->right->parent, bt2._head->right);

	// ASSERT_EQ(bt2._head->right->left->data.first, 8);
	// ASSERT_EQ(bt2._head->right->left->parent, bt2._head->right);

	// std::cout << "bt head: " << bt._head << std::endl;
	// std::cout << "bt2 head: " << bt2._head << std::endl;
}


TEST(BinaryTreeClear)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(6, true));

	ABSTNode<int, bool> *head = bt._head;

	head->left = new ABSTNode<int, bool>(NULL, NULL, head, 4, true);
	head->left->left = new ABSTNode<int, bool>(NULL, NULL, head->left, 2, true);
	head->left->right = new ABSTNode<int, bool>(NULL, NULL, head->left, 5, true);

	head->right = new ABSTNode<int, bool>(NULL, NULL, head, 10, true);
	head->right->left = new ABSTNode<int, bool>(NULL, NULL, head->right, 8, true);
	head->right->right = new ABSTNode<int, bool>(NULL, NULL, head->right, 12, true);
	bt._size += 6;

	bt.clear();

	ASSERT_EQ(bt._size, 0);

	bt.insert(ft::pair<int, bool>(6, true));

	ASSERT_EQ(bt._size, 1);
}

TEST(BinaryTreeFind)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(6, true));

	ABSTNode<int, bool> *head = bt._head;

	head->left = new ABSTNode<int, bool>(NULL, NULL, head, 4, true);
	head->left->left = new ABSTNode<int, bool>(NULL, NULL, head->left, 2, true);
	head->left->right = new ABSTNode<int, bool>(NULL, NULL, head->left, 5, true);

	head->right = new ABSTNode<int, bool>(NULL, NULL, head, 10, true);
	head->right->left = new ABSTNode<int, bool>(NULL, NULL, head->right, 8, true);
	head->right->right = new ABSTNode<int, bool>(NULL, NULL, head->right, 12, true);
	bt._size += 6;

	// bt.clear();

	ASSERT_EQ(bt.find(4)->data.first, 4);
	ASSERT_EQ(bt.find(2)->data.first, 2);
	ASSERT_EQ(bt.find(5)->data.first, 5);
	ASSERT_EQ(bt.find(10)->data.first, 10);
	ASSERT_EQ(bt.find(8)->data.first, 8);
	ASSERT_EQ(bt.find(12)->data.first, 12);
	ASSERT_EQ(bt.find(6)->data.first, 6);
	ASSERT_EQ(bt.find(42), NULL);
}


TEST(BinaryTreeLeftRot)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(4, true));

	ABSTNode<int, bool> *head = bt._head;

	head->right = new ABSTNode<int, bool>(NULL, NULL, head, 6, true);
	head->right->right = new ABSTNode<int, bool>(NULL, NULL, head->right, 8, true);
	bt._size += 2;

	// 4
	//   6
	//     8

	// ASSERT_EQ(bt.height(bt._head), 3);
	// ASSERT_EQ(bt.height(bt._head->left), 1);
	bt._head = bt.left_rotate(bt._head);

	ASSERT_EQ(bt._head->data.first, 6);
	ASSERT_EQ(bt._head->parent, NULL);


	ASSERT_EQ(bt._head->left->data.first, 4);
	ASSERT_EQ(bt._head->left->parent, bt._head);

	ASSERT_EQ(bt._head->right->data.first, 8);
	ASSERT_EQ(bt._head->right->parent, bt._head);
}

TEST(BinaryTreeRightRot)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(8, true));

	ABSTNode<int, bool> *head = bt._head;

	head->left = new ABSTNode<int, bool>(NULL, NULL, head, 6, true);
	head->left->left = new ABSTNode<int, bool>(NULL, NULL, head->left, 4, true);
	bt._size += 2;

	//      8
	//   6
	//4    

	// ASSERT_EQ(bt.height(bt._head), 3);
	// ASSERT_EQ(bt.height(bt._head->left), 1);
	bt._head = bt.right_rotate(bt._head);

	ASSERT_EQ(bt._head->data.first, 6);
	ASSERT_EQ(bt._head->parent, NULL);


	ASSERT_EQ(bt._head->left->data.first, 4);
	ASSERT_EQ(bt._head->left->parent, bt._head);

	ASSERT_EQ(bt._head->right->data.first, 8);
	ASSERT_EQ(bt._head->right->parent, bt._head);
}


TEST(BinaryTreeRightLeftRot)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(4, true));

	ABSTNode<int, bool> *head = bt._head;

	head->right = new ABSTNode<int, bool>(NULL, NULL, head, 8, true);
	head->right->left = new ABSTNode<int, bool>(NULL, NULL, head->right, 6, true);
	bt._size += 2;

	// 4
	//   8
	// 6   

	// ASSERT_EQ(bt.height(bt._head), 3);
	// ASSERT_EQ(bt.height(bt._head->left), 1);
	bt._head = bt.right_left_rotate(bt._head);

	// bt._head->right = bt.right_rotate(bt._head->right);
	// bt._head = bt.left_rotate(bt._head);

	ASSERT_EQ(bt._head->data.first, 6);
	ASSERT_EQ(bt._head->parent, NULL);


	ASSERT_EQ(bt._head->left->data.first, 4);
	ASSERT_EQ(bt._head->left->parent, bt._head);

	ASSERT_EQ(bt._head->right->data.first, 8);
	ASSERT_EQ(bt._head->right->parent, bt._head);
}


// TEST(BTreeInsertGrowingWtf)
// {
// 	BSTree<int, bool> bt;

// 	bt.insert(ft::pair<int, bool>(4, true));
// 	bt.insert(ft::pair<int, bool>(5, true));
	
// 	bt.insert(ft::pair<int, bool>(6, true));

// 	std::cout << " --- " << std::endl;

// 	std::cout << "Head: " << bt._head->data.first << std::endl;
// 	std::cout << "Head left: " << bt._head->left->data.first << std::endl;
// 	std::cout << "Head right: " << bt._head->right->data.first << std::endl;
// 	std::cout << "Head right right: " << bt._head->right->right->data.first << std::endl;

// 	ASSERT_NEQ(bt._head->right->right, NULL)
// }


TEST(BTreeInsertGrowingHeightAndBalance)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(4, true));
	bt.insert(ft::pair<int, bool>(5, true));
	
	bt.insert(ft::pair<int, bool>(6, true));
	ASSERT_EQ(bt._head->height, 2);
	bt.print();
	std::cout << " --- " << std::endl;

	bt.insert(ft::pair<int, bool>(7, true));




	std::cout << "Head: " << bt._head->data.first << std::endl;
	std::cout << "Head left: " << bt._head->left->data.first << std::endl;
	std::cout << "Head right: " << bt._head->right->data.first << std::endl;
	std::cout << "Head right right: " << bt._head->right->right->data.first << std::endl;


	// std::cout << "Head left left: " << bt._head->left->left->data.first << std::endl;
	// std::cout << "Head right left: " << bt._head->right->left->data.first << std::endl;
	// std::cout << "Head right right: " << bt._head->right->left->data.first << std::endl;
	
	std::cout << " --- " << std::endl;


	std::cout << "Head: " << bt._head->data.first << std::endl;
	std::cout << "Head left: " << bt._head->left->data.first << std::endl;
	std::cout << "Head right: " << bt._head->right->data.first << std::endl;
	std::cout << "Head right left: " << bt._head->right->left->data.first << std::endl;
	std::cout << "Head right right: " << bt._head->right->right->data.first << std::endl;
	
	ASSERT_EQ(bt._head->height, 2);
	ASSERT_EQ(bt._head->left->height, 0);
	ASSERT_EQ(bt._head->right->height, 1);
	// ASSERT_EQ(bt._head->left->left->height, 0);
	ASSERT_EQ(bt._head->right->right->height, 0);
	ASSERT_EQ(bt._head->right->left->height, 0);

	ASSERT_EQ(bt._head->bf, 1);
	ASSERT_EQ(bt._head->left->bf, 0);
	// ASSERT_EQ(bt._head->left->left->bf, 0);
	ASSERT_EQ(bt._head->right->bf, 0);
	ASSERT_EQ(bt._head->right->right->bf, 0);
	ASSERT_EQ(bt._head->right->left->bf, 0);
}


// TODO check if rebalancing doesn't move the 'end' pointer

int main(void)
{
	run_tests();

	std::cout << "ms: " << std::map<int, bool>::node << std::endl;
}