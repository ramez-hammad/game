#include <ncurses.h>

#include <stdio.h>
#include <stdlib.h>

/* print_map: clears screen and prints the map */
void 
print_map(char map[21][17])
{
        clear(); /* Clear the screen */

        for (int i = 0; i < 21; i++)
        {
                for (int j = 0; j < 17; j++)
                {
                        if (map[i][j] == 0)
                        {
                                printw("  ");
                        } else if (map[i][j] == 2) {
                                printw("# ");
                        } else {
                                printw("^ ");
                        }
                }

                printw("\n");
        }

        refresh(); /* Changes are not printed to the actual screen until refresh is called */
}

int
main(void)
{
       initscr(); /* Enter curses mode */

       noecho(); /* Switch off keyboard input echo */

       curs_set(0); /* Set cursor state to invisible  */

       char map[21][17] = {
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

        char *ptr = &map[0][0];

        int current_position = 19; /* Set player position */

        char key;

        print_map(map);

        while (1)
        {
                key = getch();

                switch (key)
                {
                        case 'w':
                                napms(125); /* Sleep for 125 ms */


                                /* 
                                 *
                                 *
                                 *
                                 *
                                 *
                                 *
                                 *
                                 * Since array elements are stored one after another in the memory, and knowing
                                 * the number of columns in the array, we can move the character one row up using
                                 * a pointer to change the position of the character 17 (Number of columns) 
                                 * elements back.
                                 *
                                 * Similarly,
                                 * we can move the position 17 elements forward to move the character one row down.
                                 *
                                 * Using the same way, we can move the character 1 element forward to move it to the right,
                                 * and 1 element backward to move it to the left. 
                                 *
                                 *
                                 *
                                 *
                                 *
                                 *
                                 * 
                                 */

                                if (*(ptr + current_position - 17 - 1) == 2) 
                                {
                                        break;
                                }

                                *(ptr + current_position - 1) = 0;
                                *(ptr + current_position - 18) = 1;

                                current_position -= 17;

                                break;

                        case 'a':
                                napms(125);

                                if (*(ptr + current_position - 2) == 2)
                                {
                                        break;
                                }

                                *(ptr + current_position - 1) = 0;
                                *(ptr + current_position - 2) = 1;

                                current_position -= 1;

                                break;

                        case 's':
                                napms(125);

                                if (*(ptr + current_position + 16) == 2)
                                {
                                        break;
                                }

                                *(ptr + current_position - 1) = 0;
                                *(ptr + current_position + 16) = 1;

                                current_position += 17;

                                break;

                        case 'd':
                                napms(125);

                                if (*(ptr + current_position) == 2)
                                {
                                        break;
                                }

                                *(ptr + current_position - 1) = 0;
                                *(ptr + current_position) = 1;

                                current_position += 1;

                                break;
                }

                print_map(map);
                flushinp(); /* Flush stdin */
        }

        endwin(); /* Exit curses mode */

        return EXIT_SUCCESS;
}
