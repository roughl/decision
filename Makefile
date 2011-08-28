GCC = gcc
LIBFLAGS = `pkg-config --libs openssl`
CFLAGS = -Wall -g -O2 -pipe -std=c99

all: decision

decision: decision.c
	${GCC} ${CFLAGS} ${LIBFLAGS} -o decision decision.c
