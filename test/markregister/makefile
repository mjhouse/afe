CC=g++
CPPFLAGS=-lm -Werror -std=c++11
OUT=test
DEPS=-I.
OBJECTS=test_markregister.o markregister.o mark.o line.o message.o

all: test

# link executable
test: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUT)
#	rm *.o

# main
test_markregister.o: test_markregister.cpp
	$(CC) $(CPPFLAGS) -c test_markregister.cpp

# markregister
markregister.o: ../../markregister.cpp
	$(CC) $(CPPFLAGS) -c ../../markregister.cpp

# mark
mark.o: ../../mark.cpp
	$(CC) $(CPPFLAGS) -c ../../mark.cpp
	
# line
line.o: ../../line.cpp
	$(CC) $(CPPFLAGS) -c ../../line.cpp
	
# message
message.o: ../../message.cpp
	$(CC) $(CPPFLAGS) -c ../../message.cpp

clean:
	rm *.o
