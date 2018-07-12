SYSTEMC_HOME = /shsv/MobAP2/prj_MCS/01_common/01_SystemC/systemc-2.3.1a_gcc493_64bit
INCDIR = -I. -I$(SYSTEMC_HOME)/include
LIBDIR = -L. -L$(SYSTEMC_HOME)/lib-linux64
LIB = -lsystemc -lm
FLAG = -Wl,-rpath,$(SYSTEMC_HOME)/lib-linux64/
CC = g++
OBJ = test.o counter_cthread.o

counter: $(OBJ)
	$(CC) $(INCDIR) $(LIBDIR) -o $(@) $(OBJ) $(LIB) $(FLAG)
	
counter_cthread.o:
	$(CC) $(INCDIR) $(LIBDIR) -c $(@:.o=.cpp) $(LIB)
	
.cpp.o:
	$(CC) $(INCDIR) $(LIBDIR) -c  $<

clean:
	rm -r *.o
	rm -r sim
	rm -r *.vcd
