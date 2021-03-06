cmake_minimum_required(VERSION 3.5)

set(TARGET_NAME FLAME_Tester)
project(${TARGET_NAME} VERSION 1.0.0 LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})



if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
endif()



##################################
# Options: Library configuration #
##################################

add_subdirectory(modules/FLAME)



################
# Dependencies #
################





#############################
# Static library definition #
#############################

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*")
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/include/*")
file(GLOB_RECURSE CONFIG_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/cmake/*")
list(APPEND CONFIG_FILES "${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt")
list(APPEND CONFIG_FILES "${CMAKE_CURRENT_LIST_DIR}/conanfile.txt")

add_executable(${TARGET_NAME} ${SRC_FILES} ${HEADER_FILES} ${CONFIG_FILES})

target_include_directories(${TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif ()

set_target_properties(${TARGET_NAME} PROPERTIES C_STANDARD 11)
set_target_properties(${TARGET_NAME} PROPERTIES CXX_EXTENSIONS OFF)

if(MSVC)
    set_property(TARGET ${TARGET_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else()
    target_compile_options(${TARGET_NAME} PRIVATE -Wno-psabi)
endif()


############################
# Preprocessor definitions #
############################

if (WIN32)
    target_compile_definitions(${TARGET_NAME} PRIVATE
       WIN32_LEAN_AND_MEAN      # Prevents Windows.h from adding unnecessary includes
       NOMINMAX                 # Prevents Windows.h from defining min/max as macros 
       _CRT_SECURE_NO_WARNINGS
    )
endif()




###########
# Linking #
###########

target_link_libraries(${TARGET_NAME} FLAME::FLAME)



#######################
# Precompiled Headers #
#######################




#######
# IDE #
#######

#set_property(GLOBAL PROPERTY USE_FOLDERS ON)
#
#source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" PREFIX "src" FILES ${SRC_FILES})
#source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/include" PREFIX "include" FILES ${HEADER_FILES})
#source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${CONFIG_FILES})


##################
# Subdirectories #
##################




###########
# Install #
###########

# Install binaries
install(
    TARGETS ${TARGET_NAME}
    EXPORT ${TARGET_NAME}Targets
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    INCLUDES DESTINATION "include"
)
