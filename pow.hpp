#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <string>
#include <cmath>
#include "iterator.hpp"

class Pow : public Base {
        public:
         Pow(Base* val1 ,Base* val2) : Base() {this->val1=val1; this->val2=val2;}
         double evaluate() {
		return std::pow(val1->evaluate(),val2->evaluate());
        }

         std::string stringify() {
                return val1->stringify() + " ** " + val2->stringify();
        }
	Iterator* create_iterator(){
                Iterator* it = new BinaryIterator(this);
                return it;
	}
        Base* get_left(){
                return val1;
        }
        Base* get_right() {
                return val2;
        }
	void accept(CountVisitor* visitor){
                visitor->visit_pow();
        }
        private:
         Base* val1;
         Base* val2;
};

#endif
