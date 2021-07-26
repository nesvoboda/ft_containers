#include "elementest.hpp"

#include <stack>
#include "stack.hpp"

TEST(StackConstructor)
{
	ft::stack<int> fs;
	std::stack<int> std;
	ASSERT_EQ(fs.empty(), std.empty());
	ASSERT_EQ(fs.size(), std.size());
}

TEST(StackEmpty)
{
	ft::stack<int> fs;
	std::stack<int> std;

	ASSERT_EQ(fs.empty(), std.empty());
	ASSERT_EQ(fs.size(), std.size());
}

TEST(StackPush)
{
	ft::stack<int> fs;
	std::stack<int> std;

	fs.push(5);
	std.push(5);

	ASSERT_EQ(fs.empty(), std.empty());
	ASSERT_EQ(fs.top(), std.top());
	ASSERT_EQ(fs.size(), std.size());
}


TEST(StackPush2)
{
	ft::stack<int> fs;
	std::stack<int> std;

	fs.push(5);
	std.push(5);

	fs.push(2);
	std.push(2);

	ASSERT_EQ(fs.empty(), std.empty());
	ASSERT_EQ(fs.top(), std.top());
	ASSERT_EQ(fs.size(), std.size());
}

TEST(StackPop)
{
	ft::stack<int> fs;
	std::stack<int> std;

	fs.push(5);
	std.push(5);

	fs.push(2);
	std.push(2);

	fs.pop();
	std.pop();

	ASSERT_EQ(fs.empty(), std.empty());
	ASSERT_EQ(fs.top(), std.top());
	ASSERT_EQ(fs.size(), std.size());
}

TEST(StackPop2)
{
	ft::stack<int> fs;
	std::stack<int> std;

	fs.push(2);
	std.push(2);

	fs.pop();
	std.pop();

	ASSERT_EQ(fs.empty(), std.empty());
	ASSERT_EQ(fs.empty(), std.empty());
	// ASSERT_EQ(fs.top(), std.top());
}

TEST(StackCopyConstructor)
{
	ft::stack<int> fs;
	std::stack<int> std;

	fs.push(5);
	std.push(5);

	fs.push(2);
	std.push(2);

	fs.pop();
	std.pop();

	ft::stack<int> fs2(fs);
	std::stack<int> std2(std);

	ASSERT_EQ(fs2.empty(), std2.empty());
	ASSERT_EQ(fs2.top(), std2.top());
	ASSERT_EQ(fs2.size(), std2.size());
}

TEST(StackRelativeOperators1)
{
	ft::stack<int> fs;
	std::stack<int> std;

	ft::stack<int> fs_a;
	std::stack<int> std_a;

	ASSERT_EQ((fs == fs_a), (std == std_a));
	ASSERT_EQ((fs != fs_a), (std != std_a));
	ASSERT_EQ((fs < fs_a), (std < std_a));
	ASSERT_EQ((fs <= fs_a), (std <= std_a));
	ASSERT_EQ((fs > fs_a), (std > std_a));
	ASSERT_EQ((fs >= fs_a), (std >= std_a));
}

TEST(StackRelativeOperators2)
{
	ft::stack<int> fs;
	std::stack<int> std;

	fs.push(2);
	std.push(2);

	ft::stack<int> fs_a;
	std::stack<int> std_a;

	ASSERT_EQ((fs == fs_a), (std == std_a));
	ASSERT_EQ((fs != fs_a), (std != std_a));
	ASSERT_EQ((fs < fs_a), (std < std_a));
	ASSERT_EQ((fs <= fs_a), (std <= std_a));
	ASSERT_EQ((fs > fs_a), (std > std_a));
	ASSERT_EQ((fs >= fs_a), (std >= std_a));
}

TEST(StackRelativeOperators3)
{
	ft::stack<int> fs;
	std::stack<int> std;

	ft::stack<int> fs_a;
	std::stack<int> std_a;

	fs_a.push(2);
	std_a.push(2);


	ASSERT_EQ((fs == fs_a), (std == std_a));
	ASSERT_EQ((fs != fs_a), (std != std_a));
	ASSERT_EQ((fs < fs_a), (std < std_a));
	ASSERT_EQ((fs <= fs_a), (std <= std_a));
	ASSERT_EQ((fs > fs_a), (std > std_a));
	ASSERT_EQ((fs >= fs_a), (std >= std_a));
}

TEST(StackRelativeOperators4)
{
	ft::stack<int> fs;
	std::stack<int> std;

	ft::stack<int> fs_a;
	std::stack<int> std_a;

	fs_a.push(2);
	std_a.push(2);

	fs.push(2);
	std.push(2);


	ASSERT_EQ((fs == fs_a), (std == std_a));
	ASSERT_EQ((fs != fs_a), (std != std_a));
	ASSERT_EQ((fs < fs_a), (std < std_a));
	ASSERT_EQ((fs <= fs_a), (std <= std_a));
	ASSERT_EQ((fs > fs_a), (std > std_a));
	ASSERT_EQ((fs >= fs_a), (std >= std_a));
}

TEST(StackRelativeOperators5)
{
	ft::stack<int> fs;
	std::stack<int> std;

	ft::stack<int> fs_a;
	std::stack<int> std_a;

	fs_a.push(2);
	std_a.push(2);

	fs.push(3);
	std.push(3);


	ASSERT_EQ((fs == fs_a), (std == std_a));
	ASSERT_EQ((fs != fs_a), (std != std_a));
	ASSERT_EQ((fs < fs_a), (std < std_a));
	ASSERT_EQ((fs <= fs_a), (std <= std_a));
	ASSERT_EQ((fs > fs_a), (std > std_a));
	ASSERT_EQ((fs >= fs_a), (std >= std_a));
}

TEST(StackRelativeOperators6)
{
	ft::stack<int> fs;
	std::stack<int> std;

	ft::stack<int> fs_a;
	std::stack<int> std_a;

	fs_a.push(3);
	std_a.push(3);

	fs.push(2);
	std.push(2);


	ASSERT_EQ((fs == fs_a), (std == std_a));
	ASSERT_EQ((fs != fs_a), (std != std_a));
	ASSERT_EQ((fs < fs_a), (std < std_a));
	ASSERT_EQ((fs <= fs_a), (std <= std_a));
	ASSERT_EQ((fs > fs_a), (std > std_a));
	ASSERT_EQ((fs >= fs_a), (std >= std_a));
}

TEST(FtIsIntegral)
{
	ASSERT_EQ(ft::is_integral<int>::value, std::is_integral<int>::value);
	ASSERT_EQ(ft::is_integral<std::string>::value, std::is_integral<std::string>::value);
}



int main(void)
{
	run_tests();
}