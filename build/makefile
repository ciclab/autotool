CXX=g++
CXXFLAGS=-g -Wall \
	-DREAD_COUT=0 \
	-DASEM_COUT=0 \
	-DINSTR_COUT=0 \
	-DASGEN_COUT=0
SRC=src
VPATH=../src/frontend:../src/lib:../src/ir:../src/as:../src/preprocessor
INCLUDE=-I../src/include
LEX = flex -v
YACC = bison -dv
BINUTILS_DIR = ../../z/binutils-2.23-r
input_file = ../swift.des

# driver:y.o l.o strstack.o l.h  driver.cpp 
# 	$(CXX) $(CXXFLAGS) $(INCLUDE) -I.  $^ -o $@

binutils: y.c y.h l.c l.h coff-dummy.c tc-dummy.c
	cp y.c y.h l.c l.h  $(BINUTILS_DIR)/gas;cp tc-dummy.c $(BINUTILS_DIR)/gas/config;cp coff-dummy.c $(BINUTILS_DIR)/bfd;cp ../src/as/strstack.cpp $(BINUTILS_DIR)/gas/strstack.c; cp ../src/include/strstack.h $(BINUTILS_DIR)/gas ; cp ./reloc.c $(BINUTILS_DIR)/bfd ; cp ./reloc.texi $(BINUTILS_DIR)/bfd/doc

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

as.lex as.y _as.y coff-dummy.c reloc.c tc-dummy.c: asgen out hash.o coff-dummy1 coff-dummy3 coff-dummy4 tc-dummy1 tc-dummy1 tc-dummy3
	./asgen out as.lex as.y

asgen: asGen.cpp libir.a
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

rd: hash.o ir.o libir.a asem.o read.o
	$(CXX) $(CXXFLAGS) $(INCLUDE)  $^ -o $@

out: rd $(input_file) pp
	cpp $(input_file) | ./pp  >in.tmp && ./rd in.tmp $@

pp: pp.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

pp.cpp: pp.lex
	$(LEX) -o $@ $^

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
	rm *.* rd asgen out pp
