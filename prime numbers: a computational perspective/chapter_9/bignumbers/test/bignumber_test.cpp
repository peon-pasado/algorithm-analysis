#include <bits/stdc++.h>
#include "../bignumber.hpp"
using namespace std;



int main() {	
	Decimal d = 123456789;
	d = d*d;
	d = d*d;
	d = d*d;
	//cout << d*d << endl;

	Binary b = 10;
	cout << b << " " << ((b>>1)<<300) << endl;
	
	return 0;
}
