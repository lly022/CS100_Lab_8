#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__

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

TEST(VisitorTest, PreOrderTest1){
        Base *num1 = new Op(3);
        Base *num2 = new Op(7);
        Pow *temp = new Pow(num1, num2);
        Base *dummy = new Add(temp, num2);

        Iterator *pit = new PreorderIterator(dummy);

        CountVisitor *visit = new CountVisitor();
        pit->first();
        while(!pit->is_done()){
                Base *phase = pit->current();
                phase->accept(visit);
                pit->next();
        }
	EXPECT_EQ(visit->op_count(), 3);
        EXPECT_EQ(visit->pow_count(), 1);
        EXPECT_EQ(visit->add_count(), 0);
}

TEST(VisitorTest, PreOrderTest2){
        Base *num1 = new Op(8);
        Base *num2 = new Op(2);
        Base *num3 = new Op(6);
        Base *num4 = new Op(3);
        Div *temp = new Div(num1, num2);
        Sub *temp2 = new Sub(num3, num4);
        Base *dummy = new Mult(temp, temp2);

        Iterator *pit = new PreorderIterator(dummy);

        CountVisitor *visit = new CountVisitor();
        pit->first();
        while(!pit->is_done()){
                Base *phase = pit->current();
                phase->accept(visit);
                pit->next();
        }

        EXPECT_EQ(visit->op_count(), 4);
        EXPECT_EQ(visit->div_count(), 1);
        EXPECT_EQ(visit->sub_count(), 1);
	EXPECT_EQ(visit->mult_count(), 0);
}

TEST(VisitorTest, PreOrderTest3){
        Base *num1 = new Op(9);
        Base *num2 = new Op(1);
        Base *num3 = new Op(7);
        Base *num4 = new Op(2);
        Add *temp = new Add(num1, num2);
        Sub *temp2 = new Sub(num3, num4);
        Base *dummy = new Mult(temp, temp2);

        Iterator *pit = new PreorderIterator(dummy);

        CountVisitor *visit = new CountVisitor();
        pit->first();
        while(!pit->is_done()){
                Base *phase = pit->current();
                phase->accept(visit);
                pit->next();
        }

        EXPECT_EQ(visit->op_count(), 4);
        EXPECT_EQ(visit->add_count(), 1);
        EXPECT_EQ(visit->sub_count(), 1);
        EXPECT_EQ(visit->mult_count(), 0);
}

TEST(VisitorTest, IteratorTestWithVisitor){
        Base *num1 = new Op(8);
        Base *num2 = new Op(2);
        Pow *temp = new Pow(num1, num2);
        Base *dummy = new Add(temp, num2);

        Iterator *it = dummy->create_iterator();

        CountVisitor *visit = new CountVisitor();
        it->first();
        while(!it->is_done()){
                Base *phase = it->current();
                phase->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(), 1);
        EXPECT_EQ(visit->pow_count(), 1);
        EXPECT_EQ(visit->add_count(), 0);
}

#endif //__VISITOR_TEST_HPP__
