#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"

# include "struct.h"
# include "def.h"


# include <stdio.h>//norminette

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_strlen(char *str);
void		mercotte(t_mlx *mlx);
void		cot(t_mlx *mlx, int y, int x);
int		get_next_line(int fd, char **line);
int		free_for_rtn(void *ptr, int rtn);
char	*ft_nextline(char **str);
char	*lolilol(char **str, char *strr, int x, int y);
int		ft_read(char **str, int fd);
char	*ft_read_suite(int fd, int n, char *strr, int *rid);
int		ft_check(char *str);
void		ft_putchar(char c);
void		ft_putnbr(int n);
void	sprint_map(t_mlx *mlx);
void		showtab(t_mlx *mlx);
int		create_tab(char *line, t_mlx *mlx, int y);
typedef struct		s_long
{
		int	error_map_ber;
		int	error;
		int	fd;
		int	size;
		int	gnl;
		
		int	**mappy;
		int	E_x;
		int	E_y;
		int	P_x;
		int	P_y;
}			t_long;


int	main(int ac, char **av);

#endif
