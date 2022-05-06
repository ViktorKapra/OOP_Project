# CMakeList.txt : CMake project for StoreHouse, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("StoreHouse")

# Add source to this project's executable.
add_executable (StoreHouse "Main.cpp"  "TextContainer.h" "Product.h" "TextContainer.cpp" "Date.h" ) #   )

# TODO: Add tests and install targets if needed.
