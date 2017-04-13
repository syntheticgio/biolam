# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wno-reorder -O3
CXXFLAGS = -DRELEASE

# the build target executable
TARGET = biolam-linux

all: compile

# Debug mode
# 'make debug'
debug: CFLAGS += -pthread -g -Wall
debug: CXXFLAGS = -DDEBUG
debug: TARGET = biolam-linux-debug
debug: compile
#debug: interface

# Raspberry pi
# 'make raspberry'
raspberry: CC = g++-4.9
raspberry: CFLAGS += -g -Wall -gdwarf-3
raspberry: CXXFLAGS = -DDEBUG
raspberry: TARGET = biolam-raspbian
raspberry: compile

# OSX Debug
# 'make osx_debug'
# This is a debug build for OSX
osx_debug: CC = clang++
osx_debug: CFLAGS += -stdlib=libc++ -g -Wall -gdwarf-3
osx_debug: CXXFLAGS = -DDEBUG
osx_debug: TARGET = biolam-osx-debug
osx_debug: compile

#OSX Release
# 'make osx'
# This is the release build for OSX
osx: CC = clang++
osx: CFLAGS += -stdlib=libc++ -O3
osx: CXXFLAGS = -DRELEASE
osx: TARGET = biolam-osx
osx: compile

# Support functions
compile: biolam-base.o main.o
	$(CC) $(CFLAGS) -o $(TARGET) biolam-base.o main.o $(CXXFLAGS)

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp -o main.o $(CXXFLAGS)

biolam-base.o: biolam-base.cpp biolam-base.hpp
	$(CC) $(CFLAGS) -c biolam-base.cpp -o biolam-base.o $(CXXFLAGS)

#interface: 
#	g++ src/interface.cpp -o src/interface -std=c++11 `pkg-config gtkmm-3.0 --cflags --libs`

# clean up the built files
clean: 
	$(RM) $(TARGET) *.o *~
