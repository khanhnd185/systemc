// SC_CTHREAD process is different from the SC_THREAD process in a number of ways. First the SC_CTHREAD
// process specifies a clock object. When other process types are described in a module constructor they
// only have the name of the process specified, but the SC_CTHREAD process has the name of the process
// and the clock that triggers the process. An SC_CTHREAD does not have a separate sensitivity list like
// the other process types. The sensitivity list is just the specified clock edge. The SC_CTHREAD process
// will be activated whenever the specified clock edge occurs. In this example the positive edge of the 
// clock is specified so process incr_count will execute on every positive edge of the clock
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
  // cthreads require to have thread name and triggering 
  // event to passed as clock object
  SC_CTHREAD(incr_count, clock.pos());
  // Level Sensitive to change in counter output
  SC_THREAD(print_count);
    sensitive << counter_out;
} // End of Constructor

}; // End of Module counter
