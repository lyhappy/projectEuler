CC=gcc
COMPILE.c ?= $(CC) $(CFLAGS) $(CPPFLAGS) -c -ansi
LINK.c ?= $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

CFLAGS = -Wall 
CFLAGSO = -Wall -O

INCLUDE = -I ../../include/
COMPILE.c += ${INCLUDE}


