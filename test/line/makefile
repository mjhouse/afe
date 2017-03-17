CC=g++
CPPFLAGS=-lm -Werror -std=c++11
OUT=test
DEPS=-I.
OBJECTS=test_line.o line.o markregister.o message.o mark.o

all: test

# link executable
test: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUT)
#	rm *.o

# main
test_line.o: test_line.cpp
	$(CC) $(CPPFLAGS) -c test_line.cpp

# line
line.o: ../../line.cpp
	$(CC) $(CPPFLAGS) -c ../../line.cpp

# markregister
markregister.o: ../../markregister.cpp
	$(CC) $(CPPFLAGS) -c ../../markregister.cpp

# message
message.o: ../../message.cpp
	$(CC) $(CPPFLAGS) -c ../../message.cpp

# mark
mark.o: ../../mark.cpp
	$(CC) $(CPPFLAGS) -c ../../mark.cpp

clean:
	rm *.o
