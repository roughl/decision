GCC = gcc
CFLAGS = -Wall -g -O2 -pipe -std=c99

all: decision

decision: decision.c
	${GCC} ${CFLAGS} -o decision decision.c
