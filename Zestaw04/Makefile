
DIR = $(notdir $(CURDIR))
tar_name = Wojciech_Szymanski_$(DIR)

ArrayInclude = ArrayList
CursorInclude = CursorList
CXXFLAGS := -Wall -O3 -std=c++11 -pedantic 
LDFLAGS := -s 
LDLIBS := -lm


%.o: %.cpp                        # Reguła wzorcowa .c [+ .h] -> .o
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.x: %.o 						# Reguła wzorcowa .o + ... -> .x
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: all clean tar

all: Generator.x ArrayList.x CursorList.x


Generator.x: Generator.o

ArrayList.o: ArrayList.cpp $(addsuffix .hpp, $(ArrayInclude))
CursorList.o: CursorList.cpp $(addsuffix .hpp, $(CursorInclude))
clean:
	$(RM)  *.o  *~ *.a *.so *.x core core* a.out *.exe *.exe.stackdump 

tar: clean
	(cd ../; tar --exclude='.vscode' -cvzf $(tar_name).tar.gz  $(DIR) )
