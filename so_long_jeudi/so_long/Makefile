NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3


MLX_LINUX = ./minilibx-linux/

MLX_MAC = ./minilibx-mac/

INCLUDES = ./includes/

SRCS = srcs/main.c\
	srcs/get_next_line.c\
	srcs/get_next_line_utils.c\
	srcs/ft_putnbr.c\
	srcs/ft_putchar.c\
	srcs/create_tab.c\
	srcs/move_it.c\
	srcs/ft_error.c\
	srcs/create_suite.c\
	srcs/bear.c\
	srcs/semi_parse.c\
	srcs/map_img.c\
	srcs/map_cot.c\
	srcs/print_map.c


OS_NAME = $(shell uname -s)

CINCLUDES = -I $(INCLUDES)

OBJS = $(SRCS:.c=.o)

OBJS_D = $(OBJS:.o=.d)

MLX_OS = 
ifeq ($(OS_NAME), Linux)
	MLX_IS = $(MLX_LINUX)
	CINCLUDES += -I $(MLX_LINUX)
	MLX_OS += -L $(MLX_LINUX) -lmlx -lXext -lX11
endif
ifeq ($(OS_NAME), Darwin)
	MLX_IS = $(MLX_MAC)
	CINCLUDE += -I $(MLX_MAC)
	MLX_OS += -L $(MLX_MAC) -lmlx -framework OpenGL -framework Appkit
endif

all:	$(NAME)

$(NAME) : $(OBJS) $(MLX_IS)libmlx.a
	@make -C $(MLX_LINUX)
	@$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) $(MLX_OS) -o $(NAME)

-include $(OBJS_D)
.c.o:
			@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)

$(MLX_IS)libmlx.a :
	@make -C $(MLX_IS) all

clean: clean
	@make -C $(MLX_LINUX) clean
	@make -C $(MLX_MAC) clean
	@rm -rf $(OBJS) $(OBJS_D)
fclean: clean
	@rm -rf $(NAME)
re:	fclean all

.PHONY: all clean fclean re
.SILENT:
