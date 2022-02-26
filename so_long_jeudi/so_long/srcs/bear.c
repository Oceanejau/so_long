/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bear.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 06:46:28 by ojauregu          #+#    #+#             */
/*   Updated: 2022/02/26 11:11:21 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	bear_me(t_mlx *mlx)
{
	mapy(&*mlx);
	mur_test(&*mlx);
	if (mlx->err_len == -1)
		err_cl(&*mlx, "Toutes les lignes de la map ne sont pas égales.");
	else if (mlx->err_mur == -1)
		err_cl(&*mlx, "Problème dans les murs de la map.");
	else if (mlx->err_cot == 0)
		err_cl(&*mlx, "Pas de joueur sur la map.");
	else if (mlx->err_col == 0)
		err_cl(&*mlx, "Pas de collectible sur la map.");
	else if (mlx->err_cot > 1)
		err_cl(&*mlx, "Trop de joueur sur la map.");
	else if (mlx->err_nid == 0)
		err_cl(&*mlx, "Pas de sorties sur la map.");
	else if (mlx->err_nid > 1)
		err_cl(&*mlx, "Trop de sorties sur la map.");
	else if (mlx->err_img == -1)
		err_cl(&*mlx, "");
	else if (mlx->error_map_ber == -1)
		err_cl(&*mlx, "Probleme de map.");
	return ;
}

void	check_suite(t_mlx *mlx, int y, char *line, char *nom)
{
	mlx->error_map_ber = 0;
	mlx->fd = open(nom, O_RDONLY);
	if (mlx->fd == -1)
	{
		err_cl(&*mlx, "N'a pas pu lire le fichier .");
		mlx->close = 1;
		return ;
	}
	while (mlx->gnl == 1 && mlx->err_tab != -1)
	{
		mlx->gnl = get_next_line(mlx->fd, &line);
		if (mlx->gnl < 0)
			return ;
		mlx->err_tab = create_tab(line, &*mlx, y);
		free(line);
		y++;
	}
	return ;
}

void	check_the_bear(char *nom, t_mlx *mlx, int x, int y)
{
	char	*line;

	line = NULL;
	while (nom[x] != '\0')
		x++;
	if (nom[x - 4] == '.' && nom[x - 3] == 'b' && nom[x - 2] == 'e'
		&& nom[x - 1] == 'r')
		check_suite(&*mlx, y, line, nom);
	else
	{
		mlx->error_map_ber = -1;
		err_cl(&*mlx, "La map doit être de type map.ber.");
		return ;
	}
	if (mlx->close == 1)
		return ;
	mlx->len_x = mlx->len;
	if (mlx->err_char == -1)
	{
		err_cl(&*mlx, "Chars autorises: 0 1 E P C.");
		return ;
	}
	bear_me(&*mlx);
	return ;
}
