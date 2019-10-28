//Written by Marwane Adlani
//Header file for MP3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MP3
{
    char* artistName;
    char* songTitle;
    int songYear;
    int runTime;
    struct MP3* next;
    struct MP3* prev;
} mp3_node;

mp3_node *createMp3(char *artist, char *name, int year, int runtime);

void addMP3(char* artist, char* title, int year, int duration);
void deleteMP3(char* artist);
void printMP3Forward();
void printMP3Backward();
void cleanUpList();