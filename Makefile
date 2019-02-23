#
# EE 4374 Assignment 2 Makefile
# Author: ???
#


all: sgalindo_prog2

sgalindo_prog2: sgalindo_prog2.o sgalindo_argtok.o sgalindo_exec.o
	cc -o $@ $^
sgalindo_prog2.o: sgalindo_prog2.c sgalindo_argtok.h sgalindo_exec.h
	cc -c sgalindo_prog2.c
sgalindo_argtok.o: sgalindo_argtok.c sgalindo_argtok.h
	cc -c sgalindo_argtok.c
sgalindo_exec.o: sgalindo_exec.c sgalindo_exec.h
	cc -c sgalindo_exec.c
#clean:
#	rm -f *.o sgalindo_prog2

clean:
	rm *.o; rm sgalindo_prog2
