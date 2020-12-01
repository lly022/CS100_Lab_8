#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "Div.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "pow.hpp"

TEST(IteratorTest, Bin_is_done) {
	Base* num1 = new Op(2);
	Base* num2 = new Op(3);
	Add* tree1 = new Add(num1,num2);
	
	Base* num3 = new Op(4);
	Base* num4 = new Op(5);
	Mult* tree2 = new Mult(num3,num4);

	Div* test = new Div(tree1,tree2);
	Iterator* it = test->create_iterator();
	ASSERT_TRUE(!it->is_done());
	it->next();
	ASSERT_TRUE(!it->is_done());
        it->next();
	ASSERT_TRUE(it->is_done());
}

TEST(IteratorTest, Bin_current) {
        Base* num1 = new Op(2);
        Base* num2 = new Op(3);
        Add* tree1 = new Add(num1,num2);

        Base* num3 = new Op(4);
        Base* num4 = new Op(5);
        Mult* tree2 = new Mult(num3,num4);

        Div* test = new Div(tree1,tree2);
        Iterator* it = test->create_iterator();
        EXPECT_EQ(it->current()->evaluate(), 5);
	it->next();
	EXPECT_EQ(it->current()->evaluate(), 20);
	it->next();
	ASSERT_TRUE(it->current() == nullptr);
}

TEST(IteratorTest, Bin_first) {
        Base* num1 = new Op(2);
        Base* num2 = new Op(3);
        Add* tree1 = new Add(num1,num2);

        Base* num3 = new Op(4);
        Base* num4 = new Op(5);
        Mult* tree2 = new Mult(num3,num4);

        Div* test = new Div(tree1,tree2);
        Iterator* it = test->create_iterator();
        EXPECT_EQ(it->current()->evaluate(), 5);
        it->next();
        EXPECT_EQ(it->current()->evaluate(), 20);
        it->next();
        ASSERT_TRUE(it->current() == nullptr);
	it->first();
	EXPECT_EQ(it->current()->evaluate(), 5);
}

TEST(IteratorTest, Bin_next) {
        Base* num1 = new Op(2);
        Base* num2 = new Op(3);
        Add* tree1 = new Add(num1,num2);

        Base* num3 = new Op(4);
        Base* num4 = new Op(5);
        Mult* tree2 = new Mult(num3,num4);

        Div* test = new Div(tree1,tree2);
        Iterator* it = test->create_iterator();
        EXPECT_EQ(it->current()->evaluate(), 5);
        it->next();
        EXPECT_EQ(it->current()->evaluate(), 20);
        it->next();
        ASSERT_TRUE(it->current() == nullptr);
        it->first();
        EXPECT_EQ(it->current()->evaluate(), 5);
	it->next();
        EXPECT_EQ(it->current()->evaluate(), 20);
        it->next();
        ASSERT_TRUE(it->current() == nullptr);
}


#endif
