// Multi bit vector and logic example
#include "systemc.h"

int sc_main(int argc, char* argvp[]) {
	sc_core::sc_report_handler::set_actions( "/IEEE_Std_1666/deprecated", sc_core::SC_DO_NOTHING );
										   
	sc_bv<8> bit_vetor_8,d1,d2;
	sc_bv<16> bit_vector_16;
	sc_bit bv_parity;
	
	bit_vetor_8 = "00001011";
	cout << "Value of bit_vetor_8: " << bit_vetor_8 << "\n";
	
	bit_vector_16.range(0,7) = bit_vetor_8;
	cout << "Value of bit_vector_16: " << bit_vector_16 << "\n";
	
	bit_vector_16.range(7,0) = bit_vetor_8;
	cout << "Value of bit_vector_16: " << bit_vector_16 << "\n";
	
	bit_vector_16[10] = "1";
	cout << "Value of bit_vector_16: " << bit_vector_16 << "\n";
	
	bv_parity = bit_vector_16.xor_reduce();
	cout << "Value of parity: " << bv_parity << "\n";

	d1 = "11110000";
	cout << "Value of d1: " << d1 << "\n";
	d2 = "11001100";
	cout << "Value of d2: " << d2 << "\n";
	cout << "Value of d1|d2: " << (d1|d2) << "\n";
	cout << "Value of d1&d2: " << (d1&d2) << "\n";
	cout << "Value of d1^d2: " << (d1^d2) << "\n";
	
	sc_lv<8> logic_vector_8 (sc_logic('z')); // All bits are Z
	sc_lv<16> logic_vector_16,lv1,lv2;		 // All bits are X
	sc_logic lv_parity;
	
	cout << "Value of logic_vector_8: " << logic_vector_8 << "\n";
	cout << "Value of logic_vector_16: " << logic_vector_16 << "\n";
	
	logic_vector_16.range(0,7) = logic_vector_8;
	cout << "Value of logic_vector_16: " << logic_vector_16 << "\n";
	logic_vector_16.range(7,0) = logic_vector_8;
	cout << "Value of logic_vector_16: " << logic_vector_16 << "\n";
	logic_vector_16[10] = "1";
	cout << "Value of logic_vector_16: " << logic_vector_16 << "\n";
	
	lv_parity = logic_vector_16.xor_reduce();
	cout << "Value of parity: " << lv_parity << "\n";
	
	lv1 = "xxxxzzzz00001111";
	lv2 = "xz01xz01xz01xz01";
	cout << "Value of lv1: " << lv1 << "\n";
	cout << "Value of lv2: " << lv2 << "\n";
	cout << "Value of lv1|lv2 " << (lv1|lv2) << "\n";
	cout << "Value of lv1%lv2 " << (lv1|lv2) << "\n";
	cout << "Value of lv1^lv2 " << (lv1|lv2) << "\n";
	
	return 0;
}
