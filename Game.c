#include <ncurses.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

void 
refresh_(char grid[21][17])
{
        clear();

        for (int i = 0; i < 21; i++)
        {
                for (int j = 0; j < 17; j++)
                {
                        if (grid[i][j] == 0)
                        {
                                printw("  ");
                        } else if (grid[i][j] == 2) {
                                printw("# ");
                        } else {
                                printw("^ ");
                        }
                }

                printw("\n");
        }

        refresh();
}

int
main(void)
{
       initscr();

       noecho();

       curs_set(0);

       char grid[21][17] = {
                                {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                                {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
                          };

        char *ptr = &grid[0][0];

        int initial_position = 19;
        int current_position = initial_position;

        char key;
        int direction;

        refresh_(grid);

        while (1)
        {
                key = getch();

                switch (key)
                {
                        case 'w':
                                napms(125);

                                if (*(ptr + current_position - 18) == 2)
                                {
                                        break;
                                }

                                *(ptr + current_position - 1) = 0;
                                *(ptr + current_position - 18) = 1;

                                refresh_(grid);

                                current_position -= 17;
                                direction = UP;

                                break;

                        case 'a':
                                napms(125);

                                if (*(ptr + current_position - 2) == 2)
                                {
                                        break;
                                }

                                *(ptr + current_position - 1) = 0;
                                *(ptr + current_position - 2) = 1;

                                refresh_(grid);

                                current_position -= 1;
                                direction = LEFT;

                                break;

                        case 's':
                                napms(125);

                                if (*(ptr + current_position + 16) == 2)
                                {
                                        break;
                                }

                                *(ptr + current_position - 1) = 0;
                                *(ptr + current_position + 16) = 1;

                                refresh_(grid);

                                current_position += 17;
                                direction = DOWN;

                                break;

                        case 'd':
                                napms(125);

                                if (*(ptr + current_position) == 2)
                                {
                                        break;
                                }

                                *(ptr + current_position - 1) = 0;
                                *(ptr + current_position) = 1;

                                refresh_(grid);

                                current_position += 1;
                                direction = RIGHT;

                                break;
                }

                flushinp();
        }

        endwin();

        return EXIT_SUCCESS;
}
