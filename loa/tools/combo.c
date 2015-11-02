/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 23:11:26 by ymonfray          #+#    #+#             */
/*   Updated: 2015/06/10 23:11:27 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include <stdio.h>

typedef struct 			s_comb
{
	int					w[300][23];
}						t_comb;

void					combinations(int v[23], int start, int k, int w[300][23], int *index)
{
	int					i;

	if (k > 22)
	{	
		i = -1;
		printf("Combo\t");
		while (++i < 23)
		{
			w[(*index)][i] = v[i];
			printf("[%d]", v[i]);
		}
		*index += 1;
		printf("\n");
		return;
	}
	i = start;
	while (i < 25)
	{
		v[k] = i;
		combinations(v, i+1, k+1, w, index);
		i++;
	}
}

void					init_combo(t_comb *g)
{
	int 				v[23];
	int					w[300][23];
	int					index;
	int					i;
	int					j;

	index = 0;
	combinations(v, 0, 0, w, &index);
	printf("Here\n");
	i = -1;
	j = -1;
	while (++j < 300)
	{
		while (++i < 23)
			g->w[j][i] = w[j][i];
		i = -1;
	}
	// return (w);
}

int						main(int ac, char **av)
{
	int					i;
	int					j;
	// int					*w[300][23];
	// static				list[25];
	t_comb				*g;

	g = (t_comb *)malloc(sizeof(t_comb));
	i = 0;
	j = 0;
	if (ac == 3)
	{
		init_combo(g);
		while (j < 300)
		{
			// printf("Combo %d\t:\t", j);
			printf("[");
			while (i < 23)
			{
				printf("%d, ", g->w[j][i]);
				i++;
			}
			i = 0;
			j++;
			printf("],\n");
		}
	}
	return (0);
}
