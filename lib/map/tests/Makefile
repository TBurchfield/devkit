CC=	gcc
CFLAGS=	-g -gdwarf-2 -Wall -std=gnu99
LD=	gcc
LDFLAGS=	-L.
AR=	ar
ARFLAGS=	rcs
TARGETS=	test

all:	$(TARGETS)

test.o: test.c
	@echo "Compiling test.o"
	@$(CC) $(CFLAGS) -c -o test.o test.c

map.o: ../map.c ../map.h
	@echo "Compiling map.o"
	@$(CC) $(CFLAGS) -c -o map.o ../map.c

hash.o: ../hash.c
	@echo "Compiling hash.o"
	@$(CC) $(CFLAGS) -c -o hash.o ../hash.c

test:	test.o map.o hash.o
	@echo "Linking object files into test"
	@$(LD) $(LDFLAGS) -o test test.o map.o hash.o

clean:
	@echo "Cleaning..."
	@rm *.o $(TARGETS)

.PHONY:	all clean
