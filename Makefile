#This is a very simple makefile for building the Lisp interpreter
# project when using C++ on stdlinux. Feel free to add any improvements:
# e.g. pattern rules, automatic tracking of dependencies, etc. There
# is a lot of info about "make" on the web.

# C++ compiler
CXX = g++

# C++ compiler flags
CXXFLAGS = -g -Wall

# Creating a .o file
COMPILE = $(CXX) $(CXXFLAGS) -c

# Name of the executable; should match the contents of Runfile
EXE = myint

# All object files
OBJS = main.o Scanner.o Parser.o Emptylistchecker.o TypeChecker.o Interpreter.o 

# The first target is the one that is executed when you invoke
# "make". The line describing the action starts with <TAB>. Variable
# "$@" stands for the current target. 

$(EXE) : $(OBJS) # depends on all object files
	$(CXX) $^ -o $@

# An object file is dependent on the corresponding source file
%.o : %.cc
	$(COMPILE) -o $@ $<

main.o : Interpreter.h
Interpreter.o : Emptylistchecker.h
Interpreter.o : TypeChecker.h
Interpreter.o : Parser.h
Emptylistchecker.o : Parser.h
TypeChecker.o : Parser.h
Parser.o : Scanner.h 
Scanner.o :Scanner.h