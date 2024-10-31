/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_it_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:09:35 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/16 18:09:51 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	stuff(t_mlx *mlx, int x, int y)
{
	if (mlx->fo == 1 && mlx->ber[mlx->fo_a_y][mlx->fo_a_x] == 4)
	{
		mlx->ber[mlx->fo_a_y][mlx->fo_a_x] = 3;
		mlx->ber[mlx->fo_b_y][mlx->fo_b_x] = 4;
	}
	else if (mlx->fo == 1 && mlx->ber[mlx->fo_a_y][mlx->fo_a_x] == 3)
	{
		mlx->ber[mlx->fo_a_y][mlx->fo_a_x] = 4;
		mlx->ber[mlx->fo_b_y][mlx->fo_b_x] = 3;
	}
	mercotte(&*mlx, 0);
	sprint_map(&*mlx, 0, 0);
	x = 50 * mlx->cot_x;
	y = 50 * mlx->cot_y;
	mlx->addr = mlx_get_data_addr(mlx->sol, &mlx->pixy, &mlx->lh, &mlx->en);
	mlx->offset = (mlx->y * mlx->lh + mlx->x * (mlx->pixy / 8));
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cot, x, y);
	mlx->count++;
	mlx->toa = toa(mlx->count);
	mlx_string_put(&*mlx->mlx, &*mlx->win, 25, 25, 1, mlx->toa);
	free(mlx->toa);
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
