cmake_minimum_required(VERSION 2.8.2)

message("Googletest is cloned from repository...")
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
)
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds the following targets:
# gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest-build"
)

# The gtest/gmock targets carry header search path dependencies
# automatically when using CMake 2.8.11 or later. Otherwise we
# have to add them here ourselves.
if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include"
    )
endif()

# Устанавливаем стандарты для компиляции библиотеки googletest
set_target_properties(gtest gtest_main gmock gmock_main PROPERTIES CXX_STANDARD 11)
set_target_properties(gtest gtest_main gmock gmock_main PROPERTIES CXX_STANDARD_REQUIRED ON)
message("Googletest is cloned")

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate

message("Project BigInteger building is started...")
project(BigInteger LANGUAGES CXX)
add_executable(BigInteger src/main_big_integer.cpp src/big_integer.cpp)
set_target_properties(BigInteger PROPERTIES CXX_STANDARD 11)
set_target_properties(BigInteger PROPERTIES CXX_STANDARD_REQUIRED ON)
set_target_properties(BigInteger PROPERTIES RUNTIME_OUTPUT_DIRECTORY "./bin")
message("Project BigInteger building is finished")

message("Project RationalNumber building is started...")
project(RationalNumber LANGUAGES CXX)
add_executable(RationalNumber src/main_rational_number.cpp src/rational_number.cpp src/leibniz_row.cpp)
set_target_properties(RationalNumber PROPERTIES CXX_STANDARD 11)
set_target_properties(RationalNumber PROPERTIES CXX_STANDARD_REQUIRED ON)
set_target_properties(RationalNumber PROPERTIES RUNTIME_OUTPUT_DIRECTORY "./bin")
message("Project RationalNumber building is finished")

message("Project GTests building is started...")
project(GTests LANGUAGES CXX)
add_executable(GTests test/test.cpp test/bi_tests.cpp src/big_integer.cpp test/rn_tests.cpp src/rational_number.cpp)
set_target_properties(GTests PROPERTIES CXX_STANDARD 11)
set_target_properties(GTests PROPERTIES CXX_STANDARD_REQUIRED ON)
set_target_properties(GTests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "./bin")
target_link_libraries(GTests gtest gtest_main)
message("Project GTests building is finished")

install(TARGETS BigInteger RUNTIME DESTINATION bin)
install(TARGETS RationalNumber RUNTIME DESTINATION bin)
install(TARGETS GTests RUNTIME DESTINATION bin)
