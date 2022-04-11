cmake_minimum_required(VERSION 3.13)
project(FLAME_Tester)

include(${CMAKE_BINARY_DIR}/../conanbuildinfo.cmake)
conan_basic_setup()

find_package(Battery REQUIRED)

add_executable(${PROJECT_NAME} "")
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_include_directories(${PROJECT_NAME} PUBLIC include)

file(GLOB_RECURSE SRC_FILES "src/*")
target_sources(${PROJECT_NAME} PUBLIC ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
target_link_libraries(${PROJECT_NAME} Battery::Battery)
