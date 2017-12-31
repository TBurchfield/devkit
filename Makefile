CC=				gcc
CFLAGS=		-std=gnu99 -Wall
LD=				gcc
LDFLAGS=	-L.
TARGET=		devkit

# REQUIRES MODULES to be specified at run time.
FILES=	$(foreach var, $(MODULES), Modules/$(var)/$(var).o )
LIBS= map
LIBFILES= $(foreach var, $(LIBS), lib/$(var)/$(var).o) lib/map/hash.o


all:
	@echo Building with $(MODULES)
	make $(TARGET)


$(TARGET): main.c
	@echo Building from $<
	@for F in $(LIBS); do \
		echo Building $$F library; \
		cd lib/$$F; \
		make; \
		cd ../..; \
	done
	@for F in $(MODULES); do \
		echo Building $$F module; \
		cd Modules/$$F; \
		make; \
		cd ../..; \
	done
	$(LD) $(LDFLAGS)  -o $@ main.c $(FILES) $(LIBFILES)

clean:
	rm $(TARGET)



