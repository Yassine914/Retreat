#!/bin/bash

# clean build if specified
if [ "$1" == "clean" ] || [ "$1" == "c" ]; then
    rm -rf build
fi

# Create a build directory if it doesn't exist
mkdir -p build
cd build || exit 1

# Run cmake to generate Makefiles
cmake ../ -B . -G "Unix Makefiles" || exit 1

# Build the project
make || exit 1

# Run the executable
./bin/retreat || exit 1
