#Sean Whelan
#Makefile for Lab 2
#16/03/2023

OBJECTS = Semaphore.o signal.o

SOURCES = Semaphore.cpp signal.cpp main.cpp
HEADERS = Semaphore.h

OUTPUTS = main.out

CC=g++
CFLAGS= -std=c++11 -pthread
LFLAGS= 

#SIMPLE:
#	$(CC) $(CFLAGS) $(SOURCES) $(HEADERS) $(OBJECTS)
# -g is for debugging
all: $(OBJECTS)
	$(CC) -g $(OBJECTS) -o $(OUTPUTS) $(LFLAGS)
	make CLEAN
CLEAN:
	rm -f $(OBJECTS) #removes all object by force
