NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror


MLX_LINUX = ./minilibx-linux/

MLX_MAC = ./minilibx-mac/

INCLUDES = ./includes/

SRCS = srcs/main.c\
	srcs/get_next_line.c\
	srcs/get_next_line_utils.c\
	srcs/trgb.c\
	srcs/ft_putnbr.c\
	srcs/ft_putchar.c\
	srcs/create_tab.c


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
	@$(CC) $(CFLAGS)$(CINCLUDES) $(OBJS) $(MLX_OS) -o $(NAME)

-include $(OBJS_D)
.c.o:
			@$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $(<:.c=.o)

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
