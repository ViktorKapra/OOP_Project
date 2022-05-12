# CMakeList.txt : CMake project for StoreHouse, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("StoreHouse")

# Add source to this project's executable.
add_executable (StoreHouse "Main.cpp"  "Logic/TextContainer.h" "Data/Product.h" "Logic/TextContainer.cpp" "Data/Date.h"  "Data/Date.cpp" "Data/Product.cpp"   "Logic/DynamicArray.hpp"  "Data/Batch.cpp" "Data/Shelf.h"  "Data/Shelf.cpp" "Data/Section.h" "Logic/WareHouseLogic.h" "UI/UI.h" "UI/UI.cpp" "Logic/WareHouseLogic.cpp" "Data/Section.cpp") #   )

# TODO: Add tests and install targets if needed.
