#include <vector>
#include <iostream>

class TestBase {
public:
	int a;
	virtual void run() = 0;
};

std::vector<TestBase *> tests;

#define TEST(testName) \
	class testName : public TestBase { \
	public: \
		testName() { \
			tests.push_back(this);\
		} \
		void run(void); \
	}; \
	testName func_##testName;\
	void testName::run()

TEST(macarena) {
	std::cout << "Mda" << std::endl;
}

TEST(macarena2) {
	std::cout << "Mda2" << std::endl;
}

void run_tests()
{
	for (size_t i = 0; i < tests.size(); i++)
	{
		tests[i]->run();
	}
}
