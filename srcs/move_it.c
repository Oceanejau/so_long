/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:44:10 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/16 18:47:23 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	stuff(t_mlx *mlx, int x, int y)
{
	mercotte(&*mlx, 0);
	sprint_map(&*mlx, 0, 0);
	x = 50 * mlx->cot_x;
	y = 50 * mlx->cot_y;
	mlx->addr = mlx_get_data_addr(mlx->sol, &mlx->pixy, &mlx->lh, &mlx->en);
	mlx->offset = (mlx->y * mlx->lh + mlx->x * (mlx->pixy / 8));
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cot, x, y);
	mlx->count++;
	ft_putnbr(mlx->count);
	ft_putchar('\n');
}

void	move_char_left(t_mlx *mlx, int x, int y)
{
	if (mlx->ber[mlx->cot_y][mlx->cot_x - 1] >= 3)
	{
		if (mlx->ber[mlx->cot_y][mlx->cot_x - 1] == 4)
			close_it(mlx);
		else if (mlx->ber[mlx->cot_y][mlx->cot_x - 1] == 69)
		{
			mlx->ber[mlx->cot_y][mlx->cot_x] = 3;
			mlx->ber[mlx->cot_y][mlx->cot_x - 1] = 81;
		}
		else if (mlx->ber[mlx->cot_y][mlx->cot_x] == 81)
		{	
			mlx->ber[mlx->cot_y][mlx->cot_x] = 69;
			mlx->ber[mlx->cot_y][mlx->cot_x - 1] = 80;
		}
		else if (mlx->ber[mlx->cot_y][mlx->cot_x - 1] >= 3)
		{
			mlx->ber[mlx->cot_y][mlx->cot_x] = 3;
			mlx->ber[mlx->cot_y][mlx->cot_x - 1] = 80;
		}
		stuff(&*mlx, x, y);
	}
}

void	move_char_right(t_mlx *mlx, int x, int y)
{
	if (mlx->ber[mlx->cot_y][mlx->cot_x + 1] >= 3)
	{
		if (mlx->ber[mlx->cot_y][mlx->cot_x + 1] == 4)
			close_it(mlx);
		else if (mlx->ber[mlx->cot_y][mlx->cot_x + 1] == 69)
		{
			mlx->ber[mlx->cot_y][mlx->cot_x] = 3;
			mlx->ber[mlx->cot_y][mlx->cot_x + 1] = 81;
		}
		else if (mlx->ber[mlx->cot_y][mlx->cot_x] == 81)
		{	
			mlx->ber[mlx->cot_y][mlx->cot_x] = 69;
			mlx->ber[mlx->cot_y][mlx->cot_x + 1] = 80;
		}
		else if (mlx->ber[mlx->cot_y][mlx->cot_x + 1] >= 3)
		{
			mlx->ber[mlx->cot_y][mlx->cot_x] = 3;
			mlx->ber[mlx->cot_y][mlx->cot_x + 1] = 80;
		}
		stuff(&*mlx, x, y);
	}
}

void	move_char_bot(t_mlx *mlx, int x, int y)
{
	if (mlx->ber[mlx->cot_y + 1][mlx->cot_x] >= 3)
	{
		if (mlx->ber[mlx->cot_y + 1][mlx->cot_x] == 4)
			close_it(mlx);
		else if (mlx->ber[mlx->cot_y + 1][mlx->cot_x] == 69)
		{
			mlx->ber[mlx->cot_y][mlx->cot_x] = 3;
			mlx->ber[mlx->cot_y + 1][mlx->cot_x] = 81;
		}
		else if (mlx->ber[mlx->cot_y][mlx->cot_x] == 81)
		{	
			mlx->ber[mlx->cot_y][mlx->cot_x] = 69;
			mlx->ber[mlx->cot_y + 1][mlx->cot_x] = 80;
		}
		else if (mlx->ber[mlx->cot_y + 1][mlx->cot_x] >= 3)
		{
			mlx->ber[mlx->cot_y][mlx->cot_x] = 3;
			mlx->ber[mlx->cot_y + 1][mlx->cot_x] = 80;
		}
		stuff(&*mlx, x, y);
	}
}

void	move_char_top(t_mlx *mlx, int x, int y)
{
	if (mlx->ber[mlx->cot_y - 1][mlx->cot_x] >= 3)
	{
		if (mlx->ber[mlx->cot_y - 1][mlx->cot_x] == 4)
			close_it(mlx);
		else if (mlx->ber[mlx->cot_y - 1][mlx->cot_x] == 69)
		{
			mlx->ber[mlx->cot_y][mlx->cot_x] = 3;
			mlx->ber[mlx->cot_y - 1][mlx->cot_x] = 81;
		}
		else if (mlx->ber[mlx->cot_y][mlx->cot_x] == 81)
		{	
			mlx->ber[mlx->cot_y][mlx->cot_x] = 69;
			mlx->ber[mlx->cot_y - 1][mlx->cot_x] = 80;
		}
		else if (mlx->ber[mlx->cot_y - 1][mlx->cot_x] >= 3)
		{
			mlx->ber[mlx->cot_y][mlx->cot_x] = 3;
			mlx->ber[mlx->cot_y - 1][mlx->cot_x] = 80;
		}
		stuff(&*mlx, x, y);
	}
}
