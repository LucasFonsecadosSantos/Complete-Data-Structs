######################################
# MAKEFILE TO DATA STRUCTURE REPO    #
# Wrote by: Lucas Fonseca dos Santos.#
######################################

main:	src/Queue.o src/QueueTest.o
	g++ src/Queue.o src/QueueTest.o -o main && rm src/*.o

#stack.o:	src/Stack.o  include/Stack.o
	#g++ -c	src/Stack.c

queue.o:	src/Queue.o include/Queue.o
	g++ -c	src/Queue.cpp

#stackTest.o: src/StackTest.o include/Stack.o
	#g++ -c src/StackTest.c

queueTest.o: src/QueueTest.o include/Queue.o src/Queue.o
	g++ -c src/QueueTest.cpp

clean:
	rm src/*.o


