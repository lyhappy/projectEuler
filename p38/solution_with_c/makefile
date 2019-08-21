main: main.o
	${LINK.c} -o $@ $^
	@rm *.o

main.o: main.c
	${COMPILE.c} -o $@ $^

.INTERMEDIATE:*.o
include ../../makefile
