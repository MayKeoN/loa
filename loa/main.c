#include <stdio.h>

int		main(void)
{
	long int i, j;

	i = 0;
	while (i++ < 5000000000)
		j = i-3;
	return (0);
}
