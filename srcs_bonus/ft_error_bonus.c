/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:28:48 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/16 18:29:01 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	err(char *str, int x)
{
	write(2, str, ft_strlen(str));
	ft_putchar('\n');
	return (x);
}

int	err_cl(t_mlx *mlx, char *str)
{
	write(2, "Error:\n ", 9);
	write(2, str, ft_strlen(str));
	ft_putchar('\n');
	mlx->close = 1;
	if (mlx->error_map_ber == -1 || mlx->fd == -1)
	{
		free(mlx->path);
		return (-1);
	}
	else if (mlx->err_tab == -1 || mlx->err_mur == -1 || mlx->err_len == -1
		|| mlx->err_cot != 1 || mlx->err_col == 0 || mlx->err_nid != 1
		|| mlx->mlx == NULL)
		mlx->close = free_tab(mlx->ber, mlx->len_y, 1);
	free(mlx->path);
	exit (-1);
	return (-1);
}

int	close_it(t_mlx *mlx)
{
	int	y;

	y = 0;
	mlx->close = 1;
	free(mlx->path);
	mlx_destroy_image(mlx->mlx, mlx->cot);
	mlx_destroy_image(mlx->mlx, mlx->sun);
	mlx_destroy_image(mlx->mlx, mlx->sol);
	mlx_destroy_image(mlx->mlx, mlx->nid);
	mlx_destroy_image(mlx->mlx, mlx->mur);
	if (mlx->obsy == 1)
		mlx_destroy_image(mlx->mlx, mlx->obs);
	if (mlx->fo == 1)
		mlx_destroy_image(mlx->mlx, mlx->fox);
	while (y < mlx->len_y)
	{
		free(mlx->ber[y]);
		y++;
	}
	free(mlx->ber);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	exit(0);
}
