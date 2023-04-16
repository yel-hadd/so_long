/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_blocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:54:48 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/16 23:11:53 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

t_blocks    *load_blocks(void *mlx_ptr)
{
	t_blocks	*b;
	int			var;
    int			var1;

	b = (t_blocks *)malloc(sizeof(t_blocks));
	if (!b)
		return (b);
	b->C = mlx_xpm_file_to_image(mlx_ptr, "assets/C.xpm", &var, &var1);
	b->W = mlx_xpm_file_to_image(mlx_ptr, "assets/W.xpm", &var, &var1);
	b->E = mlx_xpm_file_to_image(mlx_ptr, "assets/E.xpm", &var, &var1);
	b->PU = mlx_xpm_file_to_image(mlx_ptr, "assets/PU.xpm", &var, &var1);
	b->PD = mlx_xpm_file_to_image(mlx_ptr, "assets/PD.xpm", &var, &var1);
	b->PR = mlx_xpm_file_to_image(mlx_ptr, "assets/PR.xpm", &var, &var1);
	b->PL = mlx_xpm_file_to_image(mlx_ptr, "assets/PL.xpm", &var, &var1);
	b->O = mlx_xpm_file_to_image(mlx_ptr, "assets/O.xpm", &var, &var1);
    b->next = NULL;
	return (b);
}
