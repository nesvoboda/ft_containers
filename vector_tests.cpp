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

int main(void)
{
    run_tests();
}