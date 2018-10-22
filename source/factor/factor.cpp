#include "factor.h"

using namespace std;

// You should add your own helper functions and private methods

factor::factor(const scope &sc, double d) {
// your code here
}

double factor::operator()(const factor::assign &i) const {
// your code here
}

double &factor::operator()(const factor::assign &i) {
// your code here
}

void factor::print(ostream &os) const {
// your code here
}

factor factor::reduce(const assign &a) const {
// your code here
}

factor factor::marginalize(const scope &tosumout) const {
// your code here
}

factor factor::operator*(const factor &f2) const {
// your code here
}
factor factor::operator/(const factor &f2) const {
// your code here
}
factor factor::operator+(const factor &f2) const {
// your code here
}
factor factor::operator-(const factor &f2) const {
// your code here
}

factor::scope factor::getscope() const {
// your code here
}

