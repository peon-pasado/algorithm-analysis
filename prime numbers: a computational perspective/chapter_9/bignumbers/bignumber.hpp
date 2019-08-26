#ifndef BIGNUMBER_HPP
#define BIGNUMBER_HPP
#include "../polynomials/polynomial.hpp"

template<size_t base>
class Bignumber : public Polynomial<int> {
public:
	using Polynomial<int>::Polynomial;	

	Bignumber(const Polynomial& other): Polynomial(other) {}
	Bignumber(int number) {
		if (number == 0) {
			(*this).push_back(0);
		} else {
			while (number > 0) {
				(*this).push_back(number%base);
				number /= base;
			}
		}
	}

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

	bool operator <(const Bignumber& other) const {
		int n = this->size(), m = other.size();
		if (n < m) return true;
		if (n > m) return false;
		for (int i = 0; i < n; ++i) {
			if ((*this)[i] < other[i]) return true;
			if (other[i] < (*this)[i]) return false;
		}
		return false;
	}

	string prettify() const {
		int n = (*this).size();
		string res = "";
		for (int i = n-1; i >= 0; --i) {
			res += to_string((*this)[i]);
		}
		return res;
	}

	friend ostream& operator <<(ostream& out, const Bignumber& number) {
		out << number.prettify();
		return out;
	}
};

typedef Bignumber<10> Decimal;

class Binary : public Bignumber<2> {
public:
	using Bignumber<2>::Bignumber;
	
	Binary operator >>(size_t k) {
		if (k >= (*this).size()) return Binary(0);
		Binary res = *this;
		while (k--) res.pop_front();
		return res;
	}

	Binary operator <<(size_t k) {
		if ((*this).empty()) return Binary(0);
		Binary res = *this;
		while (k--) res.push_front(0);
		return res;
	}
	
	//Bignumber<10> to_decimal() {	
	//}
};

#endif
