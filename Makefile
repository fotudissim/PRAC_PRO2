OBJECTES=$(patsubst %.cc,%.o,$(wildcard *.cc))
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
CXX=g++

all: program.exe

%.o: %.cc
	$(CXX) -c $< $(CXXFLAGS)

program.exe: $(OBJECTES)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.o

distclean:
	rm -rf *.o *.exe DOC/
doc:
	doxygen Doxyfile
