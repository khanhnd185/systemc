#include "systemc.h"

SC_MODULE(counter_4bit) {
	sc_in_clk clk;
	sc_in<bool> reset;
	sc_in<bool> enable;
	sc_out<sc_uint<4> > count_out;
	
	sc_uint<4> count;
	void incr_count() {
		// count = (reset == 1) ? 0 : ((enable == 1) ? (count + 1) : count);
		if (reset)
			count = 0;
		else if (enable)
			count = count + 1;
		count_out.write(count);
	};
	
	void print_out () {
		cout << "@" << sc_time_stamp() << "::Counter value " << count_out.read() << "\n";
	}
	SC_CTOR (counter_4bit) {
		count = 0;
		cout << "Counter created.\n";
		SC_METHOD(incr_count);
			sensitive << clk.pos() << reset;
		SC_METHOD(print_out);
			sensitive << count_out;
	}
};
