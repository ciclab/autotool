CXX=g++
CXXFLAGS=-g -Wall \
	-DREAD_COUT=0 \
	-DASEM_COUT=0 \
	-DINSTR_COUT=0 \
	-DASGEN_COUT=0
SRC=src
VPATH=../src/frontend:../src/lib:../src/ir:../src/as
INCLUDE=-I../src/include
LEX = flex -v
YACC = bison -dv

driver:y.o l.o strstack.o l.h  driver.cpp 
	$(CXX) $(CXXFLAGS) $(INCLUDE) -I.  $^ -o $@

strstack.o: strstack.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

l.o: l.c
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@
y.o: y.c
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

l.c: as.lex y.h
	$(LEX) --prefix=dummy_ -o l.c $^

l.h: as.lex
	$(LEX) --header-file=l.h --prefix=dummy_ $^

y.c y.h: _as.y
	$(YACC) --name-prefix=dummy_ -o y.c $^

as.lex as.y _as.y: asgen out hash.o
	./asgen out as.lex as.y

asgen: asGen.cpp libir.a
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

rd: hash.o ir.o libir.a asem.o read.o
	$(CXX) $(CXXFLAGS) $(INCLUDE)  $^ -o $@

out: rd in
	./rd in $@

libir.a: hash.o wire.o stage.o enum.o instruction.o \
memory.o pipeline.o register.o type.o do_content.o ir.o
	ar crv $@ $^

asem.o: asem.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

read.o: read.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

ir.o: ir.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

hash.o: hash.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

wire.o: wire.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

stage.o: stages.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

enum.o: enum.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

instruction.o: instruction.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

memory.o: memory.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

pipeline.o: pipeline.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

register.o: register.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

type.o: type.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

do_content.o: do_content.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@
clean:
	rm *.* rd asgen out
