#include "elementest.hpp"

bool lastTestFailed = false;
int failureLine = 0;
const char *failureFile;
int testsFailed = 0;
// std::vector<TestBase *> tests;
bool exception_thrown = false;

std::vector<TestBase *> tests;

#include <unistd.h>

int main(void)
{
	run_tests();
	sleep(10);
}