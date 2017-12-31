CC=				gcc
CFLAGS=		-std=gnu99 -Wall
LD=				gcc
LDFLAGS=	-L.
TARGET=		map.o

all:	$(TARGET) hash.o

$(TARGET): map.c map.h hash.c ../../main.h
	@echo Linking $(TARGET)...
	$(CC) $(CCFLAGS) -c -o $@ $<

hash.o: hash.c
	$(CC) $(CCFLAGS) -c -o $@ $<
