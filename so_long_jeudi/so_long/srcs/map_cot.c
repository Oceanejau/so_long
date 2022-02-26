/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 07:52:36 by ojauregu          #+#    #+#             */
/*   Updated: 2022/02/26 07:53:29 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	cot(t_mlx *mlx, int y, int x)
{
	void	*tmp;

	if (mlx->cot)
		mlx_destroy_image(mlx->mlx, mlx->cot);
	mlx->cot = ft_strjoin(mlx->path, "cot50.xpm");
	mlx->cot_y = y;
	mlx->cot_x = x;
	tmp = mlx->cot;
	mlx->cot = mlx_xpm_file_to_image(mlx->mlx, mlx->cot, &mlx->img_width,
			&mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cot, (mlx->cot_x * 50),
		(mlx->cot_y * 50));
	free(tmp);
	return ;
}

void	cot_fin(t_mlx *mlx, int y, int x)
{
	void	*tmp;

	if (mlx->cot)
		mlx_destroy_image(mlx->mlx, mlx->cot);
	mlx->cot = ft_strjoin(mlx->path, "nid_cot50.xpm");
	mlx->cot_y = y;
	mlx->cot_x = x;
	tmp = mlx->cot;
	mlx->cot = mlx_xpm_file_to_image(mlx->mlx, mlx->cot, &mlx->img_width,
			&mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cot, (mlx->cot_x * 50),
		(mlx->cot_y * 50));
	free(tmp);
	return ;
}

void	exi(t_mlx *mlx, int y, int x)
{
	void	*tmp;

	if (mlx->nid)
		mlx_destroy_image(mlx->mlx, mlx->nid);
	mlx->nid = ft_strjoin(mlx->path, "nid50.xpm");
	tmp = mlx->nid;
	mlx->nid = mlx_xpm_file_to_image(mlx->mlx, mlx->nid, &mlx->img_width,
			&mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->nid, (x + mlx->x),
		(y + mlx->y));
	free(tmp);
	return ;
}
