#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP
#include <queue>
#include <string>
using namespace std;

template<class T>
class Polynomial : public deque<T> {
public:
	using deque<T>::deque; 	

	Polynomial operator +(const Polynomial& other) const {
		int n = this->size(), m = other.size();
		Polynomial res = *this;
		res.resize(max(n, m));
		for (int i = 0; i < m; ++i) {
			res[i] = res[i] + other[i];
		}
		return res;
	}
	
	//simple product
	Polynomial operator *(const Polynomial& other) const {
		int n = this->size(), m = other.size();
		if (n == 0 or m == 0) return Polynomial();
		Polynomial res(n + m - 1);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				res[i + j] += (*this)[i] * other[j];	
			}
		}
		return res;
	}

	string prettify() {
		int n = this->size();
		if (n == 0) return "0";
		string res = "";
		for (int i = 0; i < n; ++i) {
			res += (i == 0 ? "" : " + ")
					+ to_string((*this)[i])
						+ (i == 0 ? "" : "x^" + to_string(i));
		}
		return res;
	}
};

#endif
