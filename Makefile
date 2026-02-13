CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -O0 -gdwarf-4 -Wall -Wextra -Werror -pedantic -fsanitize=address,undefined,implicit-conversion,local-bounds -fno-omit-frame-pointer -fno-optimize-sibling-calls -fsanitize-address-use-after-return=always -Wno-error=unused-parameter $(INCLUDES)

exec: bin/exec
tests: bin/tests

bin/exec: ./includes/solution.hpp ./src/solution.cc ./src/driver.cc
	$(CXX) $(CXXFLAGS) ./src/driver.cc ./src/solution.cc ./bin/exceptional.o  -o $@

bin/tests: ./includes/solution.hpp ./src/solution.cc ./tests/tests.cc 
	$(CXX) -std=c++20 -Iincludes -gdwarf-4 -fstandalone-debug -O0 -Wall -Wextra -pedantic ./tests/tests.cc  ./src/solution.cc ./bin/exceptional.o  -o $@


.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -f -- bin/exec bin/tests