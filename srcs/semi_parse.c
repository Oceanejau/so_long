/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semi_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 07:42:03 by ojauregu          #+#    #+#             */
/*   Updated: 2022/02/26 12:18:04 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

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
