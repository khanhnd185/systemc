#include "systemc.h"

int sc_main(int argc, char* argv[]) {
	sc_int<1> abit = 0;
	sc_int<4> anibble = 1;
	sc_int<8> abyte = 2;
	sc_int<32> adword = 3;
	
	adword++;
	cout <<"Value of adword : " << adword << "\n";	
	abyte += anibble;
	cout <<"Value of abyte : " << abyte << "\n";
	abit = adword[2];
	cout <<"Value of abit : " << abit << "\n";
	anibble = adword.range(4,1);
	cout <<"Value of anibble : " << anibble << "\n";
	adword = (abyte,abyte,abyte,abyte);
	cout <<"Value of adword : " << adword << "\n";
	abyte = ~anibble;
	cout <<"Value of abyte : " << abyte << "\n";
	return 0;
}
