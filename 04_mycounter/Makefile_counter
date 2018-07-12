SYSTEMC_HOME = 
INCDIR = -I. -I$(SYSTEMC_HOME)/include
LIBDIR = -L. -L$(SYSTEMC_HOME)/lib-linux64
LIB = -lsystemc -lm
FLAG = -Wl,-rpath,$(SYSTEMC_HOME)/lib-linux64/
CC = g++
OBJ = test.o counter.o

counter: $(OBJ)
	$(CC) $(INCDIR) $(LIBDIR) -o $(@) $(OBJ) $(LIB) $(FLAG)
	
# counter.o:
	# $(CC) $(INCDIR) $(LIBDIR) -c $(@:.o=.cpp) $(LIB)

# test.o:
	# $(CC) $(INCDIR) $(LIBDIR) -c $(@:.o=.cpp) $(LIB)
	
.cpp.o:
	$(CC) $(INCDIR) $(LIBDIR) -c  $<

clean:
	rm -r *.o
	rm -r sim
	rm -r *.vcd
