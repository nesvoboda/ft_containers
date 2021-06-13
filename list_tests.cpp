#define UNIT_TEST

#include "list.hpp"
#include "elementest.hpp"

TEST(listNodeConstructs)
{
	ft::listNode<int> ln_i(3);
	ASSERT_EQ(ln_i.getValue(), 3);
	ASSERT_EQ(ln_i.getNext(), NULL);
	ASSERT_EQ(ln_i.getPrev(), NULL);
}

TEST(listNodeCopyConstructs)
{
	ft::listNode<int> ln_i(3);
	ft::listNode<int> ln_i2(ln_i);
	ASSERT_EQ(ln_i2.getValue(), 3);
	ASSERT_EQ(ln_i2.getNext(), NULL);
	ASSERT_EQ(ln_i2.getPrev(), NULL);
}

TEST(listNodeAssignmentOperator)
{
	ft::listNode<int> ln_i(3);
	ft::listNode<int> ln_i3(ln_i);
	ASSERT_EQ(ln_i3.getValue(), 3);
	ASSERT_EQ(ln_i3.getNext(), NULL);
	ASSERT_EQ(ln_i3.getPrev(), NULL);

	ft::listNode<int> ln_i4(5);

	ln_i3 = ln_i4;

	ASSERT_EQ(ln_i4.getValue(), 5);
	ASSERT_EQ(ln_i4.getNext(), NULL);
	ASSERT_EQ(ln_i4.getPrev(), NULL);
}

TEST(listNodeDestructor)
{
	ft::listNode<int> ln_i5(10);
}

TEST(listNodeGetValueSetValue)
{
	ft::listNode<int> ln_i6(-5);
	ASSERT_EQ(ln_i6.getValue(), -5);
	ln_i6.setValue(50);
	ASSERT_EQ(ln_i6.getValue(), 50);
}

TEST(listNodeGetNextSetNext)
{
	ft::listNode<int> ln_a(-5);
	ft::listNode<int> ln_b(0);

	ASSERT_EQ(ln_a.getNext(), NULL);
	ln_a.setNext(&ln_b);
	ASSERT_EQ(ln_a.getNext(), &ln_b);
}

TEST(listNodeGetPrevsetPrev)
{
	ft::listNode<int> ln_a(-5);
	ft::listNode<int> ln_b(0);

	ASSERT_EQ(ln_a.getPrev(), NULL);
	ln_a.setPrev(&ln_b);
	ASSERT_EQ(ln_a.getPrev(), &ln_b);
}

TEST(listDefaultConstructor)
{
	ft::list<int> l_i;
	ASSERT_EQ(l_i.empty(), true);
}

TEST(listFillConstructor)
{
	ft::list<int> l_i1((size_t)5, 10);
	ASSERT_EQ(l_i1.front(), 10);
	ASSERT_EQ(l_i1.size(), 5);
}

TEST(listFillConstructorZeroElements)
{
	ft::list<int> l_i1((size_t)0, 10);
	// ASSERT_EQ(l_i1.front(), 10);
	ASSERT_EQ(l_i1.size(), 0);

	// TODO check element access
}

TEST(listIteratorConstructor)
{
	ft::listNode<int> ln_a(-5);

	ft::list<int>::iterator it;
	ft::list<int>::iterator it2(&ln_a);
}

TEST(listIteratorCopyConstructor)
{
	ft::listNode<int> ln_a(-5);
	ft::list<int>::iterator it_a(&ln_a);

	ft::list<int>::iterator it_b(it_a);
}

TEST(listIteratorAssignmentOperator)
{
	ft::listNode<int> ln_a(-5);
	ft::listNode<int> ln_b(0);

	ft::list<int>::iterator it_a(&ln_a);
	ft::list<int>::iterator it_b(&ln_b);
	it_a = it_b;
}

TEST(listIteratorDestructor)
{
	ft::list<int>::iterator it5;
}

TEST(listBegin)
{
	ft::list<int> list_a((size_t)5, 10);
	ft::list<int>::iterator iter_a = list_a.begin();
}

TEST(listIteratorStarOperator)
{
	ft::list<int> list_a((size_t)5, 10);

	ft::list<int>::iterator iter_a = list_a.begin();
	ASSERT_EQ(*iter_a, 10);
}

TEST(listIteratorOperatorPlusPlus)
{
	ft::list<int> list_a((size_t)5, 10);

	ft::list<int>::iterator iter_a = list_a.begin();
	iter_a++;
	ASSERT_EQ(*iter_a, 10);
}

TEST(listIteratorNotEqualsOperator)
{
	ft::list<int> list_a((size_t)5, 10);

	ft::list<int>::iterator iter_a = list_a.begin();

	iter_a++;

	ft::list<int>::iterator iter_b = list_a.begin();
	ASSERT_EQ((iter_b != iter_a), true);
}

TEST(listIteratorOperatorMinusMinus)
{
	ft::list<int> list_a((size_t)5, 10);

	ft::list<int>::iterator iter_a = list_a.begin();

	iter_a++;
	--iter_a;
	ASSERT_EQ(*iter_a, 10);
	CHECK_EQ(iter_a, list_a.begin());
}

TEST(listIteratorEqualityOperator)
{
	ft::list<int> list_a((size_t)5, 10);
	ft::list<int>::iterator iter_a = list_a.begin();

	ft::list<int>::iterator iter_b = list_a.begin();

	ASSERT_EQ((iter_b == iter_a), true);
}

TEST(listIteratorPlusPlusoperator)
{
	ft::list<int> list_a((size_t)5, 10);
	ft::list<int>::iterator iter_a = list_a.begin();

	iter_a++;

	ASSERT_EQ(*iter_a, 10);
	CHECK_NEQ(list_a.begin(), iter_a);
}

TEST(listIteratorMinusMinusoperator)
{
	ft::list<int> list_a((size_t)5, 10);
	ft::list<int>::iterator iter_a = list_a.begin();

	iter_a++;
	iter_a--;
	ASSERT_EQ(*iter_a, 10);
	CHECK_EQ(list_a.begin(), iter_a);
}

TEST(listEnd)
{
	ft::list<int> list_a((size_t)5, 10);
	ft::list<int>::iterator iter_a = list_a.begin();
	for (int i = 0; i < 5; i++)
		iter_a++;
	CHECK_EQ(iter_a, list_a.end());
}

TEST(ListReverse_iteratorConstructor)
{
	ft::list<int>::reverse_iterator reverseiter_a;
	ft::listNode<int> listnode_a(5);

	ft::list<int>::reverse_iterator reverseiter_b(&listnode_a);
}

TEST(ListReverse_iteratorCopyConstructor)
{
	ft::listNode<int> listnode_a(5);

	ft::list<int>::reverse_iterator reverseiter_a(&listnode_a);
	ft::list<int>::reverse_iterator reverseiter_b(reverseiter_a);
}

TEST(ListReverse_iteratorAssignmentOperator)
{
	ft::listNode<int> listnode_a(5);
	ft::listNode<int> listnode_b(-42);

	ft::list<int>::reverse_iterator reverseiter_a(&listnode_a);
	ft::list<int>::reverse_iterator reverseiter_b(&listnode_b);

	reverseiter_b = reverseiter_a;
}

TEST(ListReverse_iteratorDestructor)
{
	ft::list<int>::reverse_iterator rit5;
}

TEST(ListRend)
{
	ft::list<int> list_a((size_t)5, 10);
	ft::list<int>::reverse_iterator revIter = list_a.rend();
	// Can't check the value because it's null
}

TEST(ListReverse_iteratorStaroperator)
{
	ft::listNode<int> listNodeA(55);
	ft::listNode<int> listNodeB(54);

	listNodeA.setPrev(&listNodeB);
	ft::list<int>::reverse_iterator revIter(&listNodeA);
	ASSERT_EQ(*revIter, 54);
}

TEST(ListReverse_iteratorOperatorPlusPlus)
{
	ft::list<int> list_a((size_t)5, 10);
	ft::list<int>::reverse_iterator revIter = list_a.rend();

	revIter++;

	ASSERT_EQ(*revIter, 10);
}

TEST(ListReverse_iteratorNotEqualsoperator)
{
	ft::list<int> list_a((size_t)5, 10);
	ft::list<int>::reverse_iterator revIter = list_a.rend();

	revIter++;

	CHECK_NEQ(revIter, list_a.rend());
}

TEST(ListReverse_iteratoroperatorMinusMinus)
{
	ft::list<int> list_a((size_t)5, 10);
	ft::list<int>::reverse_iterator revIter = list_a.rend();

	revIter++;

	--revIter;
	CHECK_EQ(revIter, list_a.rend());

	++revIter;

	revIter--;
	CHECK_EQ(revIter, list_a.rend());
}

TEST(ListReverse_iteratorEqualsOperator)
{
	ft::list<int> list_a((size_t)5, 10);
	ft::list<int>::reverse_iterator revIter = list_a.rend();
	ASSERT_EQ((revIter == list_a.rend()), true);
	ASSERT_EQ((revIter == list_a.rbegin()), false);
}

TEST(ListReverse_iteratorPlusPlusOperator)
{
	ft::list<int> list_a((size_t)5, 10);
	ft::list<int>::reverse_iterator revIter = list_a.rend();
	revIter++;
	ASSERT_EQ((revIter == list_a.rend()), false);
}

TEST(ListReverse_iteratorMinusMinusOperator)
{
	ft::list<int> list_a((size_t)5, 10);
	ft::list<int>::reverse_iterator revIter = list_a.rend();
	revIter++;

	revIter--;
	CHECK_EQ(revIter, list_a.rend());
}

TEST(ListReverseIteratorEndBegin)
{
	ft::list<int> list_a((size_t)5, 10);
	ft::list<int>::reverse_iterator revIterA = list_a.rbegin(); // points to the element after the last

	for (size_t i = 0; i < 5; i++)
	{
		revIterA--;
	}
	CHECK_EQ(revIterA, list_a.rend());
}

/*
TEST(ListAssignmentOperator)
{
	ft::list<int> list_a((size_t)5, 10);

	ft::list<int> list_b(3, 8);
	
	list_b = list_a;

	ASSERT_EQ(list_b.size(), 5);

	ft::list<int>::iterator iter;
	for (iter = list_b.begin(); iter != list_b.end(); iter++)
	{
		ASSERT_EQ(*iter, 10);
	}

}
*/

TEST(ListBack)
{
	ft::list<int> list_a((size_t)1, 10);

	ASSERT_EQ(list_a.back(), 10);
}

TEST(ListBackConst)
{
	const ft::list<int> list_a((size_t)1, 10);

	ASSERT_EQ(list_a.back(), 10);
}

TEST(ListFront)
{
	ft::list<int> list_a((size_t)1, 10);

	ASSERT_EQ(list_a.front(), 10);
}

TEST(ListFrontConst)
{
	const ft::list<int> list_a((size_t)1, 10);

	ASSERT_EQ(list_a.front(), 10);
}

TEST(ListPushFront)
{
	ft::list<int> list_a;

	ASSERT_EQ(list_a.size(), 0);

	list_a.push_front(42);
	ASSERT_EQ(list_a.size(), 1);
	ASSERT_EQ(list_a.front(), 42);
	ASSERT_EQ(list_a.back(), 42);

	ft::list<int> list_b((size_t)5, 10);
	ASSERT_EQ(list_b.size(), 5);

	list_b.push_front(-42);
	ASSERT_EQ(list_b.size(), 6);
	ASSERT_EQ(list_b.front(), -42);
	ASSERT_EQ(list_b.back(), 10);
}

TEST(ListPopFront)
{
	ft::list<int> list_a((size_t)5, 10);
	ASSERT_EQ(list_a.size(), 5);

	list_a.push_front(-42);
	ASSERT_EQ(list_a.size(), 6);
	ASSERT_EQ(list_a.front(), -42);
	ASSERT_EQ(list_a.back(), 10);

	list_a.pop_front();
	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 10);

	ft::list<int> list_b((size_t)5, 10);
	list_b.pop_front();
	ASSERT_EQ(list_b.size(), 4);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);

	ft::list<int> list_c((size_t)1, 10);
	list_c.pop_front();
	ASSERT_EQ(list_c.size(), 0);
}

TEST(ListPushBack)
{
	ft::list<int> list_a;

	ASSERT_EQ(list_a.size(), 0);

	list_a.push_back(42);
	ASSERT_EQ(list_a.size(), 1);
	ASSERT_EQ(list_a.front(), 42);
	ASSERT_EQ(list_a.back(), 42);

	ft::list<int> list_b((size_t)5, 10);
	ASSERT_EQ(list_b.size(), 5);

	list_b.push_back(-42);
	ASSERT_EQ(list_b.size(), 6);
	ASSERT_EQ(list_b.back(), -42);
	ASSERT_EQ(list_b.front(), 10);
}

TEST(ListPopBack)
{
	ft::list<int> list_a((size_t)5, 10);
	ASSERT_EQ(list_a.size(), 5);

	list_a.push_back(-42);
	ASSERT_EQ(list_a.size(), 6);
	ASSERT_EQ(list_a.back(), -42);
	ASSERT_EQ(list_a.front(), 10);

	list_a.pop_back();
	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 10);

	ft::list<int> list_b((size_t)5, 10);
	list_b.pop_back();
	ASSERT_EQ(list_b.size(), 4);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);

	ft::list<int> list_c((size_t)1, 10);
	list_c.pop_back();
	ASSERT_EQ(list_c.size(), 0);

	ft::list<int> list_d((size_t)2, 10);
	list_d.pop_back();
	ASSERT_EQ(list_d.size(), 1);
	ASSERT_EQ(list_d.front(), 10);
	ASSERT_EQ(list_d.back(), 10);
}

TEST(ListInsertOne)
{
	ft::list<int> list_a;
	list_a.insert(list_a.end(), 42);

	ASSERT_EQ(list_a.size(), 1);
	ASSERT_EQ(list_a.front(), 42);
	ASSERT_EQ(list_a.back(), 42);

	list_a.insert(list_a.end(), 43);

	ASSERT_EQ(list_a.size(), 2);
	ASSERT_EQ(list_a.front(), 42);
	ASSERT_EQ(list_a.back(), 43);

	list_a.insert(list_a.begin(), 45);

	ASSERT_EQ(list_a.size(), 3);
	ASSERT_EQ(list_a.front(), 45);
	ASSERT_EQ(list_a.back(), 43);

	ft::list<int> list_b((size_t)5, 10);
	ASSERT_EQ(list_b.size(), 5);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);

	list_b.insert(list_b.begin(), 42);
	ASSERT_EQ(list_b.size(), 6);
	ASSERT_EQ(list_b.front(), 42);
	ASSERT_EQ(list_b.back(), 10);

	list_b.insert(list_b.end(), 44);

	ASSERT_EQ(list_b.size(), 7);
	ASSERT_EQ(list_b.front(), 42);
	ASSERT_EQ(list_b.back(), 44);

	ft::list<int>::iterator iter = list_b.begin();

	iter++;

	list_b.insert(iter, 21);
	ASSERT_EQ(list_b.size(), 8);
	ASSERT_EQ(list_b.front(), 42);
	ASSERT_EQ(list_b.back(), 44);

	ASSERT_EQ(*(++list_b.begin()), 21);
}

TEST(ListInsertFillOne)
{
	ft::list<int> list_a;
	list_a.insert(list_a.end(), (size_t)1, 42);

	ASSERT_EQ(list_a.size(), 1);
	ASSERT_EQ(list_a.front(), 42);
	ASSERT_EQ(list_a.back(), 42);

	list_a.insert(list_a.end(), (size_t)1, 43);

	ASSERT_EQ(list_a.size(), 2);
	ASSERT_EQ(list_a.front(), 42);
	ASSERT_EQ(list_a.back(), 43);

	list_a.insert(list_a.begin(), (size_t)1, 45);

	ASSERT_EQ(list_a.size(), 3);
	ASSERT_EQ(list_a.front(), 45);
	ASSERT_EQ(list_a.back(), 43);

	ft::list<int> list_b((size_t)5, 10);
	ASSERT_EQ(list_b.size(), 5);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);

	list_b.insert(list_b.begin(), (size_t)1, 42);
	ASSERT_EQ(list_b.size(), 6);
	ASSERT_EQ(list_b.front(), 42);
	ASSERT_EQ(list_b.back(), 10);

	list_b.insert(list_b.end(), (size_t)1, 44);

	ASSERT_EQ(list_b.size(), 7);
	ASSERT_EQ(list_b.front(), 42);
	ASSERT_EQ(list_b.back(), 44);

	ft::list<int>::iterator iter = list_b.begin();

	iter++;

	list_b.insert(iter, (size_t)1, 21);
	ASSERT_EQ(list_b.size(), 8);
	ASSERT_EQ(list_b.front(), 42);
	ASSERT_EQ(list_b.back(), 44);

	ASSERT_EQ(*(++list_b.begin()), 21);
}

TEST(ListInsertFillMany)
{
	ft::list<int> list_a;

	list_a.insert(list_a.begin(), (size_t)(size_t)5, 10);

	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_a.back(), 10);
	ASSERT_EQ(list_a.front(), 10);

	ft::list<int> list_b;
	list_b.insert(list_b.begin(), (size_t)(size_t)5, 10);
	ASSERT_EQ(list_b.size(), 5);
	ASSERT_EQ(list_b.back(), 10);
	ASSERT_EQ(list_b.front(), 10);
}
#include <vector>

#include <list>

TEST(ListInsertRangeEmpty)
{
	ft::list<int> list_a;
	std::vector<int> list_b;

	list_b.push_back(5);
	list_b.push_back(4);
	list_b.push_back(3);

	list_a.insert(list_a.begin(), list_b.begin(), list_b.end());

	ASSERT_EQ(list_a.size(), 3);
	ASSERT_EQ(list_a.front(), 5);
	ASSERT_EQ(list_a.back(), 3);
}

TEST(ListInsertRangeSome)
{
	ft::list<int> list_a((size_t)5, 10);
	std::vector<int> list_b;

	list_b.push_back(5);
	list_b.push_back(4);
	list_b.push_back(3);

	list_a.insert(list_a.begin(), list_b.begin(), list_b.end());

	ASSERT_EQ(list_a.size(), 8);
	ASSERT_EQ(list_a.front(), 5);
	ASSERT_EQ(list_a.back(), 10);
}

TEST(ListEraseFirst)
{
	ft::list<int> list_a((size_t)1, 10);

	ASSERT_EQ(list_a.size(), 1);

	list_a.erase(list_a.begin());

	ASSERT_EQ(list_a.size(), 0);

	ft::list<int> list_b((size_t)3, 10);

	ASSERT_EQ(list_b.size(), 3);

	list_b.erase(list_b.begin());

	ASSERT_EQ(list_b.size(), 2);
}

TEST(ListEraseLast)
{
	ft::list<int> list_a((size_t)3, 10);

	ASSERT_EQ(list_a.size(), 3);

	list_a.erase(--list_a.end());

	ASSERT_EQ(list_a.size(), 2);
}

TEST(ListEraseMiddle)
{
	ft::list<int> list_a;

	list_a.push_back(5);
	list_a.push_back(4);
	list_a.push_back(3);

	ASSERT_EQ(list_a.size(), 3);

	list_a.erase(++list_a.begin());

	ASSERT_EQ(list_a.size(), 2);
	ASSERT_EQ(list_a.front(), 5);
	ASSERT_EQ(list_a.back(), 3);
}

TEST(ListEraseRange)
{
	ft::list<int> list_a;

	list_a.push_back(5);
	list_a.push_back(4);
	list_a.push_back(3);
	list_a.push_back(2);
	list_a.push_back(1);

	ft::list<int>::iterator first = list_a.begin();

	first++;

	ft::list<int>::iterator last = list_a.end();
	last--;

	list_a.erase(first, last);
	ASSERT_EQ(list_a.size(), 2);
	ASSERT_EQ(list_a.front(), 5);
	ASSERT_EQ(list_a.back(), 1);
}

TEST(ListEraseRangeFull)
{
	ft::list<int> list_a;

	list_a.push_back(5);
	list_a.push_back(4);
	list_a.push_back(3);
	list_a.push_back(2);
	list_a.push_back(1);

	ft::list<int>::iterator first = list_a.begin();
	ft::list<int>::iterator last = list_a.end();

	list_a.erase(first, last);
	ASSERT_EQ(list_a.size(), 0);
}

TEST(ListEraseRangeBegin)
{
	ft::list<int> list_a;

	list_a.push_back(5);
	list_a.push_back(4);
	list_a.push_back(3);
	list_a.push_back(2);
	list_a.push_back(1);

	ft::list<int>::iterator first = list_a.begin();
	ft::list<int>::iterator last = list_a.end();
	last--;
	last--;

	list_a.erase(first, last);
	ASSERT_EQ(list_a.size(), 2);
	ASSERT_EQ(list_a.front(), 2);
	ASSERT_EQ(list_a.back(), 1);
}

TEST(ListEraseRangeEnd)
{
	ft::list<int> list_a;

	list_a.push_back(5);
	list_a.push_back(4);
	list_a.push_back(3);
	list_a.push_back(2);
	list_a.push_back(1);

	ft::list<int>::iterator first = list_a.begin();
	first++;
	first++;

	ft::list<int>::iterator last = list_a.end();

	list_a.erase(first, last);
	ASSERT_EQ(list_a.size(), 2);
	ASSERT_EQ(list_a.front(), 5);
	ASSERT_EQ(list_a.back(), 4);
}

TEST(ListSwap)
{
	ft::list<int> list_a((size_t)5, 10);
	ft::list<int> list_b((size_t)4, 20);

	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 10);

	ASSERT_EQ(list_b.size(), 4);
	ASSERT_EQ(list_b.front(), 20);
	ASSERT_EQ(list_b.back(), 20);

	list_a.swap(list_b);

	ASSERT_EQ(list_b.size(), 5);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);

	ASSERT_EQ(list_a.size(), 4);
	ASSERT_EQ(list_a.front(), 20);
	ASSERT_EQ(list_a.back(), 20);
}

TEST(ListResize)
{
	ft::list<int> list_a;

	// nothing should change
	list_a.resize(0);

	ASSERT_EQ(list_a.size(), 0);

	list_a.resize(1, 42);
	ASSERT_EQ(list_a.size(), 1);
	ASSERT_EQ(list_a.front(), 42);
	ASSERT_EQ(list_a.back(), 42);

	list_a.resize(0);
	ASSERT_EQ(list_a.size(), 0);

	list_a.resize(500);

	ASSERT_EQ(list_a.size(), 500);
	ASSERT_EQ(list_a.front(), 0);
	ASSERT_EQ(list_a.back(), 0);

	for (ft::list<int>::iterator i = list_a.begin(); i != list_a.end(); i++)
		ASSERT_EQ(*i, 0);
}

TEST(ListClear)
{
	ft::list<int> list_a;

	ASSERT_EQ(list_a.size(), 0);
	list_a.clear();
	ASSERT_EQ(list_a.size(), 0);

	ft::list<int> list_b((size_t)5, 10);
	ASSERT_EQ(list_b.size(), 5);

	list_b.clear();
	ASSERT_EQ(list_b.size(), 0);

	ft::list<int> list_c((size_t)5, 10);
	list_c.clear();
	ASSERT_EQ(list_c.size(), 0);
}

TEST(ListSpliceEntireList)
{
	ft::list<int> list_a;
	ft::list<int> list_b((size_t)5, 10);

	list_a.splice(list_a.begin(), list_b);
	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 10);
	ASSERT_EQ(list_b.size(), 0);
}

TEST(ListSpliceEntireListEnd)
{
	ft::list<int> list_a;
	ft::list<int> list_b((size_t)5, 10);

	list_a.splice(list_a.end(), list_b);
	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 10);
	ASSERT_EQ(list_b.size(), 0);
}

TEST(ListSpliceEntireListEndNotEmpty)
{
	ft::list<int> list_a((size_t)4, 20);
	ft::list<int> list_b((size_t)5, 10);

	list_a.splice(list_a.end(), list_b);
	ASSERT_EQ(list_a.size(), 9);
	ASSERT_EQ(list_a.front(), 20);
	ASSERT_EQ(list_a.back(), 10);
	ASSERT_EQ(list_b.size(), 0);
}

TEST(ListSpliceEntireListEmptyList)
{
	ft::list<int> list_a;
	ft::list<int> list_b((size_t)5, 10);

	list_a.splice(list_b.begin(), list_a);
	ASSERT_EQ(list_b.size(), 5);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
	ASSERT_EQ(list_a.size(), 0);
}

TEST(ListSpliceSingleElementToEmptyFromBeginning)
{
	ft::list<int> list_a;
	ft::list<int> list_b((size_t)5, 10);

	list_a.splice(list_a.begin(), list_b, list_b.begin());
	ASSERT_EQ(list_a.size(), 1);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 10);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
	ASSERT_EQ(list_b.size(), 4);
}

TEST(ListSpliceSingleElementToEmptyFromEnd)
{
	ft::list<int> list_a;
	ft::list<int> list_b((size_t)5, 10);

	list_a.splice(list_a.begin(), list_b, --list_b.end());
	ASSERT_EQ(list_a.size(), 1);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 10);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
	ASSERT_EQ(list_b.size(), 4);
}

TEST(ListSpliceSingleElementToEmptyFromMiddle)
{
	ft::list<int> list_a;
	ft::list<int> list_b((size_t)5, 10);

	list_a.splice(list_a.begin(), list_b, ++list_b.begin());
	ASSERT_EQ(list_a.size(), 1);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 10);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
	ASSERT_EQ(list_b.size(), 4);
}

template <typename T, typename iterator>
void check_container(T comparator[], iterator first, iterator last)
{
	size_t i = 0;
	for (iterator iter = first; iter != last; iter++)
	{
		ASSERT_EQ(*iter, comparator[i]);
		i++;
	}
}

TEST(ListSpliceSingleElementToNotEmptyFromBeginning)
{
	ft::list<int> list_a((size_t)3, 20);
	ft::list<int> list_b((size_t)3, 10);

	list_a.splice(list_a.begin(), list_b, list_b.begin());
	ASSERT_EQ(list_a.size(), 4);
	ASSERT_EQ(list_b.size(), 2);

	// check_container(list_a, test);

	list_a.splice(list_a.end(), list_b, list_b.begin());
	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_b.size(), 1);

	list_a.splice(++list_a.begin(), list_b, list_b.begin());
	ASSERT_EQ(list_a.size(), 6);
	ASSERT_EQ(list_b.size(), 0);
}

TEST(ListSpliceSingleElementToNotEmptyFromMiddle)
{
	ft::list<int> list_a((size_t)3, 20);
	ft::list<int> list_b((size_t)6, 10);

	list_a.splice(list_a.begin(), list_b, ++list_b.begin());
	ASSERT_EQ(list_a.size(), 4);
	ASSERT_EQ(list_b.size(), 5);

	// check_container(list_a, test);

	list_a.splice(list_a.end(), list_b, ++list_b.begin());
	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_b.size(), 4);

	list_a.splice(++list_a.begin(), list_b, ++list_b.begin());
	ASSERT_EQ(list_a.size(), 6);
	ASSERT_EQ(list_b.size(), 3);
}

TEST(ListSpliceSingleElementToNotEmptyFromEnd)
{
	ft::list<int> list_a((size_t)3, 20);
	ft::list<int> list_b((size_t)6, 10);

	list_a.splice(list_a.begin(), list_b, --list_b.end());
	ASSERT_EQ(list_a.size(), 4);
	ASSERT_EQ(list_b.size(), 5);

	// check_container(list_a, test);

	list_a.splice(list_a.end(), list_b, --list_b.end());
	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_b.size(), 4);

	list_a.splice(++list_a.begin(), list_b, --list_b.end());
	ASSERT_EQ(list_a.size(), 6);
	ASSERT_EQ(list_b.size(), 3);
}

TEST(ListSpliceRangeToEmptyFromBeginning)
{
	ft::list<int> list_a;
	ft::list<int> list_b((size_t)6, 10);

	list_a.splice(list_a.begin(), list_b, list_b.begin(), --list_b.end());

	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_b.size(), 1);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 10);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
}

TEST(ListSpliceRangeToEmptyFromMiddle)
{
	ft::list<int> list_a;
	ft::list<int> list_b((size_t)6, 10);

	list_a.splice(list_a.begin(), list_b, ++list_b.begin(), --list_b.end());

	ASSERT_EQ(list_a.size(), 4);
	ASSERT_EQ(list_b.size(), 2);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 10);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
}

TEST(ListSpliceRangeToEmptyFromEnd)
{
	ft::list<int> list_a;
	ft::list<int> list_b((size_t)6, 10);

	list_a.splice(list_a.begin(), list_b, ++list_b.begin(), list_b.end());

	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_b.size(), 1);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 10);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
}

TEST(ListSpliceRangeToNotEmptyFromBeginningToBeginning)
{
	ft::list<int> list_a((size_t)3, 20);
	ft::list<int> list_b((size_t)6, 10);

	list_a.splice(list_a.begin(), list_b, list_b.begin(), ++++++list_b.begin());

	ASSERT_EQ(list_a.size(), 6);
	ASSERT_EQ(list_b.size(), 3);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 20);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
}

TEST(ListSpliceRangeToNotEmptyFromBeginningToMiddle)
{
	ft::list<int> list_a((size_t)3, 20);
	ft::list<int> list_b((size_t)6, 10);

	list_a.splice(++list_a.begin(), list_b, list_b.begin(), ++++++list_b.begin());

	ASSERT_EQ(list_a.size(), 6);
	ASSERT_EQ(list_b.size(), 3);
	ASSERT_EQ(list_a.front(), 20);
	ASSERT_EQ(list_a.back(), 20);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
}

TEST(ListSpliceRangeToNotEmptyFromBeginningToEnd)
{
	ft::list<int> list_a((size_t)3, 20);
	ft::list<int> list_b((size_t)6, 10);

	list_a.splice(list_a.end(), list_b, list_b.begin(), ++++++list_b.begin());

	ASSERT_EQ(list_a.size(), 6);
	ASSERT_EQ(list_b.size(), 3);
	ASSERT_EQ(list_a.front(), 20);
	ASSERT_EQ(list_a.back(), 10);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
}

TEST(ListSpliceRangeToNotEmptyFromMiddleToBeginning)
{
	ft::list<int> list_a((size_t)3, 20);
	ft::list<int> list_b((size_t)6, 10);

	list_a.splice(list_a.begin(), list_b, ++list_b.begin(), ++++++list_b.begin());

	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_b.size(), 4);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 20);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
}

TEST(ListSpliceRangeToNotEmptyFromMiddleToMiddle)
{
	ft::list<int> list_a((size_t)3, 20);
	ft::list<int> list_b((size_t)6, 10);

	list_a.splice(++list_a.begin(), list_b, ++list_b.begin(), ++++++list_b.begin());

	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_b.size(), 4);
	ASSERT_EQ(list_a.front(), 20);
	ASSERT_EQ(list_a.back(), 20);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
}

TEST(ListSpliceRangeToNotEmptyFromMiddleToEnd)
{
	ft::list<int> list_a((size_t)3, 20);
	ft::list<int> list_b((size_t)6, 10);

	list_a.splice(list_a.end(), list_b, ++list_b.begin(), ++++++list_b.begin());

	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_b.size(), 4);
	ASSERT_EQ(list_a.front(), 20);
	ASSERT_EQ(list_a.back(), 10);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
}

TEST(ListSpliceRangeToNotEmptyFromEndToBeginning)
{
	ft::list<int> list_a((size_t)3, 20);
	ft::list<int> list_b((size_t)6, 10);

	list_a.splice(list_a.begin(), list_b, ----list_b.end(), list_b.end());

	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_b.size(), 4);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 20);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
}

TEST(ListSpliceRangeToNotEmptyFromEndToMiddle)
{
	ft::list<int> list_a((size_t)3, 20);
	ft::list<int> list_b((size_t)6, 10);

	list_a.splice(++list_a.begin(), list_b, ----list_b.end(), list_b.end());

	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_b.size(), 4);
	ASSERT_EQ(list_a.front(), 20);
	ASSERT_EQ(list_a.back(), 20);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
}

TEST(ListSpliceRangeToNotEmptyFromEndToEnd)
{
	ft::list<int> list_a((size_t)3, 20);
	ft::list<int> list_b((size_t)6, 10);

	list_a.splice(list_a.end(), list_b, ----list_b.end(), list_b.end());

	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_b.size(), 4);
	ASSERT_EQ(list_a.front(), 20);
	ASSERT_EQ(list_a.back(), 10);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);
}

TEST(TestSpliceRangeSameContainer)
{
	ft::list<int> list_a((size_t)3, 20);

	list_a.push_back(5);
	list_a.push_back(5);

	ASSERT_EQ(list_a.back(), 5);
	ASSERT_EQ(list_a.front(), 20);
	ASSERT_EQ(list_a.size(), 5);

	list_a.splice(list_a.begin(), list_a, ----list_a.end(), list_a.end());

	ASSERT_EQ(list_a.back(), 20);
	ASSERT_EQ(list_a.front(), 5);
	ASSERT_EQ(list_a.size(), 5);

	list_a.splice(list_a.end(), list_a, list_a.begin(), ++++list_a.begin());

	ASSERT_EQ(list_a.back(), 5);
	ASSERT_EQ(list_a.front(), 20);
	ASSERT_EQ(list_a.size(), 5);

	list_a.splice(++list_a.begin(), list_a, ----list_a.end(), list_a.end());
}

TEST(ListRemove)
{
	ft::list<int> list_a((size_t)5, 10);

	list_a.push_back(50);
	list_a.push_back(50);
	list_a.push_back(50);
	list_a.push_back(10);
	list_a.push_back(10);

	ASSERT_EQ(list_a.size(), 10)

	list_a.remove(50);

	ASSERT_EQ(list_a.size(), 7);

	list_a.push_back(50);
	list_a.remove(50);
	ASSERT_EQ(list_a.size(), 7);

	list_a.push_front(50);
	list_a.remove(50);
	ASSERT_EQ(list_a.size(), 7);
}

bool equalsFifty(int i)
{
	return i == 50;
}

TEST(ListRemoveIf)
{
	ft::list<int> list_a((size_t)5, 10);

	list_a.push_back(50);
	list_a.push_back(50);
	list_a.push_back(50);
	list_a.push_back(10);
	list_a.push_back(10);

	ASSERT_EQ(list_a.size(), 10)

	list_a.remove_if(equalsFifty);

	ASSERT_EQ(list_a.size(), 7);

	list_a.push_back(50);
	list_a.remove_if(equalsFifty);
	ASSERT_EQ(list_a.size(), 7);

	list_a.push_front(50);
	list_a.remove_if(equalsFifty);
	ASSERT_EQ(list_a.size(), 7);
}

TEST(ListUnique)
{
	ft::list<int> list_a((size_t)3, 10);
	list_a.push_back(20);

	list_a.unique();

	ASSERT_EQ(list_a.size(), 2);
}

TEST(ListUnique2)
{
	ft::list<int> list_a((size_t)3, 10);

	list_a.unique();

	ASSERT_EQ(list_a.size(), 1);
}

bool binarypr(int a, int b)
{
	return a == b;
}

TEST(ListUniquePred)
{
	ft::list<int> list_a((size_t)3, 10);
	list_a.push_back(20);

	list_a.unique(binarypr);

	ASSERT_EQ(list_a.size(), 2);
}

TEST(ListUniquePred2)
{
	ft::list<int> list_a((size_t)3, 10);

	list_a.unique(binarypr);

	ASSERT_EQ(list_a.size(), 1);
}

TEST(ListMerge)
{
	ft::list<int> list_a;

	list_a.push_back(1);
	list_a.push_back(5);
	list_a.push_back(5);
	list_a.push_back(5);
	list_a.push_back(7);

	ft::list<int> list_b;

	list_b.push_back(2);
	list_b.push_back(3);
	list_b.push_back(4);
	list_b.push_back(20);

	list_a.merge(list_b);

	int tester[] = {1, 2, 3, 4, 5, 5, 5, 7, 20};
	check_container(tester, list_a.begin(), list_a.end());
}

bool compRev(int a, int b)
{
	return a > b;
}

TEST(ListMergePred)
{
	ft::list<int> list_a;

	list_a.push_back(7);
	list_a.push_back(5);
	list_a.push_back(5);
	list_a.push_back(5);
	list_a.push_back(1);

	ft::list<int> list_b;

	list_b.push_back(20);
	list_b.push_back(4);
	list_b.push_back(3);
	list_b.push_back(2);

	list_a.merge(list_b, compRev);

	int tester[] = {20, 7, 5, 5, 5, 4, 3, 2, 1};
	check_container(tester, list_a.begin(), list_a.end());

}

TEST(ListAssign)
{
	ft::list<int> list_a((size_t)2, 42);

	std::list<int> list_b;

	list_b.push_back(5);
	list_b.push_back(4);
	list_b.push_back(3);

	list_a.assign(list_b.begin(), list_b.end());

	int tester[] = {5, 4, 3};
	check_container(tester, list_a.begin(), list_a.end());
	check_container(tester, list_b.begin(), list_b.end());
}

TEST(ListAssignFill)
{
	ft::list<int> list_a((size_t)2, 42);

	int tester[] = {7, 7, 7};
	list_a.assign((size_t)3, 7);
	check_container(tester, list_a.begin(), list_a.end());

	list_a.assign((size_t)0, 7);
	ASSERT_EQ(list_a.size(), 0);
}

TEST(ListRangeConstructor)
{
	std::list<int> list_a;
	list_a.push_back(5);
	list_a.push_back(4);
	list_a.push_back(3);
	list_a.push_back(2);

	ft::list<int> list_b(++list_a.begin(), --list_a.end());
	int tester[] = {4, 3};
	check_container(tester, list_b.begin(), list_b.end());
}

TEST(ListReverse)
{
	ft::list<int> list_a;

	list_a.push_back(1);
	list_a.push_back(2);
	list_a.push_back(3);

	list_a.reverse();

	int tester[] = {3, 2, 1};
	check_container(tester, list_a.begin(), list_a.end());
}

TEST(ListReverseEmpty)
{
	ft::list<int> list_a;

	list_a.reverse();

	ASSERT_EQ(list_a.size(), 0);
}

TEST(ListReverseOne)
{
	ft::list<int> list_a;

	list_a.push_back(1);

	list_a.reverse();

	ASSERT_EQ(list_a.size(), 1);
	ASSERT_EQ(list_a.front(), 1);
	ASSERT_EQ(list_a.back(), 1);
}

TEST(ListReverseTwo)
{
	ft::list<int> list_a;

	list_a.push_back(1);
	list_a.push_back(2);

	list_a.reverse();

	int tester[] = {2, 1};
	check_container(tester, list_a.begin(), list_a.end());
}

TEST(ListSort)
{
	ft::list<int> list_a;

	list_a.push_back(5);
	list_a.push_back(4);
	list_a.push_back(3);
	list_a.push_back(2);
	list_a.push_back(1);

	list_a.sort();

	int tester[] = {1, 2, 3, 4, 5};
	check_container(tester, list_a.begin(), list_a.end());
}

TEST(ListMergeInterestingCase)
{

	ft::list<int> list_a;

	list_a.push_back(1);
	list_a.push_back(2);
	list_a.push_back(5);

	ft::list<int> list_b;
	list_b.push_back(3);
	list_b.push_back(4);

	list_a.merge(list_b);


	int tester[] = {1, 2, 3, 4, 5};
	check_container(tester, list_a.begin(), list_a.end());
}


TEST(ListFrontBackSplit)
{
	{
		ft::list<int> list_a;
		ft::list<int> list_b;

		list_a.push_back(2);
		list_a.push_back(1);

		list_a.frontBackSplit(list_b);

		int tester_a[] = {2};
		check_container(tester_a, list_a.begin(), list_a.end());

		int tester_b[] = {1};
		check_container(tester_b, list_b.begin(), list_b.end());
	}

	{
		ft::list<int> list_a;
		ft::list<int> list_b;

		list_a.push_back(1);
		list_a.push_back(2);
		list_a.push_back(3);

		list_a.frontBackSplit(list_b);

		int tester_a[] = {1};
		check_container(tester_a, list_a.begin(), list_a.end());

		int tester_b[] = {2, 3};
		check_container(tester_b, list_b.begin(), list_b.end());
	}
}

TEST(ListMli) {
	ft::list<int> lst(7);
	ft::list<int> lst_two(4);
	ft::list<int> lst_three;
	ft::list<int> lst_four;

	ft::list<int>::iterator it;

	it = lst.begin();
	for (unsigned long int i = 0; i < lst.size(); ++i)
		*it++ = (lst.size() - i) * 3;

	it = lst_two.begin();
	for (unsigned long int i = 0; i < lst_two.size(); ++i)
		*it++ = (lst_two.size() - i) * 5;

	std::cout << lst.size() << std::endl;
	std::cout << lst_two.size() << std::endl;

	lst_three.assign(lst.begin(), lst.end());
	lst.assign(lst_two.begin(), lst_two.end());
	lst_two.assign(2, 42);
	lst_four.assign(4, 21);

	std::cout << "\t### After assign(): ###" << std::endl;

	std::cout << lst.size() << std::endl;
	std::cout << lst_two.size() << std::endl;
	std::cout << lst_three.size() << std::endl;
	std::cout << lst_four.size() << std::endl;

	lst_four.assign(6, 84);
	std::cout << lst_four.size() << std::endl;

	std::cout << "\t### assign() : ###" << std::endl;

	lst.assign(5, 53);

	it = lst_three.begin(); ++it; ++it; ++it;
	lst_two.assign(lst_three.begin(), it);

	std::cout << lst.size() << std::endl;
	std::cout << lst_two.size() << std::endl;

	// return (0);
}

void	checkErase(ft::list<std::string> const &lst,
					ft::list<std::string>::const_iterator const &it)
{
	static int i = 0;

	int j = 0;
	ft::list<std::string>::const_iterator ite = lst.begin();
	while (it != ite--)
		++j;

	std::cout << "[" << i++ << "] " << "erase: " << j << std::endl;
	std::cout << lst.size() << std::endl;
}

TEST(MliSimple)
{
	ft::list<int> list_a;

	list_a.push_back(1);
	list_a.push_back(2);
	list_a.push_back(3);
	// list_a.push_back(4);


	ft::list<int>::const_iterator it_a = list_a.begin();
	ft::list<int>::const_iterator it_b = list_a.erase(++list_a.begin()); // should be pointing to 3;

	for (ft::list<int>::iterator iter = list_a.begin(); iter != list_a.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}	

	std::cout << "Simple bomba" << std::endl;

	size_t j = 0;
	while (it_a != it_b--)
	{
		std::cout << "Tick" << std::endl;
		++j;
	}

}

TEST(MliTest1)
{
	std::list<int> lst;

	// lst.push_back(1);
	// lst.push_back(2);
	// lst.push_back(3);
	std::cout << *(lst.end()) << std::endl;
	// std::cout << lst.size() << std::endl;

	std::cout << "BOMBA" << std::endl;
	// checkErase(lst, lst.erase(++lst.begin())
	std::list<int>::const_iterator ite = lst.begin();
	std::list<int>::const_iterator it = ++++lst.begin();
	while (it != ite--)
	{
		std::cout << "Tick" << std::endl;

	}
}

TEST(MliTest2)
{
	ft::list<std::string> lst(10);
	ft::list<std::string>::iterator ita = lst.begin();

	for (unsigned long int i = 0; i < lst.size(); ++i)
		*ita++ = std::string((lst.size() - i), i + 65);
	std::cout << lst.size() << std::endl;

	std::cout << "BOMBA" << std::endl;
	// checkErase(lst, lst.erase(++lst.begin())
	ft::list<std::string>::const_iterator ite = lst.begin();
	ft::list<std::string>::const_iterator it = lst.erase(++lst.begin());
	int j = 0;
	while (it != ite--)
	{
		std::cout << "Tick" << std::endl;
		++j;
	}
	for (ft::list<std::string>::iterator iter = lst.begin(); iter != lst.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}
}

TEST(EraseLastElement)
{
	ft::list<int> list_a;
	list_a.push_back(2);

	list_a.erase(list_a.begin());
	ASSERT_EQ(list_a.size(), 0);
	list_a.erase(list_a.begin());
	ASSERT_EQ(list_a.size(), 0);
}

TEST(ConstIteratorsAreOK)
{
	ft::list<int> list_a;

	list_a.push_back(1);
	list_a.push_back(2);
	list_a.push_back(3);
	list_a.push_back(4);

	ft::list<int>::const_iterator iter = list_a.begin();
	ASSERT_EQ(*iter++, 1);
	ASSERT_EQ(*iter++, 2);
	ASSERT_EQ(*iter++, 3);
	ASSERT_EQ(*iter++, 4);
}

TEST(EraseIterator)
{
	ft::list<int> list_a;

	list_a.push_back(1);
	list_a.push_back(2);
	list_a.push_back(3);

	list_a.erase(list_a.begin(), list_a.end());

	ASSERT_EQ(list_a.size(), 0);
}

TEST(EraseIterator2)
{
	ft::list<int> list_a;

	list_a.push_back(1);
	list_a.push_back(2);
	list_a.push_back(3);

	list_a.erase(list_a.begin(), list_a.end());

	ASSERT_EQ(list_a.size(), 0);
}

TEST(CopyConstructor)
{
	ft::list<int> list_a;

	list_a.push_back(1);
	list_a.push_back(2);
	list_a.push_back(3);

	list_a.debug();

	ft::list<int> list_b(list_a);

	list_b.debug();

	int tester[] = {1, 2, 3};
	

	list_b = list_a;

	check_container(tester, list_b.begin(), list_b.end());
}


#include <unistd.h>

int main()
{

	run_tests();

	// sleep(500);
}