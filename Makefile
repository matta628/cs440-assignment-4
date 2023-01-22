CFLAGS = -g -Wall -Wextra -pedantic -std=c++14

all: test_Array-new

test_Array-new: test_Array-new.o
	g++ $(CFLAGS) -o test_Array-new test_Array-new.o
test_Array-new.o: test_Array-new.cpp Array.hpp
	g++ $(CFLAGS) -c test_Array-new.cpp

run: all
	./test_Array-new

clean:
	rm -rf *.o test_Array-new

memcheck: all
	valgrind ./test_Array-new
memcheck++: all
	valgrind --leak-check=full --track-origins=yes -v ./test_Array-new
