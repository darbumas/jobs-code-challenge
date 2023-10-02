#include "tfl_challenge.h"

/**
 * main - Entry of program
 *
 * @author: B. Bwashi <github.com/darbumas>
 *
 * Return: Always 0.
 */
int main()
{
	char line[256];

	printf("Enter a string: ");

	/* Read input */
	if (fgets(line, sizeof(line), stdin))
	{
		line[strcspn(line, "\n")] = '\0';
		printModifiedStr(line);
	}
	else
		perror("Error reading input.");

	return (0);
}
