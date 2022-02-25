#include "so_long.h"

int	close_it(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx->close = 1;
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
	return;
}

void	mercotte(t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	mlx->col = 0;
	while (y < mlx->len_y)
	{
		x = 0;
		while (x < mlx->len_x)
		{
				printf("passe dans mercotte %d\n", mlx->ber[y][x]);
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
	//	printf("mlx->cot_x %d, %d, collectibles = %d\n", mlx->cot_x, mlx->cot_y, mlx->col);
	return;
}

void	mapy(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	printf("len x =%d len y =%d\n", mlx->len_x, mlx->len_y);
	while (y < mlx->len_y)
	{
	printf("passe\n");
		x = 0;
		while (x < mlx->len_x)
		{
printf("non\n");
		printf("x = %d, y = %d\n", x, y);
			if (mlx->ber[y][x] == 80)
				mlx->err_cot++;
			if (mlx->ber[y][x] == 67)
				mlx->err_col++;//si on ne met pas mercotte avant
			if (mlx->ber[y][x] == 69)
				mlx->err_nid++;
//printf("x = %d, y = %d", x, y);
			x++;

		}
		y++;
	}
	return;
}

void	mur_test(t_mlx *mlx)
{
	int	x;

	x = 0;
	//	printf("len y  =%d x = %d\n", mlx->len_y, mlx->len_x);
	while (x < mlx->len_x && mlx->err_mur == 0)
	{
		printf("%d\n", mlx->ber[0][x]);
		if (mlx->ber[0][x] != 1 || mlx->ber[mlx->len_y - 1][x] != 1)
			mlx->err_mur = -1;
		x++;
	}
	//	printf("fin de x\n");
	x = 0;
	while (x < mlx->len_y && mlx->err_mur == 0)
	{

		//printf("%d, %d\n", mlx->ber[x][0], mlx->err_mur);
		if (mlx->ber[x][0] != 1 || mlx->ber[x][mlx->len_x - 1] != 1)
			mlx->err_mur = -1;
		x++;

	}
	printf("mur = %d\n", mlx->err_mur);
	return;
}

int	err_cl(t_mlx *mlx, char *str)
{
	write(2, "Error:\n ", 9);
	write(2, str, ft_strlen(str));
	ft_putchar('\n');
	if (mlx->err_tab == -1)
	{	printf("je free ici\n");
	//	while (mlx->len_y != 0)
	//	{
			free(mlx->ber/*[mlx->len_y]*/);
	//		mlx->len_y--;
	//	}
	}
	//	mlx_destroy_window(mlx->mlx, mlx->win);
	//	free(mlx->mur);
	//	free(mlx->cot);
	//	free(mlx->sun);
	//	free(mlx->sol);
	//	free(mlx->nid);
	//	free(mlx->obs);
	//	free(mlx->cot);
	mlx->close = 1;
	return (-1);
}

void	bear_me(t_mlx *mlx)
{

	mapy(&*mlx);
	mur_test(&*mlx);

	printf("%d\n", mlx->err_tab);
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
//	printf("%d\n", mlx->err_nid);
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
	if (nom[x - 4] == '.' && nom[x - 3] == 'b' && nom[x - 2] == 'e' && nom[x - 1] == 'r')
	{
		mlx->error_map_ber = 0;
		mlx->fd = open(nom, O_RDONLY);
		if (mlx->fd == -1)
		{
			err_cl(&*mlx, "N'a pas pu lire le fichier .");//Error : failed reading the file
			return;
		}
		while (mlx->gnl == 1 && mlx->err_tab != -1)
		{
			mlx->gnl = get_next_line(mlx->fd , &line);
			mlx->err_tab = create_tab(line, &*mlx, y);
	//	printf("mlx->error_tab = %d, gnl = %d\n", mlx->err_tab, mlx->gnl);
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
	showtab(&*mlx);
	bear_me(&*mlx);
	return;
}

void	move_char_left(t_mlx *mlx)//Bleu A
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
		//		showtab(&*mlx);
		mlx->addr = mlx_get_data_addr(mlx->sol, &mlx->bits_per_pixy, &mlx->line_length, &mlx->endian);//endian trie les bits
		mlx->offset = (mlx->y * mlx->line_length + mlx->x * (mlx->bits_per_pixy / 8));
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cot, 50 * mlx->cot_x, 50 * mlx->cot_y);
		mlx->count++;//compte les mouvements
		ft_putnbr(mlx->count);//afficher count
		ft_putchar('\n');

	}
}

void	move_char_right(t_mlx *mlx)//fushia D
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
		//		showtab(&*mlx);
		mlx->addr = mlx_get_data_addr(mlx->sol, &mlx->bits_per_pixy, &mlx->line_length, &mlx->endian);//endian trie les bits
		mlx->offset = (mlx->y * mlx->line_length + mlx->x * (mlx->bits_per_pixy / 8));
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cot, 50 * mlx->cot_x, 50 * mlx->cot_y);
		mlx->count++;//compte les mouvements
		ft_putnbr(mlx->count);//afficher count
		ft_putchar('\n');

	}
}

void	move_char_bot(t_mlx *mlx)//bot S aqua
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
		//		showtab(&*mlx);
		mlx->addr = mlx_get_data_addr(mlx->sol, &mlx->bits_per_pixy, &mlx->line_length, &mlx->endian);//endian trie les bits
		mlx->offset = (mlx->y * mlx->line_length + mlx->x * (mlx->bits_per_pixy / 8));
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cot, 50 * mlx->cot_x, 50 * mlx->cot_y);
		mlx->count++;//compte les mouvements
		ft_putnbr(mlx->count);//afficher count
		ft_putchar('\n');
	}
}

void	move_char_top(t_mlx *mlx)//vert W lime
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
		//		showtab(&*mlx);
		mlx->addr = mlx_get_data_addr(mlx->sol, &mlx->bits_per_pixy, &mlx->line_length, &mlx->endian);//endian trie les bits
		mlx->offset = (mlx->y * mlx->line_length + mlx->x * (mlx->bits_per_pixy / 8));
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cot, 50 * mlx->cot_x, 50 * mlx->cot_y);
		mlx->count++;//compte les mouvements
		ft_putnbr(mlx->count);//afficher count
		ft_putchar('\n');

	}
}

int	keep_rest(int keycode, t_mlx *mlx)// key pressed
{
	//	printf("===================================================key pressed, %d\n", keycode);
	mercotte(&*mlx);
	if (keycode == ESC)//cette touche compte pour le décompte
	{
		//	printf("je me FERME, %d\n", keycode);
		close_it(&*mlx);
		return (0);
	}
	else if (keycode == A)
		move_char_left(&*mlx);
	else if (keycode == W)
		move_char_top(&*mlx);
	else if (keycode == S)
		move_char_bot(&*mlx);
	else if (keycode == D)
		move_char_right(&*mlx);
	else
		return (0);
	return (0);
}

void	vide(t_mlx *mlx, int y, int x)
{
	mlx->sol = "./images/50/grass50.xpm";
	mlx->sol = mlx_xpm_file_to_image(mlx->mlx, mlx->sol, &mlx->img_width, &mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sol, (x + mlx->x), (y + mlx->y));
	return;
}

void	mur(t_mlx *mlx, int y, int x)
{
	mlx->mur = "./images/50/tree50.xpm";
	mlx->mur = mlx_xpm_file_to_image(mlx->mlx, mlx->mur, &mlx->img_width, &mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->mur, (x + mlx->x), (y + mlx->y));
	return;
}

void	obs(t_mlx *mlx, int y, int x)
{
	mlx->obs = "./images/50/buche50.xpm";
	mlx->obs = mlx_xpm_file_to_image(mlx->mlx, mlx->obs, &mlx->img_width, &mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->obs, (x + mlx->x), (y + mlx->y));
	return;
}

void	collect(t_mlx *mlx, int y, int x)
{
	mlx->sun = "./images/50/sun50.xpm";
	mlx->sun = mlx_xpm_file_to_image(mlx->mlx, mlx->sun, &mlx->img_width, &mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sun, (x + mlx->x), (y + mlx->y));
	return;
}


void	cot(t_mlx *mlx, int y, int x)
{
	mlx->cot = "./images/50/cot50.xpm";
	mlx->cot_y = y;
	mlx->cot_x = x;
	mlx->cot = mlx_xpm_file_to_image(mlx->mlx, mlx->cot, &mlx->img_width, &mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cot, (mlx->cot_x * 50), (mlx->cot_y * 50));
	return;
}

void	cot_fin(t_mlx *mlx, int y, int x)
{
	mlx->cot = "./images/50/nid_cot50.xpm";
	mlx->cot_y = y;
	mlx->cot_x = x;
	mlx->cot = mlx_xpm_file_to_image(mlx->mlx, mlx->cot, &mlx->img_width, &mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cot, (mlx->cot_x * 50), (mlx->cot_y * 50));
	return;
}

void	exi(t_mlx *mlx, int y, int x)
{
	mlx->nid = "./images/50/nid50.xpm";
	mlx->nid = mlx_xpm_file_to_image(mlx->mlx, mlx->nid, &mlx->img_width, &mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->nid, (x + mlx->x), (y + mlx->y));
	return;
}

void	sprint_map(t_mlx *mlx)
{
	int	x;
	int	y;
	x = 0;
	y = 0;
	mlx->y = 0;
	if (mlx->mur == NULL || mlx->sol == NULL || mlx->obs == NULL || mlx->cot == NULL || mlx->sun == NULL)
		printf("i----------------------raté\n");
	while (y < mlx->len_y)
	{
		mlx->x = 0;
		x = 0;
		while (x < mlx->len_x)
		{
			if (mlx->ber[y][x] == 3)//vide
				vide(&*mlx, y, x);
			else if (mlx->ber[y][x] == 1)//mur
				mur(&*mlx, y, x);
			else if (mlx->ber[y][x] == 2)//obstacle
				obs(&*mlx, y, x);
			else if (mlx->ber[y][x] == 67)//Collectible
				collect(&*mlx, y, x);
			else if (mlx->ber[y][x] == 69)//Exit
				exi(&*mlx, y, x);
			else if (mlx->ber[y][x] == 80)//Personnage
				cot(&*mlx, y, x);
			else if (mlx->ber[y][x] == 81)//Personnage
				cot_fin(&*mlx, y, x);
			mlx->x =  mlx->x + mlx->img_width - 1;
			x++;
		}
		mlx->y = mlx->y + (mlx->img_height - 1);
		y++;
		//	printf("y = %d, %d\n", y, mlx->lar);
	}
	//	printf("fin d'affichage de la map\n");
	return;
}

void	mlx_struct_init(t_mlx *mlx)
{
	mlx->end_loop = 0;
	mlx->count = 0;
	mlx->err_mur = 0;
	mlx->err_cot = 0;
	mlx->err_nid = 0;
	mlx->err_tab = 0;
	mlx->close = 0;
	mlx->gnl = 1;
	mlx->len = -1;
	mlx->P_x = -1;
	mlx->E_x = -1;
	mlx->y = 0;
	mlx->x = 0;

	return;
}

int	loopy_loop(t_mlx *mlx)
{
	int	x;

	x = 0;
//	mercotte(&*mlx);
	printf("entre dans looooppy loooop\n");
	if (mlx->ber[mlx->cot_y][mlx->cot_x] == 81 && mlx->col == 0)
		{
			while (x < 50)
				x++;
			close_it(&*mlx);
		//	exit(0);
			mlx_loop_end(mlx->mlx);
			return (-1);
		}
	return (0);
}


int	err(char *str, int x)
{
	write(2, str, ft_strlen(str));
	ft_putchar('\n');
	//	free(mlx->ber);
	//	mlx_destroy_window(mlx->mlx, mlx->win);
	//	mlx->close = 1;

	return (x);
}

int	main(int ac, char **av)// pas de png utiliser xpm
{
	t_mlx	mlx;

	mlx_struct_init(&mlx);
	if (ac != 2)
		return (err("Error:\n Trop d'arguments.", -1));//Error : too many arguments or too low wrong number of args
	check_the_bear(av[1], &mlx);//vérifier que le fichier soit un .ber
	if (mlx.close == 1)
		return (-1);
	obsy(&mlx);//mets les obstacles en 2(buche) et non en 1(arbre)
	mlx.lon = 50 * mlx.len_x;//50 = taille des images en pixels
	mlx.lar = 50 * mlx.len_y;
	//ouvrir un fichier .ber
	//parser le fichier 0(vide) 1(mur) C(collectible minimum 1) E(exit x1) P(personnage x1), cart encadrée de murs
	//carte rectangulaire
	printf("début main\n");
	mlx.mlx = mlx_init();// return Xvar
	mlx.win = mlx_new_window(mlx.mlx, mlx.lon, mlx.lar, "so_long");//size en pixels
	sprint_map(&mlx);
	printf("MAP imprimée\n");
	mlx_hook(mlx.win, 2, 1L<<0, keep_rest, &mlx);//deplace le personnage
	mlx_loop_hook(mlx.mlx, loopy_loop, &mlx);
	return (0);//?
	}
