/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:30:34 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/16 18:30:41 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	fox(t_mlx *mlx, int y, int x)
{
	void	*tmp;

	if (mlx->fox)
		mlx_destroy_image(mlx->mlx, mlx->fox);
	mlx->fox = ft_strjoin(mlx->path, "fox50.xpm");
	tmp = mlx->fox;
	mlx->fox = mlx_xpm_file_to_image(mlx->mlx, mlx->fox, &mlx->img_width,
			&mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->fox, (x + mlx->x),
		(y + mlx->y));
	free(tmp);
	return ;
}

void	vide(t_mlx *mlx, int y, int x)
{
	void	*tmp;

	if (mlx->sol)
		mlx_destroy_image(mlx->mlx, mlx->sol);
	mlx->sol = ft_strjoin(mlx->path, "grass50.xpm");
	tmp = mlx->sol;
	mlx->sol = mlx_xpm_file_to_image(mlx->mlx, mlx->sol, &mlx->img_width,
			&mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sol, (x + mlx->x),
		(y + mlx->y));
	free(tmp);
	return ;
}

void	mur(t_mlx *mlx, int y, int x)
{
	void	*tmp;

	if (mlx->mur)
		mlx_destroy_image(mlx->mlx, mlx->mur);
	mlx->mur = ft_strjoin(mlx->path, "tree50.xpm");
	tmp = mlx->mur;
	mlx->mur = mlx_xpm_file_to_image(mlx->mlx, mlx->mur, &mlx->img_width,
			&mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->mur, (x + mlx->x),
		(y + mlx->y));
	free(tmp);
	return ;
}

void	obs(t_mlx *mlx, int y, int x)
{
	void	*tmp;

	if (mlx->obs)
		mlx_destroy_image(mlx->mlx, mlx->obs);
	mlx->obs = ft_strjoin(mlx->path, "buche50.xpm");
	tmp = mlx->obs;
	mlx->obs = mlx_xpm_file_to_image(mlx->mlx, mlx->obs, &mlx->img_width,
			&mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->obs, (x + mlx->x),
		(y + mlx->y));
	free(tmp);
	return ;
}

void	collect(t_mlx *mlx, int y, int x)
{
	void	*tmp;

	if (mlx->sun)
		mlx_destroy_image(mlx->mlx, mlx->sun);
	mlx->sun = ft_strjoin("", "./images/cold/sun50.xpm");
	tmp = mlx->sun;
	mlx->sun = mlx_xpm_file_to_image(mlx->mlx, mlx->sun, &mlx->img_width,
			&mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sun, (x + mlx->x),
		(y + mlx->y));
	free(tmp);
	return ;
}
