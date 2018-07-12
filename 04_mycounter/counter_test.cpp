#include "counter.cpp"

int sc_main(int argc, char* argv[]) {
	sc_signal<bool> clock;
	sc_signal<bool> reset;
	sc_signal<bool> enable;
	sc_signal<sc_uint<4> > count_out;
	
	int i = 0;
	
	counter_4bit counter("COUNTER");
		counter.clk(clock);
		counter.reset(reset);
		counter.enable(enable);
		counter.count_out(count_out);
		
	sc_start(1, SC_NS);
	
	sc_trace_file *wf = sc_create_vcd_trace_file("chart");
	sc_trace(wf, clock,"clock");
	sc_trace(wf, reset,"reset");
	sc_trace(wf, enable,"enable");
	sc_trace(wf, count_out, "count_out");
	
	reset = 0;
	enable = 0;
	for (i=0;i<5;i++) {
		clock = 0;
		sc_start(1, SC_NS);
		clock = 1;
		sc_start(1, SC_NS);
	}
	
	reset = 1;
	cout << "@" << sc_time_stamp() << "Asserting reset \n";
	for (i=0;i<10;i++) {
		clock = 0;
		sc_start(1, SC_NS);
		clock = 1;
		sc_start(1, SC_NS);
	}

	reset = 0;
	cout << "@" << sc_time_stamp() << "De-asserting reset \n";
	for (i=0;i<5;i++) {
		clock = 0;
		sc_start(1, SC_NS);
		clock = 1;
		sc_start(1, SC_NS);
	}
	
	enable = 1;
	cout << "@" << sc_time_stamp() << "Asserting enable \n";
	for (i=0;i<20;i++) {
		clock = 0;
		sc_start(1, SC_NS);
		clock = 1;
		sc_start(1, SC_NS);
	}
	
	cout << "@" << sc_time_stamp() <<" Asserting reset\n" << endl;
	reset = 1; // Assert enable
	sc_start(1, SC_NS);
	cout << "@" << sc_time_stamp() <<" De-Asserting reset\n" << endl;
	reset = 0; // De-assert enable
	for (i=0;i<10;i++) {
		clock = 0; 
		sc_start(1, SC_NS);
		clock = 1; 
		sc_start(1, SC_NS);
	}
	
	enable = 0;
	cout << "@" << sc_time_stamp() << "De-asserting enable \n";
	for (i=0;i<5;i++) {
		clock = 0;
		sc_start(1, SC_NS);
		clock = 1;
		sc_start(1, SC_NS);
	}
	
	enable = 1;
	cout << "@" << sc_time_stamp() << "Asserting enable \n";
	for (i=0;i<5;i++) {
		clock = 0;
		sc_start(1, SC_NS);
		clock = 1;
		sc_start(1, SC_NS);
	}
	
	cout << "@" << sc_time_stamp() <<" Terminating simulation\n" << endl;
	sc_close_vcd_trace_file(wf);
	return 0;// Terminate simulation
}
