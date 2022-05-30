CC=gcc
CFLAGS=-Wall -Wextra -pedantic -O3
OUTPUT=release
TARGET=libarray.a
LIB_PATH=/usr/lib64
INCLUDE_PATH=/usr/include
MODULES=\
array.o



all: env $(MODULES)
	ar -crs $(OUTPUT)/$(TARGET) $(MODULES)
	

array.o: src/array.c src/array.h
	$(CC) $(CFLAGS) -c src/array.c -o array.o


install:
	cp -v src/array.h $(INCLUDE_PATH)
	cp -v ${OUTPUT}/${TARGET} $(LIB_PATH)


test.o: test/test.c array.o
	$(CC) $(CFLAGS) -Isrc/ -c test/test.c 


autotest: env test.o $(MODULES)
	$(CC) $(CFLAGS) $(MODULES) test.o -o $(OUTPUT)/test
	$(OUTPUT)/test


env:
	mkdir -pv $(OUTPUT)


clean:
	rm -vfr ${OUTPUT}
	rm -vf ./*.o
