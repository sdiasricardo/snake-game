#include <stdlib.h>

typedef struct  body{ // The snake body will be a linked list so that I can keep track
// of every position and delete them directly when the snake walks
    int coordinates[2];
    body* next; //Pointer to the next body piece
    body* previous;
}body;

typedef struct snake{
    int size;
    int direction[2];
    body* head;
    body* tail;
}Snake;
