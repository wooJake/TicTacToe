#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    
    int winState = -1;
    int turn = 0;
    char cTurn[2] = { 'X', 'O' };
    
    while(winState == -1){
        
        int pass = 0;
        int boardIn;
        
        while(pass == 0){
            
            //This works like a mirrored (right to left) keyboard layout.
            printf("%c turn, enter position 1 - 9: ", cTurn[turn % 2]);
            
            
            scanf("%d", &boardIn);
            
            if(board[boardIn - 1] != ' '){
                
                printf("Place already taken, choose another square!!!\n");
                continue;
            }
            
            board[boardIn - 1] = cTurn[turn % 2];
            pass = 1;
        }
        
        for(int i = 8; i >= 0; --i){
            
            printf("|%c|", board[i]);
            
            if(i % 3 == 0){
                
                printf("\n");
            }
        }
        printf("\n");
        ++turn;
        turn %= 8;
        
        if ((board[2] == board[1] && board[2] == board[3] && board[2] != ' ') || 
            (board[4] == board[1] && board[4] == board[7] && board[4] != ' ') ||
            (board[5] == board[1] && board[5] == board[9] && board[5] != ' ') ||
            (board[5] == board[3] && board[5] == board[7] && board[5] != ' ') ||
            (board[5] == board[4] && board[5] == board[6] && board[5] != ' ') ||
            (board[5] == board[2] && board[5] == board[8] && board[5] != ' ') ||
            (board[6] == board[3] && board[6] == board[9] && board[6] != ' ') ||
            (board[8] == board[7] && board[8] == board[9] && board[8] != ' ')){
                
            if(board[boardIn - 1] == 'x'){
                
                winState = 1;
            }   
            else{
                
                winState = 2;
            }
        }
    }
    
    if(winState == 1){
        
        printf("X wins!\n");
    }
    if(winState == 2){
        
        printf("O wins!\n");
    }

    return 0;
}
