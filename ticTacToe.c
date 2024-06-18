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

void put(char map[size][size], char player){
        int row;
        int col;
        printf("\nSelect a row (0-2): ");
        scanf("%d",&row);
        printf("\nSelect a column (0-2): ");
        scanf("%d",&col);

        if (map[row][col] ==' ')
        {
            map[row][col] = player;
        }else{
            printf("This position is alredy filled");
            put(map,player);
        }
        
}

void checkWin(char map[size][size]){
    
}

int main(){
    char map [size][size]= {{' ',' ',' '},
                            {' ',' ',' '},
                            {' ',' ',' '}};

    printMap(map);

    int status = 1;

    do
    {
        put(map, 'X');   
        printMap(map);
        checkWin(map);
        put(map,'O');
        printMap(map);
        checkWin(map);
             
    } while (status==1);
    

    return 0;
}