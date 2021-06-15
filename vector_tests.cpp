#include "vector.hpp"
#include "elementest.hpp"

TEST(VectorConstructor)
{
    ft::vector<int> vector_a;
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
    
    ASSERT_EQ(vector_a.capacity(), 10);
    std::vector<int> svector_a(5, 42);
    std::cout << svector_a.capacity() << std::endl;
    svector_a.push_back(3);
    std::cout << svector_a.capacity() << std::endl;
}

TEST(VectorReserve)
{
    ft::vector<int> vector_a(5, 42);
    
    ASSERT_EQ(vector_a.capacity(), 10);
    vector_a.reserve(3);
    ASSERT_EQ(vector_a.capacity(), 10);
    vector_a.reserve(20);
    ASSERT_EQ(vector_a.capacity(), 20);
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

/*
TEST(STDMadness)
{
    std::vector<int> v1(2, 42);
    std::vector<int> v2(2, 21);

    std::vector<int>::iterator it1 = v1.begin();
    std::vector<int>::iterator it2 = v2.begin();

    size_t it3 = v1 - v2;
    std::cout << it3 << std::endl;
}
*/

int main(void)
{
    run_tests();
}