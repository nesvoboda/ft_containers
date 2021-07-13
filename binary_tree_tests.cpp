#include "elementest.hpp"
#include "binary_tree.hpp"

#include <map>
#include <string>

TEST(BTreeConstruct)
{
	BSTree<ABSTNode<int>, int> bt;

	// the empty tree has a single 'end' node to accomodate end iterators
	// in the future.
	ASSERT_EQ(bt._head->left, NULL);
	ASSERT_EQ(bt._head->right, NULL);
	ASSERT_EQ(bt._head->parent, NULL);
	ASSERT_EQ(bt._head->content, 0);

	ASSERT_EQ(bt._size, 0);
}

TEST(BTreeInsertToEmpty)
{
	BSTree<ABSTNode<int>, int> bt;

	pair<ABSTNode<int> *, bool> ret = bt.insert(5);

	ASSERT_EQ(bt._size, 1);

	ASSERT_EQ(ret.first, bt._head);
	ASSERT_EQ(ret.second, true);

	ASSERT_EQ(bt._head->left, NULL);
	ASSERT_NEQ(bt._head->right, NULL);
	ASSERT_EQ(bt._head->parent, NULL);
	ASSERT_EQ(bt._head->content, 5);

	ABSTNode<int> *endElement = bt._head->right;

	ASSERT_EQ(endElement->left, NULL);
	ASSERT_EQ(endElement->right, NULL);
	ASSERT_NEQ(endElement->parent, NULL);
	ASSERT_EQ(endElement->parent, bt._head);
}

TEST(BTreeInsertToNotEmptyGreater)
{
	BSTree<ABSTNode<int>, int> bt;

	bt.insert(5);
	pair<ABSTNode<int> *, bool> ret = bt.insert(6);

	ASSERT_EQ(bt._size, 2);

	ASSERT_EQ(bt._head->left, NULL);
	ASSERT_NEQ(bt._head->right, NULL);
	ASSERT_EQ(bt._head->parent, NULL);
	ASSERT_EQ(bt._head->content, 5);

	ABSTNode<int> *newElement = bt._head->right;
	ASSERT_EQ(ret.first, newElement);
	ASSERT_EQ(ret.second, true);
	ASSERT_EQ(newElement->left, NULL);
	ASSERT_NEQ(newElement->right, NULL);
	ASSERT_EQ(newElement->content, 6);

	ABSTNode<int> *endElement = bt._head->right->right;

	ASSERT_EQ(endElement->left, NULL);
	ASSERT_EQ(endElement->right, NULL);
	ASSERT_NEQ(endElement->parent, NULL);
	ASSERT_EQ(endElement->parent, newElement);
}

TEST(BTreeInsertToNotEmptyLess)
{
	BSTree<ABSTNode<int>, int> bt;

	bt.insert(5);
	pair<ABSTNode<int> *, bool> ret = bt.insert(2);

	ASSERT_EQ(bt._size, 2);

	ASSERT_NEQ(bt._head->left, NULL);
	ASSERT_NEQ(bt._head->right, NULL);
	ASSERT_EQ(bt._head->parent, NULL);
	ASSERT_EQ(bt._head->content, 5);

	ABSTNode<int> *newElement = bt._head->left;
	ASSERT_EQ(ret.first, newElement);
	ASSERT_EQ(ret.second, true);
	ASSERT_EQ(newElement->left, NULL);
	ASSERT_EQ(newElement->right, NULL);
	ASSERT_NEQ(newElement->parent, NULL);
	ASSERT_EQ(newElement->parent, bt._head);
	ASSERT_EQ(newElement->content, 2);

	ABSTNode<int> *endElement = bt._head->right;

	ASSERT_EQ(endElement->left, NULL);
	ASSERT_EQ(endElement->right, NULL);
	ASSERT_NEQ(endElement->parent, NULL);
	ASSERT_EQ(endElement->parent, bt._head);
}

TEST(BTreeInsertExisting)
{
	BSTree<ABSTNode<int>, int> bt;

	bt.insert(5);
	pair<ABSTNode<int> *, bool> ret = bt.insert(5);

	ASSERT_EQ(bt._size, 1);

	ASSERT_EQ(ret.first, bt._head);
	ASSERT_EQ(ret.second, false);

	ASSERT_EQ(bt._head->left, NULL);
	ASSERT_NEQ(bt._head->right, NULL);
	ASSERT_EQ(bt._head->parent, NULL);
	ASSERT_EQ(bt._head->content, 5);

	ABSTNode<int> *endElement = bt._head->right;

	ASSERT_EQ(endElement->left, NULL);
	ASSERT_EQ(endElement->right, NULL);
	ASSERT_NEQ(endElement->parent, NULL);
	ASSERT_EQ(endElement->parent, bt._head);

}

TEST(BtreeDetect)
{
	BSTree<ABSTNode<int>, int> bt;
	bt.insert(5);
	bt.insert(2);
	bt.insert(3);
	bt.insert(4);

	ASSERT_EQ(bt._head->left->content, 2);
	ASSERT_EQ(bt._head->left->right->content, 3);
	ASSERT_EQ(bt._head->left->right->right->content, 4);
}

// TEST(AmICrazy)
// {
// 	std::map<std::string, int> map1;

// 	map1.insert(std::pair<std::string, int>("hehe", 5));
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