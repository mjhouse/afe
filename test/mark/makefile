CC=g++
CPPFLAGS=-lm -Werror -std=c++11
OUT=test
DEPS=-I.
OBJECTS=test_mark.o mark.o line.o message.o markregister.o

all: test

# link executable
test: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUT)
#	rm *.o

# main
test_mark.o: test_mark.cpp
	$(CC) $(CPPFLAGS) -c test_mark.cpp

# line
line.o: ../../line.cpp
	$(CC) $(CPPFLAGS) -c ../../line.cpp

# mark
mark.o: ../../mark.cpp
	$(CC) $(CPPFLAGS) -c ../../mark.cpp

# markregister
markregister.o: ../../markregister.cpp
	$(CC) $(CPPFLAGS) -c ../../markregister.cpp

# message
message.o: ../../message.cpp
	$(CC) $(CPPFLAGS) -c ../../message.cpp

clean:
	rm *.o
