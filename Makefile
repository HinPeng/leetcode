### MakeAll

SUBDIRS := $(shell ls -d */)

all:
	for dir in $(SUBDIRS); do \
		make -C $$dir; \
	done

clean:
	for dir in $(SUBDIRS); do \
		make clean -C $$dir; \
	done

# CXX = g++
# UNAME_S := $(shell uname -s)
# ifeq ($(UNAME_S),Darwin)
# 	CXX = clang++
# endif
# ifeq ($(UNAME_S),Linux)
# 	CXX = g++
# endif

# CCFLAGS		:=
# INCLUDES	:=
# LDFLAGS		:=
# LIBRARIES	:=

# ########################################
# all:	build
# build:	main

# main.o:xx.cc
# 	$(CXX) $(INCLUDES) $(CCFLAGS) -o $@ -c $<
# main:main.o
# 	$(CXX) $(LDFLAGS) -o $@ $+ $(LIBRARIES)

# .PHONY: clean
# clean:
# 	rm -f main.o main
