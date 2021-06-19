#include "vector.hpp"
#include "elementest.hpp"

TEST(VectorConstructor)
{
    ft::vector<int> vector_a;
    std::vector<int> svector_a;

    ASSERT_EQ(vector_a.capacity(), svector_a.capacity());
}

TEST(VectorFillConstructor5)
{
    ft::vector<int> vector_a(5, 10);

    std::vector<int> svector_a(5, 10);
    for (size_t i = 0; i < 5; i++)
    {
        ASSERT_EQ(vector_a[i], svector_a[i]);
    }
}

TEST(VectorFillConstructor0)
{
    ft::vector<int> vector_a(10);

    std::vector<int> svector_a(10);
    for (size_t i = 0; i < 10; i++)
    {
        ASSERT_EQ(vector_a[i], svector_a[i]);
    }
}

TEST(VectorAt)
{
    ft::vector<int> vector_a(3);
    const ft::vector<int> vector_c(3);
    ASSERT_EXCEPTION(vector_a.at(500), std::out_of_range);
    ASSERT_EXCEPTION(vector_c.at(500), std::out_of_range);
}

TEST(VectorSize)
{
    ft::vector<int> vector_a(5);
    ft::vector<int> vector_b;
    ASSERT_EQ(vector_a.size(), 5);
    ASSERT_EQ(vector_b.size(), 0);
}

TEST(VectorPushBack)
{
    ft::vector<int> vector_a(5, 42);
    
    ASSERT_EQ(vector_a.size(), 5);
    ASSERT_EQ(vector_a[4], 42);
    vector_a.push_back(21);
    ASSERT_EQ(vector_a[5], 21);
    ASSERT_EQ(vector_a.size(), 6);
}

TEST(VectorPushBackReserve)
{
    ft::vector<int> v_a;
    std::vector<int> sv_a;

    v_a.push_back(1);
    sv_a.push_back(1);

    ASSERT_EQ(v_a.capacity(), sv_a.capacity());

    v_a.push_back(2);
    sv_a.push_back(2);

    ASSERT_EQ(v_a.capacity(), sv_a.capacity());

    v_a.push_back(3);
    sv_a.push_back(3);

    ASSERT_EQ(v_a.capacity(), sv_a.capacity());

    v_a.push_back(4);
    sv_a.push_back(4);

    ASSERT_EQ(v_a.capacity(), sv_a.capacity());

    v_a.push_back(5);
    sv_a.push_back(5);

    ASSERT_EQ(v_a.capacity(), sv_a.capacity());

    v_a.push_back(6);
    sv_a.push_back(6);

    ASSERT_EQ(v_a.capacity(), sv_a.capacity());

    v_a.push_back(7);
    sv_a.push_back(7);

    ASSERT_EQ(v_a.capacity(), sv_a.capacity());

    v_a.push_back(8);
    sv_a.push_back(8);

    ASSERT_EQ(v_a.capacity(), sv_a.capacity());

    v_a.push_back(9);
    sv_a.push_back(9);

    ASSERT_EQ(v_a.capacity(), sv_a.capacity());

    v_a.push_back(10);
    sv_a.push_back(10);

    ASSERT_EQ(v_a.capacity(), sv_a.capacity());
}

TEST(VectorPopBack)
{
    ft::vector<int> vector_a(5, 42);
    
    ASSERT_EQ(vector_a.size(), 5);
    ASSERT_EQ(vector_a[4], 42);
    vector_a.pop_back();
    ASSERT_EQ(vector_a.size(), 4);
    ASSERT_EQ(vector_a[3], 42);
}

TEST(VectorCapacity)
{
    ft::vector<int> vector_a(5, 42);
    std::vector<int> svector_a(5, 42);
    
    ASSERT_EQ(vector_a.capacity(), svector_a.capacity());
    // std::cout << svector_a.capacity() << std::endl;
    // std::cout << svector_a.capacity() << std::endl;
}

TEST(VectorReserve)
{
    ft::vector<int> vector_a(5, 42);
    std::vector<int> svector_a(5, 42);
    
    ASSERT_EQ(vector_a.capacity(), svector_a.capacity());
    vector_a.reserve(3);
    svector_a.reserve(3);
    ASSERT_EQ(vector_a.capacity(), svector_a.capacity());
    vector_a.reserve(20);
    svector_a.reserve(20);
    ASSERT_EQ(vector_a.capacity(), svector_a.capacity());

    int tester[] = {42, 42, 42, 42, 42};
    check_container(tester, vector_a.begin(), vector_a.begin());
}


TEST(VectorEmpty)
{
    ft::vector<int> vector_a(5, 42);
    
    ASSERT_EQ(vector_a.empty(), false);

    ft::vector<int> vector_b;
    
    ASSERT_EQ(vector_b.empty(), true);
}

TEST(VectorClear)
{
    ft::vector<int> vector_a(5, 42);
    vector_a.clear();
    ASSERT_EQ(vector_a.size(), 0);
    ASSERT_EQ(vector_a.empty(), true);
}

TEST(VectorIteratorConstructs)
{
    ft::vector<int>::iterator iter;
}

TEST(VectorIteratorCopyConstructs)
{
    ft::vector<int>::iterator iter;
    ft::vector<int>::iterator iter2(iter);
}

TEST(VectorConstIteratorConstructs)
{
    ft::vector<int>::const_iterator iter;
}

TEST(VectorConstIteratorCopyConstructs)
{
    ft::vector<int>::const_iterator iter;
    ft::vector<int>::const_iterator iter2(iter);
}

TEST(VectorIteratorConstructsFromElement)
{
    ft::vector<int> vector_a(5, 42);
    ft::vector<int>::iterator iter(&vector_a[0]);
}

TEST(VectorConstIteratorConstructsFromElement)
{
    ft::vector<int> vector_a(5, 42);
    ft::vector<int>::const_iterator iter(&vector_a[0]);
}

TEST(VectorIteratorPlusPlus)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::iterator iter(&vector_a[0]);
    ASSERT_EQ(*iter, 42);
    iter++;
    ASSERT_EQ(*iter, 21);
}

TEST(VectorIteratorPlusPlusInt)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::iterator iter(&vector_a[0]);
    ASSERT_EQ(*iter, 42);
    ++iter;
    ASSERT_EQ(*iter, 21);
}

TEST(VectorConstIteratorPlusPlus)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::const_iterator iter(&vector_a[0]);
    ASSERT_EQ(*iter, 42);
    iter++;
    ASSERT_EQ(*iter, 21);
}

TEST(VectorConstIteratorPlusPlusInt)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::const_iterator iter(&vector_a[0]);
    ASSERT_EQ(*iter, 42);
    ++iter;
    ASSERT_EQ(*iter, 21);
}

TEST(VectorIteratorMinusMinus)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::iterator iter(&vector_a[0]);
    ASSERT_EQ(*iter, 42);
    iter++;
    ASSERT_EQ(*iter, 21);
    iter--;
    ASSERT_EQ(*iter, 42);
}

TEST(VectorIteratorMinusMinusInt)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::iterator iter(&vector_a[0]);
    ASSERT_EQ(*iter, 42);
    ++iter;
    ASSERT_EQ(*iter, 21);
    --iter;
    ASSERT_EQ(*iter, 42);
}


TEST(VectorConstIteratorMinusMinus)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::const_iterator iter(&vector_a[0]);
    ASSERT_EQ(*iter, 42);
    iter++;
    ASSERT_EQ(*iter, 21);
    iter--;
    ASSERT_EQ(*iter, 42);
}

TEST(VectorConstIteratorMinusMinusInt)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::const_iterator iter(&vector_a[0]);
    ASSERT_EQ(*iter, 42);
    ++iter;
    ASSERT_EQ(*iter, 21);
    --iter;
    ASSERT_EQ(*iter, 42);
}


TEST(VectorIteratorArrow)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::iterator iter(&vector_a[0]);
    ASSERT_EQ(*iter, 42);
    ASSERT_EQ(*(iter.operator->()), 42);
    ++iter;
    ASSERT_EQ(*iter, 21);
    ASSERT_EQ(*(iter.operator->()), 21);
}

TEST(VectorConstIteratorArrow)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::const_iterator iter(&vector_a[0]);
    ASSERT_EQ(*iter, 42);
    ASSERT_EQ(*(iter.operator->()), 42);
    ++iter;
    ASSERT_EQ(*iter, 21);
    ASSERT_EQ(*(iter.operator->()), 21);
}

TEST(VectorCanAssignAt)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ASSERT_EQ(vector_a[1], 21);
    vector_a[1] = 42;
    ASSERT_EQ(vector_a[1], 42);
    vector_a.at(1) = 21;
    ASSERT_EQ(vector_a[1], 21);
}

TEST(VectorIteratorCanAssignAt)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::iterator iter(&vector_a[1]);
    ASSERT_EQ(*iter, 21);
    *iter = 42;
    ASSERT_EQ(vector_a[1], 42);
}

TEST(VectorIteratorArithmeticPlus)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::iterator iter(&vector_a[0]);
    ASSERT_EQ(*iter, 42);
    ASSERT_EQ(*(iter + 2), 21);
}

TEST(VectorIteratorArithmeticMinus)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::iterator iter(&vector_a[2]);
    ASSERT_EQ(*iter, 21);
    ASSERT_EQ(*(iter - 2), 42);
}

TEST(VectorConstIteratorArithmeticPlus)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::const_iterator iter(&vector_a[0]);
    ASSERT_EQ(*iter, 42);
    ASSERT_EQ(*(iter + 2), 21);
}

TEST(VectorConstIteratorArithmeticMinus)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::const_iterator iter(&vector_a[2]);
    ASSERT_EQ(*iter, 21);
    ASSERT_EQ(*(iter - 2), 42);
}

TEST(VectorIteratorPlusEquals)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::iterator iter(&vector_a[0]);
    ASSERT_EQ(*iter, 42);
    iter += 2;
    ASSERT_EQ(*iter, 21);
}

TEST(VectorIteratorMinusEquals)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::iterator iter(&vector_a[2]);
    ASSERT_EQ(*iter, 21);
    iter -= 2;
    ASSERT_EQ(*iter, 42);
}

TEST(VectorConstIteratorPlusEquals)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::const_iterator iter(&vector_a[0]);
    ASSERT_EQ(*iter, 42);
    iter += 2;
    ASSERT_EQ(*iter, 21);
}

TEST(VectorConstIteratorMinusEquals)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::const_iterator iter(&vector_a[2]);
    ASSERT_EQ(*iter, 21);
    iter -= 2;
    ASSERT_EQ(*iter, 42);
}

/// REVERSE ITERATOR

TEST(VectorReverseIteratorConstructs)
{
    ft::vector<int>::reverse_iterator iter;
}

TEST(VectorReverseIteratorCopyConstructs)
{
    ft::vector<int>::reverse_iterator iter;
    ft::vector<int>::reverse_iterator iter2(iter);
}

TEST(VectorConstRevIteratorConstructs)
{
    ft::vector<int>::const_reverse_iterator iter;
}

TEST(VectorConstRevIteratorCopyConstructs)
{
    ft::vector<int>::const_reverse_iterator iter;
    ft::vector<int>::const_reverse_iterator iter2(iter);
}

TEST(VectorRevIteratorConstructsFromElement)
{
    ft::vector<int> vector_a(5, 42);
    ft::vector<int>::reverse_iterator iter(&vector_a[0]);
}

TEST(VectorConstRevIteratorConstructsFromElement)
{
    ft::vector<int> vector_a(5, 42);
    ft::vector<int>::const_reverse_iterator iter(&vector_a[0]);
}

TEST(VectorRevIteratorPlusPlus)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::reverse_iterator iter(&vector_a[2]);
    ASSERT_EQ(*iter, 21);
    iter++;
    ASSERT_EQ(*iter, 42);
}

TEST(VectorRevIteratorPlusPlusInt)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::reverse_iterator iter(&vector_a[2]);


    std::vector<int> svector_a(1, 42);
    svector_a.push_back(21);
    std::vector<int>::reverse_iterator siter(svector_a.begin()+2);

    ASSERT_EQ(*iter, 21);
    ASSERT_EQ(*iter, *siter);
    ++iter;
    ASSERT_EQ(*iter, 42);
}

TEST(VectorConstRevIteratorPlusPlus)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::const_reverse_iterator iter(&vector_a[2]);
    ASSERT_EQ(*iter, 21);
    iter++;
    ASSERT_EQ(*iter, 42);
}

TEST(VectorConstRevIteratorPlusPlusInt)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::const_reverse_iterator iter(&vector_a[2]);
    ASSERT_EQ(*iter, 21);
    ++iter;
    ASSERT_EQ(*iter, 42);
}

TEST(VectorRevIteratorMinusMinus)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::reverse_iterator iter(&vector_a[2]);
    ASSERT_EQ(*iter, 21);
    iter++;
    ASSERT_EQ(*iter, 42);
    iter--;
    ASSERT_EQ(*iter, 21);
}

TEST(VectorRevIteratorMinusMinusInt)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::reverse_iterator iter(&vector_a[2]);
    ASSERT_EQ(*iter, 21);
    ++iter;
    ASSERT_EQ(*iter, 42);
    --iter;
    ASSERT_EQ(*iter, 21);
}


TEST(VectorConstRevIteratorMinusMinus)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::const_reverse_iterator iter(&vector_a[2]);
    ASSERT_EQ(*iter, 21);
    iter++;
    ASSERT_EQ(*iter, 42);
    iter--;
    ASSERT_EQ(*iter, 21);
}

TEST(VectorConstRevIteratorMinusMinusInt)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::const_reverse_iterator iter(&vector_a[2]);
    ASSERT_EQ(*iter, 21);
    ++iter;
    ASSERT_EQ(*iter, 42);
    --iter;
    ASSERT_EQ(*iter, 21);
}


TEST(VectorRevIteratorArrow)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::reverse_iterator iter(&vector_a[2]);
    ASSERT_EQ(*iter, 21);
    ASSERT_EQ(*(iter.operator->()), 21);
    ++iter;
    ASSERT_EQ(*iter, 42);
    ASSERT_EQ(*(iter.operator->()), 42);
}

TEST(VectorConstRevIteratorArrow)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::const_reverse_iterator iter(&vector_a[2]);
    ASSERT_EQ(*iter, 21);
    ASSERT_EQ(*(iter.operator->()), 21);
    ++iter;
    ASSERT_EQ(*iter, 42);
    ASSERT_EQ(*(iter.operator->()), 42);
}

TEST(VectorRevIteratorCanAssignAt)
{
    ft::vector<int> vector_a(1, 42);
    vector_a.push_back(21);
    ft::vector<int>::reverse_iterator iter(&vector_a[2]);

    std::vector<int> svector_a(1, 42);
    svector_a.push_back(21);
    std::vector<int>::reverse_iterator siter(svector_a.rbegin());


    ASSERT_EQ(*iter, 21);
    ASSERT_EQ(*iter, *siter);
    *iter = 42;
    ASSERT_EQ(vector_a[1], 42);
}

TEST(VectorRevIteratorArithmeticPlus)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::reverse_iterator iter(&vector_a[3]);
    ASSERT_EQ(*iter, 21);
    ASSERT_EQ(*(iter + 2), 42);
}

TEST(VectorRevIteratorArithmeticMinus)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::reverse_iterator iter(&vector_a[1]);
    ASSERT_EQ(*iter, 42);
    ASSERT_EQ(*(iter - 2), 21);
}

TEST(VectorConstRevIteratorArithmeticPlus)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::const_reverse_iterator iter(&vector_a[3]);
    ASSERT_EQ(*iter, 21);
    ASSERT_EQ(*(iter + 2), 42);
}

TEST(VectorConstRevIteratorArithmeticMinus)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::const_reverse_iterator iter(&vector_a[1]);
    ASSERT_EQ(*iter, 42);
    ASSERT_EQ(*(iter - 2), 21);
}

TEST(VectorRevIteratorPlusEquals)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::reverse_iterator iter(&vector_a[3]);
    ASSERT_EQ(*iter, 21);
    iter += 2;
    ASSERT_EQ(*iter, 42);
}

TEST(VectorRevIteratorMinusEquals)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::reverse_iterator iter(&vector_a[1]);
    ASSERT_EQ(*iter, 42);
    iter -= 2;
    ASSERT_EQ(*iter, 21);
}

TEST(VectorConstRevIteratorPlusEquals)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::const_reverse_iterator iter(&vector_a[3]);
    ASSERT_EQ(*iter, 21);
    iter += 2;
    ASSERT_EQ(*iter, 42);
}

TEST(VectorConstRevIteratorMinusEquals)
{
    ft::vector<int> vector_a(2, 42);
    vector_a.push_back(21);

    ft::vector<int>::const_reverse_iterator iter(&vector_a[1]);
    ASSERT_EQ(*iter, 42);
    iter -= 2;
    ASSERT_EQ(*iter, 21);
}

TEST(VectorBegin)
{
    ft::vector<int> vector_a;
    vector_a.push_back(4);
    vector_a.push_back(2);

    ft::vector<int>::iterator it = vector_a.begin();

    ASSERT_EQ(*it, 4);

    const ft::vector<int> vector_b(2, 4);

    ft::vector<int>::const_iterator it2 = vector_b.begin();
    ASSERT_EQ(*it2, 4);
}

TEST(VectorRbegin)
{
    {
        ft::vector<int> vector_a;
        vector_a.push_back(4);
        vector_a.push_back(2);

        std::vector<int> svector_a;
        svector_a.push_back(4);
        svector_a.push_back(2);

        ASSERT_EQ(*(vector_a.rbegin()), *(svector_a.rbegin()));   
    }

    {
        const ft::vector<int> vector_a(2, 44);

        const std::vector<int> svector_a(2, 44);

        ASSERT_EQ(*(vector_a.rbegin()), *(svector_a.rbegin()));
    }

}

TEST(VectorRend)
{
    ft::vector<int> vector_a;
    vector_a.push_back(4);
    vector_a.push_back(2);

    std::vector<int> svector_a;
    svector_a.push_back(4);
    svector_a.push_back(2);

    ASSERT_EQ(*(--vector_a.rend()), *(--svector_a.rend()));


}

TEST(VectorFront)
{
    ft::vector<int> vector_a;
    vector_a.push_back(4);
    vector_a.push_back(2);

    std::vector<int> svector_a;
    svector_a.push_back(4);
    svector_a.push_back(2);

    ASSERT_EQ(vector_a.front(),svector_a.front());

    const int& a = vector_a.front();
    const int& b = svector_a.front();

    ASSERT_EQ(a, b);
}

TEST(VectorBack)
{
    ft::vector<int> vector_a;
    vector_a.push_back(4);
    vector_a.push_back(2);

    std::vector<int> svector_a;
    svector_a.push_back(4);
    svector_a.push_back(2);

    ASSERT_EQ(vector_a.back(), svector_a.back());

    const int& a = vector_a.back();
    const int& b = svector_a.back();

    ASSERT_EQ(a, b);
}

TEST(VectorEnd)
{
    ft::vector<int> vector_a;
    vector_a.push_back(4);
    vector_a.push_back(2);

    std::vector<int> svector_a;
    svector_a.push_back(4);
    svector_a.push_back(2);

    ASSERT_EQ(*(--vector_a.end()), *(--svector_a.end()));
}

TEST(VectorAssign1)
{
    ft::vector<int> vector_a;
    vector_a.push_back(4);
    vector_a.push_back(2);
    
    ASSERT_EQ(vector_a.size(), 2);

    vector_a.assign(5, 10);

    ASSERT_EQ(vector_a.size(), 5);
    int tester[] = {10, 10, 10, 10, 10};
    check_container(tester, vector_a.begin(), vector_a.end());
}

TEST(VectorAssign2)
{
    ft::vector<int> vector_a;
    vector_a.push_back(4);
    vector_a.push_back(2);
    
    ASSERT_EQ(vector_a.size(), 2);

    std::vector<int> b(4, 42);

    vector_a.assign(b.begin(), b.end());

    ASSERT_EQ(vector_a.size(), 4);
    int tester[] = {42, 42, 42, 42};
    check_container(tester, vector_a.begin(), vector_a.end());
}

TEST(VectorRangeConst)
{
    std::vector<int> base;
    base.push_back(1);
    base.push_back(5);
    base.push_back(4);
    base.push_back(3);

    ft::vector<int> vector_a(base.begin(), base.end());
    
    
    ASSERT_EQ(vector_a.size(), 4);

    int tester[] = {1, 5, 4, 3};
    check_container(tester, vector_a.begin(), vector_a.end());
}

TEST(VectorCopy)
{
    ft::vector<int> v_a;

    v_a.push_back(21);
    v_a.push_back(42);
    v_a.push_back(1337);

    ft::vector<int> v_b(v_a);

    int tester[] = {21, 42, 1337};
    check_container(tester, v_b.begin(), v_b.end());
}

TEST(VectorCopyAssignment)
{
     ft::vector<int> v_a;

    v_a.push_back(21);
    v_a.push_back(42);
    v_a.push_back(1337);

    ft::vector<int> v_b;

    v_b.push_back(1);

    v_b = v_a;

    int tester[] = {21, 42, 1337};
    check_container(tester, v_b.begin(), v_b.end());
}

TEST(VectorCopyAssignment2)
{
     ft::vector<int> v_a;

    v_a.push_back(21);
    v_a.push_back(42);
    v_a.push_back(1337);
    v_a.push_back(1337);
    v_a.push_back(1337);
    v_a.push_back(1337);
    v_a.push_back(1337);
    v_a.push_back(1337);
    v_a.push_back(1337);
    v_a.push_back(1337);
    v_a.push_back(1337);
    v_a.push_back(1337);

    ft::vector<int> v_b;

    v_b.push_back(1);

    v_b = v_a;

    int tester[] = {21, 42, 1337, 1337, 1337, 1337, 1337, 1337, 1337, 1337, 1337, 1337};
    check_container(tester, v_b.begin(), v_b.end());
}

TEST(VectorResize)
{
    ft::vector<int> v_a;

    v_a.resize(5, 42);

    ASSERT_EQ(v_a.size(), 5);

    int tester[] = {42, 42, 42, 42, 42};
    check_container(tester, v_a.begin(), v_a.end());

    v_a.resize(2, 21);

    int tester2[] = {42, 42};
    check_container(tester2, v_a.begin(), v_a.end());
}

TEST(VectorInsertMiddle)
{
    ft::vector<int> v_a;
    v_a.push_back(1);
    v_a.push_back(2);
    v_a.push_back(3);

    ft::vector<int>::iterator it = v_a.insert(++v_a.begin(), 21);

    int tester[] = {1, 21, 2, 3};

    check_container(tester, v_a.begin(), v_a.end());
    ASSERT_EQ(*it, 21);
}

TEST(VectorInsertBegin)
{
    ft::vector<int> v_a;
    v_a.push_back(1);
    v_a.push_back(2);
    v_a.push_back(3);

    ft::vector<int>::iterator it = v_a.insert(v_a.begin(), 21);

    int tester[] = {21, 1, 2, 3};

    check_container(tester, v_a.begin(), v_a.end());

    ASSERT_EQ(*it, 21);
}


TEST(VectorInsertEnd)
{
    ft::vector<int> v_a;
    v_a.push_back(1);
    v_a.push_back(2);
    v_a.push_back(3);

    ft::vector<int>::iterator it = v_a.insert(v_a.end(), 21);

    int tester[] = {1, 2, 3, 21};

    check_container(tester, v_a.begin(), v_a.end());
    ASSERT_EQ(*it, 21);
}












/////////////////////

TEST(VectorInsertFillMiddle)
{
    ft::vector<int> v_a;
    v_a.push_back(1);
    v_a.push_back(2);
    v_a.push_back(3);

    int tester_a[] = {1, 2, 3};

    check_container(tester_a, v_a.begin(), v_a.end());

    std::cout << "Test: insert" << std::endl;
    std::cout << "Actual address of first element: " << &v_a.front() << std::endl;
    std::cout << "Actual value of first element: " << v_a.front() << std::endl;
    std::cout << "Actual value of begin: " << *(++v_a.begin()) << std::endl;
    std::cout << "Actual adress of begin: " << (++v_a.begin()).base() << std::endl;

    v_a.insert(++v_a.begin(), 3, 7);

    int tester[] = {1, 7, 7, 7, 2, 3};

    check_container(tester, v_a.begin(), v_a.end());
}

TEST(VectorInsertFillBegin)
{
    ft::vector<int> v_a;
    v_a.push_back(1);
    v_a.push_back(2);
    v_a.push_back(3);

    v_a.insert(v_a.begin(), 3, 7);

    int tester[] = {7, 7, 7, 1, 2, 3};

    check_container(tester, v_a.begin(), v_a.end());
}


TEST(VectorInsertFillEnd)
{
    ft::vector<int> v_a;
    v_a.push_back(1);
    v_a.push_back(2);
    v_a.push_back(3);

    v_a.insert(v_a.end(), 3, 7);

    int tester[] = {1, 2, 3, 7, 7, 7};

    check_container(tester, v_a.begin(), v_a.end());
}





TEST(VectorEraseMiddle)
{
    ft::vector<int> v_a;
    v_a.push_back(1);
    v_a.push_back(2);
    v_a.push_back(3);

    ft::vector<int>::iterator iter = v_a.erase(++v_a.begin());
    ASSERT_EQ(*iter, 3);

    int tester[] = {1, 3};

    check_container(tester, v_a.begin(), v_a.end());
}

TEST(VectorEraseBegin)
{
    ft::vector<int> v_a;
    v_a.push_back(1);
    v_a.push_back(2);
    v_a.push_back(3);

    ft::vector<int>::iterator iter = v_a.erase(v_a.begin());

    int tester[] = {2, 3};
    ASSERT_EQ(*iter, 2);

    check_container(tester, v_a.begin(), v_a.end());
}


TEST(VectorEraseEnd)
{
    ft::vector<int> v_a;
    v_a.push_back(1);
    v_a.push_back(2);
    v_a.push_back(3);

    ft::vector<int>::iterator iter = v_a.erase(--v_a.end());
    CHECK_EQ(iter, v_a.end());

    int tester[] = {1, 2};

    check_container(tester, v_a.begin(), v_a.end());
}





TEST(VectorEraseRangeMiddle)
{
    ft::vector<int> v_a;
    v_a.push_back(1);
    v_a.push_back(2);
    v_a.push_back(3);
    v_a.push_back(4);
    v_a.push_back(5);

    ft::vector<int>::iterator iter = v_a.erase(++v_a.begin(), ++++++v_a.begin());
    ASSERT_EQ(*iter, 4);

    int tester[] = {1, 4, 5};

    check_container(tester, v_a.begin(), v_a.end());
}

TEST(VectorEraseRangeBegin)
{
    ft::vector<int> v_a;
    v_a.push_back(1);
    v_a.push_back(2);
    v_a.push_back(3);
    v_a.push_back(4);
    v_a.push_back(5);

    ft::vector<int>::iterator iter = v_a.erase(v_a.begin(), ++++v_a.begin());

    int tester[] = {3, 4, 5};
    ASSERT_EQ(*iter, 3);

    check_container(tester, v_a.begin(), v_a.end());
}


TEST(VectorEraseRangeEnd)
{
    ft::vector<int> v_a;
    v_a.push_back(1);
    v_a.push_back(2);
    v_a.push_back(3);
    v_a.push_back(4);
    v_a.push_back(5);

    ft::vector<int>::iterator iter = v_a.erase(----v_a.end(), v_a.end());
    CHECK_EQ(iter, v_a.end());

    int tester[] = {1, 2, 3};

    check_container(tester, v_a.begin(), v_a.end());
}

TEST(VectorSwap)
{
    ft::vector<int> v_a;
    v_a.push_back(1);
    v_a.push_back(2);
    v_a.push_back(3);
    v_a.push_back(4);
    v_a.push_back(5);

    ft::vector<int> v_b;
    v_b.push_back(6);
    v_b.push_back(7);
    v_b.push_back(8);

    v_a.swap(v_b);

    int tester[] = {1, 2, 3, 4, 5};
    int tester2[] = {6, 7, 8};

    check_container(tester, v_b.begin(), v_b.end());
    check_container(tester2, v_a.begin(), v_a.end());
}

TEST(VectorEquals)
{
    ft::vector<int> v_a;
    ft::vector<int> v_b;

    ASSERT_EQ((v_a == v_b), true);
    
    v_a.push_back(1);
    ASSERT_EQ((v_a == v_b), false);

    v_b.push_back(1);
    ASSERT_EQ((v_a == v_b), true);
}

TEST(VectorGreater)
{
    ft::vector<int> v_a;
    ft::vector<int> v_b;

    ASSERT_EQ((v_a > v_b), false);
    ASSERT_EQ((v_b > v_a), false);
    
    v_a.push_back(1);
    ASSERT_EQ((v_a > v_b), true);
    ASSERT_EQ((v_b > v_a), false);

    v_b.push_back(1);
    ASSERT_EQ((v_a > v_b), false);
    ASSERT_EQ((v_b > v_a), false);

    v_a.push_back(2);
    v_b.push_back(1);
    ASSERT_EQ((v_a > v_b), true);
    ASSERT_EQ((v_b > v_a), false);
}

TEST(VectorSmaller)
{
    ft::vector<int> v_a;
    ft::vector<int> v_b;

    ASSERT_EQ((v_a < v_b), false);
    ASSERT_EQ((v_b < v_a), false);
    
    v_a.push_back(1);
    ASSERT_EQ((v_a < v_b), false);
    ASSERT_EQ((v_b < v_a), true);

    v_b.push_back(1);
    ASSERT_EQ((v_a < v_b), false);
    ASSERT_EQ((v_b < v_a), false);

    v_a.push_back(2);
    v_b.push_back(1);
    ASSERT_EQ((v_a < v_b), false);
    ASSERT_EQ((v_b < v_a), true);
}

TEST(VectorGreaterOrEq)
{
    ft::vector<int> v_a;
    ft::vector<int> v_b;

    ASSERT_EQ((v_a >= v_b), true);
    ASSERT_EQ((v_b >= v_a), true);
    
    v_a.push_back(1);
    ASSERT_EQ((v_a >= v_b), true);
    ASSERT_EQ((v_b >= v_a), false);

    v_b.push_back(1);
    ASSERT_EQ((v_a >= v_b), true);
    ASSERT_EQ((v_b >= v_a), true);

    v_a.push_back(2);
    v_b.push_back(1);
    ASSERT_EQ((v_a >= v_b), true);
    ASSERT_EQ((v_b >= v_a), false);
}

TEST(VectorSmallerOrEqual)
{
    ft::vector<int> v_a;
    ft::vector<int> v_b;

    ASSERT_EQ((v_a <= v_b), true);
    ASSERT_EQ((v_b <= v_a), true);
    
    v_a.push_back(1);
    ASSERT_EQ((v_a <= v_b), false);
    ASSERT_EQ((v_b <= v_a), true);

    v_b.push_back(1);
    ASSERT_EQ((v_a <= v_b), true);
    ASSERT_EQ((v_b <= v_a), true);

    v_a.push_back(2);
    v_b.push_back(1);
    ASSERT_EQ((v_a <= v_b), false);
    ASSERT_EQ((v_b <= v_a), true);
}

TEST(VectorMaxSize)
{
    ft::vector<int> vec_a;
    std::vector<int> svec_a;

    ASSERT_EQ(vec_a.max_size(), svec_a.max_size());
}

TEST(VectorReverseIteratorValueAssignment)
{
	ft::vector<int> v(5);

	ft::vector<int>::reverse_iterator it = v.rbegin();

	for(int i = 0; i < 5; i++)
	{
		std::cout << "i: " << i << std::endl;
		it[i] = i;
	}
}

/*
TEST(STDMadness)
{
    std::vector<int> v1(2, 42);
    std::vector<int> v2(2, 21);

    std::vector<int>::reverse_iterator it1 = v1.begin();
    std::vector<int>::iterator it2 = v2.begin();

    size_t it3 = v1 - v2;
    std::cout << it3 << std::endl;
}
*/

int main(void)
{
    run_tests();
}