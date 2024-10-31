/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foxy_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:27:51 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/16 18:27:54 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	fox_init(t_mlx *mlx, int x, int y)
{
	if (mlx->ber[y][x] == 3 && mlx->ber[y][x + 1] == 3)
	{
		mlx->fo_a_x = x;
		mlx->fo_a_y = y;
		mlx->ber[y][x] = 4;
		mlx->fo_b_x = x + 1;
		mlx->fo_b_y = y;
		mlx->fo = 1;
	}
	else if (mlx->ber[y][x] == 3 && mlx->ber[y + 1][x] == 3)
	{
		mlx->fo_a_x = x;
		mlx->fo_a_y = y;
		mlx->ber[y][x] = 4;
		mlx->fo_b_x = x;
		mlx->fo_b_y = y + 1;
		mlx->fo = 1;
	}
	return ;
}

void	foxtrott(t_mlx *mlx)
{
	int	y;
	int	x;

	y = 1;
	if (mlx->len_x > 4 && mlx->len_y > 4)
	{
		mlx->fo = 0;
		while (y < mlx->len_y - 1 && mlx->fo == 0)
		{
			x = 0;
			while (x < mlx->len_x - 1 && mlx->fo == 0)
			{
				if (mlx->ber[y][x] == 3)
					fox_init(&*mlx, x, y);
				x++;
			}
			y++;
		}
	}
	return ;
}
