/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loa_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 04:09:25 by ymonfray          #+#    #+#             */
/*   Updated: 2015/05/15 04:09:25 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
