#include "elementest.hpp"

#include <stack>
#include "stack.hpp"

TEST(StackConstructor)
{
	ft::stack<int> fs;
	std::stack<int> std;
}

int main(void)
{
	run_tests();
}