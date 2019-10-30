# choose your compiler
CC=gcc
#CC=gcc -Wall

mp3: mp3.o
	$(CC) -g mp3.o -o mp3

mp3.o: mp3.c mp3.h
	$(CC) -g -c mp3.c
	
clean:
	rm -rf *.o mp3