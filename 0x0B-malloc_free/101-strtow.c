#include <stdlib.h>
#include <stdio.h> // Added for NULL definition

/**
 * count_words - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_words(const char *s)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            in_word = 0;
        }
        else
        {
            if (in_word == 0)
            {
                in_word = 1;
                count++;
            }
        }
    }

    return count;
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(const char *str)
{
    if (str == NULL || *str == '\0')
        return NULL;

    int len = 0;
    while (str[len])
        len++;

    int words = count_words(str);
    if (words == 0)
        return NULL;

    char **matrix = (char **)malloc(sizeof(char *) * (words + 1));
    if (matrix == NULL)
        return NULL;

    int k = 0;
    int c = 0;
    int start = 0;
    int end;

    for (int i = 0; i <= len; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            if (c)
            {
                end = i;
                char *tmp = (char *)malloc(sizeof(char) * (c + 1));
                if (tmp == NULL)
                {
                    // Free allocated memory for previous strings
                    for (int j = 0; j < k; j++)
                        free(matrix[j]);
                    free(matrix);
                    return NULL;
                }
                int index = 0;
                for (int j = start; j < end; j++)
                    tmp[index++] = str[j];
                tmp[index] = '\0';
                matrix[k++] = tmp;
                c = 0;
            }
        }
        else if (c++ == 0)
            start = i;
    }

    matrix[k] = NULL;

    return matrix;
}

