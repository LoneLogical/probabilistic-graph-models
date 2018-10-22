#ifndef FACTOR_H
#define FACTOR_H

#include <iostream>
#include <map>

// a stub for you to build your factor class
// (do not delete any methods, but you may add methods and members)

class factor {
public:
	/* This is the definition of a scope: */
	// first int is the "name" of the variable
	// second int is the size of the variable's domain
	typedef std::map<int,int> scope;

	/* This is the definition of an assignment (to a set of variables): */
	// (looks similar to scope, but it is semantically different)!)
	// first int is the "name" of the variable
	// second int is the assignment to that variable (from 0 to size-1)
	typedef std::map<int,int> assign;

	// build blank factors (all values=d) over scope 
	factor(const scope &sc, double d=0.0);
	// if you write your code properly, you won't need a 
	// copy constructor, assignment operator or destructor
	// as the defaults will be fine.  Don't do your own memory
	// allocation -- use the STL.

	// if i does not include an assignment for all variables,
	// the return value is undefined
	// This returns the value of the factor for the given assignment
	// (note that i might have assignments to other variables too
	//  they can just be ignored)
	double operator()(const assign &i) const;
	double &operator()(const assign &i);

	// reduce the factor to only those assignments consistent with a	
	factor reduce(const assign &a) const;
	// sum out those variables mentioned in the scope tosumout
	factor marginalize(const scope &tosumout) const;

	// the standard factor operations (division isn't covered in the
	// book until later, but it is analogous to multiplication)
	factor operator*(const factor &f2) const;
	factor operator/(const factor &f2) const;
	factor operator+(const factor &f2) const;
	factor operator-(const factor &f2) const;

	// These are the inplace versions with a scalar
	// you don't need to implement them
	/*
	factor &operator*=(double d);
	factor &operator/=(double d);
	factor &operator+=(double d);
	factor &operator-=(double d);
	*/

	// returns the scope of this factor
	scope getscope() const;

	// prints out the factor in the format described in the assignment
	void print(std::ostream &os) const;
private:
	// put your own data structure here!!
	// you may only change this file between this line
	
	// and this line (do not remove these comments!)
};

#endif
