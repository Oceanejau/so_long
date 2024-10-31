/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mercotte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:16:07 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/16 17:17:52 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	coti(t_mlx *mlx, int x, int y)
{
	mlx->cot_x = x;
	mlx->x = x;
	mlx->y = y;
	mlx->cot_y = y;
	return ;
}

void	mercotte(t_mlx *mlx, int y)
{
	int	x;

	mlx->col = 0;
	while (y < mlx->len_y)
	{
		x = 0;
		while (x < mlx->len_x)
		{
			if (mlx->ber[y][x] >= 80)
				coti(&*mlx, x, y);
			if (mlx->ber[y][x] == 67)
				mlx->col++;
			x++;
		}
		y++;
	}
	if (mlx->col == 0)
	{
		free(mlx->path);
		mlx->path = ft_strjoin("", "./images/50/");
	}
	return ;
}
