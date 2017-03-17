CC=g++
CPPFLAGS=`pkg-config --static --libs glfw3` -ldl -lGLEW -lm -lfreetype -std=c++11
#CPPFLAGS=`pkg-config --static --libs glfw3` -ldl -lm -lfreetype -Werror -Wpedantic -Wall -Wextra -std=c++11

TARGET = bin/afe
BLDDIR = obj
SRCDIR = src 
INCDIR = inc

INC = -I$(INCDIR) -I/usr/include/freetype2 `pkg-config --cflags glfw3`

# find all source files in src
SOURCES := $(shell find src/ -type f -name '*.cpp')

# assembles each source file into a BLDIR/*.o filename
OBJECTS := $(SOURCES:src/%.cpp=$(BLDDIR)/%.o)

# ----------------------------------------------------------------------
# DON'T EDIT BELOW THIS LINE
# ----------------------------------------------------------------------
all: link

# link executable
link: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(CPPFLAGS)

# build all .o files
obj/%.o: src/%.c*
	$(CC) $(INC) -c $< -o $@ $(CPPFLAGS)

clean:
	rm $(BLDDIR)/*.o; rm $(TARGET)
