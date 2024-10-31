NAME = so_long

BONUS = so_long_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_LINUX = ./minilibx-linux/

MLX_MAC = ./minilibx-mac/

INCLUDES = ./includes/

SRCS = srcs/main.c\
	   srcs/get_next_line.c\
	   srcs/get_next_line_utils.c\
	   srcs/ft_putnbr.c\
	   srcs/mercotte.c\
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

SRCS_BONUS = srcs_bonus/foxy_bonus.c\
			srcs_bonus/main_bonus.c\
			srcs_bonus/get_next_line_bonus.c\
			srcs_bonus/ft_itoa_bonus.c\
			srcs_bonus/ft_putchar_bonus.c\
			srcs_bonus/get_next_line_utils_bonus.c\
			srcs_bonus/mercotte_bonus.c\
			srcs_bonus/create_tab_bonus.c\
			srcs_bonus/move_it_bonus.c\
			srcs_bonus/ft_error_bonus.c\
			srcs_bonus/create_suite_bonus.c\
			srcs_bonus/bear_bonus.c\
			srcs_bonus/semi_parse_bonus.c\
			srcs_bonus/map_img_bonus.c\
			srcs_bonus/map_cot_bonus.c\
			srcs_bonus/print_map_bonus.c\

OS_NAME = $(shell uname -s)

CINCLUDES = -I $(INCLUDES)

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

OBJS_D = $(OBJS:.o=.d)

OBJS_BONUS_D = $(OBJS_BONUS:.o=.d)

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

bonus:	$(BONUS)

$(BONUS) : $(OBJS_BONUS) $(MLX_IS)libmlx.a
	@make -C $(MLX_LINUX)
	@$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS_BONUS) $(MLX_OS) -o $(BONUS)
	
-include $(OBJS_D)
-include $(OBJS_BONUS_D)
.c.o:
			@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)

$(MLX_IS)libmlx.a :
	  @make -C $(MLX_IS) all

clean: clean
	@make -C $(MLX_LINUX) clean
	@make -C $(MLX_MAC) clean
	@rm -rf $(OBJS) $(OBJS_D) $(OBJS_BONUS) $(OBJS_BONUS_D)
fclean: clean
	@rm -rf $(NAME) $(BONUS)
re:	fclean all

.PHONY: all clean fclean re
.SILENT:
