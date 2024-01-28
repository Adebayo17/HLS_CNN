# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Include directories
INCLUDE_DIRS = -Iinclude -Iac_fixed

# Source directory
SRC_DIR = src

# Output directory
OBJ_DIR = obj

# Binary name
TARGET = top_cnn_hardware

# List of source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# List of object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Default rule
all: $(TARGET)

# Rule to link the executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -o $@ $^

# Rule to compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c -o $@ $<

# Rule to create the object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean rule
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
