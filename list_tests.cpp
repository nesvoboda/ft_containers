#include "list.hpp"
#include "elementest.hpp"

TEST(listNodeConstructs)
{
	listNode<int> ln_i(3);
	ASSERT_EQ(ln_i.getValue(), 3);
	ASSERT_EQ(ln_i.getNext(), NULL);
	ASSERT_EQ(ln_i.getPrev(), NULL);
}

TEST(listNodeCopyConstructs)
{
	listNode<int> ln_i(3);
	listNode<int> ln_i2(ln_i);
	ASSERT_EQ(ln_i2.getValue(), 3);
	ASSERT_EQ(ln_i2.getNext(), NULL);
	ASSERT_EQ(ln_i2.getPrev(), NULL);
}

TEST(listNodeAssignmentOperator)
{
	listNode<int> ln_i(3);
	listNode<int> ln_i3(ln_i);
	ASSERT_EQ(ln_i3.getValue(), 3);
	ASSERT_EQ(ln_i3.getNext(), NULL);
	ASSERT_EQ(ln_i3.getPrev(), NULL);

	listNode<int> ln_i4(5);

	ln_i3 = ln_i4;

	ASSERT_EQ(ln_i4.getValue(), 5);
	ASSERT_EQ(ln_i4.getNext(), NULL);
	ASSERT_EQ(ln_i4.getPrev(), NULL);
}

TEST(listNodeDestructor)
{
	listNode<int> ln_i5(10);
}

TEST(listNodeGetValueSetValue)
{
	listNode<int> ln_i6(-5);
	ASSERT_EQ(ln_i6.getValue(), -5);
	ln_i6.setValue(50);
	ASSERT_EQ(ln_i6.getValue(), 50);
}

TEST(listNodeGetNextSetNext)
{
	listNode<int> ln_a(-5);
	listNode<int> ln_b(0);

	ASSERT_EQ(ln_a.getNext(), NULL);
	ln_a.setNext(&ln_b);
	ASSERT_EQ(ln_a.getNext(), &ln_b);
}

TEST(listNodeGetPrevsetPrev)
{
	listNode<int> ln_a(-5);
	listNode<int> ln_b(0);

	ASSERT_EQ(ln_a.getPrev(), NULL);
	ln_a.setPrev(&ln_b);
	ASSERT_EQ(ln_a.getPrev(), &ln_b);
}

TEST(listDefaultConstructor)
{
	list<int> l_i;
	ASSERT_EQ(l_i.empty(), true);
}

TEST(listFillConstructor)
{
	list<int> l_i1(5, 10);
	ASSERT_EQ(l_i1.front(), 10);
	ASSERT_EQ(l_i1.size(), 5);
}

TEST(listFillConstructorZeroElements)
{
	list<int> l_i1(0, 10);
	// ASSERT_EQ(l_i1.front(), 10);
	ASSERT_EQ(l_i1.size(), 0);

	// TODO check element access
}

TEST(listIteratorConstructor)
{
	listNode<int> ln_a(-5);

	list<int>::iterator it;
	list<int>::iterator it2(&ln_a);
}

TEST(listIteratorCopyConstructor)
{
	listNode<int> ln_a(-5);
	list<int>::iterator it_a(&ln_a);

	list<int>::iterator it_b(it_a);
}

TEST(listIteratorAssignmentOperator)
{
	listNode<int> ln_a(-5);
	listNode<int> ln_b(0);

	list<int>::iterator it_a(&ln_a);
	list<int>::iterator it_b(&ln_b);
	it_a = it_b;
}

TEST(listIteratorDestructor)
{
	list<int>::iterator it5;
}

TEST(listBegin)
{
	list<int> list_a(5, 10);
	list<int>::iterator iter_a = list_a.begin();
}

TEST(listIteratorStarOperator)
{
	list<int> list_a(5, 10);

	list<int>::iterator iter_a = list_a.begin();
	ASSERT_EQ(*iter_a, 10);
}

TEST(listIteratorOperatorPlusPlus)
{
	list<int> list_a(5, 10);

	list<int>::iterator iter_a = list_a.begin();
	iter_a++;
	ASSERT_EQ(*iter_a, 10);
}

TEST(listIteratorNotEqualsOperator)
{
	list<int> list_a(5, 10);

	list<int>::iterator iter_a = list_a.begin();

	iter_a++;

	list<int>::iterator iter_b = list_a.begin();
	ASSERT_EQ((iter_b != iter_a), true);
}

TEST(listIteratorOperatorMinusMinus)
{
	list<int> list_a(5, 10);

	list<int>::iterator iter_a = list_a.begin();

	iter_a++;
	--iter_a;
	ASSERT_EQ(*iter_a, 10);
	CHECK_EQ(iter_a, list_a.begin());
}

TEST(listIteratorEqualityOperator)
{
	list<int> list_a(5, 10);
	list<int>::iterator iter_a = list_a.begin();

	list<int>::iterator iter_b = list_a.begin();

	ASSERT_EQ((iter_b == iter_a), true);
}

TEST(listIteratorPlusPlusoperator)
{
	list<int> list_a(5, 10);
	list<int>::iterator iter_a = list_a.begin();

	iter_a++;

	ASSERT_EQ(*iter_a, 10);
	CHECK_NEQ(list_a.begin(), iter_a);
}

TEST(listIteratorMinusMinusoperator)
{
	list<int> list_a(5, 10);
	list<int>::iterator iter_a = list_a.begin();

	iter_a++;
	iter_a--;
	ASSERT_EQ(*iter_a, 10);
	CHECK_EQ(list_a.begin(), iter_a);
}

TEST(listEnd)
{
	list<int> list_a(5, 10);
	list<int>::iterator iter_a = list_a.begin();
	for (int i = 0; i < 5; i++)
		iter_a++;
	CHECK_EQ(iter_a, list_a.end());
}

TEST(ListReverse_iteratorConstructor)
{
	list<int>::reverse_iterator reverseiter_a;
	listNode<int> listnode_a(5);

	list<int>::reverse_iterator reverseiter_b(&listnode_a);
}

TEST(ListReverse_iteratorCopyConstructor)
{
	listNode<int> listnode_a(5);

	list<int>::reverse_iterator reverseiter_a(&listnode_a);
	list<int>::reverse_iterator reverseiter_b(reverseiter_a);
}

TEST(ListReverse_iteratorAssignmentOperator)
{
	listNode<int> listnode_a(5);
	listNode<int> listnode_b(-42);

	list<int>::reverse_iterator reverseiter_a(&listnode_a);
	list<int>::reverse_iterator reverseiter_b(&listnode_b);

	reverseiter_b = reverseiter_a;
}

TEST(ListReverse_iteratorDestructor)
{
	list<int>::reverse_iterator rit5;
}

TEST(ListRend)
{
	list<int> list_a(5, 10);
	list<int>::reverse_iterator revIter = list_a.rend();
	// Can't check the value because it's null
}

TEST(ListReverse_iteratorStaroperator)
{
	listNode<int> listNodeA(55);
	listNode<int> listNodeB(54);

	listNodeA.setPrev(&listNodeB);
	list<int>::reverse_iterator revIter(&listNodeA);
	ASSERT_EQ(*revIter, 54);
}

TEST(ListReverse_iteratorOperatorPlusPlus)
{
	list<int> list_a(5, 10);
	list<int>::reverse_iterator revIter = list_a.rend();

	revIter++;

	ASSERT_EQ(*revIter, 10);
}

TEST(ListReverse_iteratorNotEqualsoperator)
{
	list<int> list_a(5, 10);
	list<int>::reverse_iterator revIter = list_a.rend();

	revIter++;

	CHECK_NEQ(revIter, list_a.rend());
}

TEST(ListReverse_iteratoroperatorMinusMinus)
{
	list<int> list_a(5, 10);
	list<int>::reverse_iterator revIter = list_a.rend();

	revIter++;

	--revIter;
	CHECK_EQ(revIter, list_a.rend());

	++revIter;

	revIter--;
	CHECK_EQ(revIter, list_a.rend());
}

TEST(ListReverse_iteratorEqualsOperator)
{
	list<int> list_a(5, 10);
	list<int>::reverse_iterator revIter = list_a.rend();
	ASSERT_EQ((revIter == list_a.rend()), true);
	ASSERT_EQ((revIter == list_a.rbegin()), false);
}

TEST(ListReverse_iteratorPlusPlusOperator)
{
	list<int> list_a(5, 10);
	list<int>::reverse_iterator revIter = list_a.rend();
	revIter++;
	ASSERT_EQ((revIter == list_a.rend()), false);
}

TEST(ListReverse_iteratorMinusMinusOperator)
{
	list<int> list_a(5, 10);
	list<int>::reverse_iterator revIter = list_a.rend();
	revIter++;

	revIter--;
	CHECK_EQ(revIter, list_a.rend());
}

TEST(ListReverseIteratorEndBegin)
{
	list<int> list_a(5, 10);
	list<int>::reverse_iterator revIterA = list_a.rbegin(); // points to the element after the last

	for (size_t i = 0; i < 5; i++)
	{
		revIterA--;
	}
	CHECK_EQ(revIterA, list_a.rend());
}

/*
TEST(ListAssignmentOperator)
{
	list<int> list_a(5, 10);

	list<int> list_b(3, 8);
	
	list_b = list_a;

	ASSERT_EQ(list_b.size(), 5);

	list<int>::iterator iter;
	for (iter = list_b.begin(); iter != list_b.end(); iter++)
	{
		ASSERT_EQ(*iter, 10);
	}

}
*/

TEST(ListBack)
{
	list<int> list_a(1, 10);

	ASSERT_EQ(list_a.back(), 10);
}

TEST(ListBackConst)
{
	const list<int> list_a(1, 10);

	ASSERT_EQ(list_a.back(), 10);
}

TEST(ListFront)
{
	list<int> list_a(1, 10);

	ASSERT_EQ(list_a.front(), 10);
}

TEST(ListFrontConst)
{
	const list<int> list_a(1, 10);

	ASSERT_EQ(list_a.front(), 10);
}

TEST(ListPushFront)
{
	list<int> list_a;

	ASSERT_EQ(list_a.size(), 0);

	list_a.push_front(42);
	ASSERT_EQ(list_a.size(), 1);
	ASSERT_EQ(list_a.front(), 42);
	ASSERT_EQ(list_a.back(), 42);

	list<int> list_b(5, 10);
	ASSERT_EQ(list_b.size(), 5);

	list_b.push_front(-42);
	ASSERT_EQ(list_b.size(), 6);
	ASSERT_EQ(list_b.front(), -42);
	ASSERT_EQ(list_b.back(), 10);
}

TEST(ListPopFront)
{
	list<int> list_a(5, 10);
	ASSERT_EQ(list_a.size(), 5);

	list_a.push_front(-42);
	ASSERT_EQ(list_a.size(), 6);
	ASSERT_EQ(list_a.front(), -42);
	ASSERT_EQ(list_a.back(), 10);

	list_a.pop_front();
	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 10);

	list<int> list_b(5, 10);
	list_b.pop_front();
	ASSERT_EQ(list_b.size(), 4);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);

	list<int> list_c(1, 10);
	list_c.pop_front();
	ASSERT_EQ(list_c.size(), 0);
}

TEST(ListPushBack)
{
	list<int> list_a;

	ASSERT_EQ(list_a.size(), 0);

	list_a.push_back(42);
	ASSERT_EQ(list_a.size(), 1);
	ASSERT_EQ(list_a.front(), 42);
	ASSERT_EQ(list_a.back(), 42);

	list<int> list_b(5, 10);
	ASSERT_EQ(list_b.size(), 5);

	list_b.push_back(-42);
	ASSERT_EQ(list_b.size(), 6);
	ASSERT_EQ(list_b.back(), -42);
	ASSERT_EQ(list_b.front(), 10);
}

TEST(ListPopBack)
{
	list<int> list_a(5, 10);
	ASSERT_EQ(list_a.size(), 5);

	list_a.push_back(-42);
	ASSERT_EQ(list_a.size(), 6);
	ASSERT_EQ(list_a.back(), -42);
	ASSERT_EQ(list_a.front(), 10);

	list_a.pop_back();
	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_a.front(), 10);
	ASSERT_EQ(list_a.back(), 10);

	list<int> list_b(5, 10);
	list_b.pop_back();
	ASSERT_EQ(list_b.size(), 4);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);

	list<int> list_c(1, 10);
	list_c.pop_back();
	ASSERT_EQ(list_c.size(), 0);

	list<int> list_d(2, 10);
	list_d.pop_back();
	ASSERT_EQ(list_d.size(), 1);
	ASSERT_EQ(list_d.front(), 10);
	ASSERT_EQ(list_d.back(), 10);
}

TEST(ListInsertOne)
{
	list<int> list_a;
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

	list<int> list_b(5, 10);
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

	list<int>::iterator iter = list_b.begin();

	iter++;

	list_b.insert(iter, 21);
	ASSERT_EQ(list_b.size(), 8);
	ASSERT_EQ(list_b.front(), 42);
	ASSERT_EQ(list_b.back(), 44);

	ASSERT_EQ(*(++list_b.begin()), 21);
}

TEST(ListInsertFillOne)
{
	list<int> list_a;
	list_a.insert(list_a.end(), 1, 42);

	ASSERT_EQ(list_a.size(), 1);
	ASSERT_EQ(list_a.front(), 42);
	ASSERT_EQ(list_a.back(), 42);

	list_a.insert(list_a.end(), 1, 43);

	ASSERT_EQ(list_a.size(), 2);
	ASSERT_EQ(list_a.front(), 42);
	ASSERT_EQ(list_a.back(), 43);

	list_a.insert(list_a.begin(), 1, 45);

	ASSERT_EQ(list_a.size(), 3);
	ASSERT_EQ(list_a.front(), 45);
	ASSERT_EQ(list_a.back(), 43);

	list<int> list_b(5, 10);
	ASSERT_EQ(list_b.size(), 5);
	ASSERT_EQ(list_b.front(), 10);
	ASSERT_EQ(list_b.back(), 10);

	list_b.insert(list_b.begin(), 1, 42);
	ASSERT_EQ(list_b.size(), 6);
	ASSERT_EQ(list_b.front(), 42);
	ASSERT_EQ(list_b.back(), 10);

	list_b.insert(list_b.end(), 1, 44);

	ASSERT_EQ(list_b.size(), 7);
	ASSERT_EQ(list_b.front(), 42);
	ASSERT_EQ(list_b.back(), 44);

	list<int>::iterator iter = list_b.begin();

	iter++;

	list_b.insert(iter, 1, 21);
	ASSERT_EQ(list_b.size(), 8);
	ASSERT_EQ(list_b.front(), 42);
	ASSERT_EQ(list_b.back(), 44);

	ASSERT_EQ(*(++list_b.begin()), 21);
}

TEST(ListInsertFillMany)
{
	list<int> list_a;

	list_a.insert(list_a.begin(), 5, 10);

	ASSERT_EQ(list_a.size(), 5);
	ASSERT_EQ(list_a.back(), 10);
	ASSERT_EQ(list_a.front(), 10);

	list<int> list_b;
	list_b.insert(list_b.begin(), 5, 10);
	ASSERT_EQ(list_b.size(), 5);
	ASSERT_EQ(list_b.back(), 10);
	ASSERT_EQ(list_b.front(), 10);
}

#include <list>

#include <unistd.h>

int main()
{

	run_tests();

	sleep(500);

	// TODO: leaks-check

	// listNode<int> *a = l_i2.start;
	// for (int i = 0; i < 10; i++)
	// {
	// 	std::cout << "i: " << i << std::endl;
	// 	std::cout << a << std::endl;
	// 	std::cout << "value: " << a->getValue() << std::endl;
	// 	std::cout << "prev: " << a->getPrev() << std::endl;
	// 	std::cout << "next: " << a->getNext() << std::endl;

	// 	a = a->getNext();
	// }
}