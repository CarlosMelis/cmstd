cmake_minimum_required(VERSION 3.24)
project(cmstd C)

set(CMAKE_C_STANDARD 23)

add_executable(StringTest
        lib/String/StringTest.c
        lib/String/String.c
        lib/Bool/Bool.h
        lib/Macros/Macros.h
        lib/PrimitiveTypes/PrimitiveTypes.h
        lib/Result/Result.c
        lib/Result/Result.h)

add_executable(LinkedListTest
        lib/Bool/Bool.h
        lib/Macros/Macros.h
        lib/LinkedList/LinkedList.c
        lib/LinkedList/LinkedList.h
        lib/Node/Node.c
        lib/Node/Node.h
        lib/PrimitiveTypes/PrimitiveTypes.h
        lib/Result/Result.c
        lib/Result/Result.h)

add_executable(NodeTest
        lib/Node/NodeTest.c
        lib/Node/Node.c
        lib/Node/Node.h
        lib/String/String.c
        lib/PrimitiveTypes/PrimitiveTypes.h
        lib/Result/Result.c
        lib/Result/Result.h)
