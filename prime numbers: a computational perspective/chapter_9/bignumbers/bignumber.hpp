#ifndef BIGNUMBER_HPP
#define BIGNUMBER_HPP
#include "../polynomials/polynomial.hpp"

class Bignumber : public Polynomial<int> {
public:
	using Polynomial<int>::Polynomial;	

	Bignumber(const Polynomial& other): Polynomial(other) {}

	Bignumber operator *(const Bignumber& other) const {
		Bignumber res = (*this).Polynomial<int>::operator*(other);		
		int n = res.size();
		int carry = 0;
		for (int i = 0; i < n; ++i) {
			res[i] += carry;
			carry = res[i] / 10;
			res[i] %= 10;
		}
		while (carry > 0) {
			res.push_back(carry % 10);
			carry /= 10;
		}
		return res;
	}

	string prettify() {
		int n = (*this).size();
		string res = "";
		for (int i = n-1; i >= 0; --i) {
			res += to_string((*this)[i]);
		}
		return res;
	}
};

#endif
