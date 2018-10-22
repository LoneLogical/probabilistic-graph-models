#include "factor.h"

using namespace std;

// You should add your own helper functions and private methods

factor::factor(const scope &sc, double d) {
	this.f_scope = sc;
	vector<int> v_dims, v_names;
	int num_rows = 1; //num possible factor assignments
	scope::const_iterator s_it;
	for (s_it=sc.begin(); s_it!=sc.end(); s_it++) {
		num_rows *= s_it->second;
		v_names.push_back(s_it->first);
		v_dims.push_back(s_it->second);
	}
	this.f_values = vector<double>(num_rows, d);
	this.f_index = Index(v_names, v_dims);
	
}

double factor::operator()(const factor::assign &i) const {
	return f_values.at(f_index.get_index(i));
}

double &factor::operator()(const factor::assign &i) {
	return f_values.at(f_index.get_index(i));
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
	return f_scope;
}

