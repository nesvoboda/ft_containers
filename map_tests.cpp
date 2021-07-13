#include "elementest.hpp"
#include "map.hpp"
#include <utility>
#include <map>

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


int main(void)
{
	run_tests();
}