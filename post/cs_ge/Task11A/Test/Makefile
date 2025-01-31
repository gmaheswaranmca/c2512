# Target executable
TARGET = Tests.out

# Directories
SRCDIR = ./../Client/Sources
OBJDIR = ./../Client/Builds
HEADDIR = ./../Client/Headers

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I$(HEADDIR) -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lgtest -lgtest_main -pthread
# Detect all source files and create corresponding object file paths
SRCS = $(wildcard $(SRCDIR)/*.cpp) TestMain.cpp
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS) 
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
	@rm -f Department.dat

# Print source and object files (optional debugging targets)
print:
	@echo "Source files: $(SRCS)"
	@echo "Object files: $(OBJS)"

# Run the built executable
test: all
	@echo "\nRunning $(TARGET)..."
	./$(TARGET)