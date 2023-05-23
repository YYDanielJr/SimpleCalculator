cmake_minimum_required(VERSION 3.0.0)
project(SimpleCalculator VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(SimpleCalculator src/main.c src/stack.c src/control.c src/calculate.c src/postfix.c src/filewriter.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
