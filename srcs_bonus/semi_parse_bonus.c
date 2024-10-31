/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semi_parse_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:31:47 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/16 19:20:12 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	obsy(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 1;
	mlx->obsy = 0;
	while (y < mlx->len_y - 1)
	{
		x = 1;
		while (x < mlx->len_x - 1)
		{
			if (mlx->ber[y][x] == 1)
			{
				mlx->ber[y][x] = 2;
				mlx->obsy = 1;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	mapy(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->len_y)
	{
		x = 0;
		while (x < mlx->len_x)
		{
			if (mlx->ber[y][x] == 80)
				mlx->err_cot++;
			if (mlx->ber[y][x] == 67)
				mlx->err_col++;
			if (mlx->ber[y][x] == 69)
				mlx->err_nid++;
			x++;
		}
		y++;
	}
	return ;
}

void	mur_test(t_mlx *mlx)
{
	int	x;

	x = 0;
	while (x < mlx->len_x && mlx->err_mur == 0)
	{
		if (mlx->ber[0][x] != 1 || mlx->ber[mlx->len_y - 1][x] != 1)
			mlx->err_mur = -1;
		x++;
	}
	x = 0;
	while (x < mlx->len_y && mlx->err_mur == 0)
	{
		if (mlx->ber[x][0] != 1 || mlx->ber[x][mlx->len_x - 1] != 1)
			mlx->err_mur = -1;
		x++;
	}
	return ;
}
