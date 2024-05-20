#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 9

int board[SIZE][SIZE];
int erase_number = 0;

enum {
    EASY,
    MEDIUM,
    HARD
};

void create_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

bool is_safe(int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + start_row][j + start_col] == num) {
                return false;
            }
        }
    }
    return true;
}

bool fill_sudoku() {
    int row, col;

    bool is_empty = false;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                is_empty = true;
                break;
            }
        }
        if (is_empty) {
            break;
        }
    }

    if (!is_empty) {
        return true;
    }

    for (int i = 0; i < SIZE; i++) {
        int tmp = rand() % 9 + 1;
        if (is_safe(row, col, tmp)) {
            board[row][col] = tmp;
            if (fill_sudoku()) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false; 
}

void display_board() {
    printf("   A B C D E F G H I \n\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d  ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0)
                printf("  ");
            else
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void create_level(int difficulty) {
    switch (difficulty) {
    case EASY: 
        erase_number = 25;
        break;
    case MEDIUM:
        erase_number = 40;
        break;
    case HARD:
        erase_number = 55;
        break;
    }

    for (int i = 0; i < erase_number; ) {
        int row = rand() % 9;
        int col = rand() % 9;
        if (board[row][col] != 0) {
            board[row][col] = 0;
            i++;
        }
    }
}

void play() {
    char position[3];
    int answer;
    int row, col;
    int mistakes = 0;


    while (erase_number > 0) {
        do {
            system("cls");
            display_board();
            printf("# Choose position #\n");
            printf("For example: A1\n");

            scanf_s("%s", position, 3);
            row = atoi(&position[1]) - 1;
            col = position[0] - 65;
            if (board[row][col] != 0) {
                printf("#Wrong position selected\n");
                printf("# Click [ENTER] #\n");
                getchar();
                getchar();
            }

        } while (row < 0 || row > 8 || col < 0 || col > 8 || board[row][col] != 0);

        do {
            printf("# Choose number for cell [%s] #\n", position);
            scanf_s("%d", &answer);
        } while (answer < 1 || answer > 9);

        if (is_safe(row, col, answer)) {
            board[row][col] = answer;
            system("cls");
            display_board();
            erase_number--;
        }
        else {
            system("cls");
            mistakes++;
            printf("#Wrong number\n");
            printf("#Mistakes made: %d/3\n", mistakes);
            printf("# Click [ENTER] #\n");
            getchar();
            getchar();
            system("cls");
        }

        if (mistakes >= 3) {
            printf("# END OF GAME #\n");
            printf("#You made 3 mistakes\n");
            getchar();
            getchar();
            return;
        }
    }

    printf("You won! Congratulations\n");
    printf("Click [ENTER]\n");
}

int main() {
    srand(time(NULL));
    bool exit = false;
    int choice1, choice2;
    do {
        create_board();
        system("cls");
        printf("# SUDOKU #\n");
        printf("1. New game\n");
        printf("0. Exit\n");

        scanf_s("%d", &choice1);
        system("cls");
        switch (choice1) {
        case 1:
            printf("# CHOOSE DIFFICULTY LEVEL #\n");
            printf("1. Easy\n");
            printf("2. Medium\n");
            printf("3. Hard\n");

            scanf_s("%d", &choice2);

            if (choice2 >= 1 && choice2 <= 3) {
                if (fill_sudoku()) {
                    create_level(choice2-1);
                    play();
                    getchar();
                    getchar();
                }
                else {
                    printf("#Generating SUDOKU failed :(\n");
                }
            }
            else {
                printf("#Wrong number selected");
                getchar();
                getchar();
            }
            break;
        case 0:
            exit = true;
            break;
        }
    } while (exit == false);
    
    return 0;
}
