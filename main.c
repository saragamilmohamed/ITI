#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int col, int line) {
    COORD coord;
    coord.X = col;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textattr(int attr) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr);
}

int main() {
    char menu[3][10] = {"New", "Display", "Exit"};
    char subNew[3][10] = {"Open", "Empty", "Exist"};
    char subDisplay[3][10] = {"New", "Reference", "Create"};
    int n= 0;
    int x = 0;
    char ch;
    int flag = 1;
    int check = 0;
    do {

        if (!check) {

            for (int i = 0; i < 3; i++) {
                gotoxy(5, 5 + i);
                if (i == n) {
                    textattr(0x04);
                } else {
                    textattr(0x07);
                }
                printf("%s\n", menu[i]);
            }
        } else {

            if (n == 0) {

                for (int i = 0; i < 3; i++) {
                    gotoxy(15, 5 + i);
                    if (i == x) {
                        textattr(0x04);
                    } else {
                        textattr(0x07);
                    }
                    printf("%s\n", subNew[i]);
                }
            } else if (n == 1) {

                for (int i = 0; i < 3; i++) {
                    gotoxy(15, 5 + i);
                    if (i == x) {
                        textattr(0x04);
                    } else {
                        textattr(0x07);
                    }
                    printf("%s\n", subDisplay[i]);
                }
            }
        }

        textattr(0x07);
        ch = _getch();

        switch (ch) {
            case -32:
                ch = _getch();
                if (!check) {

                    if (ch == 72) {
                        n = (n - 1 + 3) % 3;
                    } else if (ch == 80) {
                        n = (n + 1) % 3;
                    }
                } else {

                    if (ch == 72) {
                        x = (x - 1 + 3) % 3;
                    } else if (ch == 80) {
                        x = (x + 1) % 3;
                    } else if (ch == 75) {
                        system("cls");
                        check = 0;
                    }
                }
                break;

            case 13:
                if (check == 0) {
                    if (n == 2) {
                        system("cls");
                        printf("You selected: %s\n", menu[n]);
                        flag=0;
                        ch = 27;
                        _getch();
                    } else if (n == 0) {
                        x= 0;
                        check = 1;

                    } else if (n == 1) {
                        x = 0;
                        check = 2;
                    }
                }
                break;

            case 27:
                flag = 0;
                break;
        }

    } while (flag);

    return 0;
}



