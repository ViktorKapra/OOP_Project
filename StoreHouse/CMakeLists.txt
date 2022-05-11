# CMakeList.txt : CMake project for StoreHouse, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("StoreHouse")

# Add source to this project's executable.
add_executable (StoreHouse "Main.cpp"  "TextContainer.h" "Product.h" "TextContainer.cpp" "Date.h"  "Date.cpp" "Product.cpp" "IdGenerator.h" "IdGenerator.cpp" "DynamicArray.hpp"  "Batch.cpp" "Shelf.h"  "Shelf.cpp") #   )

# TODO: Add tests and install targets if needed.
