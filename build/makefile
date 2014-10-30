CXX=g++
CXXFLAGS=-g -Wall \
	-DREAD_COUT=0 \
	-DASEM_COUT=0 \
	-DINSTR_COUT=0 \
	-DASGEN_COUT=0 \
	-DIGNORE_CASE\
	-std=c++11\
	-lglog\
	-lgflags

SRC=../src

VPATH=../src/frontend:../src/lib:../src/ir:../src/as:../src/preprocessor:../src/simulator:../src/simulator/common:../src/simulator/unit_prototype:../src/simulator/framework

INCLUDE=-I../src/include -I. -I..
LEX = flex -v
YACC = bison -dv
BINUTILS_DIR = ../../z/binutils-2.23-r
input_file = ../swift.des

# driver:y.o l.o strstack.o l.h  driver.cpp 
# 	$(CXX) $(CXXFLAGS) $(INCLUDE) -I.  $^ -o $@

binutils: y.c y.h l.c l.h coff-dummy.c tc-dummy.c dis_as.c dis_as.h dis_l.h dis_l.c dis_as.y.h
	cp y.c y.h l.c l.h  $(BINUTILS_DIR)/gas;cp tc-dummy.c $(BINUTILS_DIR)/gas/config;cp coff-dummy.c $(BINUTILS_DIR)/bfd/coff-mips.c;cp ../src/as/strstack.cpp $(BINUTILS_DIR)/gas/strstack.c; cp ../src/include/strstack.h $(BINUTILS_DIR)/gas ; cp ./reloc.c $(BINUTILS_DIR)/bfd ; cp ./reloc.texi $(BINUTILS_DIR)/bfd/doc ;cp ../src/include/strstack.h $(BINUTILS_DIR)/binutils ; cp ../src/as/strstack.cpp $(BINUTILS_DIR)/binutils/strstack.c ; cp ./dummy-dis.c $(BINUTILS_DIR)/opcodes ; cp  dis_l.c dis_as.c $(BINUTILS_DIR)/opcodes ; cp dis_as.h dis_as.y.h  dis_l.h $(BINUTILS_DIR)/include/opcode 

simGen: simGen.o ir.o libir.a asem.o hash.o utility.o
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

class.h pipeline.h reg.h : simGen out
	./simGen out out2

simulator: class.h pipeline.h reg.h simulator.cpp sim_dis.y.c sim_dis.l.c sim_dis.y.h simlib.cpp reg.c mem.c sim_dis.l.h stage.c vars.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

runsim: simulator aa.out
	./simulator aa.out

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

dis_l.h: dis_as.y.lex
	$(LEX) --header-file=dis_l.h --prefix=dis_ $^

dis_l.c: dis_as.y.lex
	$(LEX) --prefix=dis_ -o $@ $^

dis_as.c dis_as.h: dis_as.y.y
	$(YACC) --name-prefix=dis_ -o $@ $^

sim_dis.y.c sim_dis.y.h: sim_dis.y
	$(YACC) --name-prefix=dis_ -o $@ $^

sim_dis.l.h: sim_dis.lex
	$(LEX) --header-file=sim_dis.l.h --prefix=dis_ $^

sim_dis.l.c: sim_dis.lex
	$(LEX) --prefix=dis_ -o $@ $^

sim_dis.lex sim_dis.y dis_as.y.h dis_as.y.lex dis_as.y.y as.lex as.y _as.y coff-dummy.c reloc.c tc-dummy.c dummy-dis.c: asgen out hash.o coff-dummy1 coff-dummy3 coff-dummy4 tc-dummy1 tc-dummy1 tc-dummy3 dummy-dis1.c dummy-dis2.c
	./asgen out as.lex as.y

asgen: asGen.cpp libir.a
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

rd: hash.o ir.o libir.a asem.o read.o
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

out: rd $(input_file) pp
	cpp $(input_file) | ../src/preprocessor/pp  > in.tmp && ./rd in.tmp $@

pp: pp.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

pp.cpp: pp.lex
	$(LEX) -o $@ $^

libir.a: hash.o wire.o stage.o enum.o instruction.o \
memory.o pipeline.o register.o type.o do_content.o ir.o\
addr.o
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

addr.o: addr.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

simGen.o: simGen.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

utility.o: utility.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

sample_simulator: sample_simulator.cpp simulator.cpp mem_base.cpp register_base.cpp pipeline_base.cpp type_base.cpp instruction_base.cpp
	$(CXX) $(INCLUDE) $^ -o $@ $(CXXFLAGS)

clean:
	rm *.* rd asgen out pp simulator sample_simulator
