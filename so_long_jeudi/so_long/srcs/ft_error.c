/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:41:27 by ojauregu          #+#    #+#             */
/*   Updated: 2022/02/25 19:55:55 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	err(char *str, int x)
{
	write(2, str, ft_strlen(str));
	ft_putchar('\n');
	//	free(mlx->ber);
	//	mlx_destroy_window(mlx->mlx, mlx->win);
	//	mlx->close = 1;

	return (x);
}

