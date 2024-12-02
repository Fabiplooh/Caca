CC=gcc
CFLAGS=-Wall -Werror

.PHONY: clean

all: essai_fap

clean:
	rm -f *.o essai_fap

# Dependances
essai_fap: essai_fap.o fap_bug.o

fap_bug.o: fap_bug.c fap.h
essai_fap.o: essai_fap.c fap.h


