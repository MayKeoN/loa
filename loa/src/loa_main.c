/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loa_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 04:08:39 by ymonfray          #+#    #+#             */
/*   Updated: 2015/05/15 04:08:39 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loa.h"
long int *mingap;
int	maxtree;
int fdout;
int lenu64;

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

void			curse_mask(t_mask *mask, register unsigned long int acc)
{
	// t_mask		*num;

	// printf("NUM: %d\n", mask->n);
	if (acc > 14999999000)
	{
		// if ((mask->next == NULL) && acc < 999700)
			// return;
		if (acc < 15000001000)
			printf("%ld:%d\n", acc, mask->n);
		return;
	}

	// if (mask->next != NULL)
	{
		// printf("-> * %d\t", num->n);
	}

	// if (mask->next != NULL)
	if (mask->next)
	{
		curse_mask(mask->next, acc * mask->next->n);
		curse_mask(mask->next, acc);
		// printf("<- * 1 (%d)\t", num->n);
	}
	return;
}


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


void			curse_mask_tab(int *pl, register unsigned long int acc, register const unsigned long int upper_lim, register const unsigned long int lower_lim)
{
	if (acc > lower_lim)
	{
		// 1499999948900
		if (acc < upper_lim)
		{
			// 1500000051100
			// printf("%ld\n", acc);
			// long int finalgap = (acc - lower_lim);
			// printf("FINAL GAP: %ld\n", finalgap);
			char *numsave = u64toa(acc - lower_lim);
			write(fdout, numsave, strlen(numsave));
			// printf("%ld:%d\t", acc, *pl);
			// long int finalgap = (acc - (upper_lim+lower_lim)/2);
			// printf("FINAL GAP: %ld\n", finalgap);
			// int i = 0;
			// while (mingap[i])
				// i++;
			// if (finalgap < mingap)
			{
				// mingap[i] = finalgap;
				// printf("%p\n", mingap);
				// printf("I: %d\tmin: %ld\tfin:%ld\n", i, mingap[i], finalgap);
			}
			// exit(0);
			return;
		}
		return;
	}
	if (*(pl + 1))
	{
		// printf("%d->", pl[1]);		
		curse_mask_tab(pl + 1, acc * *(pl + 1), upper_lim, lower_lim);
		// if (*pl < 6)
		// 	fork();

		// printf("%d->", 1);
		curse_mask_tab(pl + 1, acc, upper_lim, lower_lim);
	}
	// printf("\n");
	// if (*(pl + 1))
	{
		// printf("%d->", 1);
	}
	// printf("\n");
	return;
	// exit(0);
}

///////////////////////////////////////////////////////////////
static pid_t fork_ok(void)
{
    pid_t pid;
    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "Fork failure in pid %d\n", (int)getpid());
        exit(1);
    }
    return pid;
}

static void new_level(int *pl, unsigned long int acc, unsigned long int upper_lim, unsigned long int lower_lim, int bran)
{
	int f1, f2;

    if (*pl > maxtree)
    {
    	int f11;


	    // if (())
    	f11 = fork_ok();
	    {	
	    	// printf("F11: %d\tF21: %d\n", f11, f21);
	        if (!f11)
	        {
	        	// printf("Pri: %d\tAcc: %ld\n", *(pl +  1), acc);
				curse_mask_tab(pl + 1, acc, upper_lim, lower_lim);
				// exit(-1);
	        }
		    else
		    {
				// printf("Pri: %d\tAcc: %ld\n", *(pl +  1), acc * *(pl +  1));
   				curse_mask_tab(pl + 1, acc * *(pl + 1), upper_lim, lower_lim);
				// exit(-1);
		    }
	    }
	    // else
	    {
	        // printf("i am %d, my parent is %d\n",
	                // (int)getpid(), (int)getppid());
	        // while (wait(0) > 0)
	            // ;
	        // printf("Exit %d\n", (int)getpid());
	    }
	    return;
	    // exit(-1);


    	// if (!bran)
			// curse_mask_tab(pl + 1, acc, upper_lim, lower_lim);
		// else
			// curse_mask_tab(pl + 1, acc * *(pl + 1), upper_lim, lower_lim);
    }
    (f1 = fork_ok());
    {	
    	// printf("F1: %d\tF2: %d\n", f1, f2);
        if (!f1)
        {
        	// if (!bran)
		        // new_level(pl + 1, acc, upper_lim, lower_lim, !bran);
        	// else
	        	new_level(pl + 1, acc, upper_lim, lower_lim, 0);
	        // exit(0);
        }
	    else
	    {
	    	// if (!bran)
        		// new_level(pl + 1, acc * *(pl + 1), upper_lim, lower_lim, !bran);
        	// else
	        	new_level(pl + 1, acc * *(pl + 1), upper_lim, lower_lim, 0);
	    	// exit(0);
	    }
    }
    // else
    {
        // printf("i am %d, my parent is %d\n",
                // (int)getpid(), (int)getppid());
        while (wait(0) > 0)
            ;
        // printf("Exit %d\n", (int)getpid());
    }
    // exit(0);
}

// int main(void)
// {
//     printf("Start %d\n", (int)getpid());
//     new_level(0);
//     // fflush(0);
//     return(0);
// }


//////////////////////////////////////////


int				main(int ac, char **av)
{
	// t_num		**list;
	t_num								*one;
	t_mask								*nmask;
	t_mask								**lmask;
	t_env								*e;
	int									*pl;
	register unsigned long int 			acc;
	register unsigned long int 	upper_lim;
	register unsigned long int 	lower_lim;
	// int			i;
	// printf("IN\n");
	// if (ac == 2)
	// 	if (!init_all(e, 100))
	// 		mlx_loop(e->mlx);
	acc = 1;
	pl = (int *)malloc(sizeof(int) * 6544);
	pl[0] = 1;

	{
		// i = 0;
		e = (t_env *)malloc(sizeof(t_env));

		e->loa = new_num_list(atoi(av[3]));
		maxtree = atoi(av[4]);
		fdout = open(av[5], O_CREAT|O_WRONLY|O_APPEND, 777);
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
		// (*lmask) = nmask->next;
		nmask = lmask[0];
		// while ((nmask = nmask->next))
		{
			// printf("N: %d\n", nmask->n);
		}
		// i = 0;
		// while (pl[i])
		// 	printf("%d\n", pl[i++]);
		// nmask = lmask[0]->next;
		nmask->n = 1;
		// printf("mask: %d\n", nmask->n);		
		// printf("mask2: %d\n", nmask->next->n);		
		// printf("mask3: %d\n", nmask->next->next->n);	
		{
			// pl += 9;
			// acc = 1938;
		}
		long int margin = atol(av[2]);
		unsigned long int target = atol(av[1]);
		lower_lim = (unsigned long int)(margin);
		upper_lim = (unsigned long int)(target);
		// lower_lim = (unsigned long int)(target - margin);
		// upper_lim = (unsigned long int)(target + margin);
		// unsigned long int lim


		// printf("Margin: %ld\n", margin);
		// printf("TARGET:%ld\n", target);
		// printf("GAP Range:%ld\n", upper_lim - lower_lim);
		// printf("Lower Limit:%ld\n", lower_lim);
		// printf("Upper Limit:%ld\n", upper_lim);
		// printf("Start %d\n", (int)getpid());
		// extern long int mingap;
		mingap = (long int *)malloc(sizeof(long int) * 1000);
		// mingap[0] = -1;
		new_level(pl, acc, upper_lim, lower_lim, 0);
		// curse_mask_tab(pl, acc, upper_lim, lower_lim);

		// curse_mask(nmask, acc);

		// printf("IN!\n");
		// one = (*list);
		// while (((*list) = (*list)->next) )//&& i < atoi(av[1]))
		// {
		// 	// printf("ZERO0: %lx\n", (long)(one));
		// 	// printf("ZERO0: %lx\n", (long)(one->next));
		// 	// if ((*list)->s->n == 0 || (*list)->s->n > 96)
		// 	{		
		// 		printf("%d\t", (int)((*list)->n));
		// 		printf("%d\n", (int)((*list)->m));
		// 		// printf("\t= \t%d   \t\t* ", (int)((*list)->l->n));
		// 		// printf("\t%d\n", (int)((*list)->s->n));
		// 	}
		// 	// printf("adr: \t\t%lx\n", (long)(*list));
		// 	i++;
		// }
		// free(list);
	}
	free(e);
	// int i = 0;
	// while (mingap[i])
	// 	printf("MinGap FINAL: %ld\n", mingap[i++]);
	return (0);
}
//