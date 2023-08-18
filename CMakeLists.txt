cmake_minimum_required(VERSION 3.24)
project(cmstd C)

set(CMAKE_C_STANDARD 23)

add_executable(StringTest
        lib/String/StringTest.c
        lib/String/String.c
        lib/String/String.h
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
        lib/Result/Result.h
        lib/Queue/QueueTest.c)

add_executable(NodeTest
        lib/Node/NodeTest.c
        lib/Node/Node.c
        lib/Node/Node.h
        lib/String/String.h
        lib/String/String.c
        lib/PrimitiveTypes/PrimitiveTypes.h
        lib/Result/Result.c
        lib/Result/Result.h)

add_executable(ResultTest
        lib/Result/Result.c
        lib/Result/Result.h
        lib/Result/ResultTest.c
        lib/String/String.c
        lib/String/String.h
        lib/Bool/Bool.h
        lib/Macros/Macros.h)

add_executable(StackTest
        lib/Stack/Stack.c
        lib/Stack/Stack.h
        lib/Stack/StackTest.c)

add_executable(QueueTest
        lib/Queue/Queue.c
        lib/Queue/Queue.h
        lib/Queue/QueueTest.c)
