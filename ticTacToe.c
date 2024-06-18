#include <stdio.h>

#define size 3

void printMap(char map[size][size]){
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf(" %c ",map[i][j]);
            if(j<size-1) printf("|");
        }
        printf("\n");
        if(i<size-1) printf("---+---+---\n");
    }
    printf("\n");
}


int main(){
    char map [size][size]= {{' ',' ',' '},
                            {' ',' ',' '},
                            {' ',' ',' '}};

    printMap(map);
    return 0;
}