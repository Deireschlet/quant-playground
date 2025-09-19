CXX      := clang++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -Werror -O3 -g \
            -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all \
            -Iinclude 

# add file here (src/filename.cpp) if it should also be linked
SRC  := src/main.cpp src/io.cpp src/compute.cpp
OBJ  := $(SRC:.cpp=.o)
BIN  := simpaths

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)
