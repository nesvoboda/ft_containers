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


TEST(MapBrackets)
{
	ft::map<std::string, int> m1;
	std::map<std::string, int> sm1;

	m1["42"] = 21;
	sm1["42"] = 21;

	ASSERT_EQ(m1["42"], sm1["42"]);

	m1["42"] = 42;
	sm1["42"] = 42;

	ASSERT_EQ(m1["42"], sm1["42"]);
}

TEST(MapIteratorConstructible)
{
	ft::map<std::string, int>::iterator iter1;
}


TEST(MapIteratorCopyConstructible)
{
	ft::map<std::string, int>::iterator iter1;
	ft::map<std::string, int>::iterator iter2(iter1);
}

TEST(MapIteratorCopyAssignable)
{
	ft::map<std::string, int>::iterator iter1;
	ft::map<std::string, int>::iterator iter2;

	iter2 = iter1;
}

TEST(MapConstIteratorConstructible)
{
	ft::map<std::string, int>::const_iterator iter1;
}


TEST(MapConstIteratorCopyConstructible)
{
	ft::map<std::string, int>::const_iterator iter1;
	ft::map<std::string, int>::const_iterator iter2(iter1);
}

TEST(MapConstIteratorCopyAssignable)
{
	ft::map<std::string, int>::const_iterator iter1;
	ft::map<std::string, int>::const_iterator iter2;

	iter2 = iter1;
}

TEST(MapBeginAndIterComparison)
{
	ft::map<std::string, int> m1;
	std::map<std::string, int> sm1;

	ft::map<std::string, int>::iterator it1 = m1.begin();
	std::map<std::string, int>::iterator sit1 = sm1.begin();

	m1["42"] = 21;
	sm1["42"] = 21;

	ft::map<std::string, int>::iterator it2 = m1.begin();
	std::map<std::string, int>::iterator sit2 = sm1.begin();

	ft::map<std::string, int>::iterator it0;
	std::map<std::string, int>::iterator sit0;

	ASSERT_EQ((*it2).first, (*sit2).first);
	ASSERT_EQ((*it2).second, (*sit2).second);

	CHECK_NEQ(it1, it2);
	CHECK_NEQ(it1, it0);
}

TEST(MapIteratorArrow)
{
	ft::map<std::string, int> m1;
	std::map<std::string, int> sm1;

	m1["42"] = 21;
	sm1["42"] = 21;

	ft::map<std::string, int>::iterator it2 = m1.begin();
	std::map<std::string, int>::iterator sit2 = sm1.begin();

	ASSERT_EQ(it2->first, sit2->first);

	// ft::map<std::string, int>::iterator it0;
	// std::map<std::string, int>::iterator sit0;

	// ASSERT_EQ((*it2).first, (*sit2).first);
	// ASSERT_EQ((*it2).second, (*sit2).second);

	// CHECK_NEQ(it1, it2);
	// CHECK_NEQ(it1, it0);
}

TEST(MapIteratorPlusPlusInt)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::iterator it2 = m1.begin();
	std::map<int, bool>::iterator sit2 = sm1.begin();

	while (sit2 != sm1.end())
	{
		// std::cout << "it2: " << it2->first << ", sit2: " << sit2->first << std::endl;
		ASSERT_EQ((it2++)->first, (sit2++)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	CHECK_EQ(it2, m1.end());
	CHECK_EQ(it0, m1.end());

}

TEST(MapIteratorPlusPlus)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::iterator it2 = m1.begin();
	std::map<int, bool>::iterator sit2 = sm1.begin();

	while (sit2 != (--sm1.end()))
	{
		ASSERT_EQ((++it2)->first, (++sit2)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	// CHECK_EQ(it2, m1.end());
	// CHECK_EQ(it0, m1.end());

}

TEST(MapConstIteratorPlusPlusInt)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::const_iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::const_iterator it2 = m1.begin();
	std::map<int, bool>::const_iterator sit2 = sm1.begin();

	while (sit2 != sm1.end())
	{
		ASSERT_EQ((it2++)->first, (sit2++)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	CHECK_EQ(it2, m1.end());
	CHECK_EQ(it0, m1.end());

}

TEST(MapConstIteratorPlusPlus)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::const_iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::const_iterator it2 = m1.begin();
	std::map<int, bool>::const_iterator sit2 = sm1.begin();

	while (sit2 != (--sm1.end()))
	{
		ASSERT_EQ((++it2)->first, (++sit2)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	// CHECK_EQ(it2, m1.end());
	// CHECK_EQ(it0, m1.end());

}

TEST(MapReverseIteratorPlusPlusInt)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::reverse_iterator it0 = m1.rbegin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::reverse_iterator it2 = m1.rbegin();
	std::map<int, bool>::reverse_iterator sit2 = sm1.rbegin();

	while (sit2 != sm1.rend())
	{
		ASSERT_EQ((it2++)->first, (sit2++)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	CHECK_EQ(it2, m1.rend());
	// CHECK_EQ(it0, m1.rend());

}

TEST(MapReverseIteratorPlusPlus)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::reverse_iterator it0 = m1.rbegin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::reverse_iterator it2 = m1.rbegin();
	std::map<int, bool>::reverse_iterator sit2 = sm1.rbegin();

	while (sit2 != (--sm1.rend()))
	{
		ASSERT_EQ((++it2)->first, (++sit2)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	// CHECK_EQ(it2, m1.end());
	// CHECK_EQ(it0, m1.end());

}

TEST(MapEraseSingle)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::iterator it2 = m1.begin();
	std::map<int, bool>::iterator sit2 = sm1.begin();

	m1.erase(++m1.begin());
	sm1.erase(++sm1.begin());

	while (sit2 != sm1.end())
	{
		ASSERT_EQ((it2++)->first, (sit2++)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	CHECK_EQ(it2, m1.end());
	CHECK_EQ(it0, m1.end());

}

TEST(MapEraseByKey)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::iterator it2 = m1.begin();
	std::map<int, bool>::iterator sit2 = sm1.begin();

	ASSERT_EQ(m1.erase(7), sm1.erase(7));

	while (sit2 != sm1.end())
	{
		ASSERT_EQ((it2++)->first, (sit2++)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	CHECK_EQ(it2, m1.end());
	CHECK_EQ(it0, m1.end());

}

TEST(MapEraseByKeyMissing)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool>::iterator it2 = m1.begin();
	std::map<int, bool>::iterator sit2 = sm1.begin();

	ASSERT_EQ(m1.erase(42), sm1.erase(42));

	while (sit2 != sm1.end())
	{
		ASSERT_EQ((it2++)->first, (sit2++)->first);
	}
	// ASSERT_EQ(it2->first, sit2->first);
	CHECK_EQ(it2, m1.end());
	CHECK_EQ(it0, m1.end());

}

TEST(MapEraseRange)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	// m1.insert(ft::pair<int, bool>(6, true));
	// m1.insert(ft::pair<int, bool>(7, true));
	// m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	// sm1.insert(std::pair<int, bool>(6, true));
	// sm1.insert(std::pair<int, bool>(7, true));
	// sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));


	m1.erase(m1.begin(), --m1.end());
	// m1.erase(++m1.begin());
	// for (ft::map<int, bool>::iterator it = m1.begin(); it != ++++++++m1.begin(); it++)
		// std::cout << it->first << std::endl;
	sm1.erase(sm1.begin(), --sm1.end());
	// sm1.erase(++sm1.begin());

	ft::map<int, bool>::iterator it2 = m1.begin();
	std::map<int, bool>::iterator sit2 = sm1.begin();
	while (sit2 != sm1.end())
	{
		std::cout << it2->first << std::endl;
		ASSERT_EQ((it2++)->first, (sit2++)->first);
		// std::cout << (sit2++)->first << std::endl;
	}
	CHECK_EQ(it2, m1.end());


	// CHECK_EQ(it0, m1.end());

}

TEST(MapEraseRange2)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	// m1.insert(ft::pair<int, bool>(6, true));
	// m1.insert(ft::pair<int, bool>(7, true));
	// m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	// sm1.insert(std::pair<int, bool>(6, true));
	// sm1.insert(std::pair<int, bool>(7, true));
	// sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));


	m1.erase(m1.begin(), m1.end());
	// m1.erase(++m1.begin());
	// for (ft::map<int, bool>::iterator it = m1.begin(); it != ++++++++m1.begin(); it++)
		// std::cout << it->first << std::endl;
	sm1.erase(sm1.begin(), sm1.end());
	// sm1.erase(++sm1.begin());

	ft::map<int, bool>::iterator it2 = m1.begin();
	std::map<int, bool>::iterator sit2 = sm1.begin();
	while (sit2 != sm1.end())
	{
		std::cout << it2->first << std::endl;
		ASSERT_EQ((it2++)->first, (sit2++)->first);
		// std::cout << (sit2++)->first << std::endl;
	}
	CHECK_EQ(it2, m1.end());


	// CHECK_EQ(it0, m1.end());

}


TEST(MapSwap)
{
	ft::map<int, bool> m1;
	ft::map<int, bool> m2;
	std::map<int, bool> sm1;
	std::map<int, bool> sm2;

	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	m2.insert(ft::pair<int, bool>(-5, true));
	m2.insert(ft::pair<int, bool>(40, true));
	m2.insert(ft::pair<int, bool>(-92, true));


	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	sm2.insert(std::pair<int, bool>(-5, true));
	sm2.insert(std::pair<int, bool>(40, true));
	sm2.insert(std::pair<int, bool>(-92, true));


	
	m1.swap(m2);
	sm1.swap(sm2);


	ft::map<int, bool>::iterator it2 = m2.begin();
	std::map<int, bool>::iterator sit2 = sm2.begin();

	ft::map<int, bool>::iterator it1 = m1.begin();
	std::map<int, bool>::iterator sit1 = sm1.begin();

	// std::cout << "it1 parent " << (it1++)._ptr->parent->data.first << std::endl;
	// std::cout << "it1 parent " << it1._ptr->parent->data.first << std::endl;

	while (sit1 != sm1.end())
	{
		ASSERT_EQ((it1++)->first, (sit1++)->first);
		// std::cout << (sit1++)->first << std::endl;
	// 	// std::cout << (it1++)->first << std::endl;
	}

	while (sit2 != sm2.end())
	{
		ASSERT_EQ((it2++)->first, (sit2++)->first);
	// 	// std::cout << (sit2++)->first << std::endl;
	}
	// ASSERT_EQ(it2->first, sit2->first);
	// CHECK_EQ(it2, m1.end());
	// CHECK_EQ(it0, m1.end());

}

TEST(BinaryTreeClear)
{
	ft::map<int, bool> m1;

	std::map<int, bool> sm1;


	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	m1.clear();
	sm1.clear();

	ASSERT_EQ(m1.size(), sm1.size());
	ASSERT_EQ(m1.empty(), sm1.empty());

	m1.insert(ft::pair<int, bool>(-21, true));
	sm1.insert(std::pair<int, bool>(-21, true));

	ASSERT_EQ(m1.size(), sm1.size());
	ASSERT_EQ(m1.empty(), sm1.empty());

	ft::map<int, bool>::iterator it1 = m1.begin();
	std::map<int, bool>::iterator sit1 = sm1.begin();

	while (sit1 != sm1.end())
	{
		ASSERT_EQ((it1++)->first, (sit1++)->first);
	}
}


TEST(BinaryTreeFind)
{
	ft::map<int, bool> m1;

	std::map<int, bool> sm1;


	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ASSERT_EQ(m1.find(6)->first, sm1.find(6)->first);

	CHECK_EQ(m1.find(-42), m1.end());

}


TEST(BinaryTreeCount)
{
	ft::map<int, bool> m1;

	std::map<int, bool> sm1;


	ft::map<int, bool>::iterator it0 = m1.begin();

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ASSERT_EQ(m1.count(6), sm1.count(6));
	ASSERT_EQ(m1.count(7), sm1.count(7));
	ASSERT_EQ(m1.count(8), sm1.count(8));
	ASSERT_EQ(m1.count(9), sm1.count(9));
	ASSERT_EQ(m1.count(12), sm1.count(12));

}

TEST(BinaryTreeLowerBound)
{
	ft::map<int, bool> m1;

	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	// m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	// sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ASSERT_EQ(m1.lower_bound(5)->first, sm1.lower_bound(5)->first)
	ASSERT_EQ(m1.lower_bound(2)->first, sm1.lower_bound(2)->first)
	ASSERT_EQ((m1.lower_bound(10) == m1.end()), (sm1.lower_bound(10) == sm1.end()))
	ASSERT_EQ(m1.lower_bound(7)->first, sm1.lower_bound(7)->first)
	ASSERT_EQ(m1.lower_bound(8)->first, sm1.lower_bound(8)->first)
}

TEST(BinaryTreeUpperBound)
{
	ft::map<int, bool> m1;

	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	// m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	// sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ASSERT_EQ(m1.upper_bound(5)->first, sm1.upper_bound(5)->first)
	ASSERT_EQ(m1.upper_bound(2)->first, sm1.upper_bound(2)->first)
	ASSERT_EQ((m1.upper_bound(10) == m1.end()), (sm1.upper_bound(10) == sm1.end()))
	ASSERT_EQ(m1.upper_bound(7)->first, sm1.upper_bound(7)->first)
	ASSERT_EQ(m1.upper_bound(8)->first, sm1.upper_bound(8)->first)
}

TEST(MapCopy)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool> m2(m1);
	std::map<int, bool> sm2(sm1);

	ft::map<int,bool>::iterator mit = m2.begin();

	for (std::map<int, bool>::iterator it = sm2.begin(); it != sm2.end(); it++)
	{
		ASSERT_EQ((it)->first, (mit++)->first);
	}

	CHECK_EQ(mit, m2.end());

}

TEST(MapAssign)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool> m2;
	std::map<int, bool> sm2;

	m2.insert(ft::pair<int, bool>(-5, true));
	m2.insert(ft::pair<int, bool>(-6, true));
	m2.insert(ft::pair<int, bool>(-7, true));
	m2.insert(ft::pair<int, bool>(-8, true));
	m2.insert(ft::pair<int, bool>(-9, true));

	sm2.insert(std::pair<int, bool>(-5, true));
	sm2.insert(std::pair<int, bool>(-6, true));
	sm2.insert(std::pair<int, bool>(-7, true));
	sm2.insert(std::pair<int, bool>(-8, true));
	sm2.insert(std::pair<int, bool>(-9, true));

	m2 = m1;
	sm2 = sm1;

	ft::map<int,bool>::iterator mit = m2.begin();

	for (std::map<int, bool>::iterator it = sm2.begin(); it != sm2.end(); it++)
	{
		ASSERT_EQ((it)->first, (mit++)->first);
	}

	CHECK_EQ(mit, m2.end());

	ft::map<int,bool>::iterator mit1 = m1.begin();

	for (std::map<int, bool>::iterator it = sm1.begin(); it != sm1.end(); it++)
	{
		ASSERT_EQ((it)->first, (mit1++)->first);
	}

	CHECK_EQ(mit1, m1.end());


}


TEST(MapRangeConstructor)
{
	ft::map<int, bool> m1;
	std::map<int, bool> sm1;

	m1.insert(ft::pair<int, bool>(5, true));
	m1.insert(ft::pair<int, bool>(6, true));
	m1.insert(ft::pair<int, bool>(7, true));
	m1.insert(ft::pair<int, bool>(8, true));
	m1.insert(ft::pair<int, bool>(9, true));

	sm1.insert(std::pair<int, bool>(5, true));
	sm1.insert(std::pair<int, bool>(6, true));
	sm1.insert(std::pair<int, bool>(7, true));
	sm1.insert(std::pair<int, bool>(8, true));
	sm1.insert(std::pair<int, bool>(9, true));

	ft::map<int, bool> m2(m1.begin(), m1.end());
	std::map<int, bool> sm2(sm1.begin(), sm1.end());

	ft::map<int,bool>::iterator mit = m2.begin();

	for (std::map<int, bool>::iterator it = sm2.begin(); it != sm2.end(); it++)
	{
		ASSERT_EQ((it)->first, (mit++)->first);
	}

	CHECK_EQ(mit, m2.end());

}

// TEST(MapMaxSize)
// {
// 	ft::map<int, bool> m1;
// 	std::map<int, bool> sm1;

// 	ASSERT_EQ(m1.max_size(), sm1.max_size());
// }

int main(void)
{
	run_tests();
	// sleep(10);
}