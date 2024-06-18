#include <stdio.h>

#define size 3

void printMap(char map[size][size]){
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
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
        printf("\n%c select a row (0-2): ",player);
        scanf("%d",&row);
        printf("\n%c select a column (0-2): ",player);
        scanf("%d",&col);

        if (map[row][col] ==' ')
        {
            map[row][col] = player;
        }else{
            printf("This position is alredy filled");
            put(map,player);
        }
        
}

void checkWin(char map[size][size],int *status, char player){
    //horizontal check
    if (map[0][0]==map[0][1]&&map[0][1]==map[0][2]&&map[0][0]!=' ')
    {
        if (player=='X')
        {
            *status = 2;
        }else
        {
            *status=3;
        }        
    }
    else if (map[1][0]==map[1][1]&&map[1][1]==map[1][2]&&map[1][0]!=' ')
    {
        if (player=='X')
        {
            *status = 2;
        }else
        {
            *status=3;
        }
    }
    else if (map[2][0]==map[2][1]&&map[2][1]==map[2][2]&&map[2][0]!=' ')
    {
        if (player=='X')
        {
            *status = 2;
        }else
        {
            *status=3;
        }
    }
    //vetical check
    else if (map[0][0]==map[1][0]&&map[1][0]==map[2][0]&&map[0][0]!=' ')
    {
        if (player=='X')
        {
            *status = 2;
        }else
        {
            *status=3;
        }
    }
    else if (map[0][1]==map[1][1]&&map[1][1]==map[2][1]&&map[1][1]!=' ')
    {
        if (player=='X')
        {
            *status = 2;
        }else
        {
            *status=3;
        }
    }
    else if (map[0][2]==map[1][2]&&map[1][2]==map[2][2]&&map[2][2]!=' ')
    {
        if (player=='X')
        {
            *status = 2;
        }else
        {
            *status=3;
        }
    }
    //oblique check
    else if (map[0][0]==map[1][1]&&map[1][1]==map[2][2]&&map[0][0]!=' ')
    {
        if (player=='X')
        {
            *status = 2;
        }else
        {
            *status=3;
        }
    }
    else if (map[0][2]==map[1][1]&&map[1][1]==map[2][0]&&map[0][2]!=' ')
    {
        if (player=='X')
        {
            *status = 2;
        }else
        {
            *status=3;
        }
    }
    //draw check
    else if (map[0][0]!=' '&&map[0][1]!=' '&&map[0][2]!=' '
            &&map[1][0]!=' '&&map[1][1]!=' '&&map[1][2]!=' '
            &&map[2][0]!=' '&&map[2][1]!=' '&&map[2][2]!=' ')
    {
        *status = 4;
    }
    
    
}



int main(){
    char map [size][size]= {{' ',' ',' '},
                            {' ',' ',' '},
                            {' ',' ',' '}};

    printMap(map);

    int status = 1;
    char player = 'X';

    do
    {
        put(map, player);   
        printMap(map);
        checkWin(map,&status,player);

        if (player=='X')
        {
            player = 'O';
        }else
        {
            player = 'X';
        }
                  
    } while (status == 1);

    if (status==2)
    {
        printf("X is the winner!");
    }
    else if (status==3)
    {
        printf("O is the winner!");
    }
    else if (status==4)
    {
        printf("Draw");
    }

    return 0;
}