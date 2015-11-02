/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loa_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 22:58:18 by ymonfray          #+#    #+#             */
/*   Updated: 2015/06/07 22:58:19 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loa.h"

void				draw_pixel_data(t_im *i, int x, int y, int color)
{
	unsigned int	adr;
	unsigned int	*pix;

	while (x >= i->s_line >> 2)
	{
		x -= i->s_line >> 2;
		y += 350;
	}
	// printf("x: %d\ty: %d\n", x, y);
	if (y >= 0 && y <= i->n_line && x >= 0 && x <= (i->s_line >> 2))
	{
		adr = y * i->s_line + x * (i->bpp >> 3);
		pix = (unsigned int *)&(i->data)[adr];
		*pix = color;
	}
}

int					draw_line_data(int x1, int y1, int x2, int y2, t_im *i, int color)
{
	int 			dx;
	int				dy;

	// printf("x1: %d\ty1: %d\tx2: %d\ty2: %d\n", x1, y1, x2, y2);
	dx = (x2 - x1);
	dy = (y2 - y1);
	draw_pixel_data(i, x2, y2, color);
	if (abs(dx) > abs(dy))
		while (dx += (dx < 0) - (dx > 0))
			draw_pixel_data(i, x1 + dx, y1 + dx * (y2 - y1) / (x2 - x1), color);
	else
		while (dy += (dy < 0) - (dy > 0))
			draw_pixel_data(i, x1 + dy * (x2 - x1) / (y2 - y1), y1 + dy, color);
	draw_pixel_data(i, x1, y1, color);
	return (0);
}

int					draw_map(t_env *e)
{
	t_num			*pyr;
	int				xbit;
	int				ybit;
	int				ycolor;
	int				i;

	pyr = *(e->loa);
	xbit = 0;
	ybit = 0;
	// printf("69!\n");
	while (pyr->next && pyr->n < 338)
	{
		xbit += pyr->n;
		ybit = pyr->m;
		i = 0;
		// printf("xbit: %d\n", xbit);

		// mlx_string_put(e->mlx, e->win, 500, 510, 0x00FFFFFF, ft_strjoin("Xbit: ", ft_itoa(xbit-ybit)));
		ycolor = 0x00FF00FF;
		if (pyr->m/(float)pyr->n > 0.73)
			ycolor = (pyr->m/(float)pyr->n > 0.91) ? 0x00CCDDAA : 0x00FF001F;
		while (i < ybit)
		{
			// printf("i: %d\n", i);
			draw_line_data(xbit, i, xbit - ybit, i , e->i, ycolor);
			i++;
		}
		draw_line_data(xbit, i - 1, xbit - ybit, i - 1, e->i, 0x00FFFFFF);
		draw_line_data(xbit - ybit, 0 , xbit - ybit, i - 1, e->i, 0x00FFFFFF);
		draw_line_data(xbit, pyr->n - 1, xbit - pyr->n, pyr->n - 1, e->i, (ybit) ? 0x0022F44F : 0x005B0480);
		draw_line_data(xbit - pyr->n, pyr->n - 1, xbit - pyr->n, 0, e->i, (ybit) ? 0x0022F44F : 0x005B0480);

		ybit = xbit/WIN_WIDTH;
		while (ybit)
		{
			draw_line_data(0, ybit * 350, WIN_WIDTH, ybit * 350, e->i, 0x00FFFFFF);
			ybit--;
		}

		pyr = pyr->next;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->i->img, 0, 0);
	return (0);
}

