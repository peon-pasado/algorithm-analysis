#include <bits/stdc++.h>
#include "../polynomial.hpp"
using namespace std;

int main() {
	Polynomial<int> p = {1, 1, 1, 1, 1};
	
	cout << "(" << p.prettify() << ") * (" << p.prettify() 
		<< ") = " << (p*p).prettify() << endl;
	return 0;
}
