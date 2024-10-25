# Variables
CXX = g++
TARGET = main
SRC = main.cpp

# Default target
all: $(TARGET)

# Compilation rule
$(TARGET): $(SRC)
	$(CXX) -o $(TARGET) $(SRC)

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)
