/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:44:04 by ashishae          #+#    #+#             */
/*   Updated: 2021/03/23 15:37:00 by ashishae         ###   ########.fr       */
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
	out("ListNode | Constructor");
	listNode<int> ln_i(3);
	check(ln_i.getValue() == 3);
	check(ln_i.getNext() == NULL);
	check(ln_i.getPrev() == NULL);

	out("ListNode | Copy constructor");
	listNode<int> ln_i2(ln_i);
	check(ln_i2.getValue() == 3);
	check(ln_i2.getNext() == NULL);
	check(ln_i2.getPrev() == NULL);

	out("ListNode | Assgnment operator");
	listNode<int> ln_i3(ln_i);
	check(ln_i3.getValue() == 3);
	check(ln_i3.getNext() == NULL);
	check(ln_i3.getPrev() == NULL);

	listNode<int> ln_i4(5);
	
	ln_i3 = ln_i4;

	check(ln_i4.getValue() == 5);
	check(ln_i4.getNext() == NULL);
	check(ln_i4.getPrev() == NULL);

	out("ListNode | Destructor");
	{
		listNode<int> ln_i5(10);
	}
	
	out("ListNode | getValue/setValue");

	listNode<int> ln_i6(-5);
	check(ln_i6.getValue() == -5);
	ln_i6.setValue(50);
	check(ln_i6.getValue() == 50);
	
	out("ListNode | getNext/setNext");
	check(ln_i6.getNext() == NULL);
	ln_i6.setNext(&ln_i4);
	check(ln_i6.getNext() == &ln_i4);

	out("ListNode | getPrev/setPrev");
	check(ln_i6.getPrev() == NULL);
	ln_i6.setPrev(&ln_i4);
	check(ln_i6.getPrev() == &ln_i4);

	out("List | Default constructor");
	list<int> l_i;
	check(l_i.empty() == true);

	out("List | Fill constructor");
	list<int> l_i1(5, 10);
	check(l_i1.front() == 10);
	check(l_i1.size() == 5);

	out("List iterator | Constructor");
	list<int>::iterator it;

	list<int>::iterator it2(&ln_i6);

	out("List iterator | Copy constructor");
	list<int>::iterator it3(it2);

	out("List iterator | Assignment operator");
	list<int>::iterator it4(&ln_i4);

	it4 = it3;

	out("List iterator | Destructor");
	{
		list<int>::iterator it5;
	}

	list<int> l_i2(5, 10);
	
	out("List | begin()");

	list<int>::iterator lit1 = l_i2.begin();

	out("List iterator | * operator");
	check(*lit1 == 10);
	list<int>::iterator lit2 = lit1;
	
	out("List iterator | operator ++");
	lit1++;
	check(*lit1 == 10);

	out("List iterator | != operator");
	check(lit2 != lit1);

	out("List iterator | operator --");
	--lit1;
	
	check(*lit1 == 10);
	out("List iterator | == operator");
	
	check(lit2 == lit1);
	
	out("List iterator | ++ operator");
	lit1++;
	check(*lit1 == 10);
	check(lit2 != lit1);

	out("List iterator | -- operator");
	lit1--;
	check(*lit1 == 10);
	check(lit2 == lit1);

	out("List | end()");
	list<int>::iterator lit3 = l_i2.begin();

	for (int i = 0; i < 5; i++)
		lit3++;

	check(lit3 == l_i2.end());

	out("List reverse_iterator | Constructor");
	list<int>::reverse_iterator rit;

	list<int>::reverse_iterator rit2(&ln_i6);

	out("List reverse_iterator | Copy constructor");
	list<int>::reverse_iterator rit3(rit2);

	out("List reverse_iterator | Assignment operator");
	list<int>::reverse_iterator rit4(&ln_i4);

	rit4 = rit3;

	out("List reverse_iterator | Destructor");
	{
		list<int>::reverse_iterator rit5;
	}

	list<int> rl_i2(5, 10);
	
	out("List | rend()");

	list<int>::reverse_iterator rlit1 = rl_i2.end();

	out("List reverse_iterator | * operator");

	list<int>::reverse_iterator rlit2 = rlit1;
	
	out("List reverse_iterator | operator ++");
	rlit1++;
	check(*rlit1 == 10);

	out("List reverse_iterator | != operator");
	check(rlit2 != rlit1);

	out("List reverse_iterator | operator --");
	--rlit1;
	
	out("List reverse_iterator | == operator");
	
	check(rlit2 == rlit1);
	
	out("List reverse_iterator | ++ operator");
	rlit1++;
	check(*rlit1 == 10);
	check(rlit2 != rlit1);

	out("List reverse_iterator | -- operator");
	rlit1--;
	check(rlit2 == rlit1);

	out("List | rbegin()");
	list<int>::iterator rlit3 = rl_i2.rbegin();

	for (int i = 0; i < 5; i++)
		rlit3++;

	check(rlit3 == rl_i2.rend());

	out("List | assignment operator");
	list<int> l_i3(5, 10);

	list<int> l_i4(3, 8);
	
	l_i4 = l_i3;

	check(l_i4.size() == 5);
	// std::cout << l_i4.size() << std::endl;
	list<int>::iterator lit4;
	for (lit4 = l_i4.begin(); lit4 != l_i4.end(); lit4++)
	{
		check(*lit4 == 10);
	}

	////////////////////////////////////////////////////////////////////////////
	// List | Const iterator
	////////////////////////////////////////////////////////////////////////////

	out("List const_iterator | Constructor");
	list<int>::const_iterator cit;

	list<int>::const_iterator cit2(&ln_i6);

	out("List const_iterator | Copy constructor");
	list<int>::const_iterator cit3(cit2);

	out("List const_iterator | Assignment operator");
	list<int>::const_iterator cit4(&ln_i4);

	cit4 = cit3;

	out("List const_iterator | Destructor");
	{
		list<int>::const_iterator cit5;
	}

	list<int> cl_i2(5, 10);

	*(cl_i2.end()) = 42;
	
	out("List | cend()");

	list<int>::const_iterator lcit1 = cl_i2.cend();

	check(*lcit1 == 42);

	out("List const_iterator | = operator");

	list<int>::const_iterator lcit2 = lcit1;
	
	out("List const_iterator | operator --");
	lcit1--;
	check(*lcit1 == 10);

	out("List const_iterator | operator ++");
	lcit1++;
	check(*lcit1 == 42);

	lcit1--;

	out("List const_iterator | != operator");
	check(lcit2 != lcit1);

	out("List const_iterator | operator ++");
	++lcit1;
	
	out("List const_iterator | == operator");
	
	check(lcit2 == lcit1);

	out("List const_iterator | operator --");
	--lcit1;
	
	out("List const_iterator | ++ operator");
	lcit1++;
	check(*lcit1 == 42);
	lcit1--;
	check(lcit2 != lcit1);


	// TODO: leaks-check

	
	// listNode<int> *a = l_i2.start;
	// for (int i = 0; i < 10; i++)
	// {
	// 	std::cout << "i: " << i << std::endl;
	// 	std::cout << a << std::endl;
	// 	std::cout << "value: " << a->getValue() << std::endl;
	// 	std::cout << "prev: " << a->getPrev() << std::endl;
	// 	std::cout << "next: " << a->getNext() << std::endl;

	// 	a = a->getNext();
	// }
	
	

}