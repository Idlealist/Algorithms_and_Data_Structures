
DIR = $(notdir $(CURDIR))
tar_name = Wojciech_Szymanski_$(DIR)

Include = Dict LinkedList

CXXFLAGS := -Wall -O3 -std=c++11 -pedantic 
LDFLAGS := -s 
LDLIBS := -lm


%.o: %.cpp                        # Reguła wzorcowa .c [+ .h] -> .o
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.x: %.o 						# Reguła wzorcowa .o + ... -> .x
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: all clean tar

all: Dict.x

Dict.x: Dict.o
Dict.o: Dict.cpp $(addsuffix .hpp, $(Include))

clean:
	$(RM)  *.o  *~ *.a *.so *.x core core* a.out *.exe *.exe.stackdump 

tar: clean
	(cd ../; tar --exclude='.vscode' -cvzf $(tar_name).tar.gz  $(DIR) )
