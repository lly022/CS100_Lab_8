#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <stdlib.h> //for rand() 
#include "iterator.hpp"

class Rand : public Base {
	protected:
		double value;
	public:
		Rand() : Base() {this->value = rand() % 100; }
		virtual double evaluate() {return value; }
		virtual std::string stringify() {return std::to_string(value); }
		virtual Iterator* create_iterator() {return new NullIterator(this); }
	        virtual Base* get_left() {return nullptr;}
       		virtual Base* get_right() {return nullptr;}

};
#endif //__RAND_HPP__
