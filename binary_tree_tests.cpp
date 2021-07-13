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
	ASSERT_EQ(bt._head->key, 0);

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
	ASSERT_EQ(bt._head->key, 5);

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
	ASSERT_EQ(bt._head->key, 5);

	ABSTNode<int, bool> *newElement = bt._head->right;
	ASSERT_EQ(ret.first, newElement);
	ASSERT_EQ(ret.second, true);
	ASSERT_EQ(newElement->left, NULL);
	ASSERT_NEQ(newElement->right, NULL);
	ASSERT_EQ(newElement->key, 6);

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
	ASSERT_EQ(bt._head->key, 5);

	ABSTNode<int, bool> *newElement = bt._head->left;
	ASSERT_EQ(ret.first, newElement);
	ASSERT_EQ(ret.second, true);
	ASSERT_EQ(newElement->left, NULL);
	ASSERT_EQ(newElement->right, NULL);
	ASSERT_NEQ(newElement->parent, NULL);
	ASSERT_EQ(newElement->parent, bt._head);
	ASSERT_EQ(newElement->key, 2);

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
	ASSERT_EQ(bt._head->key, 5);

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

	ASSERT_EQ(bt._head->left->key, 2);
	ASSERT_EQ(bt._head->left->right->key, 3);
	ASSERT_EQ(bt._head->left->right->right->key, 4);
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