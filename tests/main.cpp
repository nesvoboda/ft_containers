#include "elementest.hpp"


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// BINARY TREE TESTS
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include "../binary_tree.hpp"

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
	bt.delete_node(bt._head);
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

	ASSERT_EQ(bt._head->left->height, 1);
	ASSERT_EQ(bt._head->right->height, 0);
	ASSERT_EQ(bt._head->left->left->height, 0);
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

	ASSERT_EQ(ret.first->immediateSuccessor()->data.first, 7);

}

TEST(ABSTNodeImmediatePredecessor)
{
	BSTree<int, bool> bt;
	bt.insert(ft::pair<int, bool>(5, true));
	bt.insert(ft::pair<int, bool>(7, true));
	bt.insert(ft::pair<int, bool>(4, true));
	bt.insert(ft::pair<int, bool>(2, true));
	bt.insert(ft::pair<int, bool>(10, true));
	bt.insert(ft::pair<int, bool>(45, true));

	ASSERT_EQ(bt._head->immediatePredecessor()->data.first, 5);

}

TEST(BTreeEraseLeaf)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(6, true));
	bt.insert(ft::pair<int, bool>(4, true));
	bt.insert(ft::pair<int, bool>(2, true));
	bt.insert(ft::pair<int, bool>(5, true));
	bt.insert(ft::pair<int, bool>(10, true));
	bt.insert(ft::pair<int, bool>(8, true));
	bt.insert(ft::pair<int, bool>(12, true));

	//         6
	//   4          10
	//2     5     8     12

	bt.erase(bt._head->right->left); // 8
	
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
	bt.insert(ft::pair<int, bool>(4, true));
	bt.insert(ft::pair<int, bool>(2, true));
	bt.insert(ft::pair<int, bool>(10, true));
	bt.insert(ft::pair<int, bool>(8, true));
	bt.insert(ft::pair<int, bool>(12, true));

	bt.print();

	//         6
	//   4          10
	//2           8     12

	bt.erase(bt._head->left); // 4

	ASSERT_EQ(bt._size, 5);

	ASSERT_EQ(bt._head->data.first, 6);

	ASSERT_EQ(bt._head->left->data.first, 2);
	ASSERT_EQ(bt._head->left->left, NULL);
	ASSERT_EQ(bt._head->left->right, NULL);
	
	ASSERT_EQ(bt._head->right->data.first, 10);
	ASSERT_EQ(bt._head->right->right->data.first, 12);
	ASSERT_EQ(bt._head->right->left->data.first, 8);
}

TEST(BTreeEraseTwoChildren)
{
	BSTree<int, bool> bt;


	bt.insert(ft::pair<int, bool>(6, true));
	bt.insert(ft::pair<int, bool>(4, true));
	bt.insert(ft::pair<int, bool>(2, true));
	bt.insert(ft::pair<int, bool>(5, true));
	bt.insert(ft::pair<int, bool>(10, true));
	bt.insert(ft::pair<int, bool>(8, true));
	bt.insert(ft::pair<int, bool>(12, true));

	//         6
	//   4          10
	//2     5     8     12

	// we want

	//         6
	//   5          10
	//2           8     12

	bt.erase(bt._head->left); // 4
	ASSERT_EQ(bt._size, 6);

	ASSERT_EQ(bt._head->data.first, 6);
	ASSERT_EQ(bt._head->parent, NULL);

	ASSERT_EQ(bt._head->left->data.first, 5);
	ASSERT_EQ(bt._head->left->parent, bt._head);

	ASSERT_EQ(bt._head->left->left->data.first, 2);
	ASSERT_EQ(bt._head->left->left->parent, bt._head->left);

	ASSERT_EQ(bt._head->left->right, NULL);
	
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
	bt.insert(ft::pair<int, bool>(4, true));
	bt.insert(ft::pair<int, bool>(2, true));
	bt.insert(ft::pair<int, bool>(5, true));
	bt.insert(ft::pair<int, bool>(10, true));
	bt.insert(ft::pair<int, bool>(8, true));
	bt.insert(ft::pair<int, bool>(12, true));

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
	bt.insert(ft::pair<int, bool>(4, true));
	bt.insert(ft::pair<int, bool>(2, true));
	bt.insert(ft::pair<int, bool>(5, true));
	bt.insert(ft::pair<int, bool>(10, true));
	bt.insert(ft::pair<int, bool>(8, true));
	bt.insert(ft::pair<int, bool>(12, true));

	//         6
	//   4          10
	//2     5     8     12

	BSTree<int, bool> bt2;

	bt2.insert(ft::pair<int, bool>(7, true));

	
	bt2.insert(ft::pair<int, bool>(7, true));
	bt2.insert(ft::pair<int, bool>(5, true));
	bt2.insert(ft::pair<int, bool>(3, true));
	bt2.insert(ft::pair<int, bool>(6, true));
	bt2.insert(ft::pair<int, bool>(11, true));
	bt2.insert(ft::pair<int, bool>(9, true));
	bt2.insert(ft::pair<int, bool>(13, true));


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
	bt.insert(ft::pair<int, bool>(4, true));
	bt.insert(ft::pair<int, bool>(2, true));
	bt.insert(ft::pair<int, bool>(5, true));
	bt.insert(ft::pair<int, bool>(10, true));
	bt.insert(ft::pair<int, bool>(8, true));
	bt.insert(ft::pair<int, bool>(12, true));
	bt.clear();

	ASSERT_EQ(bt._size, 0);

	bt.insert(ft::pair<int, bool>(6, true));

	ASSERT_EQ(bt._size, 1);
}

TEST(BinaryTreeFind)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(6, true));
	bt.insert(ft::pair<int, bool>(4, true));
	bt.insert(ft::pair<int, bool>(2, true));
	bt.insert(ft::pair<int, bool>(5, true));
	bt.insert(ft::pair<int, bool>(10, true));
	bt.insert(ft::pair<int, bool>(8, true));
	bt.insert(ft::pair<int, bool>(12, true));

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

	bt.delete_node(bt._head->right); // we don't need the end element in this test

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

	// bt.delete_node(bt._head->right); // we don't need the end element in this test

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
	bt.delete_node(bt._head->right); // we don't need the end element in this test

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

TEST(BTreeInsertGrowingHeightAndBalance)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(4, true));
	bt.insert(ft::pair<int, bool>(5, true));
	
	bt.insert(ft::pair<int, bool>(6, true));
	ASSERT_EQ(bt._head->height, 2);
	std::cout << " --- " << std::endl;

	bt.insert(ft::pair<int, bool>(7, true));
	
	ASSERT_EQ(bt._head->height, 2);
	ASSERT_EQ(bt._head->left->height, 0);
	ASSERT_EQ(bt._head->right->height, 1);
	ASSERT_EQ(bt._head->right->right->height, 0);
	ASSERT_EQ(bt._head->right->left->height, 0);

	ASSERT_EQ(bt._head->bf, 1);
	ASSERT_EQ(bt._head->left->bf, 0);
	ASSERT_EQ(bt._head->right->bf, 0);
	ASSERT_EQ(bt._head->right->right->bf, 0);
	ASSERT_EQ(bt._head->right->left->bf, 0);
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// MAP TESTS
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// PAIR 
///////////////////////////////////////////////////////////////////////////////
TEST(pairDefaultConstruct)
{
	ft::pair<int, float> p1;
	std::pair<int, float> sp1;

	ASSERT_EQ(p1.first, sp1.first);
	ASSERT_EQ(p1.second, sp1.second);
}

TEST(pairCopyConstruct)
{
	ft::pair<int, float> p1;
	std::pair<int, float> sp1;

	ft::pair<int, float> p2(p1);
	std::pair<int, float> sp2(sp1);

	ASSERT_EQ(p2.first, sp2.first);
	ASSERT_EQ(p2.second, sp2.second);
}

TEST(pairInitializationConstructor)
{
	ft::pair<int, float> p1(42, 21.0);
	std::pair<int, float> sp1(42, 21.0);

	ASSERT_EQ(p1.first, sp1.first);
	ASSERT_EQ(p1.second, sp1.second);
}

TEST(pairCopyConstruct2)
{
	ft::pair<int, float> p1(42, 21.0);
	std::pair<int, float> sp1(42, 21.0);

	ft::pair<int, float> p2(p1);
	std::pair<int, float> sp2(sp1);

	ASSERT_EQ(p2.first, sp2.first);
	ASSERT_EQ(p2.second, sp2.second);
}

TEST(pairEqualityOperator)
{
	ft::pair<int, float> p1(42, 21.0);
	std::pair<int, float> sp1(42, 21.0);

	ft::pair<int, float> p2;
	std::pair<int, float> sp2;

	p2 = p1;
	sp2 = sp1;

	ASSERT_EQ(p2.first, sp2.first);
	ASSERT_EQ(p2.second, sp2.second);
}

TEST(PairEqual)
{
	ft::pair<int, float> p1(42, 21.0);
	ft::pair<int, float> p2(42, 21.0);
	std::pair<int, float> sp1(42, 21.0);
	std::pair<int, float> sp2(42, 21.0);

	ASSERT_EQ((p1 == p2), (sp1 == sp2));
}

TEST(PairEqualNotEqual)
{
	ft::pair<int, float> p1(42, 21.0);
	ft::pair<int, float> p2(42, 22.0);
	std::pair<int, float> sp1(42, 21.0);
	std::pair<int, float> sp2(42, 22.0);

	ASSERT_EQ((p1 == p2), (sp1 == sp2));
}

TEST(PairLessMoreWhenEqual)
{
	ft::pair<int, float> p1(42, 21.0);
	ft::pair<int, float> p2(42, 21.0);
	std::pair<int, float> sp1(42, 21.0);
	std::pair<int, float> sp2(42, 21.0);

	ASSERT_EQ((p1 < p2), (sp1 < sp2));
	ASSERT_EQ((p1 <= p2), (sp1 <= sp2));

	ASSERT_EQ((p1 > p2), (sp1 > sp2));
	ASSERT_EQ((p1 >= p2), (sp1 >= sp2));
}

TEST(PairLessMoreWhenNotEqual)
{
	ft::pair<int, float> p1(42, 21.0);
	ft::pair<int, float> p2(42, 22.0);
	std::pair<int, float> sp1(42, 21.0);
	std::pair<int, float> sp2(42, 22.0);

	ASSERT_EQ((p1 < p2), (sp1 < sp2));
	ASSERT_EQ((p1 <= p2), (sp1 <= sp2));

	ASSERT_EQ((p1 > p2), (sp1 > sp2));
	ASSERT_EQ((p1 >= p2), (sp1 >= sp2));
}

TEST(PairLessMoreWhenEqualReverseOrder)
{
	ft::pair<int, float> p1(21.0, 42);
	ft::pair<int, float> p2(21.0, 42);
	std::pair<int, float> sp1(21.0, 42);
	std::pair<int, float> sp2(21.0, 42);

	ASSERT_EQ((p1 < p2), (sp1 < sp2));
	ASSERT_EQ((p1 <= p2), (sp1 <= sp2));

	ASSERT_EQ((p1 > p2), (sp1 > sp2));
	ASSERT_EQ((p1 >= p2), (sp1 >= sp2));
}

TEST(PairLessMoreWhenNotEqualReverseOrder)
{
	ft::pair<int, float> p1(21.0, 42);
	ft::pair<int, float> p2(22.0, 42);
	std::pair<int, float> sp1(21.0, 42);
	std::pair<int, float> sp2(22.0, 42);

	ASSERT_EQ((p1 < p2), (sp1 < sp2));
	ASSERT_EQ((p1 <= p2), (sp1 <= sp2));

	ASSERT_EQ((p1 > p2), (sp1 > sp2));
	ASSERT_EQ((p1 >= p2), (sp1 >= sp2));
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// MAP TESTS
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include "../map.hpp"

TEST(MapInsertEmpty)
{
	ft::map<std::string, int> m1;
	std::map<std::string, int> sm1;

	ft::pair<std::string, int> val1("42", 42);
	std::pair<std::string, int> sval1("42", 42);

	ft::pair<ft::map<std::string, int>::iterator, bool> r1 = m1.insert(val1);
	std::pair<std::map<std::string, int>::iterator, bool> sr1 = sm1.insert(sval1);

	ASSERT_EQ(r1.second, sr1.second);
	ASSERT_EQ(m1.size(), sm1.size());
}

TEST(MapInsertNotEmptyDifferent)
{
	ft::map<std::string, int> m1;
	std::map<std::string, int> sm1;

	ft::pair<std::string, int> val1("42", 42);
	std::pair<std::string, int> sval1("42", 42);

	ft::pair<ft::map<std::string, int>::iterator, bool> r1 = m1.insert(val1);
	std::pair<std::map<std::string, int>::iterator, bool> sr1 = sm1.insert(sval1);

	ASSERT_EQ(r1.second, sr1.second);
	ASSERT_EQ(m1.size(), sm1.size());

	ft::pair<std::string, int> val2("21", 42);
	std::pair<std::string, int> sval2("21", 42);

	ft::pair<ft::map<std::string, int>::iterator, bool> r2 = m1.insert(val2);
	std::pair<std::map<std::string, int>::iterator, bool> sr2 = sm1.insert(sval2);


	ASSERT_EQ(r2.second, sr2.second);
	ASSERT_EQ(m1.size(), sm1.size());
}

TEST(MapInsertNotEmptySame)
{
	ft::map<std::string, int> m1;
	std::map<std::string, int> sm1;

	ft::pair<std::string, int> val1("42", 42);
	std::pair<std::string, int> sval1("42", 42);

	ft::pair<ft::map<std::string, int>::iterator, bool> r1 = m1.insert(val1);
	std::pair<std::map<std::string, int>::iterator, bool> sr1 = sm1.insert(sval1);

	ASSERT_EQ(r1.second, sr1.second);
	ASSERT_EQ(m1.size(), sm1.size());

	ft::pair<std::string, int> val2("42", 42);
	std::pair<std::string, int> sval2("42", 42);

	ft::pair<ft::map<std::string, int>::iterator, bool> r2 = m1.insert(val2);
	std::pair<std::map<std::string, int>::iterator, bool> sr2 = sm1.insert(sval2);


	ASSERT_EQ(r2.second, sr2.second);
	ASSERT_EQ(m1.size(), sm1.size());
}

TEST(MapEmpty)
{
	ft::map<std::string, int> m1;
	std::map<std::string, int> sm1;


	ASSERT_EQ(m1.empty(), sm1.empty());

	m1.insert(ft::pair<std::string, int>("42", 42));
	sm1.insert(std::pair<std::string, int>("42", 42));

	ASSERT_EQ(m1.empty(), sm1.empty());
}


TEST(MapBrackets)
{
	ft::map<std::string, int> m1;
	std::map<std::string, int> sm1;

	m1["42"] = 21;
	sm1["42"] = 21;

	ASSERT_EQ(m1["42"], sm1["42"]);

	m1["42"] = 42;
	sm1["42"] = 42;

	ASSERT_EQ(m1["42"], sm1["42"]);
}

TEST(MapIteratorConstructible)
{
	ft::map<std::string, int>::iterator iter1;
}


TEST(MapIteratorCopyConstructible)
{
	ft::map<std::string, int>::iterator iter1;
	ft::map<std::string, int>::iterator iter2(iter1);
}

TEST(MapIteratorCopyAssignable)
{
	ft::map<std::string, int>::iterator iter1;
	ft::map<std::string, int>::iterator iter2;

	iter2 = iter1;
}

TEST(MapConstIteratorConstructible)
{
	ft::map<std::string, int>::const_iterator iter1;
}


TEST(MapConstIteratorCopyConstructible)
{
	ft::map<std::string, int>::const_iterator iter1;
	ft::map<std::string, int>::const_iterator iter2(iter1);
}

TEST(MapConstIteratorCopyAssignable)
{
	ft::map<std::string, int>::const_iterator iter1;
	ft::map<std::string, int>::const_iterator iter2;

	iter2 = iter1;
}

TEST(MapBeginAndIterComparison)
{
	ft::map<std::string, int> m1;
	std::map<std::string, int> sm1;

	ft::map<std::string, int>::iterator it1 = m1.begin();

	m1["42"] = 21;
	sm1["42"] = 21;

	ft::map<std::string, int>::iterator it2 = m1.begin();
	std::map<std::string, int>::iterator sit2 = sm1.begin();

	ft::map<std::string, int>::iterator it0;
	std::map<std::string, int>::iterator sit0;

	ASSERT_EQ((*it2).first, (*sit2).first);
	ASSERT_EQ((*it2).second, (*sit2).second);

	CHECK_NEQ(it1, it2);
	CHECK_NEQ(it1, it0);
}

TEST(MapIteratorArrow)
{
	ft::map<std::string, int> m1;
	std::map<std::string, int> sm1;

	m1["42"] = 21;
	sm1["42"] = 21;

	ft::map<std::string, int>::iterator it2 = m1.begin();
	std::map<std::string, int>::iterator sit2 = sm1.begin();

	ASSERT_EQ(it2->first, sit2->first);

	// ft::map<std::string, int>::iterator it0;
	// std::map<std::string, int>::iterator sit0;

	// ASSERT_EQ((*it2).first, (*sit2).first);
	// ASSERT_EQ((*it2).second, (*sit2).second);

	// CHECK_NEQ(it1, it2);
	// CHECK_NEQ(it1, it0);
}

TEST(MapIteratorPlusPlusInt)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::iterator it2 = m1.begin();
	std::map<int, bool>::iterator sit2 = sm1.begin();

	while (sit2 != sm1.end())
	{
		// std::cout << "it2: " << it2->first << ", sit2: " << sit2->first << std::endl;
		ASSERT_EQ((it2++)->first, (sit2++)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	CHECK_EQ(it2, m1.end());
	CHECK_EQ(it0, m1.end());

}

TEST(MapIteratorPlusPlus)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::iterator it2 = m1.begin();
	std::map<int, bool>::iterator sit2 = sm1.begin();

	while (sit2 != (--sm1.end()))
	{
		ASSERT_EQ((++it2)->first, (++sit2)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	// CHECK_EQ(it2, m1.end());
	// CHECK_EQ(it0, m1.end());

}

TEST(MapConstIteratorPlusPlusInt)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::const_iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::const_iterator it2 = m1.begin();
	std::map<int, bool>::const_iterator sit2 = sm1.begin();

	while (sit2 != sm1.end())
	{
		ASSERT_EQ((it2++)->first, (sit2++)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	CHECK_EQ(it2, m1.end());
	CHECK_EQ(it0, m1.end());

}

TEST(MapConstIteratorPlusPlus)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::const_iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::const_iterator it2 = m1.begin();
	std::map<int, bool>::const_iterator sit2 = sm1.begin();

	while (sit2 != (--sm1.end()))
	{
		ASSERT_EQ((++it2)->first, (++sit2)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	// CHECK_EQ(it2, m1.end());
	// CHECK_EQ(it0, m1.end());

}

TEST(MapReverseIteratorPlusPlusInt)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::reverse_iterator it0 = m1.rbegin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::reverse_iterator it2 = m1.rbegin();
	std::map<int, bool>::reverse_iterator sit2 = sm1.rbegin();

	while (sit2 != sm1.rend())
	{
		ASSERT_EQ((it2++)->first, (sit2++)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	CHECK_EQ(it2, m1.rend());
	// CHECK_EQ(it0, m1.rend());

}

TEST(MapReverseIteratorPlusPlus)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::reverse_iterator it0 = m1.rbegin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::reverse_iterator it2 = m1.rbegin();
	std::map<int, bool>::reverse_iterator sit2 = sm1.rbegin();

	while (sit2 != (--sm1.rend()))
	{
		ASSERT_EQ((++it2)->first, (++sit2)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	// CHECK_EQ(it2, m1.end());
	// CHECK_EQ(it0, m1.end());

}

TEST(MapEraseSingle)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::iterator it2 = m1.begin();
	std::map<int, bool>::iterator sit2 = sm1.begin();

	m1.erase(++m1.begin());
	sm1.erase(++sm1.begin());

	while (sit2 != sm1.end())
	{
		ASSERT_EQ((it2++)->first, (sit2++)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	CHECK_EQ(it2, m1.end());
	CHECK_EQ(it0, m1.end());

}

TEST(MapEraseByKey)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::iterator it2 = m1.begin();
	std::map<int, bool>::iterator sit2 = sm1.begin();

	ASSERT_EQ(m1.erase(7), sm1.erase(7));

	while (sit2 != sm1.end())
	{
		ASSERT_EQ((it2++)->first, (sit2++)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	CHECK_EQ(it2, m1.end());
	CHECK_EQ(it0, m1.end());

}

TEST(MapEraseByKeyMissing)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::iterator it2 = m1.begin();
	std::map<int, bool>::iterator sit2 = sm1.begin();

	ASSERT_EQ(m1.erase(42), sm1.erase(42));

	while (sit2 != sm1.end())
	{
		ASSERT_EQ((it2++)->first, (sit2++)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	CHECK_EQ(it2, m1.end());
	CHECK_EQ(it0, m1.end());

}

TEST(MapEraseRange)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	// m1.insert(ft::pair<int, bool>(6, true));
	// m1.insert(ft::pair<int, bool>(7, true));
	// m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	// sm1.insert(std::pair<int, bool>(6, true));
	// sm1.insert(std::pair<int, bool>(7, true));
	// sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));


	m1.erase(m1.begin(), --m1.end());
	// m1.erase(++m1.begin());
	// for (ft::map<int, bool>::iterator it = m1.begin(); it != ++++++++m1.begin(); it++)
		// std::cout << it->first << std::endl;
	sm1.erase(sm1.begin(), --sm1.end());
	// sm1.erase(++sm1.begin());

	ft::map<int, bool>::iterator it2 = m1.begin();
	std::map<int, bool>::iterator sit2 = sm1.begin();
	while (sit2 != sm1.end())
	{
		std::cout << it2->first << std::endl;
		ASSERT_EQ((it2++)->first, (sit2++)->first);
		// std::cout << (sit2++)->first << std::endl;
	}
	CHECK_EQ(it2, m1.end());


	// CHECK_EQ(it0, m1.end());

}

TEST(MapEraseRange2)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	// m1.insert(ft::pair<int, bool>(6, true));
	// m1.insert(ft::pair<int, bool>(7, true));
	// m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	// sm1.insert(std::pair<int, bool>(6, true));
	// sm1.insert(std::pair<int, bool>(7, true));
	// sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));


	m1.erase(m1.begin(), m1.end());
	// m1.erase(++m1.begin());
	// for (ft::map<int, bool>::iterator it = m1.begin(); it != ++++++++m1.begin(); it++)
		// std::cout << it->first << std::endl;
	sm1.erase(sm1.begin(), sm1.end());
	// sm1.erase(++sm1.begin());

	ft::map<int, bool>::iterator it2 = m1.begin();
	std::map<int, bool>::iterator sit2 = sm1.begin();
	while (sit2 != sm1.end())
	{
		std::cout << it2->first << std::endl;
		ASSERT_EQ((it2++)->first, (sit2++)->first);
		// std::cout << (sit2++)->first << std::endl;
	}
	CHECK_EQ(it2, m1.end());


	// CHECK_EQ(it0, m1.end());

}


TEST(MapSwap)
{
	ft::map<int, bool> m1;
	ft::map<int, bool> m2;
	std::map<int, bool> sm1;
	std::map<int, bool> sm2;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	m2.insert(ft::pair<int, bool>(-5, true));
	m2.insert(ft::pair<int, bool>(40, true));
	m2.insert(ft::pair<int, bool>(-92, true));


	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	sm2.insert(std::pair<int, bool>(-5, true));
	sm2.insert(std::pair<int, bool>(40, true));
	sm2.insert(std::pair<int, bool>(-92, true));


	
	m1.swap(m2);
	sm1.swap(sm2);


	ft::map<int, bool>::iterator it2 = m2.begin();
	std::map<int, bool>::iterator sit2 = sm2.begin();

	ft::map<int, bool>::iterator it1 = m1.begin();
	std::map<int, bool>::iterator sit1 = sm1.begin();

	// std::cout << "it1 parent " << (it1++)._ptr->parent->data.first << std::endl;
	// std::cout << "it1 parent " << it1._ptr->parent->data.first << std::endl;

	while (sit1 != sm1.end())
	{
		ASSERT_EQ((it1++)->first, (sit1++)->first);
		// std::cout << (sit1++)->first << std::endl;
	// 	// std::cout << (it1++)->first << std::endl;
	}

	while (sit2 != sm2.end())
	{
		ASSERT_EQ((it2++)->first, (sit2++)->first);
	// 	// std::cout << (sit2++)->first << std::endl;
	}
	// ASSERT_EQ(it2->first, sit2->first);
	// CHECK_EQ(it2, m1.end());
	// CHECK_EQ(it0, m1.end());

}

TEST(MapClear)
{
	ft::map<int, bool> m1;

	std::map<int, bool> sm1;


	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	m1.clear();
	sm1.clear();

	ASSERT_EQ(m1.size(), sm1.size());
	ASSERT_EQ(m1.empty(), sm1.empty());

	m1.insert(ft::pair<int, bool>(-21, true));
	sm1.insert(std::pair<int, bool>(-21, true));

	ASSERT_EQ(m1.size(), sm1.size());
	ASSERT_EQ(m1.empty(), sm1.empty());

	ft::map<int, bool>::iterator it1 = m1.begin();
	std::map<int, bool>::iterator sit1 = sm1.begin();

	while (sit1 != sm1.end())
	{
		ASSERT_EQ((it1++)->first, (sit1++)->first);
	}
}


TEST(MapFind)
{
	ft::map<int, bool> m1;

	std::map<int, bool> sm1;


	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ASSERT_EQ(m1.find(6)->first, sm1.find(6)->first);

	CHECK_EQ(m1.find(-42), m1.end());

}


TEST(MapCount)
{
	ft::map<int, bool> m1;

	std::map<int, bool> sm1;


	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ASSERT_EQ(m1.count(6), sm1.count(6));
	ASSERT_EQ(m1.count(7), sm1.count(7));
	ASSERT_EQ(m1.count(8), sm1.count(8));
	ASSERT_EQ(m1.count(9), sm1.count(9));
	ASSERT_EQ(m1.count(12), sm1.count(12));

}

TEST(MapLowerBound)
{
	ft::map<int, bool> m1;

	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	// m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	// sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ASSERT_EQ(m1.lower_bound(5)->first, sm1.lower_bound(5)->first)
	ASSERT_EQ(m1.lower_bound(2)->first, sm1.lower_bound(2)->first)
	ASSERT_EQ((m1.lower_bound(10) == m1.end()), (sm1.lower_bound(10) == sm1.end()))
	ASSERT_EQ(m1.lower_bound(7)->first, sm1.lower_bound(7)->first)
	ASSERT_EQ(m1.lower_bound(8)->first, sm1.lower_bound(8)->first)
}

TEST(MapUpperBound)
{
	ft::map<int, bool> m1;

	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	// m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	// sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ASSERT_EQ(m1.upper_bound(5)->first, sm1.upper_bound(5)->first)
	ASSERT_EQ(m1.upper_bound(2)->first, sm1.upper_bound(2)->first)
	ASSERT_EQ((m1.upper_bound(10) == m1.end()), (sm1.upper_bound(10) == sm1.end()))
	ASSERT_EQ(m1.upper_bound(7)->first, sm1.upper_bound(7)->first)
	ASSERT_EQ(m1.upper_bound(8)->first, sm1.upper_bound(8)->first)
}

TEST(MapCopy)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool> m2(m1);
	std::map<int, bool> sm2(sm1);

	ft::map<int,bool>::iterator mit = m2.begin();

	for (std::map<int, bool>::iterator it = sm2.begin(); it != sm2.end(); it++)
	{
		ASSERT_EQ((it)->first, (mit++)->first);
	}

	CHECK_EQ(mit, m2.end());

}

TEST(MapAssign)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool> m2;
	std::map<int, bool> sm2;

	m2.insert(ft::pair<int, bool>(-5, true));
	m2.insert(ft::pair<int, bool>(-6, true));
	m2.insert(ft::pair<int, bool>(-7, true));
	m2.insert(ft::pair<int, bool>(-8, true));
	m2.insert(ft::pair<int, bool>(-9, true));

	sm2.insert(std::pair<int, bool>(-5, true));
	sm2.insert(std::pair<int, bool>(-6, true));
	sm2.insert(std::pair<int, bool>(-7, true));
	sm2.insert(std::pair<int, bool>(-8, true));
	sm2.insert(std::pair<int, bool>(-9, true));

	m2 = m1;
	sm2 = sm1;

	ft::map<int,bool>::iterator mit = m2.begin();

	for (std::map<int, bool>::iterator it = sm2.begin(); it != sm2.end(); it++)
	{
		ASSERT_EQ((it)->first, (mit++)->first);
	}

	CHECK_EQ(mit, m2.end());

	ft::map<int,bool>::iterator mit1 = m1.begin();

	for (std::map<int, bool>::iterator it = sm1.begin(); it != sm1.end(); it++)
	{
		ASSERT_EQ((it)->first, (mit1++)->first);
	}

	CHECK_EQ(mit1, m1.end());


}


TEST(MapRangeConstructor)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool> m2(m1.begin(), m1.end());
	std::map<int, bool> sm2(sm1.begin(), sm1.end());

	ft::map<int,bool>::iterator mit = m2.begin();

	for (std::map<int, bool>::iterator it = sm2.begin(); it != sm2.end(); it++)
	{
		ASSERT_EQ((it)->first, (mit++)->first);
	}

	CHECK_EQ(mit, m2.end());

}

#include <vector>

TEST(MapConstIter)
{
	std::vector<ft::pair<int,bool> > v1;
	v1.push_back(ft::pair<int, bool>(5, true));
	v1.push_back(ft::pair<int, bool>(6, true));
	v1.push_back(ft::pair<int, bool>(7, true));
	v1.push_back(ft::pair<int, bool>(8, true));

	std::vector<std::pair<int,bool> > v2;
	v2.push_back(std::pair<int, bool>(5, true));
	v2.push_back(std::pair<int, bool>(6, true));
	v2.push_back(std::pair<int, bool>(7, true));
	v2.push_back(std::pair<int, bool>(8, true));

	const ft::map<int, bool> m1(v1.begin(), v1.end());

	// ft::map<int, bool>::const_iterator ite = m1.begin();

	m1.lower_bound(5);


}


#define COMPARE_MAPS(a, b) \
	ASSERT_EQ(a.size(), b.size()); \
	std::cout << a.size() << "==" << b.size() << std::endl; \
	ft::map<int, bool>::iterator iterB = b.begin(); \
	for (std::map<int, bool>::iterator iterA = a.begin(); iterA != a.end(); iterA++) \
	{ \
		ASSERT_EQ(iterA->first, iterB->first);\
		ASSERT_EQ(iterA->second, iterB->second); \
		iterB++; \
	} \
	CHECK_EQ(iterB, b.end()); \

TEST(MapInsert2CorrectInput)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	// m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	// sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	m1.insert(++++m1.begin(), ft::pair<int, bool>(7, true));

	sm1.insert(++++sm1.begin(), std::pair<int, bool>(7, true));

	COMPARE_MAPS(sm1, m1);
}

TEST(MapInsert2TooLow)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	// m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	// sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	m1.insert(m1.begin(), ft::pair<int, bool>(7, true));

	sm1.insert(sm1.begin(), std::pair<int, bool>(7, true));

	COMPARE_MAPS(sm1, m1);
}


TEST(MapInsert2TooHigh)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	// m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	// sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	m1.insert(++++++++m1.begin(), ft::pair<int, bool>(7, true));

	sm1.insert(++++++++sm1.begin(), std::pair<int, bool>(7, true));

	COMPARE_MAPS(sm1, m1);
}


TEST(MapInsert2Exists)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	m1.insert(++++++m1.begin(), ft::pair<int, bool>(7, true));

	sm1.insert(++++++sm1.begin(), std::pair<int, bool>(7, true));

	COMPARE_MAPS(sm1, m1);
}


TEST(MapInsert2End)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	m1.insert(m1.end(), ft::pair<int, bool>(7, true));

	sm1.insert(sm1.end(), std::pair<int, bool>(7, true));

	COMPARE_MAPS(sm1, m1);
}

TEST(MapInsert2EndSmaller)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	
	sm1.insert(std::pair<int, bool>(5, true));
	
	m1.insert(m1.end(), ft::pair<int, bool>(2, true));

	sm1.insert(sm1.end(), std::pair<int, bool>(2, true));

	COMPARE_MAPS(sm1, m1);

	size_t i = 0;
	ft::map<int, bool>::iterator iter1 = m1.begin();
	while (iter1 != m1.end())
	{
		std::cout << "m1[" << i << "]: " << iter1->first << " -> " << iter1->second << std::endl;
		iter1++;
	}

	std::map<int, bool>::iterator iter2 = sm1.begin();
	while (iter2 != sm1.end())
	{
		std::cout << "sm1[" << i << "]: " << iter2->first << " -> " << iter2->second << std::endl;
		iter2++;
	}
}

TEST(MapMaxSize)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ASSERT_EQ(m1.max_size(), sm1.max_size());

	ft::map<std::string, double> m2;
	std::map<std::string, double> sm2;
	ASSERT_EQ(m2.max_size(), sm2.max_size());
}
/*
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// STACK TESTS
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include <stack>
#include "../stack.hpp"

TEST(StackConstructor)
{
	ft::stack<int> fs;
	std::stack<int> std;
	ASSERT_EQ(fs.empty(), std.empty());
	ASSERT_EQ(fs.size(), std.size());
}

TEST(StackEmpty)
{
	ft::stack<int> fs;
	std::stack<int> std;

	ASSERT_EQ(fs.empty(), std.empty());
	ASSERT_EQ(fs.size(), std.size());
}

TEST(StackPush)
{
	ft::stack<int> fs;
	std::stack<int> std;

	fs.push(5);
	std.push(5);

	ASSERT_EQ(fs.empty(), std.empty());
	ASSERT_EQ(fs.top(), std.top());
	ASSERT_EQ(fs.size(), std.size());
}


TEST(StackPush2)
{
	ft::stack<int> fs;
	std::stack<int> std;

	fs.push(5);
	std.push(5);

	fs.push(2);
	std.push(2);

	ASSERT_EQ(fs.empty(), std.empty());
	ASSERT_EQ(fs.top(), std.top());
	ASSERT_EQ(fs.size(), std.size());
}

TEST(StackPop)
{
	ft::stack<int> fs;
	std::stack<int> std;

	fs.push(5);
	std.push(5);

	fs.push(2);
	std.push(2);

	fs.pop();
	std.pop();

	ASSERT_EQ(fs.empty(), std.empty());
	ASSERT_EQ(fs.top(), std.top());
	ASSERT_EQ(fs.size(), std.size());
}

TEST(StackPop2)
{
	ft::stack<int> fs;
	std::stack<int> std;

	fs.push(2);
	std.push(2);

	fs.pop();
	std.pop();

	ASSERT_EQ(fs.empty(), std.empty());
	ASSERT_EQ(fs.empty(), std.empty());
	// ASSERT_EQ(fs.top(), std.top());
}

TEST(StackCopyConstructor)
{
	ft::stack<int> fs;
	std::stack<int> std;

	fs.push(5);
	std.push(5);

	fs.push(2);
	std.push(2);

	fs.pop();
	std.pop();

	ft::stack<int> fs2(fs);
	std::stack<int> std2(std);

	ASSERT_EQ(fs2.empty(), std2.empty());
	ASSERT_EQ(fs2.top(), std2.top());
	ASSERT_EQ(fs2.size(), std2.size());
}

TEST(StackRelativeOperators1)
{
	ft::stack<int> fs;
	std::stack<int> std;

	ft::stack<int> fs_a;
	std::stack<int> std_a;

	ASSERT_EQ((fs == fs_a), (std == std_a));
	ASSERT_EQ((fs != fs_a), (std != std_a));
	ASSERT_EQ((fs < fs_a), (std < std_a));
	ASSERT_EQ((fs <= fs_a), (std <= std_a));
	ASSERT_EQ((fs > fs_a), (std > std_a));
	ASSERT_EQ((fs >= fs_a), (std >= std_a));
}

TEST(StackRelativeOperators2)
{
	ft::stack<int> fs;
	std::stack<int> std;

	fs.push(2);
	std.push(2);

	ft::stack<int> fs_a;
	std::stack<int> std_a;

	ASSERT_EQ((fs == fs_a), (std == std_a));
	ASSERT_EQ((fs != fs_a), (std != std_a));
	ASSERT_EQ((fs < fs_a), (std < std_a));
	ASSERT_EQ((fs <= fs_a), (std <= std_a));
	ASSERT_EQ((fs > fs_a), (std > std_a));
	ASSERT_EQ((fs >= fs_a), (std >= std_a));
}

TEST(StackRelativeOperators3)
{
	ft::stack<int> fs;
	std::stack<int> std;

	ft::stack<int> fs_a;
	std::stack<int> std_a;

	fs_a.push(2);
	std_a.push(2);


	ASSERT_EQ((fs == fs_a), (std == std_a));
	ASSERT_EQ((fs != fs_a), (std != std_a));
	ASSERT_EQ((fs < fs_a), (std < std_a));
	ASSERT_EQ((fs <= fs_a), (std <= std_a));
	ASSERT_EQ((fs > fs_a), (std > std_a));
	ASSERT_EQ((fs >= fs_a), (std >= std_a));
}

TEST(StackRelativeOperators4)
{
	ft::stack<int> fs;
	std::stack<int> std;

	ft::stack<int> fs_a;
	std::stack<int> std_a;

	fs_a.push(2);
	std_a.push(2);

	fs.push(2);
	std.push(2);


	ASSERT_EQ((fs == fs_a), (std == std_a));
	ASSERT_EQ((fs != fs_a), (std != std_a));
	ASSERT_EQ((fs < fs_a), (std < std_a));
	ASSERT_EQ((fs <= fs_a), (std <= std_a));
	ASSERT_EQ((fs > fs_a), (std > std_a));
	ASSERT_EQ((fs >= fs_a), (std >= std_a));
}

TEST(StackRelativeOperators5)
{
	ft::stack<int> fs;
	std::stack<int> std;

	ft::stack<int> fs_a;
	std::stack<int> std_a;

	fs_a.push(2);
	std_a.push(2);

	fs.push(3);
	std.push(3);


	ASSERT_EQ((fs == fs_a), (std == std_a));
	ASSERT_EQ((fs != fs_a), (std != std_a));
	ASSERT_EQ((fs < fs_a), (std < std_a));
	ASSERT_EQ((fs <= fs_a), (std <= std_a));
	ASSERT_EQ((fs > fs_a), (std > std_a));
	ASSERT_EQ((fs >= fs_a), (std >= std_a));
}

TEST(StackRelativeOperators6)
{
	ft::stack<int> fs;
	std::stack<int> std;

	ft::stack<int> fs_a;
	std::stack<int> std_a;

	fs_a.push(3);
	std_a.push(3);

	fs.push(2);
	std.push(2);


	ASSERT_EQ((fs == fs_a), (std == std_a));
	ASSERT_EQ((fs != fs_a), (std != std_a));
	ASSERT_EQ((fs < fs_a), (std < std_a));
	ASSERT_EQ((fs <= fs_a), (std <= std_a));
	ASSERT_EQ((fs > fs_a), (std > std_a));
	ASSERT_EQ((fs >= fs_a), (std >= std_a));
}

TEST(FtIsIntegral)
{
	ASSERT_EQ(ft::is_integral<int>::value, std::is_integral<int>::value);
	ASSERT_EQ(ft::is_integral<std::string>::value, std::is_integral<std::string>::value);
}
*/
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// TESTS END
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include <unistd.h>

int main(void)
{
	run_tests();
	// sleep(10);
}