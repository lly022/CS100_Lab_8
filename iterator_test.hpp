#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "mult.hpp"
#include "Div.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"

TEST(IteratorTest, NullFirstTest){
	Base *num1 = new Op(8);

	Iterator *it = num1->create_iterator();
	ASSERT_TRUE(it->current() == nullptr);
	it->first();
	ASSERT_TRUE(it->current() == nullptr);		
}

TEST(IteratorTest, NullNextTest){
	Base *num1 = new Op(8);

	Iterator *it = num1->create_iterator();
	ASSERT_TRUE(it->current() == nullptr);
	it->next();
	ASSERT_TRUE(it->current() == nullptr);
}

TEST(IteratorTest, NullDoneTest){
	Base *num1 = new Op(8);
	
	Iterator *it = num1->create_iterator();
	
	ASSERT_TRUE(it->is_done());	
}

TEST(IteratorTest, NullCurrentTest){
	Base* num1 = new Op(8);

	Iterator *it = num1->create_iterator();

	EXPECT_EQ(it->current(), nullptr);	
}

#endif //__ITERATOR_TEST_HPP__
