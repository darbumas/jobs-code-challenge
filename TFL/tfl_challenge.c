#include "tfl_challenge.h"

/**
 * countVowels - Helper function to count the number of vowels in a word.
 * @word: Pointer to the word to count.
 *
 * Return: Vowel count.
 */
int countVowels(const char *word)
{
	int count = 0, i = 0;
	char c;

	while (word[i] != '\0')
	{
		c = tolower(word[i]);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			count++;
		i++;
	}
	return (count);
}

/**
 * printModifiedStr - Prints modified string by replacing middle characters in
 * each word with the number of vowels in the given word.
 * @str: Points to the original string
 *
 * @brief: If a given word is less than 3 characters, function will print it as
 * is.
 */
void printModifiedStr(char *str)
{
	int len = 0, vowels = 0;
	const char *delim = " ";
	char *new_str, *token;

	new_str = malloc(sizeof(char) * strlen(str) + 1);
	if (!new_str)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);

	while (token)
	{
		len = strlen(token);
		if (len > 2)
		{
			vowels = countVowels(token);
			sprintf(new_str, "%c%d%c", token[0], vowels, token[len - 1]);
			printf("%s ", new_str);
		}
		else
			printf("%s ", token);
		token = strtok(NULL, delim);
	}
	free(new_str);
}
