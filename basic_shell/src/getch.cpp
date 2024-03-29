#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "../include/basicshell.hpp"

/* I found this online. I cannot remember where
 *  so I cannot give credit to whom it belongs */

int Basic_Shell::getch(void)
{
	int ch;
	struct termios oldt, newt;

	tcgetattr(STDIN_FILENO, &oldt);

	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);

	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

	return ch;
}
