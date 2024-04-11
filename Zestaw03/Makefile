
DIR = $(notdir $(CURDIR))
tar_name = Wojciech_Szymanski_$(DIR)

source = LinkedList
CXXFLAGS := -Wall -O3 -std=c++11 -pedantic 
LDFLAGS := -s 
LDLIBS := -lm


%.o: %.cpp                        # Reguła wzorcowa .c [+ .h] -> .o
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.x: %.o 						# Reguła wzorcowa .o + ... -> .x
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: all clean tar

all: Generator.x LinkedList.x


Generator.x: Generator.o

LinkedList.o: LinkedList.cpp $(addsuffix .hpp, $(source))

clean:
	$(RM)  *.o  *~ *.a *.so *.x core core* a.out *.exe *.exe.stackdump 

tar: clean
	(cd ../; tar --exclude='.vscode' -cvzf $(tar_name).tar.gz  $(DIR) )
