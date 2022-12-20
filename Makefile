####################################################################################################

#Compiler Vars: (Contact mentor for optimal compiler tags!)

CXX=clang++
CXX_FLAGS=-std=c++20 -g -O0 -Wall -Wextra -Werror

CC = g++
CFLAGS = -Wall -g

####################################################################################################

#Misc. Vars:

FILES = lib/*.cpp src/*.cpp
TEST_FILES = lib/*.cpp tests/test.cpp

####################################################################################################

exec: ${FILES}
	${CXX} ${CXX_FLAGS} $^ -o bin/exec.exe

##non clang compiling
#exec: ${FILES}
#	${CC} ${CFLAGS} $^ -o bin/exec.exe

tests: ${TEST_FILES}
	${CXX} ${CXX_FLAGS} $^ -o bin/tests.exe

##non clang compiling
#tests: ${TEST_FILES}
#	${CC} ${CFLAGS} $^ -o tests.exe

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -rf exec.exe

####################################################################################################