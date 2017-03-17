CC=g++
CPPFLAGS=-lm -Werror -std=c++11
OUT=test
DEPS=-I.
OBJECTS=test_TARGET.o TARGET.o

all: test

# link executable
test: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUT)
	rm *.o

# main
test_TARGET.o: test_TARGET.cpp
	$(CC) $(CPPFLAGS) -c test_TARGET.cpp

# TARGET
TARGET.o: ../../TARGET.cpp
	$(CC) $(CPPFLAGS) -c ../../TARGET.cpp

clean:
	rm *.o
