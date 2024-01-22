# cpp-env-var
### A small C++ libraries

> [!NOTE]  
>In case if some folks aren't familiar with the use of C++ 20 modules in CMake, here's an example:
```cmake
cmake_minimum_required(VERSION 3.28)
project(modenv CXX)

file(COPY .env DESTINATION ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_STANDARD 23)
add_library(mod
)

target_sources(mod
        PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}/mod
        FILES
        mod/getenv.cxx
        mod/getter.cxx
)

add_executable(modenv src/main.cpp
        src/sisi.h)
target_link_libraries(modenv mod)
```
