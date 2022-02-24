//#include "so_long.h"

#include <unistd.h>
#include <stdio.h>
int	err(/*t_mlx *mlx, */int err_nb)
{
	if (err_nb == -1)
	{
	//	printf("go\n");
		write(2, "   Error :\nWrong number of arguments.\n", 38);
		return (-1);
	}
	return (-1);
}


int     *check_the_bear(char *nom_map, t_mlx *mlx)
{
        char    *line;
        int     y;
        int     x;

        x = 0;
        mlx->gnl = 1;
        y = 0;
        while (nom_map[x] != '\0')
                x++;
        if (nom_map[x - 4] == '.' && nom_map[x - 3] == 'b' && nom_map[x - 2] == 'e' && nom_map[x - 1] == 'r')
        {
                mlx->error_map_ber = 0;
                mlx->fd = open(nom_map, O_RDONLY);
                if (so->fd == -1)
                        return;//Error : failed reading the file
                while (mlx->gnl == 1)
                {
                        mlx->gnl = get_next_line(mlx->fd , &line);
                        copy_map(&line, &*mlx, y++);//mappy est un int**
                }
        }
        else
	{
                mlx->error_map_ber = -1;// Error : map must be of type map.ber
		return (-1);
	}
        return (0);//renvoie le tableau de la map dans la mlx->ber
}

int	main(int ac, char *av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (err(/*mlx, */-1));
	init_mlx(&mlx);//a faire
	check_the_bear(av[1], &mlx);
	if (mlx->error_map_ber == -1)
		err("   Error: map is wrong", 0);
	return (0);
}
