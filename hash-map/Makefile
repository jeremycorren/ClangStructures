# specify compiler
CC = gcc

# include other directories in compilation
INCLUDES =

# compile with -g for debugging
# compile with -Wall to show warnings
CFLAGS	 = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

# link with -g for debugging
LDFLAGS = -g

# link with libraries
LDLIBS =

# link object files into executable
main: main.o hashmap.o

# dependencies for main.o
main.o: main.c hashmap.h

# dependencies for hashmap.o
hashmap.o: hashmap.c hashmap.h

# clean up directory
.PHONY: clean
clean:
	rm -f *.o a.out core main hashmap executable

# clean up directory and compile again
.PHONY: all
all: clean main
