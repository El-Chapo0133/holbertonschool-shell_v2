#include "_atoi.h"

/**
 * _atoi - function atoi
 * @str: str to convert to int
 *
 * Return: converted int
 */
int _atoi(char *str)
{
	int sign = 1;
	unsigned int total = 0;

	/* loop over the string */
	while (*str)
	{
		/* negative case */
		if (*str == '-')
			sign = sign * -1;
		/* increase with current char */
		else if (*str >= '0' && *str <= '9')
			total = total * 10 + *str - '0';
		/* non-number char, break loop */
		else if (*str < '0' || *str > '9')
			break;
		str++;
	}
	/* negative case */
	if (sign < 0)
		total = (-(total));
	return (total);
}
