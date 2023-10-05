CXX = g++
CXX_ARGS = -g -Wall
SRC = code_assignment_1_main.cpp
INCLUDES = code_assignment_1_classes.hpp

Main: $(SRC) $(INCLUDES)
	$(CXX) $(CXX_ARGS) $(SRC) -o $@

run: Main
	./$<

clean:
	rm Main

# end