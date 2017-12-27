CC=				gcc
CFLAGS=		-std=gnu99 -Wall
LD=				gcc
LDFLAGS=	-L.
TARGET=		devkit

# REQUIRES MODULES to be specified at run time.
FILES=	$(foreach var, $(MODULES), Modules/$(var)/$(var).o )


all:
	@echo Building with $(MODULES)
	make $(TARGET)


$(TARGET): main.c
	@echo Building from $<
	@for F in $(MODULES); do \
		echo Building $$F module; \
		cd Modules/$$F; \
		make; \
		cd ../..; \
	done
	$(LD) $(LDFLAGS)  -o $@ main.c $(FILES)

clean:
	rm $(TARGET)



