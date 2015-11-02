/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rfdv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <ymonfray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 18:29:14 by ymonfray          #+#    #+#             */
/*   Updated: 2015/09/30 18:29:21 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

long unsigned int			*fill_mask(long unsigned int num)
{
	long unsigned int		*t;
	int						i;
	long unsigned int		max;

	max = ((long unsigned int)1 << 63);
	i = 0;
	// printf("MAX %lu\n", max);
	t = (long unsigned int *)malloc(sizeof(long unsigned int) * 64);
	while (i < 64 && (max & (num << i)) == 0)
	{
		t[i] = (num << i);
		i++;
	}
	return (t);
}

void						find_mask(long unsigned int num, long unsigned int *t, long unsigned int acc, int i)
{
	if (num >= t[i])
	{
		acc += (1 << i);
		num -= t[i];
	}
	if (num < t[0])
	{
		// printf("acc: %lu\trest: %lu\n", acc, num);
		return;
	}
	if (i)
		find_mask(num, t, acc, --i);
}

int							main(int ac, char **av)
{
	long unsigned int		a;
	long unsigned int		b;
	long unsigned int		*t;
	int						start;
	long int				count;
	long unsigned int		res;	

	if (ac == 3)
	{
		a = atol(av[1]);
		b = atol(av[2]);
		t = fill_mask(b);
		start = 0;
		while (t[start] && start < 64)
			start++;
		start--;
		printf("Start @ %d\n", start);

		while (t[start] > a)
			start--;
		// for (int k = 0; k < 64;k++)
		// 	printf("%d:%lu\n", k, t[k]);
		printf("Start @ %d\n", start);
		count = 0;
		while (++count < 100000000)
		{
			find_mask(a, t, 0, start);
			// res = a /(b);
			// printf("%lu\n", res);
		}
		printf("count %lu\n", count);
	}
	return (0);
}