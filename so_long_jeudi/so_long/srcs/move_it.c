/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:44:10 by ojauregu          #+#    #+#             */
/*   Updated: 2022/02/25 19:53:57 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	move_char_left(t_mlx *mlx, int x, int y)//Bleu A
{
	if (mlx->ber[mlx->cot_y][mlx->cot_x - 1] >= 3)
	{
		if (mlx->ber[mlx->cot_y][mlx->cot_x - 1] == 69)//nid
		{	mlx->ber[mlx->cot_y][mlx->cot_x] = 3;//vide?
			mlx->ber[mlx->cot_y][mlx->cot_x - 1] = 81;//nid+poule
			printf("poule dans le nid A\n");
		}
		else if (mlx->ber[mlx->cot_y][mlx->cot_x] == 81)
		{	
			mlx->ber[mlx->cot_y][mlx->cot_x] = 69;//vide?
			mlx->ber[mlx->cot_y][mlx->cot_x - 1] = 80;//vi
		}
		else if (mlx->ber[mlx->cot_y][mlx->cot_x - 1] >= 3)// si c'est pas un arbre il avance
		{	mlx->ber[mlx->cot_y][mlx->cot_x] = 3;//vide?
			mlx->ber[mlx->cot_y][mlx->cot_x - 1] = 80;//vide?
		}
		mercotte(&*mlx);
		sprint_map(&*mlx);
		mlx->addr = mlx_get_data_addr(mlx->sol, &mlx->bits_per_pixy, &mlx->line_length, &mlx->endian);//endian trie les bits
		mlx->offset = (mlx->y * mlx->line_length + mlx->x * (mlx->bits_per_pixy / 8));
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cot, x, y);
		mlx->count++;//compte les mouvements
		ft_putnbr(mlx->count);//afficher count
		ft_putchar('\n');

	}
}

void	move_char_right(t_mlx *mlx, int x, int y)//fushia D
{
	if (mlx->ber[mlx->cot_y][mlx->cot_x + 1] >= 3)
	{
		if (mlx->ber[mlx->cot_y][mlx->cot_x + 1] == 69)//nid
		{	mlx->ber[mlx->cot_y][mlx->cot_x] = 3;//vide?
			mlx->ber[mlx->cot_y][mlx->cot_x + 1] = 81;//nid+poule
		}
		else if (mlx->ber[mlx->cot_y][mlx->cot_x] == 81)
		{	
			mlx->ber[mlx->cot_y][mlx->cot_x] = 69;//vide?
			mlx->ber[mlx->cot_y][mlx->cot_x + 1] = 80;//vi
		}
		else if (mlx->ber[mlx->cot_y][mlx->cot_x + 1] >= 3)// si c'est pas un arbre il avance
		{	mlx->ber[mlx->cot_y][mlx->cot_x] = 3;//vide?
			mlx->ber[mlx->cot_y][mlx->cot_x + 1] = 80;//vide?
		}
		mercotte(&*mlx);
		sprint_map(&*mlx);
		mlx->addr = mlx_get_data_addr(mlx->sol, &mlx->bits_per_pixy, &mlx->line_length, &mlx->endian);//endian trie les bits
		mlx->offset = (mlx->y * mlx->line_length + mlx->x * (mlx->bits_per_pixy / 8));
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cot, x, y);
		mlx->count++;//compte les mouvements
		ft_putnbr(mlx->count);//afficher count
		ft_putchar('\n');

	}
}

void	move_char_bot(t_mlx *mlx, int x, int y)//bot S aqua
{
	if (mlx->ber[mlx->cot_y + 1][mlx->cot_x] >= 3)
	{
		if (mlx->ber[mlx->cot_y + 1][mlx->cot_x] == 69)//nid
		{	mlx->ber[mlx->cot_y][mlx->cot_x] = 3;//vide?
			mlx->ber[mlx->cot_y + 1][mlx->cot_x] = 81;//nid+poule
		}
		else if (mlx->ber[mlx->cot_y][mlx->cot_x] == 81)
		{	
			mlx->ber[mlx->cot_y][mlx->cot_x] = 69;//vide?
			mlx->ber[mlx->cot_y + 1][mlx->cot_x] = 80;//vi
		}
		else if (mlx->ber[mlx->cot_y + 1][mlx->cot_x] >= 3)// si c'est pas un arbre il avance
		{	mlx->ber[mlx->cot_y][mlx->cot_x] = 3;//vide?
			mlx->ber[mlx->cot_y + 1][mlx->cot_x] = 80;//vide?
		}
		mercotte(&*mlx);
		sprint_map(&*mlx);
		mlx->addr = mlx_get_data_addr(mlx->sol, &mlx->bits_per_pixy, &mlx->line_length, &mlx->endian);//endian trie les bits
		mlx->offset = (mlx->y * mlx->line_length + mlx->x * (mlx->bits_per_pixy / 8));
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cot, x, y);
		mlx->count++;//compte les mouvements
		ft_putnbr(mlx->count);//afficher count
		ft_putchar('\n');
	}
}

void	move_char_top(t_mlx *mlx, int x, int y)//vert W lime
{
	if (mlx->ber[mlx->cot_y - 1][mlx->cot_x] >= 3)
	{
		if (mlx->ber[mlx->cot_y - 1][mlx->cot_x] == 69)//nid
		{	mlx->ber[mlx->cot_y][mlx->cot_x] = 3;//vide?
			mlx->ber[mlx->cot_y - 1][mlx->cot_x] = 81;//nid+poule
		}
		else if (mlx->ber[mlx->cot_y][mlx->cot_x] == 81)
		{	
			mlx->ber[mlx->cot_y][mlx->cot_x] = 69;//vide?
			mlx->ber[mlx->cot_y - 1][mlx->cot_x] = 80;//vi
		}
		else if (mlx->ber[mlx->cot_y - 1][mlx->cot_x] >= 3)// si c'est pas un arbre il avance
		{	mlx->ber[mlx->cot_y][mlx->cot_x] = 3;//vide?
			mlx->ber[mlx->cot_y - 1][mlx->cot_x] = 80;//vide?
		}
		mercotte(&*mlx);
		sprint_map(&*mlx);
		mlx->addr = mlx_get_data_addr(mlx->sol, &mlx->bits_per_pixy, &mlx->line_length, &mlx->endian);//endian trie les bits
		mlx->offset = (mlx->y * mlx->line_length + mlx->x * (mlx->bits_per_pixy / 8));
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cot, x, y);
		mlx->count++;//compte les mouvements
		ft_putnbr(mlx->count);//afficher count
		ft_putchar('\n');

	}
}

