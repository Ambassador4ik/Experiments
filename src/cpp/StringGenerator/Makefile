# Set the default target to 'all'
.PHONY: all clean run build

# Default target
all: build

# Configure and build the project using CMake
build:
	mkdir -p build
	cd build && cmake .. && make

# Clean the build directory
clean:
	rm -rf build bin

# Run the executable
run: build
	./build/StringGen
