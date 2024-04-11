
DIR = $(notdir $(CURDIR))
tar_name = Wojciech_Szymanski_$(DIR)

source = ArrayStack LinkedStack
CXXFLAGS := -Wall -O3 -std=c++11 -pedantic 
LDFLAGS := -s 
LDLIBS := -lm


%.o: %.cpp                        # Reguła wzorcowa .c [+ .h] -> .o
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.x: %.o 						# Reguła wzorcowa .o + ... -> .x
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)


.PHONY: all clean tar

all: Stack.x Generator.x ONP.x

Stack.o: $(addsuffix .hpp, $(source))
ONP.o: $(addsuffix .hpp, $(source))

Stack.x: Stack.o
Generator.x: Generator.o
ONP.x: ONP.o



clean:
	$(RM) *.o  *~ *.a *.so *.x core core* a.out *.exe *.exe.stackdump

tar: clean
	(cd ../; tar -cvzf $(tar_name).tar.gz  $(DIR) )
