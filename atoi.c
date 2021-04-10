#include "tom_shelleck.h"

/**
 * _atoi - converts a string to an integer
 * @s: string input
 * Return: integer value of string
 */
int _atoi(char *s)
{
	int a, c;
	double b, i;

/* start at the end of the string to find the ones' place */
	for (a = 0; s[a] != '\0';)
		a++;
	a--;
/* start a multiplier variable b, result variable i, and checker c */
	for (b = 1, i = 0, c = 0; a >= 0; a--)
	{
/* if we find a digit */
		if (s[a] <= '9' && s[a] >= '0')
		{
/* if it's a new digit after symbols were found, start counting from 0 again */
			if (c == 1 && (s[a + 1] < 48 || s[a + 1] > 57))
				i = 0, b = 1;
/* increase result i by the digit value * multiplier b */
			i += ((s[a] - 48) * b);
/* multiply b by 10 each time we move up a digit */
			b *= 10;
/* set checker flag to 1 when we first find a digit */
			c = 1;
		}
/* negative symbols change the sign of the result */
		if (s[a] == '-')
			i = -i;
	}
	return (i);
}
