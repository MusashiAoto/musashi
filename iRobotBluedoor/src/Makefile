AR = ar
CC = gcc -g
INSTALL = /usr/local/lib
INCLUDE = /usr/local/include

.PHONY:  default object archive install update uninstall docs clean

default: update

object: createoi.c createoi.h
	$(CC) -c -o createoi.o $<

archive: createoi.o
	$(AR) rcs libcreateoi.a $<

install: libcreateoi.a createoi.h
	cp $< $(INSTALL)
	cp createoi.h $(INCLUDE)
	ranlib $(INSTALL)/libcreateoi.a

update: object archive install

uninstall:
	rm $(INSTALL)/libcreateoi.a
	rm $(INCLUDE)/createoi.h

docs:
	@echo Not yet supported.  For now, use your favorite TeX editor to compile \
	manual.tex in the docs/ directory.

clean:
	rm src/libcreateoi.a
	rm src/createoi.o
