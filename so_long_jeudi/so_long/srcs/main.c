#include "so_long.h"

int	close_it(t_mlx *mlx)
{
	int	y;

	y = 0;
	mlx->close++;
	mlx->close = 1;
	free(mlx->path);
	mlx_destroy_image(mlx->mlx, mlx->cot);
	mlx_destroy_image(mlx->mlx, mlx->sun);
	mlx_destroy_image(mlx->mlx, mlx->sol);
	mlx_destroy_image(mlx->mlx, mlx->obs);
	mlx_destroy_image(mlx->mlx, mlx->nid);
	mlx_destroy_image(mlx->mlx, mlx->mur);
	while (y < mlx->len_y)
	{
		free(mlx->ber[y]);
		y++;
	}
	free(mlx->ber);
	mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}

void	obsy(t_mlx *mlx)
{
	int x;
	int y;

	y = 1;
	while (y < mlx->len_y - 1)
	{
		x = 1;
		while (x < mlx->len_x - 1)
		{
			if (mlx->ber[y][x] == 1)
				mlx->ber[y][x] = 2;
			x++;
		}
		y++;
	}
	return ;
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
	if (!(str = (char *)malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

void	mercotte(t_mlx *mlx, int y)
{
	int	x;

	mlx->col = 0;
	while (y < mlx->len_y)
	{
		x = 0;
		while (x < mlx->len_x)
		{
		if (mlx->ber[y][x] >= 80)
			{
				mlx->cot_x = x;
				mlx->x = x;
				mlx->y = y;
				mlx->cot_y = y;
			}
			if (mlx->ber[y][x] == 67)
				mlx->col++;
			x++;
		}
		y++;
	}
	if (mlx->col == 0)
	{
		free(mlx->path);
		mlx->path = ft_strjoin("", "./images/50/");
	}
	return ;
}

void	mapy(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->len_y)
	{
		x = 0;
		while (x < mlx->len_x)
		{
			if (mlx->ber[y][x] == 80)
				mlx->err_cot++;
			if (mlx->ber[y][x] == 67)
				mlx->err_col++;
			if (mlx->ber[y][x] == 69)
				mlx->err_nid++;
			x++;
		}
		y++;
	}
	return ;
}

void	mur_test(t_mlx *mlx)
{
	int	x;

	x = 0;
	while (x < mlx->len_x && mlx->err_mur == 0)
	{
		if (mlx->ber[0][x] != 1 || mlx->ber[mlx->len_y - 1][x] != 1)
			mlx->err_mur = -1;
		x++;
	}
	x = 0;
	while (x < mlx->len_y && mlx->err_mur == 0)
	{
		if (mlx->ber[x][0] != 1 || mlx->ber[x][mlx->len_x - 1] != 1)
			mlx->err_mur = -1;
		x++;
	}
	return ;
}

int	err_cl(t_mlx *mlx, char *str)
{
	write(2, "Error:\n ", 9);
	write(2, str, ft_strlen(str));
	ft_putchar('\n');
	/*if (mlx->err_tab == -1)
		free(mlx->ber);
	mlx->close = 1;
	return (-1);*/
	if (mlx->err_tab == -1 || mlx->err_mur == -1 || mlx->err_len == -1
		|| mlx->err_cot != 1 || mlx->err_col == 0 || mlx->err_nid != 1
		|| mlx->mlx == NULL)
		mlx->close = free_tab(mlx->ber, mlx->len_y, 1);
	mlx->close = 1;
	free(mlx->path);
	return (-1);

}
/*
void	bear_me(t_mlx *mlx)
{
printf("passe dans bear me\n");
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
	return;
}

void	check_the_bear(char *nom, t_mlx *mlx)
{
	char	*line;
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (nom[x] != '\0')
		x++;
	if (nom[x - 4] == '.' && nom[x - 3] == 'b' && nom[x - 2] == 'e'
		&& nom[x - 1] == 'r')
	{
		mlx->error_map_ber = 0;
		mlx->fd = open(nom, O_RDONLY);
		if (mlx->fd == -1)
		{
			err_cl(&*mlx, "N'a pas pu lire le fichier .");
			return;
		}
		while (mlx->gnl == 1 && mlx->err_tab != -1)
		{
			mlx->gnl = get_next_line(mlx->fd , &line);
			mlx->err_tab = create_tab(line, &*mlx, y);
			free(line);
			y++;
		}
	}
	else
	{
		mlx->error_map_ber = -1;
		err_cl(&*mlx, "La map doit être de type map.ber.");
		return;
	}
	mlx->len_x = mlx->len;
	printf("sort de check bear\n");
	bear_me(&*mlx);
	return ;
}
*/
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
	return (0);
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
	return;
}

void	sprint_map(t_mlx *mlx)
{
	int	x;
	int	y;
	x = 0;
	y = 0;
	mlx->y = 0;
	if (mlx->count > 1 && (mlx->mur == NULL || mlx->sol == NULL
		|| mlx->obs == NULL || mlx->cot == NULL || mlx->sun == NULL))
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
			mlx->x =  mlx->x + mlx->img_width - 1;
			x++;
		}
		mlx->y = mlx->y + (mlx->img_height - 1);
		y++;
	}
	return;
}

void	mlx_struct_init(t_mlx *mlx, char **av)
{
	mlx->end_loop = 0;
	mlx->count = 0;
	mlx->err_mur = 0;
	mlx->err_cot = 0;
	mlx->err_nid = 0;
	mlx->err_len = 0;
	mlx->err_tab = 0;
	mlx->err_col = 0;
	mlx->close = 0;
	mlx->gnl = 1;
	mlx->len = -1;
	mlx_struct_suite(&*mlx, av);
	return ;
}

void	mlx_struct_suite(t_mlx *mlx, char **av)
{
	mlx->p_x = -1;
	mlx->e_x = -1;
	mlx->y = 0;
	mlx->x = 0;
	mlx->err_img = 0;
	mlx->path = ft_strjoin("", "./images/cold/");
	mlx->ber = NULL;
	mlx->cot = NULL;
	mlx->sol = NULL;
	mlx->mur = NULL;
	mlx->obs = NULL;
	mlx->sun = NULL;
	mlx->nid = NULL;
//	if (ac != 2)
//		return (err("Error:\n Doit recevoir 2 arguments uniquement", -1));
	check_the_bear(av[1], &*mlx, 0, 0);
	return ;
}
void	tarte(t_mlx *mlx)
{
	obsy(&*mlx);//mets les obstacles en 2(buche) et non en 1(arbre)
	mlx->lon = 50 * mlx->len_x;//50 = taille des images en pixels
	mlx->lar = 50 * mlx->len_y;
	return ;
}

int	loopy_loop(t_mlx *mlx)
{
	if (mlx->close == 0)
	{
		if (mlx->ber[mlx->cot_y][mlx->cot_x] == 81 && mlx->col == 0)
		{

			close_it(mlx);
			return (-1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	mlx_struct_init(&mlx, av);
	if (ac != 2)
		return (err("Error:\n Doit recevoir 2 arguments uniquement", -1));
//	check_the_bear(av[1], &mlx);
	if (mlx.close == 1)
		return (-1);
	tarte(&mlx);
//	obsy(&mlx);//mets les obstacles en 2(buche) et non en 1(arbre)
//	mlx.lon = 50 * mlx.len_x;//50 = taille des images en pixels
//	mlx.lar = 50 * mlx.len_y;
	mlx.mlx = mlx_init();// return Xvar
	mlx.win = mlx_new_window(mlx.mlx, mlx.lon, mlx.lar, "so_long");//size en pixels
	sprint_map(&mlx);
	mlx_hook(mlx.win, 2, 1L<<0, keep_rest, &mlx);//deplace le personnage
	mlx_loop_hook(mlx.mlx, loopy_loop, &mlx);
	mlx_hook(mlx.win, 33, 1L<<17, close_it, &mlx);
	mlx_loop(mlx.mlx);
	mlx_loop_end(mlx.mlx);
	free(mlx.mlx);
	return (0);
}
