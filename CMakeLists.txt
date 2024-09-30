cmake_minimum_required(VERSION 3.27)
project(sort_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(sort_1 main.cpp
        parser.cpp
        parser.h
        sort.cpp
        sort.h
        test/test.cpp)


        include(FetchContent)

        FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest
            GIT_TAG HEAD
        )
        FetchContent_MakeAvailable(googletest)
        
        enable_testing()
        
       # add_executable(test_all sort.cpp parser.cpp test\test.cpp)
        
        add_executable(sort main.cpp sort.cpp parser.cpp)
        add_test(NAME MyTest COMMAND test_all)
        
        target_link_libraries(sort PRIVATE GTest::gtest_main)
        target_link_libraries(test_all PRIVATE GTest::gtest_main)
        
        