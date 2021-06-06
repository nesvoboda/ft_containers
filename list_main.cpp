/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:44:04 by ashishae          #+#    #+#             */
/*   Updated: 2021/06/03 15:08:07 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"

// Test-related stuff below

#include <iostream>

// Needed to automatically fail tests;
#include <assert.h>

// #include <string.h>
#include <cstring>

bool exception_thrown = false;

void check(int expression);

#define TEST_EXCEPTION(expression, exceptionType) { \
	exception_thrown = false; \
	try \
	{ \
		expression; \
	} \
	catch (const exceptionType &e) \
	{ \
		exception_thrown = true; \
	} \
	check(exception_thrown == true); \
}

int test_no = 1;

void out(std::string s)
{
	std::cout << std::endl;
	std::cout << "\033[0;34m" << "Test " << test_no << " | " << s << "\033[0m" << std::endl;
	test_no += 1;
}

// void eo(std::string s)
// {
// 	std::cout << "\33[1;33m" << "Expected output:" <<"\033[0m" << std::endl;
// 	std::cout << s << std::endl;
// }

void check(int expression)
{
	// If expression doesn't evaluate to 1, the program will abort
	assert(expression == 1);
	std::cout << "\033[92m✓ PASS\033[0m" << std::endl;
}

int main(void)
{
	
}