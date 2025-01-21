# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -IHeaders -I../LibSun/Headers
LDFLAGS = -L../LibSun -lsun
DEBUG_OPTIONS = -tui
# Target executable
TARGET = App.out

# Directories
SRCDIR = Sources
OBJDIR = Build
HEADDIR = Headers

# Detect all source files and create corresponding object file paths
SRCS = $(wildcard $(SRCDIR)/*.cpp) Main.cpp
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS) ../LibSun/libsun.a
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure the Build directory exists
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Clean up object files and the executable
clean:
	@echo "\nCleaning up..."
	@rm -rf $(OBJDIR)
	@rm -f $(TARGET)

# Print source and object files (optional debugging targets)
print:
	@echo "Source files: $(SRCS)"
	@echo "Object files: $(OBJS)"

# Run the built executable
run: all
	@echo "\nRunning $(TARGET)..."
	./$(TARGET)

# Debug the executable
debug: all
	@echo "\nDebugging $(TARGET)..."
	gdb $(DEBUG_OPTIONS) ./$(TARGET)
