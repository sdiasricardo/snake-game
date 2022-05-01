#include <stdlib.h>

typedef struct  body{
    int coordinates[2];
    body* next; //Pointer to the next body piece
}body;

typedef struct snake{
    int size;
    int direction[2];
    body*body;
}