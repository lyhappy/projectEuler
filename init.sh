#!/bin/bash

PROBLEM_NUM=$1
PROBLEM_DIR=p$1
SRC=${PROBLEM_DIR}/solution_with_c

if [ x$1 == x ]; then
    echo "please input problem number!"
fi

if [ ! -d ${PROBLEM_DIR} ]; then
    mkdir ${PROBLEM_DIR}
    mkdir ${SRC}
fi

touch ${PROBLEM_DIR}/readme.md
touch ${SRC}/makefile
touch ${SRC}/main.c

# template of main.c
cat>${SRC}/main.c<<EOF
#include <stdio.h>


int main(int argc, char** argv) {
    return 0;
};
EOF


# template of makefile
cat>${SRC}/makefile<<EOF
main: main.o
	\${LINK.c} -o \$@ $^
	@rm *.o
	
main.o: main.c
	\${COMPILE.c} -o \$@ $<

.INTERMEDIATE:*.o
include ../../makefile
EOF
