### A Template Makefile for MacOS & Linux, support clang/clang++ & gcc/g++

CXX = g++
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CXX = clang++
endif
ifeq ($(UNAME_S),Linux)
	CXX = g++
endif

CCFLAGS		:=
INCLUDES	:=
LDFLAGS		:=
LIBRARIES	:=

########################################
all:	build
build:	main

main.o:5_longest_palindromic_substring.cc
	$(CXX) $(INCLUDES) $(CCFLAGS) -o $@ -c $<
main:main.o
	$(CXX) $(LDFLAGS) -o $@ $+ $(LIBRARIES)

.PHONY: clean
clean:
	rm -f main.o main
