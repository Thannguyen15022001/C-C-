CXX = g++
CC = gcc
CFLAGS = -I .
CXXFLAGS = -I . -L .
LIB = libstatic_lib.a  #Because use -lstatic_lib => compiler will find lib with name libstatic_lib.a
OBJECT = static_lib_c.o static_lib.o

.PHONY: all clean

all: main
# main: main.cpp
# 	$(CXX) -o $@ $^ $(CXXFLAGS) static_lib.a 

main: main.cpp $(LIB)
	$(CXX) -o $@ $^ $(CXXFLAGS) -lstatic_lib

$(LIB): $(OBJECT)
	ar rcs $@ $^

%.o: %.cpp
	$(CXX) -o $@  -c $< $(CXXFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o *.a

