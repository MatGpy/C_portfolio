#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>
#include <string.h>
void PopulateTable(char table[9][9]) {
    for(int i = 0; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            table[i][j] = 'O';
        }
    }
}
void PrintTable(char table[9][9]) {
    printf(" |1|2|3|4|5|6|7|8|9|\n");
    for (int i = 0; i < 9; i++) {
        printf("%d|%c|%c|%c|%c|%c|%c|%c|%c|%c|\n", i+1,table[i][0],table[i][1],table[i][2],table[i][3],table[i][4],table[i][5],table[i][6],table[i][7],table[i][8]);
    }
}
int CheckIfVictory(int *counter, char table[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(table[i][j] == 'X'){
                (*counter)++;
            }
        }
    }
    return *counter;
}
void ReplaceValue(int i, int j, char table[9][9]){
    switch (table[i][j]) {
        case 'X':
            table[i][j] = 'O';
            break;
        case 'O':
            table[i][j] = 'X';
            break;
    }
}
void takeUserMove(int* chosenRow, int* chosenColumn, int turn) {
    char chosenMove[2];
    printf("Insert coordinates of the cell on the table where you would like to place 'X' (in a form of double digit number, where first digit is an number of row and second number is a number of column): ");
    scanf("%s", chosenMove);
    if(isdigit(chosenMove[0])==0 || isdigit(chosenMove[1])==0 || strlen(chosenMove) > 2) {
        printf("error");
        exit(-1);
    } else {
        *chosenRow = (chosenMove[0]-'0');
        *chosenColumn = (chosenMove[1]-'0');
    }
}
int main() {
    char table[9][9];
    int turn = 1;
    int counter = 0;
    int chosenRow;
    int chosenColumn;
    PopulateTable(table);
    PrintTable(table);
    while(counter < 81) {
        counter = 0;
        takeUserMove(&chosenRow, &chosenColumn, turn);
        ReplaceValue(chosenRow-1, chosenColumn-1, table);
        ReplaceValue(chosenRow-2, chosenColumn-1, table);
        ReplaceValue(chosenRow-1, chosenColumn-2, table);
        ReplaceValue(chosenRow, chosenColumn-1, table);
        ReplaceValue(chosenRow-1, chosenColumn, table);
        PrintTable(table);
        turn++;
        CheckIfVictory(&counter,table);
    }
    printf("Victory\nAmount of turns: %d", turn);
    return 0;
} 