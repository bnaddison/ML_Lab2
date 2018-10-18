# ADDBRA001 Makefile Template

## FLAGS ==================================================================
CC=g++ -std=c++11
LIBS=-lm
## ========================================================================

finds: finds.o
	$(CC) finds.o -o finds $(LIBS)


finds.o: finds.cpp
	$(CC) -c finds.cpp

clean:
	@rm -f *.o
	@rm finds

install:

	@mv finds ~/bin
