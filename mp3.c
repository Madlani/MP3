#include "mp3.h"
#define MAXCHAR 128

mp3_node *head;
mp3_node *tail;

void main()
{
    //using these variables to keep track of the inputs from user
    char numChoice[MAXCHAR];
    char artist_name[MAXCHAR];
    char song_title[MAXCHAR];
    char intInput[MAXCHAR];
    int yr = 0;
    int rt = 0;
    //used to add the escape char
    int strLen = 0;
    //used to start the loop
    strcpy(numChoice, "-1");
    //use atoi for switch cases
    while (atoi(numChoice) != 5)
    {
        printf("\nMenu\n1 - Add New MP3\n2 - Delete all MP3s by an artist\n3 - Print the playlist forward\n4 - Print the playlist backward\n5 - Exit\n\n");
        fgets(numChoice, MAXCHAR, stdin);

        switch (atoi(numChoice))
        {
        case 1: //Add MP3
            printf("Please provide the artist name\n");
            if (fgets(artist_name, MAXCHAR, stdin))
            {
                strLen = (int)strlen(artist_name);
                artist_name[strLen - 1] = '\0';
            }
            printf("Please provide the song title\n");
            if (fgets(song_title, MAXCHAR, stdin))
            {
                strLen = (int)strlen(song_title);
                song_title[strLen - 1] = '\0';
            }
            printf("Please provide the song year\n");
            if (fgets(intInput, MAXCHAR, stdin))
            {
                strLen = (int)strlen(intInput);
                intInput[strLen - 1] = '\0';
                yr = atoi(intInput);
            }
            printf("Please provide the runtime\n");
            if (fgets(intInput, MAXCHAR, stdin))
            {
                strLen = (int)strlen(intInput);
                intInput[strLen - 1] = '\0';
                rt = atoi(intInput);
            }

            addMP3(artist_name, song_title, yr, rt);
            break;

        case 2: //DeleteMP3
            printf("\nPlease provide the artist name whose songs you wish to delete\n");
            fgets(artist_name, MAXCHAR, stdin);
            strLen = (int)strlen(artist_name);
            artist_name[strLen - 1] = '\0';
            printf("you want to delete: %s", artist_name);
            deleteMP3(artist_name);
            break;

        case 3: //PrintForward
            printMP3Forward();
            break;
        case 4: //PrintBackward
            printMP3Backward();
            break;
        case 5: //Exit
            //cleanUp(newLinkedList);
            break;

        default:
            printf("You've entered a character that isn't allowed. Please enter a number 1-5\n");
            // fgets(numChoice, MAXCHAR, stdin);
        }
    }
}

mp3_node *createMP3(char *artistName, char *songTitle, int songYear, int runTime)
{
    mp3_node *createdNode = malloc(sizeof(mp3_node));
    createdNode->artistName = malloc(sizeof(artistName));
    createdNode->songTitle = malloc(sizeof(songTitle));
    strcpy(createdNode->artistName, artistName);
    strcpy(createdNode->songTitle, songTitle);
    createdNode->songYear = songYear;
    createdNode->runTime = runTime;

    createdNode->next = NULL;
    createdNode->prev = NULL;

    return createdNode;
}

void addMP3(char *artistName, char *songTitle, int songYear, int duration)
{
    mp3_node *addedMP3 = createMP3(artistName, songTitle, songYear, duration);
    if (!head)
    {
        head = addedMP3;
        tail = addedMP3;
        return;
    }

    // might need temp var
    mp3_node *temp = tail;

    temp->next = addedMP3;
    addedMP3->prev = temp;
    tail = addedMP3;
}
// void deleteMP3(char *artistName)
// {
//     mp3_node *temp;
//     temp = head;

//     while (temp)
//     {
//         printf("temp->artistName = %s\t\tartistName = %s\n", temp->artistName, artistName);
//         if (strcmp(temp->artistName, artistName) == 0)
//         {
//             printf("artist found\n");
//             //CASE 1 - deleting head
//             if (temp->prev == NULL) // < its the head
//             {
//                 if (head == tail)
//                 { // < its the tail - only one node
//                     tail = NULL;
//                     head = NULL;
//                 }

//                 if (temp==tail)
//                 {
//                     temp->next->prev = temp->prev;
//                     head = temp->next;
//                 }
//             }

//             //CASE 2 - deleting tail
//             if (temp->next) // < its the tail
//             {
//                 temp->prev->next = NULL;
//                 tail = temp->prev;
//             }

//             //CASE 3 - deleting middle
//             if (temp->prev && temp->next)
//             {
//                 temp->prev->next = temp->next;
//                 temp->next->prev = temp->prev;
//             }

//             free(temp->artistName);
//             free(temp->songTitle);
//             free(temp);
//         }

//         temp = temp->next;
//     }
// }

//deletes from head when its only node so far
//when deleting any other node besides head, gives a weird NULL as name
//when deleting head with 2 or more, seg fault
void deleteMP3(char *artistName)
{
    mp3_node *temp;
    temp = head;

    while (temp)
    {
        printf("temp->artistName = %s\t\tartistName = %s\n", temp->artistName, artistName);
        if (strcmp(temp->artistName, artistName) == 0)
        {
            printf("artist found\n");
            //CASE 1 - deleting head
            if (temp == head) // < its the head
            {
                if (head == tail)
                { // < its the tail - only one node
                    tail = NULL;
                    head = NULL;
                }

                if (temp==tail)
                {
                    temp->next->prev = temp->prev;
                    head = temp->next;
                }
            }

            //CASE 2 - deleting tail
            if (temp->next) // < its the tail
            {
                temp->prev->next = NULL;
                tail = temp->prev;
            }

            //CASE 3 - deleting middle
            if (temp->prev && temp->next)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            free(temp->artistName);
            free(temp->songTitle);
            free(temp);
        }

        temp = temp->next;
    }
}
void printMP3Forward()
{
    mp3_node *temp;
    temp = head;

    while (temp)
    {

        printf("\nArtist Name: %s\nSong Title: %s\nRelease Year: %d\nRuntime: %d\n", temp->artistName, temp->songTitle, temp->songYear, temp->runTime);
        temp = temp->next;
    }
}
void printMP3Backward()
{
    mp3_node *temp;
    temp = tail;

    while (temp)
    {
        printf("\nArtist Name: %s\nSong Title: %s\nRelease Year: %d\nRuntime: %d\n", temp->artistName, temp->songTitle, temp->songYear, temp->runTime);
        temp = temp->prev;
    }
}
void cleanUpList()
{
}
