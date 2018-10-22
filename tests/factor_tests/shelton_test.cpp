#include "factor.h"
#include <cstdarg>

// this code runs your factor class through the tests of figures 4.2 and 4.3
// as well as example 4.2

// The target output is shown in sample.out
// Note that the number of spaces separating tokens is not important
//           the number of '-' is not important
//           the order of the factor's values is not important
// (that is, your code may dump the factor's values out in a different
//  order -- for instance, the book lists them in row-major order, but
//           my code dumps them in column-major order)


// NOTE!!!
// A few things this code does NOT check, but you should make sure that
// your factor implementation does do correctly:
//   constructing factors with more than 2 variables directly
//   factor addition, subtraction, and division
//   more than 1 factor with more than 2 variables
//   factors with non-consecutive variable numbers (especially very
//      large ones, like a factor over X1001 and X8753 -- which should
//      take no longer than a factor over X0 and X1)

using namespace std;

// handy way to set an assignment quickly
// (variable arguments at the end are all integers: the assignments "in order")
// (s cannot be a reference, as va_list manipulation is undefined in this case)
// Note:  This is ugly and with C++11 could be made much more type-safe
//     However, I'm doing it this way so that you can use older compilers
factor::assign A(const factor::scope s, ...) {
	factor::assign ret;
	va_list as;
	va_start(as,s);
	for(factor::scope::const_iterator si=s.begin();si!=s.end();si++) {
		int v = va_arg(as,int);
		ret[si->first] = v;
	}
	va_end(as);
	return ret;
}

void figure42() {
	// Figure 4.2:
	// A is variable 0, B is 1, C is 2, D is 3
	factor::scope s1;
	s1[0] = 2; s1[1] = 2; // binary variables
	factor::scope s2;
	s2[1] = 2; s2[2] = 2;
	factor::scope s3;
	s3[2] = 2; s3[3] = 2;
	factor::scope s4;
	s4[0] = 2; s4[3] = 2;

	factor psi1(s1);
	psi1(A(s1,0,0)) = 30;
	psi1(A(s1,0,1)) = 5;
	psi1(A(s1,1,0)) = 1;
	psi1(A(s1,1,1)) = 10; 
	factor psi2(s2);
	psi2(A(s2,0,0)) = 100; psi2(A(s2,0,1)) = 1;
	psi2(A(s2,1,0)) = 1;   psi2(A(s2,1,1)) = 100; 
	factor psi3(s3);
	psi3(A(s3,0,0)) = 1;   psi3(A(s3,0,1)) = 100;
	psi3(A(s3,1,0)) = 100; psi3(A(s3,1,1)) = 1; 
	factor psi4(s4);
	psi4(A(s4,0,0)) = 100; psi4(A(s4,0,1)) = 1;
	psi4(A(s4,1,0)) = 1;   psi4(A(s4,1,1)) = 100; 

	cout << "unnormalized joint (Figure 4.2): " << endl;
	factor joint = psi1*psi2*psi3*psi4;
	joint.print(cout);
	cout << endl << endl << "normalized joint (Figure 4.2): " << endl;
	factor z = joint.marginalize(joint.getscope());
	cout << endl << "z = " << z(A(z.getscope(),0)) << endl;
/*
	// cannot do this until you implement operator/=
	joint /= z(A(z.getscope(),0));
	joint.print(cout);
*/

	cout << endl << endl << "marginal over A & B (example 4.2): " << endl;
	factor::scope cd;
	cd[2] = 2; cd[3] = 2;
	(joint.marginalize(cd)).print(cout);
	cout << endl;
}

void figure43() {
	// Figure 4.3:
	factor::scope sA;
	sA[0] = 3; sA[1] = 2;
	factor psiA(sA);
	psiA(A(sA,0,0)) = 0.5; psiA(A(sA,0,1)) = 0.8; psiA(A(sA,1,0)) = 0.1;
	psiA(A(sA,1,1)) = 0.0; psiA(A(sA,2,0)) = 0.3; psiA(A(sA,2,1)) = 0.9;
	factor::scope sB;
	sB[1] = 2; sB[2] = 2;
	factor psiB(sB);
	psiB(A(sB,0,0)) = 0.5; psiB(A(sB,0,1)) = 0.7;
	psiB(A(sB,1,0)) = 0.1; psiB(A(sB,1,1)) = 0.2;

	cout << endl << "Figure 4.3: " << endl;
	factor psiAB = psiA*psiB;
	psiAB.print(cout);
	cout << endl;
}

int main(int argc, char **argv) {
	figure42();
	figure43();
}
