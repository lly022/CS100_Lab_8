#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
 	double value; //could later change to private/protected
        Op(double value) : Base() {this->value = value; }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string(value); }
	virtual Iterator* create_iterator() {return new NullIterator(this); }
	virtual Base* get_left() {return nullptr;}
	virtual Base* get_right() {return nullptr;}
	void accept(CountVisitor* visitor){
		visitor->visit_op();
	}	
};

#endif //__OP_HPP__
