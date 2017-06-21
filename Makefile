######################################
# MAKEFILE TO DATA STRUCTURE REPO    #
# Wrote by: Lucas Fonseca dos Santos.#
######################################

main:	src/Stack.o src/StackTest.o src/Queue.o src/QueueTest.o
	gcc src/Stack.o src/StackTest.o src/Queue.o src/QueueTest.o -o main

stack.o:	src/Stack.o  include/Stack.o
	gcc -c	src/Stack.c

queue.o:	src/Queue.o include/Queue.o
	gcc -c	src/Queue.c

stackTest.o: src/StackTest.o include/Stack.o
	gcc -c src/StackTest.c

queueTest.o: src/QueueTest.o include/Queue.o
	gcc -c src/QueueTest.c

clean:
	rm *.o
