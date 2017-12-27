CC=				gcc
CFLAGS=		-std=gnu99 -Wall
LD=				gcc
LDFLAGS=	-L.
TARGET=		pre.o

all:	$(TARGET)

$(TARGET): pre.c ../../main.h
	@echo Linking $(TARGET)...
	$(CC) $(CCFLAGS) -c -o $@ $<
