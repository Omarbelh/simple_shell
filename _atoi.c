#include "shell.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @customInfo: pointer to info_t structure
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int interactive(info_t *customInfo)
{
    return (isatty(STDIN_FILENO) && customInfo->readfd <= 2);
}

/**
 * is_delim - verifies if character is a delimiter
 * @character: the character to verify
 * @delim: the delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char character, char *delim)
{
    while (*delim)
        if (*delim++ == character)
            return 1;
    return 0;
}

/**
 * _isalpha - verifies for alphabetic character
 * @character: The character to verify
 * Return: 1 if character is alphabetic, 0 otherwise
 */
int _isalpha(int character)
{
    if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
        return 1;
    else
        return 0;
}

/**
 * _atoi - converts a string to an integer
 * @inputString: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *inputString)
{
    int index, sign = 1, flag = 0, result;
    unsigned int convertedValue = 0;

    for (index = 0; inputString[index] != '\0' && flag != 2; index++)
    {
        if (inputString[index] == '-')
            sign *= -1;

        if (inputString[index] >= '0' && inputString[index] <= '9')
        {
            flag = 1;
            convertedValue *= 10;
            convertedValue += (inputString[index] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        result = -convertedValue;
    else
        result = convertedValue;

    return result;
}
