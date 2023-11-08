CC=g++
CFLAGS=-Wall -Werror -Iinclude
DEBUG=-g

all: clean compile lib

# Compile all files from src to bin
compile:
	$(CC) $(CFLAGS) -c src/*.cc
	mkdir -p bin
	mv *.o bin/

lib:
	ar rcs libmylib.a bin/*.o

# Compile and link the test file
test: compile
	$(CC) $(CFLAGS) $(DEBUG) -o bin/test test/test.cc bin/*.o
# Run a python http server on port 8080 to serve the test file so we can run the test and close it after the test is done
	@echo "\033[32mRunning tests...\033[0m"
	@python -m SimpleHTTPServer 8080 > /dev/null 2>&1 &
	@sleep 1
	./bin/test
	@echo "\033[32mKilling server...\033[0m"
	@kill -9 `ps aux | grep SimpleHTTPServer | grep -v grep | awk '{print $$2}'`
	@echo "\033[32mTests passed!\033[0m"

# Cleanup trash
clean:
	rm -rf bin/*.o bin/test libmylib.a