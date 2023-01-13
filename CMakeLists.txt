cmake_minimum_required(VERSION 3.10)

project("Modeler")

# set(CMAKE_TOOLCHAIN_FILE "C:/Users/thoma/vcpkg/scripts/buildsystems/vcpkg.cmake")
# set(CMAKE_PREFIX_PATH "C:/Users/thoma/vcpkg/packages/sdl2_x64-windows")

add_executable(Test "Main.cpp")
find_package(SDL2 CONFIG REQUIRED )

target_link_libraries(Test PRIVATE SDL2::SDL2)