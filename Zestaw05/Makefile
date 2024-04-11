
DIR = $(notdir $(CURDIR))
tar_name = Wojciech_Szymanski_$(DIR)

Sorts= BubbleSort InsertionSort SelectionSort
CXXFLAGS := -Wall -O3 -std=c++11 -pedantic 
LDFLAGS := -s 
LDLIBS := -lm


%.o: %.cpp                        # Reguła wzorcowa .c [+ .h] -> .o
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.x: %.o 						# Reguła wzorcowa .o + ... -> .x
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: all clean tar

all: $(addsuffix .x, $(Sorts)) Generator.x CountingSort.x


BubbleSort.x: BubbleSort.o
SelectionSort.x: SelectionSort.o
InsertionSort.x: InsertionSort.o
Generator.x: Generator.o
CountingSort.x: CountingSort.o

clean:
	$(RM)  *.o  *~ *.a *.so *.x core core* a.out *.exe *.exe.stackdump 

tar: clean
	(cd ../; tar --exclude='.vscode' -cvzf $(tar_name).tar.gz  $(DIR) )
