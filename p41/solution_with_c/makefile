main: main.o bitmap.o
	${LINK.c} -o $@ $^
	@rm *.o
	
main.o: main.c prime_number.h
	${COMPILE.c} -o $@ $<

bitmap.o: bitmap.c bitmap.h
	${COMPILE.c} -o $@ $<
.INTERMEDIATE:*.o
include ../../makefile
