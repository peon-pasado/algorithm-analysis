#ifndef BIGNUMBER_HPP
#define BIGNUMBER_HPP
#include "../polynomials/polynomial.hpp"

template<size_t base>
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
			carry = res[i] / base;
			res[i] %= base;
		}
		while (carry > 0) {
			res.push_back(carry % base);
			carry /= base;
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

typedef Bignumber<10> Decimal;

#endif
