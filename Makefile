CXX = g++
CXXFLAGS = -std=c++17 -pedantic -Wall -Wextra -ILife
LDFLAGS = -lSDL2

PROJECT_NAME = ors
PROJECT_SRCS = $(wildcard Life/*.cpp)

all: $(PROJECT_SRCS)
	$(CXX) $(CXXFLAGS) $^ -o bin/$(PROJECT_NAME) $(LDFLAGS)

run:
	bin/$(PROJECT_NAME)

bin/%.o: Life/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

