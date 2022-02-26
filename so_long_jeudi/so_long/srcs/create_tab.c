/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 06:26:52 by ojauregu          #+#    #+#             */
/*   Updated: 2022/02/26 10:53:02 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	line_to_tab(int **tab, t_mlx *mlx, char *line)
{
	int	x;

	x = 0;
	while (x < mlx->len_x)
	{
		if (line[x] == '0')
			tab[mlx->len_y][x] = 3;
		else if (line[x] == '1')
		{
			tab[mlx->len_y][x] = 1;
		}
		else if (line[x] == 'C')
			tab[mlx->len_y][x] = 67;
		else if (line[x] == 'P' || line[x] == 'E')
			tab[mlx->len_y][x] = p_et_e(&*mlx, line[x], x, mlx->len_y);
		else
			mlx->err_char = -1;
		x++;
	}
	if (mlx->ber)
		free_tab(mlx->ber, mlx->len_y, 0);
	mlx->ber = tab;
	return (1);
}

void	copy_tab(int **tab, t_mlx *mlx, char *line)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->len_y)
	{
		x = 0;
		while (x < mlx->len_x)
		{
			tab[y][x] = mlx->ber[y][x];
			x++;
		}
		y++;
	}
	mlx->error_map_ber = line_to_tab(tab, &*mlx, line);
	return ;
}

int	free_tab(int **tab, int y, int ret)
{
	int	z;

	z = 0;
	while (z < y && tab && tab[z])
	{
		free(tab[z]);
		z++;
	}
	if (tab)
		free(tab);
	return (ret);
}

int	starter(t_mlx *mlx, int y, int **tab, char *line)
{
	int	z;

	z = 0;
	tab = (int **)malloc(sizeof(int *) * (mlx->len_y + 1));
	if (!tab)
		return (-1);
	while (z <= mlx->len_y)
	{
		tab[z] = (int *)malloc(sizeof(int) * (mlx->len_x + 1));
		if (!tab[z])
			return (free_tab(tab, y, -1));
		z++;
	}
	copy_tab(tab, &*mlx, line);
	if (mlx->error_map_ber == -1)
		return (free_tab(tab, y, -1));
	return (0);
}

int	create_tab(char	*line, t_mlx *mlx, int y)
{
	int	**tab;

	tab = NULL;
	mlx->len_x = ft_strlen(line);
	mlx->len_y = y;
	if (mlx->len == -1)
		mlx->len = mlx->len_x;
	if (mlx->gnl == 0)
		return (free_tab(tab, y, 0));
	if (mlx->len_x != mlx->len)
	{	
		mlx->err_len = -1;
		return (free_tab(tab, y, -1));
	}
	mlx->err_tab = starter(&*mlx, y, tab, line);
	return (0);
}
