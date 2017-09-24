CC=gcc
COMPILE.c ?= $(CC) $(CFLAGS) $(CPPFLAGS) -c -ansi
LINK.c ?= $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

CFLAGS = -Wall 
CFLAGSO = -Wall -O

INCLUDE = -I ../../include/
COMPILE.c += ${INCLUDE}

debug: CPPFLAGS += -DDEBUG -g
debug: CFLAGS += -DDEBUG -g
debug: main
	
test: CPPFLAGS += -DTEST
test: CFLAGS += -DTEST
test: main
	
clean:
	rm -rf *.o main
