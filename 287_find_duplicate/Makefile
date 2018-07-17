### A Template Makefile for MacOS & Linux, support clang/clang++ & gcc/g++

CXX = g++
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CXX = clang++
endif
ifeq ($(UNAME_S),Linux)
	CXX = g++
endif

CCFLAGS		:= -std=c++11
INCLUDES	:=
LDFLAGS		:=
LIBRARIES	:=

########################################
all:	build
build:	main

main.o:287_find_duplicate.cc
	$(CXX) $(INCLUDES) $(CCFLAGS) -o $@ -c $<
main:main.o
	$(CXX) $(LDFLAGS) -o $@ $+ $(LIBRARIES)

.PHONY: clean
clean:
	rm -f main.o main
