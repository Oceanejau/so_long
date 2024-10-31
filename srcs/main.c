/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 08:09:10 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/16 18:44:34 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	mlx_struct_init(t_mlx *mlx, char **av)
{
	mlx->end_loop = 0;
	mlx->count = 0;
	mlx->err_mur = 0;
	mlx->err_cot = 0;
	mlx->err_nid = 0;
	mlx->err_len = 0;
	mlx->err_tab = 0;
	mlx->err_col = 0;
	mlx->close = 0;
	mlx->gnl = 1;
	mlx->err_char = 0;
	mlx->len = -1;
	mlx_struct_suite(&*mlx, av);
	return ;
}

void	mlx_struct_suite(t_mlx *mlx, char **av)
{
	mlx->p_x = -1;
	mlx->e_x = -1;
	mlx->y = 0;
	mlx->x = 0;
	mlx->err_img = 0;
	mlx->path = ft_strjoin("", "./images/cold/");
	mlx->ber = NULL;
	mlx->cot = NULL;
	mlx->sol = NULL;
	mlx->mur = NULL;
	mlx->obs = NULL;
	mlx->sun = NULL;
	mlx->nid = NULL;
	check_the_bear(av[1], &*mlx, 0, 0);
	return ;
}

void	tarte(t_mlx *mlx)
{
	obsy(&*mlx);
	mlx->lon = 50 * mlx->len_x;
	mlx->lar = 50 * mlx->len_y;
	return ;
}

int	loopy_loop(t_mlx *mlx)
{
	if (mlx->close == 0)
	{
		if (mlx->ber[mlx->cot_y][mlx->cot_x] == 81 && mlx->col == 0)
		{
			close_it(mlx);
			return (-1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (err("Error:\n Doit recevoir 2 arguments uniquement", -1));
	mlx_struct_init(&mlx, av);
	if (mlx.close == 1)
		return (-1);
	tarte(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.lon, mlx.lar, "so_long");
	sprint_map(&mlx, 0, 0);
	mlx_hook(mlx.win, 2, 1L << 0, keep_rest, &mlx);
	mlx_loop_hook(mlx.mlx, loopy_loop, &mlx);
	mlx_hook(mlx.win, 33, 1L << 17, close_it, &mlx);
	mlx_loop(mlx.mlx);
	mlx_loop_end(mlx.mlx);
	free(mlx.mlx);
	return (0);
}
