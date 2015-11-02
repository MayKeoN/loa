/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loa_def.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 04:08:01 by ymonfray          #+#    #+#             */
/*   Updated: 2015/05/15 04:08:01 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOA_DEF_H
# define LOA_DEF_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <unistd.h>
# include <time.h>
# include <math.h>
# include <fcntl.h>
# include <X.h>
# include "mlx.h"
# include "libft.h"

# define KEY_ESC		53
# define KEY_SPC		32
# define KEY_PLUS		69
# define KEY_MINUS		78

# define DEFAULT_BPP	4
# define DEFAULT_ENDIAN	1

# define WIN_WIDTH		2560
# define WIN_HEIGHT		1440

typedef struct	s_num	t_num;

typedef struct	s_mask	t_mask;

struct					s_mask
{
	int					n;
	t_mask				*prev;
	t_mask				*next;
	t_mask				*l;
	t_mask				*r;
};

struct					s_num
{
	int					n;
	int					m;
	t_num				*prev;
	t_num				*next;
};

typedef struct			s_ctl
{
	int					n;
	int					on;
}						t_ctl;

typedef struct			s_im
{	
	void				*img;
	int					bpp;
	int					s_line;
	int					n_line;
	int					endian;
	char				*data;
}						t_im;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_ctl				*c;
	t_im				*i;
	t_num				**loa;
	int					max;
}						t_env;


#endif