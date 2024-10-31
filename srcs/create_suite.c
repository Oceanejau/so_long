/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_suite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 06:43:22 by ojauregu          #+#    #+#             */
/*   Updated: 2022/02/26 07:18:59 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	p_et_e(t_mlx *mlx, char c, int x, int y)
{
	if (c == 'P')
	{
		mlx->p_x = x;
		mlx->p_y = y;
		return (80);
	}
	else if (c == 'E')
	{
		mlx->e_x = x;
		mlx->e_y = y;
		return (69);
	}
	return (-1);
}
