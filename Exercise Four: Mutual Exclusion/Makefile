#Sean Whelan
#Makefile for Lab 4
#16/03/2023

OBJECTS = Semaphore.o main.o

SOURCES = Semaphore.cpp main.cpp
HEADERS = Semaphore.h

OUTPUTS = main.out

CC=g++
CFLAGS= -std=c++11 -pthread -Wall
LFLAGS= 

#SIMPLE:
#	$(CC) $(CFLAGS) $(SOURCES) $(HEADERS) $(OBJECTS)
# -g is for debugging
all: $(OBJECTS)
	$(CC) -g $(OBJECTS) -o $(OUTPUTS) $(LFLAGS)
	make CLEAN #run clean
CLEAN:
	rm -f $(OBJECTS) #removes all object by force
