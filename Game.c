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
refresh(char grid[21][17])
{
        system("clear");

        for (int i = 0; i < 21; i++)
        {
                for (int j = 0; j < 17; j++)
                {
                        if (grid[i][j] == 0)
                        {
                                printf("  ");
                        } else if (grid[i][j] == 2) {
                                printf("# ");
                        } else {
                                printf("^ ");
                        }
                }

                printf("\n");
        }
}

void
configure_terminal(void)
{
        static struct termios terminal_settings;

        tcgetattr( STDIN_FILENO, &terminal_settings);

        terminal_settings.c_lflag &= ~(ICANON);          
        terminal_settings.c_lflag &= ~(ECHO);

        tcsetattr( STDIN_FILENO, TCSANOW, &terminal_settings);
}

int
main(void)
{
       configure_terminal();

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

        int key;
        int direction;

        refresh(grid);

        while (1)
        {
                if ((key = getchar()) != EOF)
                {
                        switch (key)
                        {
                                case 'w':
                                        if (*(ptr + current_position - 18) == 2)
                                        {
                                                break;
                                        }

                                        *(ptr + current_position - 1) = 0;
                                        *(ptr + current_position - 18) = 1;

                                        refresh(grid);

                                        current_position -= 17;
                                        direction = UP;

                                        break;

                                case 'a':
                                        if (*(ptr + current_position - 2) == 2)
                                        {
                                                break;
                                        }

                                        *(ptr + current_position - 1) = 0;
                                        *(ptr + current_position - 2) = 1;

                                        refresh(grid);

                                        current_position -= 1;
                                        direction = LEFT;

                                        break;

                                case 's':
                                        if (*(ptr + current_position + 16) == 2)
                                        {
                                                break;
                                        }

                                        *(ptr + current_position - 1) = 0;
                                        *(ptr + current_position + 16) = 1;

                                        refresh(grid);

                                        current_position += 17;
                                        direction = DOWN;

                                        break;

                                case 'd':
                                        if (*(ptr + current_position) == 2)
                                        {
                                                break;
                                        }

                                        *(ptr + current_position - 1) = 0;
                                        *(ptr + current_position) = 1;

                                        refresh(grid);

                                        current_position += 1;
                                        direction = RIGHT;

                                        break;
                        }
                }
        }
        
        return EXIT_SUCCESS;
}
