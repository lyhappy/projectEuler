debug: CPPFLAGS += -DDEBUG -g
debug: CFLAGS += -DDEBUG -g
debug: main
	
test: CPPFLAGS += -DTEST
test: CFLAGS += -DTEST
test: main

main: main.o palindromic.o
	${LINK.c} -o $@ $^
	@rm *.o

main.o: main.c
	${COMPILE.c} -o $@ $^

palindromic.o: palindromic.c
	${COMPILE.c} -o $@ $^

.INTERMEDIATE:*.o

clean:
	rm -rf *.o main

include ../../makefile
