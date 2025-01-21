# Makefile for testing libsun.a using GTest

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -I../LibSun/Headers -I/usr/local/include
LDFLAGS = -L../LibSun -lsun -L/usr/local/lib -lgtest -lgtest_main -pthread
DEBUG_OPTIONS = -tui
# Source files
SRCS = SunTest.cpp
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = testLibSun

# Default target
all: $(TARGET)

# Build the test executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run tests
test: all
	@echo "\nRunning Tests $(TARGET)..."
	./$(TARGET)

# Debug tests
debug: all
	@echo "\Debugging Tests $(TARGET)..."
	gdb $(DEBUG_OPTIONS) ./$(TARGET)

# Clean up
clean:
	@rm -f $(OBJS) $(TARGET)
