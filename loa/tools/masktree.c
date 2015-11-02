/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   masktree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 00:24:59 by ymonfray          #+#    #+#             */
/*   Updated: 2015/06/19 00:25:02 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




//////////////////////////////////////////////////////////////////
//LOA INIT

#include "loa.h"


void				pop_num(t_num *pop)
{
	pop->prev->next = pop->next;
	pop->next->prev = pop->prev;
}


void				pop_num_free(t_num *pop)
{
	pop->prev->next = pop->next;
	pop->next->prev = pop->prev;
	free(pop);
}

t_num				*find_num(t_num **list, int n)
{
	return (list[n]);
}

t_num				*find_lpf(t_num *num, int n)
{
	while (num->n != n)
		num = num->next;
	return (num);
}

void				skip_loa(t_num *one)
{
	while (one)
	{
		one->m++;
		if (one->m == one->n)
			one->m = 0;
		one = one->next;
	}
}

int					find_loa(t_num *one)
{
	int				ornot;

	ornot = 0;
	while (one)
	{
		one->m++;
		if (one->m == one->n)
		{
			ornot++;
			one->m = 0;
		}
		one = one->next;
	}
	return (!ornot);
}

t_num				*build_loa(t_num *last, t_num *one, int n, int i)
{
	// int				i;
	t_num			*num;

	// i = 3;
	num = NULL;
	if ((num = (t_num *)malloc(sizeof(t_num))))
	{		
		num->next = NULL;
		num->prev = last;
		last->next = num;
		num->n = i;
		num->m = n % i;
	}
	i++;
	return (num);
}


t_num				*new_num(t_num *last, t_num *one, int *gap)
{
	t_num			*num;
	// int				skip;


	// if (last->n > 31)
	// {
	// 	skip = last->n + *gap;
	// // 	// printf("skip: %d\n", skip);
	// 	num = one->next;
	// 	while (num->n < 32)
	// 	{
	// 		if ((skip % num->n) == 0)
	// 		{	
	// 			(*gap)++;
	// 			skip_loa(one->next);
	// 			return (last);
	// 		}
	// 		num = num->next;
	// 	}
	// 	one = find_lpf(one, 31);
	// }

	if (find_loa(one->next))
	{
		num = NULL;
		if ((num = (t_num *)malloc(sizeof(t_num))))
		{		
			num->next = NULL;
			num->prev = last;
			last->next = num;
			num->n = last->n + *gap;
			num->m = 0;
		}
		(*gap) = 1;
	}
	else
	{
		(*gap)++;
		return (last);
	}
	return (num);
}


static t_num		**new_unity(int n)
{
	t_num			**list;
	t_num			*one;
	t_num			*two;

	list = NULL;
	list = (t_num **)malloc(sizeof(t_num *) * n);
	one = (t_num *)malloc(sizeof(t_num));
	two = (t_num *)malloc(sizeof(t_num));
	if (list && one && two)
	{
		one->prev = NULL;
		one->n = 1;
		one->m = 1;
		one->next = two;
		two->prev = one;
		two->n = 2;
		two->m = 0;
		two->next = NULL;
	}
	(*list) = one;
	return (list);
}

t_num				**new_num_list(int n)
{
	t_num			**list;
	t_num			*num;
	t_num			*one;
	t_num			*two;
	int				i;
	int				gap;

	i = 3;
	gap = 0;
	list = NULL;
	if ((list = new_unity(n)))
	{
		one = (*list);
			// printf("DEBUG! %d\n", i);
		two = one->next;
		list[1] = two;
		num = two;
		while (i < n)
		{
			// printf("DEBUGap! %d\n", gap);
			num = new_num(num, two, &gap);
			// num = build_loa(num, two, n, i);
			list[i++] = num;
		}
		// list[i++] = num;

		// int j = 0;
		// while (i < 200)
		// {
		// 	num = new_num(num, one, &gap);
		// 	list[i++] = num;
		// 	// j++;
		// }
	}
	return (&list[0]);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN

int fdout;
int lenu64;


char				*u64toa(long int n)
{
	static char		*nbr;
	long int		neg;
	long int		nb;
	int				i;

	if (!nbr)
		nbr = (char *)malloc(sizeof(char) * (lenu64 + 1));
	i = 1;
	neg = (n < 0) ? -1 : 1;
	// nbr = NULL;
	nb = n;
	while (nb /= 10)
		i++;
	i -= (neg > 0);
	if (nbr)
	{
		nbr[i + 1] = 10;
		nbr[i + 2] = 0;
		if (neg < 0)
			nbr[0] = '-';
		if (!n)
			nbr[i] = '0';
		while (n)
		{
			nbr[i--] = (neg * (n % 10)) + '0';
			n /= 10;
		}
	}
	return (nbr);
}


t_mask				*new_mask(t_mask *last, int n)
{
	t_mask			*num;

	// while ((num = (t_mask *)malloc(sizeof(t_mask))) == NULL);
	if ((num = (t_mask *)malloc(sizeof(t_mask))))
	{		
		num->next = NULL;
		num->prev = last;
		last->next = num;
		num->n = n;
		last->r = num;
		last->l = num;
	}
	return (num);
}

void			curse_mask_tab(int *pl, register unsigned long int acc, register const unsigned long int upper_lim, register const unsigned long int lower_lim, int *done)
{
	// if (acc > lower_lim)
	{

		// if (acc < upper_lim)
		{
	// printf("%lu\n", acc);

			// char *numsave = u64toa(acc - lower_lim);
			// printf("%s", numsave);
			// write(fdout, numsave, strlen(numsave));
			// done[0] = 1;
			// return;
		}
		// return;
	}
	if (*(pl + 1))// && !done[0])
	{
	
		curse_mask_tab(pl + 1, acc * *(pl + 1), upper_lim, lower_lim, done);

		curse_mask_tab(pl + 1, acc, upper_lim, lower_lim, done);

		// curse_mask_tab(pl + 1, acc + *(pl + 1), upper_lim, lower_lim);
	}
	printf("%lu\n", acc);
	return;

}

int				main(int ac, char **av)
{
	// t_num		**list;
	t_num								*one;
	t_mask								*nmask;
	t_mask								**lmask;
	t_env								*e;
	int									*pl;
	int									*done;
	register unsigned long int 			acc;
	register unsigned long int 			upper_lim;
	register unsigned long int 			lower_lim;

	// int			i;
	// printf("IN\n");
	// if (ac == 2)
	// 	if (!init_all(e, 100))
	// 		mlx_loop(e->mlx);
	acc = 1;
	pl = (int *)malloc(sizeof(int) * 6544);
	done = (int *)malloc(sizeof(int));
	done[0] = 0;
	pl[0] = 1;

	{
		// i = 0;
		e = (t_env *)malloc(sizeof(t_env));

		e->loa = new_num_list(atoi(av[3]));
		// maxtree = atoi(av[4]);
		// fdout = open(av[5], O_CREAT|O_WRONLY, 777);
		lenu64 = strlen(av[1]) + 2;
		one = (e->loa[1]);
		lmask = (t_mask **)malloc(sizeof(t_mask *) * 6544);
		nmask = (t_mask *)malloc(sizeof(t_mask ));
		nmask->n = one->n;
		nmask->prev = NULL;
		nmask->next = NULL;
		nmask->l = NULL;
		nmask->r = NULL;
		(*lmask) = nmask;
		int i = 1;
		while ((one = one->next))
		{
				pl[i] = one->n;
			i++;
			// printf("N: %d\n", nmask->n);
			nmask = new_mask(nmask, one->n);
		}
		pl[i] = 0;

		nmask = lmask[0];

		nmask->n = 1;
		lower_lim = (unsigned long int)atol(av[2]);
		upper_lim = (unsigned long int)atol(av[1]);
		curse_mask_tab(pl, acc, upper_lim, lower_lim, done);
	}
	free(e);

	return (0);
}
//