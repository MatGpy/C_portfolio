#include <stdio.h>
void PopulateTable(int rows, int columns, char Table[rows][columns]) {
    for(int i = 0; i <= rows; i++) {
        for(int j = 0; j <= columns; j++) {
            Table[i][j] = 'O';
        }
    }
}
void PrintTable(int rows, int columns, char Table[rows][columns]) {
    printf(" |1|2|3|4|5|6|7|8|9|\n");
    for (int i = 0; i < rows; i++) {
        printf("%d|%c|%c|%c|%c|%c|%c|%c|%c|%c|\n", i+1,Table[i][0],Table[i][1],Table[i][2],Table[i][3],Table[i][4],Table[i][5],Table[i][6],Table[i][7],Table[i][8]);
    }
}
int CheckIfVictory(int *counter, int rows, int columns, char Table[rows][columns]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(Table[i][j] == 'X'){
                (*counter)++;
            }
        }
    }
    return *counter;
}
void ReplaceValue(int i, int j, char Table[9][9]){
    switch (Table[i][j]) {
        case 'X':
            Table[i][j] = 'O';
            break;
        case 'O':
            Table[i][j] = 'X';
            break;
    }
}
int main() {
    char Table[9][9];
    int turn = 1;
    int counter = 0;
    int ChosenRow;
    int ChosenColumn;
    PopulateTable(9, 9, Table);
    while(counter < 81) {
        counter = 0;
        printf("Turn nr.%d\nEnter the number of row, in which you want to put 'X': ", turn);
        scanf("%d", &ChosenRow);
        printf("Enter the number of column, in which you want to put 'X': ");
        scanf("%d", &ChosenColumn);
        ReplaceValue(ChosenRow-1, ChosenColumn-1, Table);
        ReplaceValue(ChosenRow-2, ChosenColumn-1, Table);
        ReplaceValue(ChosenRow-1, ChosenColumn-2, Table);
        ReplaceValue(ChosenRow, ChosenColumn-1, Table);
        ReplaceValue(ChosenRow-1, ChosenColumn, Table);
        PrintTable(9, 9, Table);
        turn++;
        CheckIfVictory(&counter, 9, 9, Table);
    }
    printf("Victory\nAmount of turns: %d", turn);
    return 0;
} 