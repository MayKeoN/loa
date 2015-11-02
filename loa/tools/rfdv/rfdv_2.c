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
#include "libft.h"
#include "gmp.h"

// long unsigned int			*fill_mask(long unsigned int num)
// {
// 	long unsigned int		*t;
// 	int						i;
// 	long unsigned int		max;

// 	max = ((long unsigned int)1 << 63);
// 	i = 0;
// 	// printf("MAX %lu\n", max);
// 	t = (long unsigned int *)malloc(sizeof(long unsigned int) * 64);
// 	while (i < 64 && (max & (num << i)) == 0)
// 	{
// 		t[i] = (num << i);
// 		i++;
// 	}
// 	return (t);
// }

// void						find_mask(long unsigned int *t, long unsigned int *acc, int i)
// {
// 	if (acc[1] >= t[i])
// 	{
// 		acc[0] += (1 << i);
// 		acc[1] -= t[i];
// 	}
// 	if (acc[1] < t[0])
// 		return;
// 	if (i)
// 		find_mask(t, acc, --i);
// }

long unsigned int			*fill_mask_m(long unsigned int num, int limit)
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

void						find_mask_m(long unsigned int *t, long unsigned int *acc, int i)
{
	if (acc[1] >= t[i])
	{
		acc[0] += (1 << i);
		acc[1] -= t[i];
	}
	if (acc[1] < t[0])
		return;
	if (i)
		find_mask_m(t, acc, --i);
}




int							main(int ac, char **av)
{
	long unsigned int		a;
	long unsigned int		b;
	// long unsigned int		*t;
	// int						start;
	long unsigned int		count;
	// long unsigned int		count2;
	// long unsigned int		count3;
	long unsigned int		res;	
	// long unsigned int		*acc;	


  	mpz_t p;
  	mpz_t q;
  	mpz_t r;

	mpz_init(p);
	mpz_init(q);
	mpz_init(r);
	if (ac == 3)
	{
		mpz_set_str(p, av[1], 10);
		mpz_set_str(q, av[2], 10);
		a = atol(av[1]);
		b = atol(av[2]);
		// t = fill_mask(b);
		// start = 0;
		// while (t[start] && start < 64)
		// 	start++;
		// start--;
		// printf("Start @ %d\n", start);

		// while (t[start] > a)
		// 	start--;
		// // for (int k = 0; k < 64;k++)
		// // 	printf("%d:%lu\n", k, t[k]);
		// printf("Start @ %d\n", start);
		// acc = (long unsigned int *)malloc(sizeof(long unsigned int) * 2);
		count = 0;
		while (++count < 1000000000000000)//~(long unsigned int)0)
		{
			// mpz_cdiv_q(r, p, q);
			// printf("R: ");
			// mpz_out_str(stdout, 10, r);
			// printf("\n");
		// 	// count2 = 0;
		// 	acc[0] = 0;
		// 	acc[1] = a + count;
		// 	find_mask(t, acc, start);
			res = (a)/ b;
		// 	// printf("acc: %lu\trest: %lu\n", acc[0], acc[1]);

		// // 	while (++count2 < ~(long unsigned int)0)
		// // 	{
		// // 					count3 = 0;
		// // 	while (++count3 < ~(long unsigned int)0)
		// // 	{
				
		// // 	}

		// // 	// printf("%lu\n", res);
		// // // printf("count %lu\n", count2);

		// // 	}

		// 	// find_mask(a + count, t, 0, start);
		// 	// res += a /(b);
		// 	// printf("%lu\n", res);
		}
		// printf("count %lu\n", count);
	}
	return (0);
}