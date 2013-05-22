export CXX = g++
export CXXFLAGS = -g -O2 -Wall -Werror -Wfloat-equal -Wshadow -Wconversion -Winline

pp:
	make -C ./src/preprocessor pp

clean:
	make -C ./src/preprocessor clean