#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <structs.c>

int height=30, width=60, gameover, score;
int x,y, fruitx, fruity, flag;
char table[32][62];

// Change it again to a linked list

Snake walk(Snake snake){
    table[snake.head[0]][snake.head[1]] = "o"
    if(snake.direction[0] = -2){
        snake.head[0] -= 2;
        table[snake.head[0]][snake.head[1]] = "O";
    }
    else if(snake.direction[0] = +2){
        snake.head[0] += 2;
        table[snake.head[0]][snake.head[1]] = "O";
    }
    else if(snake.direction[1] = -1){
        snake.head[1] -= 1;
        table[snake.head[0]][snake.head[1]] = "O";
    }
    else if(snake.direction[1] = +1){
        snake.head[1] += 1;
        table[snake.head[0]][snake.head[1]] = "O";
    }
    return snake;
}


void draw(){
    int i, j;
    for (i = 0; i < height + 2; i++) {
        for (j = 0; j < width + 3; j++) {
            if (i == 0 || i == height + 1) {
                if(j%2 == 0 ){
                    table[i][j] = '#';
                }else{
                    table[i][j] = ' ';
                }
            }
            else if(j == 0 || j == width + 2){
                table[i][j] = '#';
            }
            else {
                table[i][j] = ' ';
            }
        }
        printf("\n");
    }

    for(i=0; i<width + 3; i++){
        printf("%d", i%10);
    }
}


Snake setup(){
    //creating the snake
    Snake snake;
    snake.size=1;
    snake.head[0]=width/2 + 2;
    snake.head[1]=height/2;
    snake.tail[0] = snake.head[0];
    snake.tail[1] = snake.head[1];


    gameover=0;
    label1:
        fruitx=rand()%62;
        if(fruitx%2 == 1 || fruitx == 0)
            goto label1;
    
    label2:
        fruity=rand()%32;
        if(fruity==0)
            goto label2;
    score=0;
    return snake;

}


void input(Snake snake){
    if(khbit()){
        switch(getch()){
            case 'a':
                snake.direction[0] = -2;
                snake.direction[1] = 0;
                break;
            case 's':
                snake.direction[0] = 0;
                snake.direction[1] = +1;
                break;
            case 'd':
                snake.direction[0] = +2;
                snake.direction[1] = 0;
                break;
            case 'w':
                snake.direction[0] = 0;
                snake.direction[1] = -1;
                break;
            case 'x':
                gameover=1;
                break;
        }
    }
}


Snake logic(Snake snake)
{
    sleep(0.01);
    snake = walk(snake);
    // If the game is over
    if (snake.head[0] < 0 || snake.head[0] > width
        || snake.head[1] < 0 || snake.head[1] > height){
        gameover = 1;
        return snake;
    } else if(verify_body(snake)){
        gameover = 1;
        return snake;
    }
  
    // If snake reaches the fruit, then update the score
    if (snake.head[0] == fruitx && snake.head[1] == fruity) {
    label3:
        fruitx=rand()%62;
        if(fruitx%2 == 1 || fruitx == 0)
            goto label3;
    
    label4:
        fruity=rand()%32;
        if(fruity==0)
            goto label4;

    // If the snake eats a fruit, its not necessary to remove its last body piece
    score++;
    return snake;
    }else{
        table[snake.tail[0]][snake.tail[1]] = ' '; // Clearing the tail space;

        if(table[snake.tail[0] - 2][snake.tail[1]] == 'o'){
            snake.tail[0] -= 2;
        }else if(table[snake.tail[0] + 2][snake.tail[1]] == 'o'){
            snake.tail[0] += 2;
        }else if(table[snake.tail[0]][snake.tail[1] + 1] == 'o'){
            snake.tail[0] -= 2;
        }
    }
}


void main(){
    draw();
}