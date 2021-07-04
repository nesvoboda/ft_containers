#include "elementest.hpp"
#include "map.hpp"
#include <utility>

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


int main(void)
{
	run_tests();
}