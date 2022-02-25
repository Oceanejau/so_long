#include "so_long.h"


/*void	showtab(t_mlx *mlx)
{
	int y;
	int x;
        y = 0;
	printf("TAB =============\n");
    while (y < mlx->len_y)
    {
	x = 0;
		while (x < mlx->len_x)
         	{
		 	printf("%d ", mlx->ber[y][x]);
			x++;
		}
	printf("\n");
            y++;
    }
	printf("=========== fin du TAB \n");
	return ;
}*/

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	line_to_tab(int **tab, t_mlx *mlx, char *line)
{
	int	x;
	
	x = 0;
	while (x < mlx->len_x)
	{
	//	printf("line  x = %d, c= %c\n", x, line[x]);
		if (line[x] == '0')
			tab[mlx->len_y][x] = 3;
		else if (line[x] == '1')
		{
	//	printf("entre %d, %d\n", mlx->len_y, tab[mlx->len_y][x]);
			tab[mlx->len_y][x] = 1;
		//	printf("entre %d, %d\n", mlx->len_y, tab[mlx->len_y][x]);
	//	printf("sort\n");
		}
		else if (line[x] == 'C')
			tab[mlx->len_y][x] = 67;
		else if (line[x] == 'P')
		{
			if (mlx->P_x != -1)//si c'est diff de -1 il y a deja été déclaré donc pb
				return (-1);
			mlx->P_x = x;
			mlx->P_y = mlx->len_y;
			tab[mlx->len_y][x] = 80;
		}
		else if (line[x] == 'E')
		{
			if (mlx->E_x != -1)
				return (-1);
			mlx->E_x = x;
			mlx->E_y = mlx->len_y;
			tab[mlx->len_y][x] = 69;
		}
	//	printf("x++, %s, %d\n", line, x);
		x++;
	//	printf("%d\n", x);
	}
	mlx->ber = tab;
//	showtab(tab, &*mlx);
//	printf("ber = \n");
//	showtab(mlx->ber, &*mlx);	
//	printf("ber= %d\n", mlx->ber[0][0]);
	return (1);
}

void	copy_tab(int **tab, t_mlx *mlx, char *line)
{
	int	x;
	int	y;
//	int	err;

//	x = 0;
	y = 0;
	while (y < mlx->len_y)
	{
	//	printf("debut copy\n");
		x = 0;
		while (x < mlx->len_x)
		{
			tab[y][x] = mlx->ber[y][x];
	//		printf("%d ", tab[y][x]);
			x++;
		}
//		printf(".%d.'%s' %d\n", y, line, mlx->len_y);
		y++;
	}
//	printf("go dans line_to_tab\n");
	mlx->error_map_ber = line_to_tab(tab, &*mlx, line);
//	printf("ber suite = %d\n", mlx->ber[0][0]);
//	showtab(&*mlx);
	return;
}

int	free_tab(int **tab, int	y, int ret)
{
	int	z;

	z = 0;
	while (z < y)
	{
		free(tab[z]);
		z++;
	}
	free(tab);
	return (ret);
}

int	create_tab(char	*line, t_mlx *mlx, int y)
{
//	int	x;
	int	z;
	int	**tab;

//	printf("entre dans create tab\n");
	tab = NULL;
	z = 0;
	mlx->len_x = ft_strlen(line);
	mlx->len_y = y;
	if (mlx->len == -1)
		mlx->len = mlx->len_x;
//	printf("len = %d &  len_x = %d\n", mlx->len, mlx->len_x);
	if (mlx->gnl == 0)
		return(free_tab(tab, y, 0));
	if (mlx->len_x != mlx->len)
	{	
//	printf("passedans len_x %d, len =%d, '%s'\n", mlx->len_x, mlx->len, line);
		mlx->err_len = -1;
		return (free_tab(tab, y, -1));
	}
	tab = (int **)malloc(sizeof(int *) * (mlx->len_y + 1));
	if (!tab)
		return (free_tab(tab, y, -1));
	while (z <= mlx->len_y)
	{
	//	printf("passe dans le malloc\n");
		tab[z] = (int *)malloc(sizeof(int) * (mlx->len_x + 1));
		if (!tab[z])
			return (free_tab(tab, y, -1));
		z++;
	}
//	printf("go dans copy%d\n", mlx->len_x);
	copy_tab(tab, &*mlx, line);
//	printf("%d BER \n", mlx->ber[0][0]);
	return (0);
}
