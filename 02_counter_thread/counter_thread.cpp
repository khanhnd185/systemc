//-----------------------------------------------------
// Threads are second kind of process, which when called keeps executing or	
// waiting for some event to occur. Conditions that enable this processes can be
// event triggered, like posedge of clock.
//  
// Thread Process can be suspended and reactivated. The Thread Process can
// contain wait() functions that suspend process execution until an event occurs on
// one of the signals the process is sensitive to. An event will reactivate the thread
// process from the statement the process was last suspended. The process will
// continue to execute until the next wait().
//-----------------------------------------------------
#include "systemc.h"

SC_MODULE (first_counter) {
	sc_in_clk     clock ;      // Clock input of the design
	sc_in<bool>   reset ;      // active high, synchronous Reset input
	sc_in<bool>   enable;      // Active high enable signal for counter
	sc_out<sc_uint<4> > counter_out; // 4 bit vector output of the counter
	
	//------------Local Variables Here---------------------
	sc_uint<4>	count;
	
	//------------Code Starts Here-------------------------
	// Below function implements actual counter logic
	void incr_count () {
	// For threads, we need to have while true loop
	while (true) { 
		// Wait for the event in sensitivity list to occure
		// In this example - positive edge of clock
		wait();
		if (reset.read() == 1) {
		count =  0;
		counter_out.write(count);
		// If enable is active, then we increment the counter
		} else if (enable.read() == 1) {
		count = count + 1;
		counter_out.write(count);
		}
	}
	} // End of function incr_count
	
	// Below functions prints value of count when ever it changes
	void print_count () {
	while (true) {
		wait();
		cout<<"@" << sc_time_stamp() <<
		" :: Counter Value "<<counter_out.read()<<endl;
	}
	}
	
	// Constructor for the counter
	// Since this counter is a positive edge trigged one,
	// We trigger the below block with respect to positive
	// edge of the clock
	SC_CTOR(first_counter) {
	// Edge sensitive to clock
	SC_THREAD(incr_count);
	sensitive << clock.pos();
	// Level Sensitive to change in counter output
	SC_THREAD(print_count);
	sensitive << counter_out;
	} // End of Constructor
	
}; // End of Module counter
