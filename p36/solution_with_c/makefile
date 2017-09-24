main: main.o palindromic.o
	${LINK.c} -o $@ $^
	@rm *.o

main.o: main.c
	${COMPILE.c} -o $@ $^

palindromic.o: palindromic.c palindromic.h
	${COMPILE.c} -o $@ $<

.INTERMEDIATE:*.o
include ../../makefile
