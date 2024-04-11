
DIR = $(notdir $(CURDIR))
tar_name = Wojciech_Szymanski_$(DIR)

source = PriorityQueue
CXXFLAGS := -Wall -O3 -std=c++11 -pedantic 
LDFLAGS := -s 
LDLIBS := -lm


%.o: %.cpp                        # Reguła wzorcowa .c [+ .h] -> .o
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.x: %.o 						# Reguła wzorcowa .o + ... -> .x
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: all clean tar test

all: PriorityQueue.x 

PriorityQueue.x: PriorityQueue.o

PriorityQueue.o: PriorityQueue.cpp $(addsuffix .hpp, $(source))

test: PriorityQueue.x
	./PriorityQueue.x


clean:
	$(RM) *.o  *~ *.a *.so *.x core core* a.out *.exe *.exe.stackdump

tar: clean
	(cd ../; tar -cvzf $(tar_name).tar.gz  $(DIR) )
