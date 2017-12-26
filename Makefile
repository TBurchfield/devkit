CC=				gcc
CFLAGS=		-std=gnu99 -Wall
LD=				gcc
LDFLAGS=	-L.
TARGET=		devkit


all:	$(TARGET)


%.o: %.c
	@echo Compiling $@
	$(CC) $(CFLAGS) -c -o $@  $<


$(TARGET): main.c
	@echo Building from $<
	$(LD) $(LDFLAGS)  -o $@ main.c






