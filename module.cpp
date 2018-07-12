// A Module should in basic should contain ports, constructor, and methods/functions to work on the ports.
// Below is list of parts of a module.
    // Ports
	// Signals
    // Internal Variables
    // Constructor
    // Internal Method???
#include "systemc.h"

class module_name : sc_module {
  // Module body
}

// Or we can declare below

SC_MODULE("module_name") {
  // module body
}

// ========
first_counter counter("COUNTER");
	// Here ports are connected by position
	counter(clock,reset,enable,counter_out);

first_counter counter("COUNTER");
	// Here ports are connected by name
	counter.enable(enable);
	counter.reset(reset);
	counter.clock(clock);
	counter.counter_out(counter_out);
	

// Process can be either made level sensitive to model combonational logic
// or can be made edge sensitive logic, to module sequential logic.
SC_METHOD(incr_count);
	sensitive << reset;
	sensitive << clock.pos();
// Process can be made to run for ever, by forking them like Verilog.
// We call this as threads in SystemC. Or run when ever a event occures.
SC_THREAD(print_count);
	sensitive << counter_out;
