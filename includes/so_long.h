/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 08:22:03 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/16 18:45:10 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "./../minilibx-linux/mlx.h"

# include "struct.h"
# include "def.h"

# include <stdio.h>//norminette

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		p_et_e(t_mlx *mlx, char c, int x, int y);
int		ft_strlen(char *str);

void	coti(t_mlx *mlx, int x, int y);
void	mlx_struct_suite(t_mlx *mlx, char **av);

void	obsy(t_mlx *mlx);
void	mercotte(t_mlx *mlx, int y);
void	mapy(t_mlx *mlx);
void	mur_test(t_mlx *mlx);

void	exi(t_mlx *mlx, int y, int x);
void	vide(t_mlx *mlx, int y, int x);
void	mur(t_mlx *mlx, int y, int x);
void	obs(t_mlx *mlx, int y, int x);
void	collect(t_mlx *mlx, int y, int x);

void	cot(t_mlx *mlx, int y, int x);
void	cot_fin(t_mlx *mlx, int y, int x);

void	bear_me(t_mlx *mlx);
void	check_the_bear(char *nom, t_mlx *mlx, int x, int y);

int		err_cl(t_mlx *mlx, char*str);
int		err(char *str, int x);

int		close_it(t_mlx *mlx);

char	*ft_strjoin(char *s1, char *s2);

int		keep_rest(int keycode, t_mlx *mlx);
void	iff(t_mlx *mlx, int x, int y);

void	move_char_left(t_mlx *mlx, int x, int y);
void	move_char_right(t_mlx *mlx, int x, int y);
void	move_char_bot(t_mlx *mlx, int x, int y);
void	move_char_top(t_mlx *mlx, int x, int y);

int		err(char *str, int x);
int		free_tab(int **tab, int y, int ret);
int		ft_strlen(char *str);
void	cot(t_mlx *mlx, int y, int x);
int		get_next_line(int fd, char **line);
int		free_for_rtn(void *ptr, int rtn);
char	*ft_nextline(char **str);
char	*lolilol(char **str, char *strr, int x, int y);
int		ft_read(char **str, int fd);
char	*ft_read_suite(int fd, int n, char *strr, int *rid);
int		ft_check(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
//static void	ft_rev_str(char *str, int size);
//static int	ft_diz(long nb);
//char	*ft_itoa(int n);
void	sprint_map(t_mlx *mlx, int y, int x);
void	showtab(t_mlx *mlx);
int		create_tab(char *line, t_mlx *mlx, int y);

int		main(int ac, char **av);

#endif
