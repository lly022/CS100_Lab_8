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

TEST(VisitorTest, VisitorTest1) {
	CountVisitor *visitor = new CountVisitor();
	Base* num1 = new Op(8);
	Base* num2 = new Op(4);
	
	num1->accept(visitor);
	EXPECT_EQ(visitor->op_count(), 1);
	num2->accept(visitor);
        EXPECT_EQ(visitor->op_count(), 2);

	Base* temp1 = new Sub(num1, num2);
	Base* temp2 = new Div(num1, num2);
	
	temp1->accept(visitor);
	temp2->accept(visitor);
	EXPECT_EQ(visitor->op_count(), 2);
	EXPECT_EQ(visitor->sub_count(), 1);
	EXPECT_EQ(visitor->div_count(), 1);	
}

TEST(VisitorTest, VisitorTest2) {
	CountVisitor* visitor = new CountVisitor();
	Base* num1 = new Op(1);
	Base* num2 = new Op(2);
	Base* num3 = new Op(3);
	Base* num4 = new Op(4);
	Base* num5 = new Op(5);
	Base* num6 = new Op(6);
	Base* num7 = new Op(7);
	Base* num8 = new Op(8);
	

	Add* tree1 = new Add(num1,num2);
	Add* tree2 = new Add(num3,num4);
	Add* tree3 = new Add(num5,num6);
        Add* tree4 = new Add(num7,num8);
	
	Add* tree5 = new Add(tree1,tree2);
	Add* tree6 = new Add(tree3,tree4);

	Add* dummy = new Add(tree5,tree6);

	PreorderIterator* test = new PreorderIterator(dummy);
	test->first();
	while(!test->is_done()){
		test->current()->accept(visitor);
		test->next();
	}
	EXPECT_EQ(visitor->add_count(), 6);
	EXPECT_EQ(visitor->op_count(), 8);
}

TEST(VisitorTest, VisitorTest3) {
        CountVisitor* visitor = new CountVisitor();
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Base* num3 = new Op(3);
        Base* num4 = new Op(4);
        Base* num5 = new Op(5);
        Base* num6 = new Op(6);
        Base* num7 = new Op(7);
        Base* num8 = new Op(8);


        Add* tree1 = new Add(num1,num2);
        Add* tree2 = new Add(num3,num4);
        Add* tree3 = new Add(num5,num6);
        Add* tree4 = new Add(num7,num8);

        Mult* tree5 = new Mult(tree1,tree2);
        Div* tree6 = new Div(tree3,tree4);

        Add* dummy = new Add(tree5,tree6);

        PreorderIterator* test = new PreorderIterator(dummy);
        test->first();
        while(!test->is_done()){
                test->current()->accept(visitor);
                test->next();
        }
        EXPECT_EQ(visitor->add_count(), 4);
        EXPECT_EQ(visitor->op_count(), 8);
	EXPECT_EQ(visitor->mult_count(), 1);
	EXPECT_EQ(visitor->div_count(), 1);
}

TEST(VisitorTest, VisitorTest4) {
        CountVisitor* visitor = new CountVisitor();
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Base* num3 = new Op(3);
        Base* num4 = new Op(4);
        Base* num5 = new Op(5);
        Base* num6 = new Op(6);
        Base* num7 = new Op(7);
        Base* num8 = new Op(8);


        Add* tree1 = new Add(num1,num2);
        Sub* tree2 = new Sub(num3,num4);
        Pow* tree3 = new Pow(num5,num6);
        Add* tree4 = new Add(num7,num8);

        Mult* tree5 = new Mult(tree1,tree2);
        Div* tree6 = new Div(tree3,tree4);

        Add* dummy = new Add(tree5,tree6);

        PreorderIterator* test = new PreorderIterator(dummy);
        test->first();
        while(!test->is_done()){
                test->current()->accept(visitor);
                test->next();
        }
        EXPECT_EQ(visitor->add_count(), 2);
        EXPECT_EQ(visitor->op_count(), 8);
        EXPECT_EQ(visitor->mult_count(), 1);
        EXPECT_EQ(visitor->div_count(), 1);
	EXPECT_EQ(visitor->pow_count(), 1);
	EXPECT_EQ(visitor->sub_count(), 1);

}

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
