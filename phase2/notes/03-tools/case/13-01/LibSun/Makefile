# Makefile for LibSun with object files in a separate folder

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -IHeaders

# Target library
TARGET = libsun.a

# Directories
SRCDIR = Sources
OBJDIR = Build
HEADDIR = Headers

# Detect all source files and create corresponding object file paths
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Build the static library
$(TARGET): $(OBJS)
	@printf "\n****************Building static library $(TARGET)...****************\n"
	@printf "[executing\n\tCMD: ar rcs $@ $^]\n"
	@ar rcs $@ $^ -v

# Build object files in the Build directory
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADDIR)/%.h | $(OBJDIR)
	@printf "\n****************Compiling to object file $@...****************\n"
	@printf "[executing\n\t$(CXX) $(CXXFLAGS) -c $< -o $@]\n"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure the Build directory exists
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Clean up object files and the library
clean:
	@echo "\nCleaning up..."
	@rm -rf $(OBJDIR)
	@rm -f $(TARGET)

# Print source and object files (optional debugging targets)
print:
	@echo "Source files: $(SRCS)"
	@echo "Object files: $(OBJS)"
