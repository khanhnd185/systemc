#include "systemc.h"

int sc_main(int argc, char* argv[]) {
	sc_bit a,b,t;
	sc_logic l1,l2,lt;
	
	a = '1';
	b = '0';
	
	cout << "Value a, b " << a << " " << b << "\n";
	
	t = a;
	a = b;
	b = t;
	
	cout << "Value a, b " << a << " " << b << "\n";
	
	l1 = 'z';
	l2 = 'x';
	
	cout << "Value l1, l2 " << l1 << " " << l2 << "\n";
	
	lt = l1;
	l1 = l2;
	l2 = lt;
	
	cout << "Value l1, l2 " << l1 << " " << l2 << "\n";
	cout << "Value ~ l1, l2 " << ~l1 << " " << ~l2 << "\n";
	cout << "l1 | l2 " << (l1|l2) << "\n";
	cout << "l1 & l2 " << (l1&l2) << "\n";
	
	
	return 1;
}
