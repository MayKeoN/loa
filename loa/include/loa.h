/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loa.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 04:08:07 by ymonfray          #+#    #+#             */
/*   Updated: 2015/05/15 04:08:07 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOA_H
# define LOA_H
# include "loa_def.h"

t_num				**new_num_list(int n);
int					init_all(t_env *e, int max);
// int					init_env(t_env *e);
int					draw_map(t_env *e);

#endif