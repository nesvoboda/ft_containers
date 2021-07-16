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

	ABSTNode<int, bool> *endElement = bt._head->right;

	ASSERT_EQ(endElement->left, NULL);
	ASSERT_EQ(endElement->right, NULL);
	ASSERT_NEQ(endElement->parent, NULL);
	ASSERT_EQ(endElement->parent, bt._head);
}

TEST(BTreeInsertToNotEmptyGreater)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(5, true));
	ft::pair<ABSTNode<int, bool> *, bool> ret = bt.insert(ft::pair<int, bool>(6, true));

	ASSERT_EQ(bt._size, 2);

	ASSERT_EQ(bt._head->left, NULL);
	ASSERT_NEQ(bt._head->right, NULL);
	ASSERT_EQ(bt._head->parent, NULL);
	ASSERT_EQ(bt._head->data.first, 5);

	ABSTNode<int, bool> *newElement = bt._head->right;
	ASSERT_EQ(ret.first, newElement);
	ASSERT_EQ(ret.second, true);
	ASSERT_EQ(newElement->left, NULL);
	ASSERT_NEQ(newElement->right, NULL);
	ASSERT_EQ(newElement->data.first, 6);

	ABSTNode<int, bool> *endElement = bt._head->right->right;

	ASSERT_EQ(endElement->left, NULL);
	ASSERT_EQ(endElement->right, NULL);
	ASSERT_NEQ(endElement->parent, NULL);
	ASSERT_EQ(endElement->parent, newElement);
}

TEST(BTreeInsertToNotEmptyLess)
{
	BSTree<int, bool> bt;

	bt.insert(ft::pair<int, bool>(5, true));
	ft::pair<ABSTNode<int, bool> *, bool> ret = bt.insert(ft::pair<int, bool>(2, true));

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
	bt.insert(ft::pair<int, bool>(4, true));

	ASSERT_EQ(bt._head->left->data.first, 2);
	ASSERT_EQ(bt._head->left->right->data.first, 3);
	ASSERT_EQ(bt._head->left->right->right->data.first, 4);
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

	ASSERT_EQ(ret.first->immediatePredecessor()->data.first, 4);

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


// TEST(AmICrazy)
// {
// 	std::map<std::string, int> map1;

// 	map1.insert(std::ft::pair<std::string, int>("hehe", 5));
// 	std::map<std::string, int>::iterator it1 = map1.end();

// 	it1++;
// 	std::cout << "Map1 end+1: " << (*it1).second << std::endl;
// 	// it1++;
// 	// it1++;
// 	// std::cout << "Map1 begin+1: " << (*it1).second << std::endl;
// }

int main(void)
{
	run_tests();
}