#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "Div.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "iterator.hpp"
#include "binary_iterator.cpp"
#include "preorder_iterator.cpp"
#include "visitor.hpp"

using namespace std;

int main() {
	cout << "TEST 1" << endl;
	CountVisitor *visitor1 = new CountVisitor();
	Base *num1 = new Op(8);
	Base *num2 = new Op(4);

	cout << "Visiting an op..." << endl;
	num1->accept(visitor1);
	cout << "Visiting an op..." << endl;
	num2->accept(visitor1);

	Base* temp1 = new Sub(num1, num2);
	Base* temp2 = new Div(num1, num2);
	
	cout << "Visiting a sub..." << endl;
	temp1->accept(visitor1);
	cout << "Visiting a div..." << endl;
	temp2->accept(visitor1);

	cout << "Op count: " << visitor1->op_count() << endl;
	cout << "Sub count: " << visitor1->sub_count() << endl;
	cout << "Div count: " << visitor1->div_count() << endl << endl;

	cout << "TEST 2" << endl;
	CountVisitor* visitor2 = new CountVisitor();
        Base* num_1 = new Op(1);
        Base* num_2 = new Op(2);
        Base* num_3 = new Op(3);
        Base* num_4 = new Op(4);
        Base* num_5 = new Op(5);
        Base* num_6 = new Op(6);
        Base* num_7 = new Op(7);
        Base* num_8 = new Op(8);

        Add* tree1 = new Add(num_1,num_2);
        Sub* tree2 = new Sub(num_3,num_4);
        Pow* tree3 = new Pow(num_5,num_6);
        Add* tree4 = new Add(num_7,num_8);

        Mult* tree5 = new Mult(tree1,tree2);
        Div* tree6 = new Div(tree3,tree4);

        Add* dummy = new Add(tree5,tree6);

        PreorderIterator* test = new PreorderIterator(dummy);
        test->first();
        while(!test->is_done()){
                test->current()->accept(visitor2);
                test->next();
        }
	cout << "Test 2 tree: " << dummy->stringify() << endl;
        cout << "Add count: " << visitor2->add_count() << endl;
        cout << "Op count: " << visitor2->op_count() << endl;
        cout << "Mult count: " << visitor2->mult_count() << endl;
        cout << "Div count: " << visitor2->div_count() << endl;
	cout << "Pow count: " << visitor2->pow_count() << endl;
	cout << "Sub count: " << visitor2->sub_count() << endl;
	
	return 0;
}
