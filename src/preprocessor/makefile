LEX = flex -v
VPATH = ../include
CXXFLAGS = -O2 -g -I../include

pp: pp.cpp perr.h
	$(CXX) $(CXXFLAGS) $^ -o $@

pp.cpp: pp.lex
	$(LEX) -o $@ $^

clean:
	rm pp.cpp pp