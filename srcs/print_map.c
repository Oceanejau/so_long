/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 07:58:03 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/16 18:48:04 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	iff(t_mlx *mlx, int x, int y)
{
	if (mlx->ber[y][x] == 3)
		vide(&*mlx, y, x);
	else if (mlx->ber[y][x] == 1)
		mur(&*mlx, y, x);
	else if (mlx->ber[y][x] == 2)
		obs(&*mlx, y, x);
	else if (mlx->ber[y][x] == 67)
		collect(&*mlx, y, x);
	else if (mlx->ber[y][x] == 69)
		exi(&*mlx, y, x);
	else if (mlx->ber[y][x] == 80)
		cot(&*mlx, y, x);
	else if (mlx->ber[y][x] == 81)
		cot_fin(&*mlx, y, x);
	mlx->x = mlx->x + mlx->img_width - 1;
	return ;
}

void	sprint_map(t_mlx *mlx, int y, int x)
{
	mlx->y = 0;
	if (mlx->count > 1 && (mlx->mur == NULL || mlx->sol == NULL
			|| mlx->cot == NULL || mlx->sun == NULL || (mlx->obsy == 1
				&& mlx->obs == NULL)))
	{
		mlx->err_img = -1;
		err_cl(&*mlx, "Ne parvient pas à récupérer les images.");
	}
	while (y < mlx->len_y)
	{
		mlx->x = 0;
		x = 0;
		while (x < mlx->len_x)
		{
			iff(&*mlx, x, y);
			x++;
		}
		mlx->y = mlx->y + (mlx->img_height - 1);
		y++;
	}
	return ;
}

int	keep_rest(int keycode, t_mlx *mlx)
{
	mercotte(&*mlx, 0);
	if (keycode == ESC)
	{
		close_it(&*mlx);
		return (0);
	}
	else if (keycode == A)
		move_char_left(&*mlx, 50 * mlx->cot_x, 50 * mlx->cot_y);
	else if (keycode == W)
		move_char_top(&*mlx, 50 * mlx->cot_x, 50 * mlx->cot_y);
	else if (keycode == S)
		move_char_bot(&*mlx, 50 * mlx->cot_x, 50 * mlx->cot_y);
	else if (keycode == D)
		move_char_right(&*mlx, 50 * mlx->cot_x, 50 * mlx->cot_y);
	else
		return (0);
	if (mlx->close == 1)
	{
		close_it(&*mlx);
		return (0);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
