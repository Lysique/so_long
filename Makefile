NAME = so_long
FILES = main img_init free_functions ber_to_tab utils1 check_map display_map create_utils create_ennemy_instance imgs_tab character_loop key_hook update_player_pose close_game put_nb_step ennemy_management end_game
OBJS = $(SRCS:.c=.o)
SRCS_DIR = ./
MLX_DIR = ./mlx/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -f
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)
clean:
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
