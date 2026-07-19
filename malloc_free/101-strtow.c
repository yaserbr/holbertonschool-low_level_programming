#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts words in a string
 * @str: string to count words in
 *
 * Return: number of words
 */
static int count_words(char *str)
{
	int i;
	int count;

	count = 0;
	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
	}

	return (count);
}

/**
 * word_length - gets the length of a word
 * @str: string that starts with a word
 *
 * Return: length of the word
 */
static int word_length(char *str)
{
	int len;

	len = 0;
	while (str[len] && str[len] != ' ')
		len++;

	return (len);
}

/**
 * free_words - frees an array of words
 * @words: array of words
 * @count: number of allocated words
 *
 * Return: Nothing
 */
static void free_words(char **words, int count)
{
	int i;

	for (i = 0; i < count; i++)
		free(words[i]);
	free(words);
}

/**
 * make_word - creates a word from a string
 * @str: string that starts with a word
 * @len: length of the word
 *
 * Return: pointer to the new word, or NULL if it fails
 */
static char *make_word(char *str, int len)
{
	char *word;
	int i;

	word = malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		word[i] = str[i];
	word[i] = '\0';

	return (word);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of words, or NULL if it fails
 */
char **strtow(char *str)
{
	char **words;
	int count;
	int i;
	int word_index;
	int len;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	count = count_words(str);
	if (count == 0)
		return (NULL);

	words = malloc((count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	i = 0;
	word_index = 0;
	while (str[i] && word_index < count)
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
		{
			len = word_length(str + i);
			words[word_index] = make_word(str + i, len);
			if (words[word_index] == NULL)
			{
				free_words(words, word_index);
				return (NULL);
			}
			word_index++;
			i += len;
		}
	}
	words[word_index] = NULL;

	return (words);
}
