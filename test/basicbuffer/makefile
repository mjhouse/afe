CC=g++
CPPFLAGS=-lm -Werror -std=c++11
OUT=test
DEPS=-I.
OBJECTS=test_basicbuffer.o basicbuffer.o line.o markregister.o mark.o message.o

all: test

# link executable
test: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUT)
#	rm *.o

# test code
test_basicbuffer.o: test_basicbuffer.cpp
	$(CC) $(CPPFLAGS) -c test_basicbuffer.cpp

# basicbuffer
basicbuffer.o: ../../basicbuffer.cpp
	$(CC) $(CPPFLAGS) -c ../../basicbuffer.cpp

# line
line.o: ../../line.cpp
	$(CC) $(CPPFLAGS) -c ../../line.cpp

# markregister
markregister.o: ../../markregister.cpp
	$(CC) $(CPPFLAGS) -c ../../markregister.cpp

# mark
mark.o: ../../mark.cpp
	$(CC) $(CPPFLAGS) -c ../../mark.cpp

# message
message.o: ../../message.cpp
	$(CC) $(CPPFLAGS) -c ../../message.cpp

clean:
	rm *.o
